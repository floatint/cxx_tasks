#ifndef GAS_WELL_HPP
#define GAS_WELL_HPP

#include "abstract_well.hpp"

class GasWell : public AbstractWell {
public:
	GasWell(double& res, double pumpInVolume, double pumpOutVolume) : AbstractWell(res, pumpInVolume, pumpOutVolume) {};
	WellType getType() override {
		return WellType::GasWell;
	}
};

#endif