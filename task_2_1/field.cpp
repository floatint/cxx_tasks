#include "task_2_1.hpp"

Field::Field() {
	m_gasVolume = 0.;
	m_oilVolume = 0.;
	m_waterVolume = 0.;
	//add some wells
	addWell(WellType::GasWell, 0.);
	addWell(WellType::WaterWell, 1.12);
}
//setters
void Field::setGasVolume(double v) {
	m_gasVolume = v;
}
void Field::setOilVolume(double v) {
	m_oilVolume = v;
}
void Field::setWaterVolume(double v) {
	m_waterVolume = v;
}
//getters
double Field::getGasVolume() {
	return m_gasVolume;
}
double Field::getOilVolume() {
	return m_oilVolume;
}
double Field::getWaterVolume() {
	return m_waterVolume;
}
void Field::addWell(WellType wt, double pumpVolume) {
	switch (wt)
	{
	case WellType::GasWell:
		m_wells.push_back(new GasWell(m_gasVolume, pumpVolume));
		break;
	case WellType::OilWell:
		m_wells.push_back(new OilWell(m_oilVolume, pumpVolume));
		break;
	case WellType::WaterWell:
		m_wells.push_back(new WaterWell(m_waterVolume, pumpVolume));
		break;
	default:
		break;
	}
}

size_t Field::getWellsCount() {
	return m_wells.size();
}


void Field::pump() {
	try {
		for (auto w : m_wells) {
			w->pump();
		}
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return;
	}
}

void Field::removeWell(int idx) {
	m_wells.erase(m_wells.cbegin() + idx);
}