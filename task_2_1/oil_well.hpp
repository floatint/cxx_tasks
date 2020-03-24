#ifndef OIL_WELL_HPP
#define OIL_WELL_HPP

#include "abstract_well.hpp"

class OilWell : public AbstractWell {
public:
	OilWell(double& res, double pumpVolume);

	WellType getType() override;
};

#endif