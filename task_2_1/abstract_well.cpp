#include "task_2_1.hpp"

AbstractWell::AbstractWell(double& res, double pumpVolume) {
	m_fieldResource = &res;
	m_pumpVolume = pumpVolume;
	m_pumpedVolume = 0.;
}

void AbstractWell::pump() {
	if (m_isOn) {
		if (*m_fieldResource == 0.)
			throw std::exception(std::string(wellTypeMap[getType()] + " resource out").c_str());
		if (*m_fieldResource - m_pumpVolume < 0) {
			*m_fieldResource = 0.;
			m_pumpedVolume += std::abs(*m_fieldResource - m_pumpedVolume);
			throw std::exception(std::string(wellTypeMap[getType()] + " resource pumped out not fully").c_str());
		}
		else {
			*m_fieldResource -= m_pumpVolume;
			m_pumpedVolume += m_pumpVolume;
		}
	}
}

void AbstractWell::on() {
	m_isOn = true;
}

void AbstractWell::off() {
	m_isOn = false;
}

double AbstractWell::getPumpedVolume() {
	return m_pumpedVolume;
}


double AbstractWell::getPumpVolume() {
	return m_pumpVolume;
}

bool AbstractWell::isOn() {
	return m_isOn;
}