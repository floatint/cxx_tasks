#include "task_4_7.hpp"

int main(int argc, char *argv[])
{
	//configure log
	LoggerConfig::setLogFile(QFileInfo("log.txt"));
	qInstallMessageHandler(messageHandler);

	qInfo("Application start");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	qInfo("Main window processing");
    return a.exec();
}
