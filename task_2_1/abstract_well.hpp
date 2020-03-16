#ifndef ABSTRACT_WELL_HPP
#define ABSTRACT_WELL_HPP

#include "well_type.hpp"

class AbstractWell {
public:
	AbstractWell(double& res, double pumpInVolume, double pumpOutVolume);
	//�������
	void pumpIn();
	//�������
	void pumpOut();
	//�������� ��������
	void on();
	//��������� ��������
	void off();
	//�������� ��� ��������
	virtual WellType getType() = 0;

	double getPumpedOutVolume();

	double getPumpedInVolume();

	double getPumpInVolume();

	double getPumpOutVolume();

	void setPumpInVolume(double val);

	void setPumpOutVolume(double val);
private:
	//�������� ��������
	bool m_isOn;
	//���������� �����
	double m_pumpedInVolume;
	//���������� �����
	double m_pumpedOutVolume;
	//����� ����� �������
	double m_pumpInVolume;
	//����� ����� �������
	double m_pumpOutVolume;
protected:
	//������ �������������
	double *m_fieldResource;
};

#endif // ! ABSTRACT_WELL_HPP