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
		std::cout << "Field state: " << std::endl;
		std::cout << "Gas volume:" << f.getGasVolume() << std::endl;
		std::cout << "Oil volume:" << f.getOilVolume() << std::endl;
		std::cout << "Water volume:" << f.getWaterVolume() << std::endl;
	});

	/*
		Print all wells
	*/
	cli.addCommand("wells", [&f, &cli]() {

		auto wells = f.getAllWells();
		int idx = 0;
		for (auto wIt = wells.first; wIt != wells.second; wIt++) {
			std::cout << "=============================" << std::endl;
			std::cout << "ID: " << idx++ << std::endl;
			std::cout << "Pumped in: " << (*wIt)->getPumpedInVolume() << std::endl;
			std::cout << "Pumped out: " << (*wIt)->getPumpedOutVolume() << std::endl;
			std::cout << "Pump in volume: " << (*wIt)->getPumpInVolume() << std::endl;
			std::cout << "Pump out volume: " << (*wIt)->getPumpOutVolume() << std::endl;
			std::cout << "Type: " << wellTypeMap[(*wIt)->getType()] << std::endl;
		}
	});

	/*
		Well's control
	*/
	cli.addCommand("well", [&f, &cli]() {
		int wellId;
		if (!cli.getNextInput(wellId)) {
			return;
		}
		else {
			AbstractWell* well = nullptr;
			if (wellId >= f.getWellsCount() || wellId < 0) {
				std::cout << "Invalid well's index" << std::endl;
				return;
			}
			else {
				well = *f.getWellById(wellId);
				std::string subCommand;
				if (!cli.getNextInput(subCommand)) {
					return;
				}
				else {
					if ((subCommand != "pump") && (subCommand != "off") && (subCommand != "on") && (subCommand != "set")) {
						std::cout << "Invalid 'well' command. ";
					}
					else {
						if (subCommand == "set") {
							double inVol = 0;
							double outVol = 0;
							if (!cli.getNextInput(inVol)) {
								return;
							}
							if (!cli.getNextInput(outVol)) {
								return;
							}
							else {
								well->setPumpInVolume(inVol);
								well->setPumpOutVolume(outVol);
							}

						}
						//pump command
						if (subCommand == "pump") {
							std::string arg;
							if (!cli.getNextInput(arg)) {
								return;
							}
							else {
								if ((arg != "in") || (arg != "out")) {
									std::cout << "Well command format: well <index> <pump (in|out)> | <on|off>";
								}
								else {
									if (arg == "in") {
										well->pumpIn();
									}
									else {
										well->pumpOut();
									}
								}
							}
						}
						if (subCommand == "on") {
							well->on();
						}
						else {
							well->off();
						}
					}
				}
			}
		}
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
			//if (cmd != "pump") || (cmd != "add")
			 
			if (cmd != "pump") {
				std::cout << "Field's control format: field <pump> <in|out>" << std::endl;
				return;
			}
			else {
				std::string arg;
				if (!cli.getNextInput(arg)) {
					return;
					//std::cout << "Couldn't get user's input" << std::endl;
				}
				else {
					if ((arg != "in") && (arg != "out")) {
						std::cout << "Field's control format: field <pump> <in|out>" << std::endl;
					}
					else {
						if (arg == "in") {
							f.pumpIn();
						}
						else {
							f.pumpOut();
						}
					}
				}
			}
		}
	});

	//run
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
