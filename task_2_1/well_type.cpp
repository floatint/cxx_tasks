#include "well_type.hpp"

extern std::map<WellType, std::string> wellTypeMap = {
	{WellType::GasWell, "GAS"},
	{WellType::OilWell, "OIL"},
	{WellType::WaterWell, "WATER"}
};