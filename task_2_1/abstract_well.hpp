#ifndef ABSTRACT_WELL_HPP
#define ABSTRACT_WELL_HPP

#include "well_type.hpp"

class AbstractWell {
public:
	AbstractWell(double& res) {
		m_fieldResource = res;
	}
	//TODO: учитывать что целевой ресурс не может быть меньше нул€
	//закачка
	void pumpIn() {
		m_fieldResource += m_pumpInVolume;
		m_pumpedInVolume += m_pumpInVolume;
	}
	//откачка
	void pumpOut() {
		m_fieldResource += m_pumpOutVolume;
		m_pumpedOutVolume += m_pumpOutVolume;
	}
	//вклю€ить скважину
	void on() {
		m_isOn = true;
	}
	//выключить скважину
	void off() {
		m_isOn = false;
	}
	//получить тип скважины
	virtual WellType getType() = 0;
private:
	//скважина включена
	bool m_isOn;
	//закаченный объем
	double m_pumpedInVolume;
	//откаченный объем
	double m_pumpedOutVolume;
	//объем одной закачки
	double m_pumpInVolume;
	//объем одной откачки
	double m_pumpOutVolume;
protected:
	//ресурс месторождени€
	double m_fieldResource;
};

#endif // ! ABSTRACT_WELL_HPP