// task_2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "task_2_1.hpp"

int main()
{
	Field f;
	CLInterface cli;
	//initialize cli
	cli.setDelimiter(' ');
	cli.casesensitive(false);

	/*
		Exit
	*/
	cli.addCommand("exit", [&cli]() {
		cli.terminate();
	});
	
	/*
		Print field status
	*/
	cli.addCommand("status", [&f, &cli]() {
		std::cout << "Field info: " << std::endl;
		std::cout << "Gas volume:" << f.getGasVolume() << std::endl;
		std::cout << "Oil volume:" << f.getOilVolume() << std::endl;
		std::cout << "Water volume:" << f.getWaterVolume() << std::endl;
	});

	/*
		Print all wells
	*/
	cli.addCommand("wells", [&f, &cli]() {
		
	});

	/*
		Well's control
	*/
	cli.addCommand("well", [&f, &cli]() {
		
	});

	/*
		Field's control
	*/
	cli.addCommand("field", [&f, &cli]() {
		std::string cmd;
		if (!cli.getNextInput(cmd)) {
			std::cout << "Couldn't get user's input" << std::endl;
		}
		else {
			if (cmd != "pump") {
				std::cout << "Field's control format: field <pump> <in|out>" << std::endl;
				return;
			}
			else {
				std::string arg;
				if (!cli.getNextInput(arg)) {
					std::cout << "Couldn't get user's input" << std::endl;
				}
				else {
					if ((arg != "in") && (arg != "out")) {
						std::cout << "Field's control format: field <pump> <in|out>" << std::endl;
					}
					else {
						if (arg == "in") {
							std::cout << "I'm pump in" << std::endl;
						}
						else {
							std::cout << "I'm pump out" << std::endl;
						}
					}
				}
			}
		}
	});

	//run
	cli.processCommands();

	//int a = 0;
	//cli.getUserInput("Enter the num:", a);
	/*std::cout << "ID|" << std::setw(3) << std::right
		<< std::setw(12) << "pumpedIn|"
		<< std::setw(12) << "pumpedOut|"
		<< std::setw(15) << "pumpInVolume|"
		<< std::setw(15) << "pumpOutVolume|"
		<< std::setw(10) << "Status|"
		<< std::setw(10) << "Type|"
		<< std::endl
		<< "--------------------------------------------------------------------------"
		<< std::endl;*/
    std::cout << "Hello World!\n"; 
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
