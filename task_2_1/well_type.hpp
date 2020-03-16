#ifndef WELL_TYPE_HPP
#define WELL_TYPE_HPP

#include <map>

enum class WellType {
	GasWell,
	OilWell,
	WaterWell
};


extern std::map<WellType, std::string> wellTypeMap;

#endif // ! WELL_TYPE_HPP