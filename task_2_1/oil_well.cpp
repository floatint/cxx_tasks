#include "task_2_1.hpp"

OilWell::OilWell(double& res, double pumpInVolume, double pumpOutVolume) : AbstractWell(res, pumpInVolume, pumpOutVolume) {};

WellType OilWell::getType() {
	return WellType::OilWell;
}