#include "htmlfilewindow.hpp"

HTMLFileWindow::HTMLFileWindow(QWidget *parent, const QFileInfo& file)
	: QWidget(parent) 
{
	//layout settings
	m_layoutSpacing = 6;
	m_layoutMarginLeft = 2;
	m_layoutMarginTop = 2;
	m_layoutMarginRight = 2;
	m_layoutMarginBottom = 2;
	//process file
	m_file = file;
	processFile();
	//draw
	setupUi();
}

void HTMLFileWindow::setupUi() {
	this->setWindowTitle(m_file.filePath());
	m_verticalLayout = new QVBoxLayout(this);
	m_verticalLayout->setSpacing(6);
	m_verticalLayout->setContentsMargins(m_layoutMarginLeft, m_layoutMarginTop, m_layoutMarginRight, m_layoutMarginBottom);
	m_linksTable = new QTableWidget(this);
	m_linksTable->setColumnCount(TABLE_COL_CNT);
	m_linksTable->setShowGrid(true);
	//StringList header{ "Line", "Pos", "Substring" };
	m_linksTable->setHorizontalHeaderLabels(m_tableHeader);
	m_linksTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	//iterate over processed result
	for (auto itemIt = m_processed.cbegin(); itemIt != m_processed.cend(); itemIt++) {
		int row = m_linksTable->rowCount();
		m_linksTable->insertRow(row);
		m_linksTable->setItem(row, TABLE_LINE_INDEX, new QTableWidgetItem(QString::number(std::get<TABLE_LINE_INDEX>(*itemIt))));
		m_linksTable->setItem(row, TABLE_POS_INDEX, new QTableWidgetItem(QString::number(std::get<TABLE_POS_INDEX>(*itemIt))));
		m_linksTable->setItem(row, TABLE_SUBSTR_INDEX, new QTableWidgetItem(std::get<TABLE_SUBSTR_INDEX>(*itemIt)));
	}
	//set table to widget
	m_verticalLayout->addWidget(m_linksTable);
}

//TODO: work with file separate into other file
void HTMLFileWindow::processFile() {
	//error message
	QString msg;
	QRegExp pattern(m_urlPattern);
	if (m_file.exists()) {
		//open file
		QFile file(m_file.filePath());
		if (file.open(QIODevice::ReadOnly)) {
			QTextStream in(&file);
			int line = 0; //current file
			
			//read all file and split it
			QStringList lines = in.readAll().split("\r\n", Qt::SplitBehaviorFlags::SkipEmptyParts);
			//iterate over all lines
			for (auto lineIt = lines.cbegin(); lineIt != lines.cend(); lineIt++) {
				line++;
				int currOffset = 0;
				//try get first substring
				currOffset = pattern.indexIn(*lineIt, currOffset) + 1;
				//while matched
				while (currOffset > 0) {
					m_processed.push_back({line, currOffset, pattern.cap()});
					//math next
					currOffset = pattern.indexIn(*lineIt, currOffset) + 1;
				}
			}
			//close file
			file.close();
			if (m_processed.size() == 0) {
				//TODO: log
				Messages::warn("HTML file doesn't have any URL");
			}
		}
		else { //file couldn't open
			msg.append("Couldn't open ");
			msg.append('\'');
			msg.append(m_file.filePath());
			msg.append('\'');
			msg.append(" file");
			throw std::runtime_error(msg.toStdString());
		}
	}
	else { //file not exists
		msg.append("File ");
		msg.append('\'');
		msg.append(m_file.filePath());
		msg.append('\'');
		msg.append(" not exists");
		throw std::invalid_argument(msg.toStdString());
	};
}