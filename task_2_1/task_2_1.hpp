#ifndef task_2_1
#define task_2_1


/*

1.	Нефтяное месторождение. Месторождению принадлежат скважины, 
	скважины бывают трех видов - нефтяные, газовые, нагнетательные 
	(для закачки воды в пласт). 
	Месторождение оперерует параметрами: объем газа в месторождении, объем нефти, 
	объем воды. У каждой скважины есть параметр – объем выкаченного или закаченного 
	содержимого. Задача заключается в моделировании работы месторождения. 
	Предполагается интерфейс для задания параметров месторождения, добавления/удаления 
	скважин, задания параметром каждой скважины, а также включения/выключения ее работы.
*/

/*
	CLI

	exit - terminate programm
	status - get current field state
	wells - print list of all wells
	field pump in|out - field pumping
	field add GAS|OIL|WATER inVol outVol
	well idx pump in|out
	well idx on|off
	well idx set inVol outVol
*/

//system
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <functional>

//user
#include "field.hpp"
#include "cli.hpp"
#include "utils.hpp"


#endif