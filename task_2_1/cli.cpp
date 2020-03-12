#include "cli.hpp"

CLInterface::CLInterface() {
	m_isTerminated = false;
	m_isCaseSensitive = false;
}

void CLInterface::processCommands() {
	while (!m_isTerminated) {
		std::cout << "Enter command:" << std::endl;
		std::string command;
		if (!getNextInput(command)) {
			std::cout << "Couldn't get user's input" << std::endl;
		}
		else {
			if (command.size() != 0) {
				try {
					m_Commands[command]();
				}
				catch (std::exception& ex) {
					std::cout << "Undefined command" << std::endl;
				}
			}
		}
	}
}

void CLInterface::addCommand(const std::string& command, std::function<void()> proc) {
	m_Commands[command] = proc;
}
void CLInterface::setDelimiter(const char& d) {
	m_Delimiters.push_back(d);
}
void CLInterface::terminate() {
	m_isTerminated = true;
}
void CLInterface::casesensitive(bool f) {
	m_isCaseSensitive = f;
}