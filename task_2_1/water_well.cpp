#include "task_2_1.hpp"

WaterWell::WaterWell(double& res, double pumpVolume) : AbstractWell(res, pumpVolume) {};

void WaterWell::pump() {
	if (m_isOn) {
		*m_fieldResource += m_pumpVolume;
		m_pumpedVolume += m_pumpVolume;
	}
}

WellType WaterWell::getType() {
	return WellType::WaterWell;
}