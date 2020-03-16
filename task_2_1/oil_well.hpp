#ifndef OIL_WELL_HPP
#define OIL_WELL_HPP

#include "abstract_well.hpp"

class OilWell : public AbstractWell {
public:
	OilWell(double& res, double pumpInVolume, double pumpOutVolume) : AbstractWell(res, pumpInVolume, pumpOutVolume) {};
	WellType getType() override {
		return WellType::OilWell;
	}
};

#endif