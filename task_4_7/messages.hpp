#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "qt.hpp"

/*
	Message box emiter
*/
class Messages {
public:
	//emit error
	static void error(const QString& msg);
	//emit warning
	static void warn(const QString& msg);
	
	//low level message emiter
	static void showMessage(const QString& title, const QString& msg);
};

#endif