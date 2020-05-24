#include "messages.hpp"

void Messages::error(const QString& msg) {
	showMessage("Error", msg);
}

void Messages::warn(const QString& msg) {
	showMessage("Warning", msg);
}

void Messages::showMessage(const QString& title, const QString& msg) {
	QMessageBox msgBox;
	msgBox.setWindowTitle(title);
	msgBox.setText(msg);
	msgBox.setModal(true);
	msgBox.exec();
}