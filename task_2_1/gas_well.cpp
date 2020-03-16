#include "task_2_1.hpp"

GasWell::GasWell(double& res, double pumpInVolume, double pumpOutVolume) : AbstractWell(res, pumpInVolume, pumpOutVolume) {};

WellType GasWell::getType() {
	return WellType::GasWell;
}