#ifndef task_2_1
#define task_2_1

/*

1.	�������� �������������. ������������� ����������� ��������, 
	�������� ������ ���� ����� - ��������, �������, �������������� 
	(��� ������� ���� � �����). 
	������������� ��������� �����������: ����� ���� � �������������, ����� �����, 
	����� ����. � ������ �������� ���� �������� � ����� ����������� ��� ����������� 
	�����������. ������ ����������� � ������������� ������ �������������. 
	�������������� ��������� ��� ������� ���������� �������������, ����������/�������� 
	�������, ������� ���������� ������ ��������, � ����� ���������/���������� �� ������.
*/

/*
	CLI

	exit - terminate programm
	status - get current field state
	wells - print list of all wells
	field pump - field pumping
	field add GAS|OIL|WATER vol
	field set GAS|OIL|WATER vol
	field rm idx
	well idx pump
	well idx on|off
	well idx set vol
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