#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>

#include "gas_well.hpp"
#include "oil_well.hpp"
#include "water_well.hpp"

class Field {
public:
	Field();

	//setters
	void setGasVolume(double v);

	void setOilVolume(double v);

	void setWaterVolume(double v);

	//getters
	double getGasVolume();

	double getOilVolume();

	double getWaterVolume();

	void addWell(WellType wt, double pumpInVolume, double pumpOutVolume);

	auto getAllWells() {
		return std::pair(m_wells.cbegin(), m_wells.cend());
	}

	size_t getWellsCount();

	auto getWellById(int idx) {
		return m_wells.begin() + idx;
	}

	void pumpIn();

	void pumpOut();
private:
	//resources
	double m_gasVolume;
	double m_oilVolume;
	double m_waterVolume;
	//wells
	std::vector<AbstractWell*> m_wells;
};

#endif // !FIELD_HPP
