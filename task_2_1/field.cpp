#include "task_2_1.hpp"

Field::Field() {
	m_gasVolume = 0.;
	m_oilVolume = 0.;
	m_waterVolume = 0.;
	//add some wells
	addWell(WellType::GasWell, 0., 0.);
	addWell(WellType::WaterWell, 1.12, 2.4);
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
void Field::addWell(WellType wt, double pumpInVolume, double pumpOutVolume) {
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

size_t Field::getWellsCount() {
	return m_wells.size();
}


void Field::pumpIn() {
	for (auto w : m_wells) {
		w->pumpIn();
	}
}

void Field::pumpOut() {
	for (auto w : m_wells) {
		w->pumpOut();
	}
}