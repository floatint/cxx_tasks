#ifndef  WATER_WELL_HPP
#define WATER_WELL_HPP

#include "abstract_well.hpp"

class WaterWell : public AbstractWell {
public:
	WaterWell(double& res, double pumpVolume);

	void pump() override;

	WellType getType() override;
};

#endif // ! WATER_WELL_HPP
