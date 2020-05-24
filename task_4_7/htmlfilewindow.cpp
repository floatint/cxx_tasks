#include "htmlfilewindow.hpp"

HTMLFileWindow::HTMLFileWindow(QWidget *parent, const QFileInfo& file)
	: QWidget(parent) 
{
	qInfo("HTML file window constructor start");
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
	qInfo("HTML file window constructor finish");
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


void HTMLFileWindow::processFile() {
	qInfo("Process HTML file start");
	try {
		m_processed = HTMLFileProvider::read(m_file, QRegExp(m_urlPattern));
	}
	catch (std::exception& ex) {
		qCritical(ex.what());
		Messages::error(ex.what());
	}
	if (m_processed.size() == 0) {
		const char *msg = "HTML file hasn't any URL";
		qWarning(msg);
		Messages::warn(msg);
	}
	qInfo("Process HTML file finish");
}