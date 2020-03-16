#ifndef ABSTRACT_WELL_HPP
#define ABSTRACT_WELL_HPP

#include "well_type.hpp"

class AbstractWell {
public:
	AbstractWell(double& res, double pumpInVolume, double pumpOutVolume) {
		m_fieldResource = &res;
		m_pumpInVolume = pumpInVolume;
		m_pumpOutVolume = pumpOutVolume;
		m_pumpedInVolume = 0.;
		m_pumpedOutVolume = 0.;
	}
	//TODO: ��������� ��� ������� ������ �� ����� ���� ������ ����
	//�������
	void pumpIn() {
		*m_fieldResource += m_pumpInVolume;
		m_pumpedInVolume += m_pumpInVolume;
	}
	//�������
	void pumpOut() {
		*m_fieldResource += m_pumpOutVolume;
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

	double getPumpedOutVolume() {
		return m_pumpedOutVolume;
	}

	double getPumpedInVolume() {
		return m_pumpedInVolume;
	}

	double getPumpInVolume() {
		return m_pumpInVolume;
	}

	double getPumpOutVolume() {
		return m_pumpOutVolume;
	}

	void setPumpInVolume(double val) {
		m_pumpInVolume = val;
	}

	void setPumpOutVolume(double val) {
		m_pumpOutVolume = val;
	}
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