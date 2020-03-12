#ifndef FIELD_HPP
#define FIELD_HPP

#include <map>

#include "gas_well.hpp"
#include "oil_well.hpp"
#include "water_well.hpp"

class Field {
public:
	//setters
	void setGasVolume(double v) {
		m_gasVolume = v;
	}
	void setOilVolume(double v) {
		m_oilVolume = v;
	}
	void setWaterVolume(double v) {
		m_waterVolume = v;
	}
	//getters
	double getGasVolume() {
		return m_gasVolume;
	}
	double getOilVolume() {
		return m_oilVolume;
	}
	double getWaterVolume() {
		return m_waterVolume;
	}
	void addWell(WellType wt) {
		switch (wt)
		{
		case WellType::GasWell:
			m_wells.insert(std::make_pair(WellType::GasWell, new GasWell(m_gasVolume)));
			break;
		case WellType::OilWell:
			m_wells.insert(std::make_pair(WellType::OilWell, new OilWell(m_oilVolume)));
			break;
		case WellType::WaterWell:
			m_wells.insert(std::make_pair(WellType::WaterWell, new WaterWell(m_waterVolume)));
			break;
		default:
			break;
		}
	}
	auto getAllWells() {
		//return 0;
		return std::pair(m_wells.cbegin(), m_wells.cend());
	}

	size_t getWellsCount() {
		return m_wells.size();
	}
private:
	//resources
	double m_gasVolume;
	double m_oilVolume;
	double m_waterVolume;
	//wells
	//TODO: change to std::vector
	std::multimap<WellType, AbstractWell*> m_wells;
};

#endif // !FIELD_HPP
