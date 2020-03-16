#include "task_2_1.hpp"

WaterWell::WaterWell(double& res, double pumpInVolume, double pumpOutVolume) : AbstractWell(res, pumpInVolume, pumpOutVolume) {};

WellType WaterWell::getType() {
	return WellType::WaterWell;
}