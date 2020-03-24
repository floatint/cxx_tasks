#ifndef GAS_WELL_HPP
#define GAS_WELL_HPP

#include "abstract_well.hpp"

class GasWell : public AbstractWell {
public:
	GasWell(double& res, double pumpVolume);


	WellType getType() override;
};

#endif