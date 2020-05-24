#ifndef LOGGERCONFIG_HPP
#define LOGGERCONFIG_HPP

#include "qt.hpp"
#include "stl.hpp"
#include "messages.hpp"

/*

	Logging configuration

*/
class LoggerConfig {
public:
	static void setLogFile(const QFileInfo& file);
	static std::weak_ptr<QFile> getLogFile();
private:
	static std::shared_ptr<QFile> m_logFile;
};

//QDebug message handler
extern void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif