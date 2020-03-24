#include "task_2_1.hpp"

GasWell::GasWell(double& res, double pumpVolume) : AbstractWell(res, pumpVolume) {};

WellType GasWell::getType() {
	return WellType::GasWell;
}