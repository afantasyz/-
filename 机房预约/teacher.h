#pragma once
#include "person.h"
class teacher :
    public person
{
public:
	//Ĭ�Ϲ���
	teacher();

	//�вι��� (ְ����ţ�����������)
	teacher(int empId, string name, string password);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	void Menu();

	int m_EmpId; //��ʦ���
};

