#ifndef ABSTRACT_WELL_HPP
#define ABSTRACT_WELL_HPP

#include "well_type.hpp"

class AbstractWell {
public:
	AbstractWell(double& res) {
		m_fieldResource = res;
	}
	//TODO: ��������� ��� ������� ������ �� ����� ���� ������ ����
	//�������
	void pumpIn() {
		m_fieldResource += m_pumpInVolume;
		m_pumpedInVolume += m_pumpInVolume;
	}
	//�������
	void pumpOut() {
		m_fieldResource += m_pumpOutVolume;
		m_pumpedOutVolume += m_pumpOutVolume;
	}
	//�������� ��������
	void on() {
		m_isOn = true;
	}
	//��������� ��������
	void off() {
		m_isOn = false;
	}
	//�������� ��� ��������
	virtual WellType getType() = 0;
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
	double m_fieldResource;
};

#endif // ! ABSTRACT_WELL_HPP