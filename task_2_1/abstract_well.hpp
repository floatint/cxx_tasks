#ifndef ABSTRACT_WELL_HPP
#define ABSTRACT_WELL_HPP

#include "well_type.hpp"

class AbstractWell {
public:
	AbstractWell(double& res, double pumpVolume);
	//качать(по умолчанию - откачивать)
	virtual void pump();
	//включить скважину
	void on();
	//выключить скважину
	void off();
	//получить тип скважины
	virtual WellType getType() = 0;

	double getPumpedVolume();


	double getPumpVolume();

	void setPumpVolume(double vol) {
		m_pumpVolume = vol;
	}

	bool isOn();

protected:
	//скважина включена
	bool m_isOn;
	//закаченный/откаченный объем
	double m_pumpedVolume;
	//объем работы одной закачки/откачки
	double m_pumpVolume;
	//ресурс месторождения
	double *m_fieldResource;
};

#endif // ! ABSTRACT_WELL_HPP