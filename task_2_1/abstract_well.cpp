#include "task_2_1.hpp"

AbstractWell::AbstractWell(double& res, double pumpInVolume, double pumpOutVolume) {
	m_fieldResource = &res;
	m_pumpInVolume = pumpInVolume;
	m_pumpOutVolume = pumpOutVolume;
	m_pumpedInVolume = 0.;
	m_pumpedOutVolume = 0.;
}

void AbstractWell::pumpIn() {
	*m_fieldResource += m_pumpInVolume;
	m_pumpedInVolume += m_pumpInVolume;
}

void AbstractWell::pumpOut() {
	if (*m_fieldResource == 0.)
		throw std::exception(std::string(wellTypeMap[getType()] + " resource out").c_str());
	if (*m_fieldResource - m_pumpedOutVolume < 0) {
		*m_fieldResource = 0.;
		m_pumpedOutVolume += std::abs(*m_fieldResource - m_pumpedOutVolume);
		throw std::exception(std::string(wellTypeMap[getType()] + " resource pumped out not fully").c_str());
	}
	else {
		*m_fieldResource -= m_pumpOutVolume;
		m_pumpedOutVolume += m_pumpOutVolume;
	}
}

void AbstractWell::on() {
	m_isOn = true;
}

void AbstractWell::off() {
	m_isOn = false;
}

double AbstractWell::getPumpedOutVolume() {
	return m_pumpedOutVolume;
}

double AbstractWell::getPumpedInVolume() {
	return m_pumpedInVolume;
}

double AbstractWell::getPumpInVolume() {
	return m_pumpInVolume;
}

double AbstractWell::getPumpOutVolume() {
	return m_pumpOutVolume;
}

void AbstractWell::setPumpInVolume(double val) {
	m_pumpInVolume = val;
}

void AbstractWell::setPumpOutVolume(double val) {
	m_pumpOutVolume = val;
}