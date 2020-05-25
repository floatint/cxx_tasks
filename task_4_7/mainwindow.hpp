#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "qt.hpp"
#include "stl.hpp"
#include "messages.hpp"
#include "configprovider.hpp"
#include "htmlfilewindow.hpp"

/*

	Main window

*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

//UI PART
private:
	//top level setup ui method
	void setupUi();
	//set ui text
	void retranslateUi();
	//connect slots 
	void connectUi();
	//show html file
	void openHtmlFile();
	//
	void setupHtmlFilesMenu();

	//ui elements
	QWidget *m_centralWidget;
	QVBoxLayout *m_verticalLayout;
	QMdiArea *m_mdiArea;
	QMenuBar *m_menuBar;
	QMenu *m_fileMenu;
	QAction *m_configOpenAction;
	QMenu *m_htmlFilesMenu;
	std::vector<QMenu*> m_htmlFileOpenActions;

//LOGIC PART
private:
	//slots
	void openConfigFile();
	//main window data
	std::vector<QFileInfo> m_files;
};

#endif
