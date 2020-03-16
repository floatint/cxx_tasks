#ifndef ABSTRACT_WELL_HPP
#define ABSTRACT_WELL_HPP

#include "well_type.hpp"

class AbstractWell {
public:
	AbstractWell(double& res, double pumpInVolume, double pumpOutVolume);
	//закачка
	void pumpIn();
	//откачка
	void pumpOut();
	//включить скважину
	void on();
	//выключить скважину
	void off();
	//получить тип скважины
	virtual WellType getType() = 0;

	double getPumpedOutVolume();

	double getPumpedInVolume();

	double getPumpInVolume();

	double getPumpOutVolume();

	void setPumpInVolume(double val);

	void setPumpOutVolume(double val);
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
	//ресурс месторождения
	double *m_fieldResource;
};

#endif // ! ABSTRACT_WELL_HPP