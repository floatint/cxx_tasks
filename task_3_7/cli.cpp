#include "task_3_7.hpp"

CLInterface::CLInterface() {
	m_isTerminated = false;
}

void CLInterface::processCommands() {
	while (!m_isTerminated) {
		std::cout << "Enter command:" << std::endl;
		std::string command;
		if (getNextInput(command)) {
			if (command.size() != 0) {
				try {
					command = to_lower(command);
					m_Commands[command]();
				}
				catch (std::exception& ex) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Undefined command" << std::endl;
				}
			}
		}
	}
}

void CLInterface::addCommand(const std::string& command, std::function<void()> proc) {
	m_Commands[command] = proc;
}
void CLInterface::terminate() {
	m_isTerminated = true;
}