#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>

#include "gas_well.hpp"
#include "oil_well.hpp"
#include "water_well.hpp"

class Field {
public:
	Field() {
		m_gasVolume = 0.;
		m_oilVolume = 0.;
		m_waterVolume = 0.;
		//add some wells
		addWell(WellType::GasWell, 0., 0.);
		addWell(WellType::WaterWell, 1.12, 2.4);
	}
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
	void addWell(WellType wt, double pumpInVolume, double pumpOutVolume) {
		switch (wt)
		{
		case WellType::GasWell:
			m_wells.push_back(new GasWell(m_gasVolume, pumpInVolume, pumpOutVolume));
			break;
		case WellType::OilWell:
			m_wells.push_back(new OilWell(m_oilVolume, pumpInVolume, pumpOutVolume));
			break;
		case WellType::WaterWell:
			m_wells.push_back(new WaterWell(m_waterVolume, pumpInVolume, pumpOutVolume));
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

	auto getWellById(int idx) {
		return m_wells.begin() + idx;
	}

	void pumpIn() {
		for (auto w : m_wells) {
			w->pumpIn();
		}
	}

	void pumpOut() {
		for (auto w : m_wells) {
			w->pumpOut();
		}
	}
private:
	//resources
	double m_gasVolume;
	double m_oilVolume;
	double m_waterVolume;
	//wells
	std::vector<AbstractWell*> m_wells;
};

#endif // !FIELD_HPP
