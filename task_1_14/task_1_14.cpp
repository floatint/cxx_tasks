﻿
// task_1_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "task_1_14.hpp"


int main()
{
	//set double width
	std::cout.precision(OUT_PRECISION);
	
	std::string user_input;
	bool is_terminated = false;

	while (!is_terminated) {
		std::cout << "Enter number:" << std::endl;
		std::cin >> user_input;
		//to lower
		std::for_each(user_input.begin(), user_input.end(), [](char c) {
			c = std::tolower(c);
		});
		if (user_input == "exit") {
			is_terminated = true;
		}
		//convert
		else 
			std::cout << "Binary representation: " << user_atof(user_input.c_str()) << std::endl;
	}
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
