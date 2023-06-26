#pragma once
#include "person.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class manager :
    public person
{
public:
	vector<student> stuList;
	vector<teacher> teaList;
	vector<computerRoom> comList;

	//Ĭ�Ϲ���
	manager();

	//�вι���  ����Ա����������
	manager(string name, string pwd);

	//ѡ��˵�
	virtual void openMenu();

	void Menu();

	//����˺�  
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	void initVector();
};

