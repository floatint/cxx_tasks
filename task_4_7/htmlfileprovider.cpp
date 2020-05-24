#include "htmlfileprovider.hpp"


std::vector<std::tuple<int,int,QString>> HTMLFileProvider::read(const QFileInfo& file, QRegExp& pattern) {
	//error message
	QString msg;
	//result
	std::vector<std::tuple<int, int, QString>> result;
	if (file.exists()) {
		//open file
		qInfo("HTML file open");
		QFile fileObj(file.filePath());
		if (fileObj.open(QIODevice::ReadOnly)) {
			QTextStream in(&fileObj);
			int line = 0; //current file
			qInfo("HTML file fetch");
			//read all file and split it
			QStringList lines = in.readAll().split("\r\n", Qt::SplitBehaviorFlags::SkipEmptyParts);
			//iterate over all lines
			for (auto lineIt = lines.cbegin(); lineIt != lines.cend(); lineIt++) {
				qInfo("HTML file line iteration");
				line++;
				int currOffset = 0;
				//try get first substring
				currOffset = pattern.indexIn(*lineIt, currOffset) + 1;
				//while matched
				while (currOffset > 0) {
					qInfo("URL matched");
					result.push_back({ line, currOffset, pattern.cap() });
					//math next
					currOffset = pattern.indexIn(*lineIt, currOffset) + 1;
				}
			}
			//close file
			fileObj.close();
		}
		else { //file couldn't open
			msg.append("Couldn't open ");
			msg.append('\'');
			msg.append(file.filePath());
			msg.append('\'');
			msg.append(" file");
			qCritical(msg.toStdString().c_str());
			throw std::runtime_error(msg.toStdString());
		}
	}
	else { //file not exists
		msg.append("File ");
		msg.append('\'');
		msg.append(file.filePath());
		msg.append('\'');
		msg.append(" not exists");
		qCritical(msg.toStdString().c_str());
		throw std::invalid_argument(msg.toStdString());
	};
	return result;
}