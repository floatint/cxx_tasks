#include "task_2_1.hpp"

OilWell::OilWell(double& res, double pumpVolume) : AbstractWell(res, pumpVolume) {};

WellType OilWell::getType() {
	return WellType::OilWell;
}