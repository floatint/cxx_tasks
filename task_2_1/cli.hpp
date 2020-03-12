#ifndef CLI_HPP
#define CLI_HPP

#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <functional>

class CLInterface {
public:
	CLInterface();
	
	void processCommands();
	
	template<typename T>
	bool getNextInput(T& val) {
		try {
			std::cin >> val;
			return true;
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
		return false;
	}

	void addCommand(const std::string& command, std::function<void()> proc);
	void setDelimiter(const char& d);
	void terminate();
	void casesensitive(bool f);
private:
	std::map<std::string, std::function<void()>> m_Commands;
	std::vector<char> m_Delimiters;
	//cli statements
	bool m_isTerminated;
	bool m_isCaseSensitive;
};

#endif