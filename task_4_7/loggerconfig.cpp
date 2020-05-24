#include "loggerconfig.hpp"

void LoggerConfig::setLogFile(const QFileInfo& file) {
	m_logFile = std::make_shared<QFile>(file.filePath());
}

std::weak_ptr<QFile> LoggerConfig::getLogFile() {
	return m_logFile;
}

std::shared_ptr<QFile> LoggerConfig::m_logFile;



void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
	
	QString outStr;
	
	switch (type) {
	case QtInfoMsg:
		outStr = QString("Info: %1").arg(msg);
		break;
	case QtDebugMsg:
		outStr = QString("Error: %1").arg(msg);
		break;
	case QtWarningMsg:
		outStr = QString("Warning: %1").arg(msg);
		break;
	case QtCriticalMsg:
		outStr = QString("Critical: %1").arg(msg);
		break;
	case QtFatalMsg:
		outStr = QString("Fatal: %1").arg(msg);
		abort();
		break;
	}

	//get time
	QDateTime dateTime = QDateTime::currentDateTime();

	outStr = QString("%1: %2").arg(dateTime.toString(Qt::ISODate)).arg(outStr);

	if (LoggerConfig::getLogFile().expired()) {
		Messages::error("Log file was expired. Abort");
		abort();
	};
	//get log file and lock his
	auto logFile = LoggerConfig::getLogFile().lock();
	//open file and write
	logFile->open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream ts(&(*logFile));
	ts << outStr << endl;
}