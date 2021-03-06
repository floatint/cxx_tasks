﻿// task_2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "task_2_1.hpp"

//keywords and commands
const std::string EXIT = "exit";
const std::string HELP = "help";
const std::string STATUS = "status";
const std::string WELLS = "wells";
const std::string WELL = "well";
const std::string PUMP = "pump";
const std::string FIELD = "field";
const std::string ADD = "add";
const std::string RM = "rm";
const std::string SET = "set";
const std::string ON = "on";
const std::string OFF = "off";
const std::string GAS = "gas";
const std::string OIL = "oil";
const std::string WATER = "water";

int main()
{
	Field f;
	CLInterface cli;
	
	//initialize cli


	/*
		Exit
	*/
	cli.addCommand(EXIT, [&cli]() {
		cli.terminate();
	});

	cli.addCommand(HELP, []() {
		std::cout << "=========================HELP===================" << std::endl;
		std::cout << "exit - terminate programm" << std::endl;
		std::cout << "help - this message" << std::endl;
		std::cout << "status - current field status" << std::endl;
		std::cout << "wells - print list of all wells" << std::endl;
		std::cout << "field pump - field pumping" << std::endl;
		std::cout << "field add GAS|OIL|WATER vol - add new well" << std::endl;
		std::cout << "field set GAS|OIL|WATER vol - set field value" << std::endl;
		std::cout << "well idx pump - well's pumping" << std::endl;
		std::cout << "well idx on|off - enable/disable well" << std::endl;
		std::cout << "well idx set vol - wells's settings" << std::endl;
		std::cout << "=========================++++===================" << std::endl;
	});
	
	/*
		Print field status
	*/
	cli.addCommand(STATUS, [&f, &cli]() {
		std::cout << "Field state: " << std::endl;
		std::cout << "Gas volume:" << f.getGasVolume() << std::endl;
		std::cout << "Oil volume:" << f.getOilVolume() << std::endl;
		std::cout << "Water volume:" << f.getWaterVolume() << std::endl;
	});

	/*
		Print all wells
	*/
	cli.addCommand(WELLS, [&f, &cli]() {

		auto wells = f.getAllWells();
		int idx = 0;
		for (auto wIt = wells.first; wIt != wells.second; wIt++) {
			std::cout << "=============================" << std::endl;
			std::cout << "ID: " << idx++ << std::endl;
			std::cout << "Online: " << std::boolalpha << (*wIt)->isOn() << std::endl;
			std::cout << "Pumped volume: " << (*wIt)->getPumpedVolume() << std::endl;
			std::cout << "Pump volume: " << (*wIt)->getPumpVolume() << std::endl;
			std::cout << "Type: " << wellTypeMap[(*wIt)->getType()] << std::endl;
		}
	});

	/*
		Well's control
	*/
	cli.addCommand(WELL, [&f, &cli]() {
		int wellId;
		if (cli.getNextInput(wellId)) {
			AbstractWell* well = nullptr;
			if (wellId >= f.getWellsCount() || wellId < 0) {
				std::cout << "Invalid well's index" << std::endl;
			}
			else {
				well = *f.getWellById(wellId);
				std::string subCommand;
				if (cli.getNextInput(subCommand)) {
					subCommand = to_lower(subCommand);
					if ((subCommand != PUMP) && (subCommand != OFF) && (subCommand != ON) && (subCommand != SET)) {
						std::cout << "Invalid 'well' sub command" << std::endl;
					}
					else {
						//well set
						if (subCommand == SET) {
							double vol = 0;
							if (cli.getNextInput(vol)) {
								well->setPumpVolume(vol);
							}
						}
						//well pump
						if (subCommand == PUMP) {
							try {
								well->pump();
							}
							catch (std::exception& ex) {
								std::cout << ex.what() << std::endl;
							}
						}
						if (subCommand == ON)
							well->on();
						if (subCommand == OFF)
							well->off();
					}
				}
			}
		}
	});

	/*
		Field's control
	*/
	cli.addCommand(FIELD, [&f, &cli]() {
		std::string cmd;
		if (cli.getNextInput(cmd)) {
			cmd = to_lower(cmd);
			if ((cmd != PUMP) && (cmd != ADD) && (cmd != SET) && (cmd != RM)) {
				std::cout << "Invalid 'field' command" << std::endl;
			}
			else {
				//field pump
				if (cmd == PUMP) {
					try {
						f.pump();
					}
					catch (std::exception& ex) {
						std::cout << ex.what() << std::endl;
					}
				}
				//field add
				if (cmd == ADD) {
					std::string wellType;
					if (cli.getNextInput(wellType)) {
						wellType = to_lower(wellType);
						if ((wellType != GAS) && (wellType != OIL) && (wellType != WATER)) {
							std::cout << "Invalid 'field add' argument" << std::endl;
						}
						else {
							double vol = 0.;
							if (cli.getNextInput(vol)) {
								WellType wt;
								if (wellType == GAS)
									wt = WellType::GasWell;
								if (wellType == OIL)
									wt = WellType::OilWell;
								if (wellType == WATER)
									wt = WellType::WaterWell;
								f.addWell(wt, vol);
							}
						}
					}
				}
				if (cmd == RM) {
					int wellId;
					if (cli.getNextInput(wellId)) {
						if (wellId >= f.getWellsCount() || wellId < 0) {
							std::cout << "Invalid well's index" << std::endl;
						}
						else {
							f.removeWell(wellId);
						}
					}
				}
				//field set
				if (cmd == SET) {
					std::string arg;
					if (cli.getNextInput(arg)) {
						arg = to_lower(arg);
						double vol = 0.;
						if ((arg != OIL) && (arg != GAS) && (arg != WATER)) {
							std::cout << "Invalid 'field set' argument" << std::endl;
						}
						else {
							if (cli.getNextInput(vol)) {
								if (arg == OIL)
									f.setOilVolume(vol);
								if (arg == GAS)
									f.setGasVolume(vol);
								if (arg == WATER)
									f.setWaterVolume(vol);
							}
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
