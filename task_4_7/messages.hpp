#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "qt.hpp"

class Messages {
public:
	//top level messages emiters
	static void error(const QString& msg);
	static void warn(const QString& msg);
	//low level message emiter
	static void showMessage(const QString& title, const QString& msg);
};

#endif