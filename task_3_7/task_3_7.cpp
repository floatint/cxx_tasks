// task_3_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "task_3_7.hpp"

const std::string DEQUE = "deque";
const std::string SHOW = "show";
const std::string INT = "int";
const std::string STR = "str";
const std::string PUSH_FRONT = "push_front";
const std::string PUSH_BACK = "push_back";
const std::string POP_FRONT = "pop_front";
const std::string POP_BACK = "pop_back";
const std::string SIZE = "size";
const std::string HELP = "help";
const std::string EXIT = "exit";

int main()
{
	UserDeque<std::string> stringDeque;
	UserDeque<int> intDeque;
	
	CLInterface cli;

	cli.addCommand(EXIT, [&cli]() {
		cli.terminate();
	});

	cli.addCommand(HELP, []() {
		std::cout << "========================HELP======================" << std::endl;
		std::cout << "TYPE = int|str - deque type" << std::endl;
		std::cout << "deque TYPE show - show deque" << std::endl;
		std::cout << "deque TYPE size - show deque size" << std::endl;
		std::cout << "deque TYPE push_front - deque push front" << std::endl;
		std::cout << "deque TYPE push_back - deque push back" << std::endl;
		std::cout << "deque TYPE pop_front - deque pop front" << std::endl;
		std::cout << "deque TYPE pop_back - deque pop back" << std::endl;
		std::cout << "exit - terminate program" << std::endl;
		std::cout << "help - print this message" << std::endl;
		std::cout << "==================================================" << std::endl;
	});

	cli.addCommand(DEQUE, [&cli, &stringDeque, &intDeque]() {
		std::string dequeType;
		if (cli.getNextInput(dequeType)) {
			dequeType = to_lower(dequeType);
			if ((dequeType != INT) && (dequeType != STR)) {
				std::cout << "Invalid deque type" << std::endl;
			}
			else {
				std::string command;
				if (cli.getNextInput(command)) {
					command = to_lower(command);
					if ((command != PUSH_FRONT) && (command != PUSH_BACK) &&
						(command != POP_FRONT) && (command != POP_BACK) &&
						(command != SIZE) && (command != SHOW)
						) 
					{
						std::cout << "Invalid deque command" << std::endl;
					}
					else {
						if (command == SHOW) {
							if (dequeType == STR)
								std::cout << "String deque: " << stringDeque << std::endl;
							if (dequeType == INT)
								std::cout << "Int deque: " << intDeque << std::endl;
						}
						if (command == SIZE) {
							if (dequeType == STR)
								std::cout << "String deque size: " << stringDeque.size() << std::endl;
							if (dequeType == INT)
								std::cout << "Int deque size: " << intDeque.size() << std::endl;
						}
						std::string strElem;
						int intElem;
						try {
							if (command == PUSH_FRONT) {
								if (dequeType == STR) {
									if (cli.getNextInput(strElem)) {
										stringDeque.push_front(strElem);
									}
								}
								if (dequeType == INT) {
									if (cli.getNextInput(intElem)) {
										intDeque.push_front(intElem);
									}
								}
							}
							if (command == PUSH_BACK) {
								if (dequeType == STR) {
									if (cli.getNextInput(strElem)) {
										stringDeque.push_back(strElem);
									}
								}
								if (dequeType == INT) {
									if (cli.getNextInput(intElem)) {
										intDeque.push_back(intElem);
									}
								}
							}
							if (command == POP_FRONT) {
								if (dequeType == STR)
									stringDeque.pop_front();
								if (dequeType == INT)
									intDeque.pop_front();
							}
							if (command == POP_BACK) {
								if (dequeType == STR)
									stringDeque.pop_back();
								if (dequeType == INT)
									intDeque.pop_back();
							}
						}
						catch (std::exception& ex) {
							std::cout << ex.what() << std::endl;
						}
					}
				}
			}
		}
	});

	cli.processCommands();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
