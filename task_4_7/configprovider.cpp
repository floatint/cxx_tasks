#include "configprovider.hpp"

std::vector<QFileInfo>* ConfigProvider::read(const QFileInfo& configFile) {
	std::vector<QFileInfo> *fileList = nullptr;
	QString msg;
	//if file not exists
	if (!configFile.exists()) {
		msg.append("Config ");
		msg.append('\'');
		msg.append(configFile.filePath());
		msg.append('\'');
		msg.append(" not exists");
		throw std::invalid_argument(msg.toStdString());
	}
	else {
		fileList = new std::vector<QFileInfo>();
		auto t = configFile.filePath();
		QFile file(configFile.filePath());
		//try open file
		if (file.open(QIODevice::ReadOnly)) {
			//read file
			QTextStream in(&file);
			QString data;
			in >> data;
			//fill html files vector
			auto htmlFileNames = data.split(',', Qt::SplitBehaviorFlags::SkipEmptyParts);
			for (auto fileIt = htmlFileNames.cbegin(); fileIt != htmlFileNames.cend(); fileIt++) {
				fileList->push_back(QFileInfo(*fileIt));
			}
		}
		else {
			msg.append("Couldn't open ");
			msg.append('\'');
			msg.append(configFile.filePath());
			msg.append('\'');
			msg.append(" config");
			throw std::runtime_error(msg.toStdString());
		}

	}
	return fileList;
};