#ifndef CLI_HPP
#define CLI_HPP

class CLInterface {
public:
	CLInterface();
	
	void processCommands();
	
	template<typename T>
	bool getNextInput(T& val) {

		if (!(std::cin >> val)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid or unexpected user's input." << std::endl;
			return false;
		}
		return true;
	}

	void addCommand(const std::string& command, std::function<void()> proc);
	void terminate();
private:
	std::map<std::string, std::function<void()>> m_Commands;
	//cli statements
	bool m_isTerminated;
};

#endif