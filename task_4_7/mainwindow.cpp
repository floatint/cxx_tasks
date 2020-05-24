#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	m_files = nullptr;
	m_htmlFilesMenu = nullptr;
    setupUi();
}

void MainWindow::setupUi() {
	//central widget and mdi area
	m_centralWidget = new QWidget(this);
	m_verticalLayout = new QVBoxLayout(m_centralWidget);
	m_verticalLayout->setSpacing(6);
	m_verticalLayout->setContentsMargins(11, 11, 11, 11);
	m_mdiArea = new QMdiArea(m_centralWidget);
	m_verticalLayout->addWidget(m_mdiArea);
	this->setCentralWidget(m_centralWidget);
	//menu bar setting
	m_menuBar = new QMenuBar(this);
	m_fileMenu = new QMenu(m_menuBar);
	m_configOpenAction = new QAction(this);
	this->setMenuBar(m_menuBar);
	m_menuBar->addAction(m_fileMenu->menuAction());
	m_fileMenu->addAction(m_configOpenAction);

	//set ui text
	this->retranslateUi();
	//connect slots
	this->connectUi();
	//just resize window
	this->resize(500, 500);
}

void MainWindow::retranslateUi() {
	this->setWindowTitle("Task 4. var 7");
	m_fileMenu->setTitle("File");
	m_configOpenAction->setText("Open config file");
}

void MainWindow::connectUi() {
	connect(m_configOpenAction, &QAction::triggered, this, &MainWindow::openConfigFile);
}

void MainWindow::openConfigFile() {
	QString configFileName = QFileDialog::getOpenFileName(this, "Select config file");
	std::vector<QFileInfo> *files = nullptr;
	if (!configFileName.isEmpty()) {
		//read file
		try {
			files = ConfigProvider::read(QFileInfo(configFileName));
		}
		catch (std::exception& ex) {
			//TODO: log
			Messages::showMessage("Error", ex.what());
		}
		//if load successfull
		if (files != nullptr) {
			if (m_files != nullptr)
				delete m_files;
			m_files = files;
			//setup html files menu
			setupHtmlFilesMenu();
		}
	} else {
		//TODO: log
		Messages::error("Config file was not selected");
	};
}

void MainWindow::setupHtmlFilesMenu() {
	if (m_files->size() != 0) {
		//if already loaded
		if (m_htmlFilesMenu != nullptr) {
			m_menuBar->removeAction(m_htmlFilesMenu->menuAction());
			delete m_htmlFilesMenu;
			m_htmlFileOpenActions.clear();
		}
		m_htmlFilesMenu = new QMenu(m_menuBar);
		m_htmlFilesMenu->setTitle("HTML files");
		//iterate over file vector and setup actions
		for (int i = 0; i < m_files->size(); i++) {
			QAction *htmlFileOpenAction = new QAction(this);
			//store FileInfo index into action object
			htmlFileOpenAction->setData(i);
			htmlFileOpenAction->setText((*m_files)[i].filePath());
			//connect slot
			connect(htmlFileOpenAction, &QAction::triggered, this, &MainWindow::openHtmlFile);
			m_htmlFilesMenu->addAction(htmlFileOpenAction);
		}
		m_menuBar->addAction(m_htmlFilesMenu->menuAction());
	}
	else {
		//TODO: log
		Messages::warn("Config file is empty");
	}
}

void MainWindow::openHtmlFile() {
	//get sender
	QObject* obj = sender();
	//get action
	QAction *action = qobject_cast<QAction *>(obj);
	//get FileInfo index
	int idx = action->data().toInt();

	HTMLFileWindow *fileWindow = nullptr;

	try {
		fileWindow = new HTMLFileWindow(m_mdiArea, (*m_files)[idx]);
	}
	catch (std::exception& ex) {
		//TODO: log
		Messages::error(ex.what());
	};

	if (fileWindow != nullptr) {
		m_mdiArea->addSubWindow(fileWindow);
		fileWindow->show();
	};
}
