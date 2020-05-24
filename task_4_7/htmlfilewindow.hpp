#ifndef HTMLFILEWINDOW_HPP
#define HTMLFILEWINDOW_HPP

#include "qt.hpp"
#include "messages.hpp"
#include "htmlfileprovider.hpp"

class HTMLFileWindow : public QWidget {
public:
	explicit HTMLFileWindow(QWidget *parent, const QFileInfo& file);
//UI PART
private:
	//setup ui widgets
	void setupUi();
	//ui widgets
	QVBoxLayout *m_verticalLayout;
	QTableWidget *m_linksTable;
	//consts
	const static int TABLE_COL_CNT = 3;
	const static int TABLE_LINE_INDEX = 0;
	const static int TABLE_POS_INDEX = 1;
	const static int TABLE_SUBSTR_INDEX = 2;
	//layout settings(setup in constructor)
	int m_layoutMarginLeft;
	int m_layoutMarginTop;
	int m_layoutMarginRight;
	int m_layoutMarginBottom;
	int m_layoutSpacing;
	//table header
	QStringList m_tableHeader{"Line", "Pos", "Substring"};

//logic part
private:
	void processFile();
	//pattern for matching
	QString m_urlPattern = R"((http|ftp|gopher|news|telnet|file)(:\/\/)(([\w\d]*)+\.([\w\d]*)+)(([\w\d]*)+\.([\w\d]*)+)*)";
	//window data
	QFileInfo m_file;
	//result of processing
	std::vector<std::tuple<int, int, QString>> m_processed;
};

#endif