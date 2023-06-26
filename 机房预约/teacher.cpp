#include "teacher.h"

teacher::teacher()
{
}

//�вι��� (ְ����ţ�����������)
teacher::teacher(int empId, string name, string password)
{
	this->m_EmpId = empId;
	this->p_name = name;
	this->p_password = password;
}

void teacher::Menu()
{
	cout << "��ӭ��ʦ��" << this->m_EmpId << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�˵�����
void teacher::openMenu()
{
	int select;
	while (true)
	{
		this->Menu();
		cin >> select;
		switch (select)
		{
		case 1:
			this->showAllOrder();
			break;
		case 2:
			this->validOrder();
			break;
		case 0:
			cout << "ע������ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//�鿴����ԤԼ
void teacher::showAllOrder()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	int date;
	int time;
	string name;
	int id;
	int room;
	int state;
	int index = 1;

	while (ifs >> date && ifs >> time && ifs >> name && ifs >> id && ifs >> room && ifs >> state)
	{
		cout << index << ". ";
		string cdate;
		switch (date)
		{
		case 1:
			cdate = "һ";
			break;
		case 2:
			cdate = "��";
			break;
		case 3:
			cdate = "��";
			break;
		case 4:
			cdate = "��";
			break;
		case 5:
			cdate = "��";
			break;
		default:
			break;
		}
		cout << "ԤԼ���ڣ� ��" << cdate << " ";
		cout << " ʱ��Σ� " << (time == 1 ? "����" : "����") << " ";
		cout << " ѧ�ţ� " << id << " ";
		cout << " �����ˣ� " << name << " ";
		cout << " �����ţ� " << room << " ";
		string cstate;
		if (state == 1)
			cstate = "�����";
		if (state == 0)
			cstate = "��ȡ��";
		if (state == -1)
			cstate = "δͨ��";
		if (state == 2)
			cstate = "��˳ɹ�";
		cout << " ״̬�� " << cstate << " ";
		cout << endl;
		index++;
	}

	ifs.close();
	system("pause");
	system("cls");
}

//���ԤԼ
void teacher::validOrder()
{
	orderFile odF;
	if (odF.o_num == 0)
	{
		cout << "���޼�¼�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ǰ����" << odF.o_num << "����¼" << endl;

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	int date;
	int time;
	string name;
	int id;
	int room;
	int state;
	int index = 1;

	while (ifs >> date && ifs >> time && ifs >> name && ifs >> id && ifs >> room && ifs >> state)
	{
		cout << index << ". ";
		string cdate;
		switch (date)
		{
		case 1:
			cdate = "һ";
			break;
		case 2:
			cdate = "��";
			break;
		case 3:
			cdate = "��";
			break;
		case 4:
			cdate = "��";
			break;
		case 5:
			cdate = "��";
			break;
		default:
			break;
		}
		cout << "ԤԼ���ڣ� ��" << cdate << " ";
		cout << " ʱ��Σ� " << (time == 1 ? "����" : "����") << " ";
		cout << " ѧ�ţ� " << id << " ";
		cout << " �����ˣ� " << name << " ";
		cout << " �����ţ� " << room << " ";
		string cstate;
		if (state == 1)
			cstate = "�����";
		if (state == 0)
			cstate = "��ȡ��";
		if (state == -1)
			cstate = "δͨ��";
		if (state == 2)
			cstate = "��˳ɹ�";
		cout << " ״̬�� " << cstate << " ";
		cout << endl;
		index++;
	}

	cout << "��������˵�ԤԼ" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select <= odF.o_num && select > 0)
		{
			break;
		}
		cout << "��������������ѡ��" << endl;
	}

	cout << "��������˽��" << endl;
	cout << "1��ͨ��" << endl;
	cout << "2����ͨ��" << endl;
	int status;
	cin >> status;
	if(status==1)
		odF.order[select - 1].a_state = 2;
	else if(status==2)
		odF.order[select - 1].a_state = -1;
	else
	{
		cout << "���ʧ��" << endl;
		system("pause");
		system("cls");
	}
	odF.updateOrder();
	cout << "��˳ɹ�" << endl;
	system("pause");
	system("cls");
}