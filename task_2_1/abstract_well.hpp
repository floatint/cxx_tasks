#ifndef ABSTRACT_WELL_HPP
#define ABSTRACT_WELL_HPP

#include "well_type.hpp"

class AbstractWell {
public:
	AbstractWell(double& res, double pumpVolume);
	//������(�� ��������� - ����������)
	virtual void pump();
	//�������� ��������
	void on();
	//��������� ��������
	void off();
	//�������� ��� ��������
	virtual WellType getType() = 0;

	double getPumpedVolume();


	double getPumpVolume();

	void setPumpVolume(double vol) {
		m_pumpVolume = vol;
	}

	bool isOn();

protected:
	//�������� ��������
	bool m_isOn;
	//����������/���������� �����
	double m_pumpedVolume;
	//����� ������ ����� �������/�������
	double m_pumpVolume;
	//������ �������������
	double *m_fieldResource;
};

#endif // ! ABSTRACT_WELL_HPP