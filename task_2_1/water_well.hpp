#ifndef  WATER_WELL_HPP
#define WATER_WELL_HPP

#include "abstract_well.hpp"

class WaterWell : public AbstractWell {
public:
	WaterWell(double& res, double pumpInVolume, double pumpOutVolume) : AbstractWell(res, pumpInVolume, pumpOutVolume) {};
	WellType getType() {
		return WellType::WaterWell;
	}
};

#endif // ! WATER_WELL_HPP
