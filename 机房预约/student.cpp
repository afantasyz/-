#include "student.h"

student::student()
{

}

student::student(int id, string name, string password)
{
	this->m_id = id;
	this->p_name = name;
	this->p_password = password;

	ifstream ifs;
	int f_size;
	int f_roomId;
	ifs.open(COMPUTER_FILE, ios::in | ios::app);
	computerRoom* com = NULL;
	while (ifs >> f_roomId && ifs >> f_size)
	{
		com = new computerRoom(f_roomId, f_size);
		comList.push_back(*com);
	}
	ifs.close();
}

void student::Menu()
{
	cout << "��ӭѧ������" << this->p_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void student::openMenu()
{
	int select;
	while (true)
	{
		this->Menu();
		cin >> select;
		switch (select)
		{
		case 1:
			this->applyOrder();
			break;
		case 2:
			this->showMyOrder();
			break;
		case 3:
			this->showAllOrder();
			break;
		case 4:
			this->cancelOrder();
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

void student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int day;
	while (true)
	{
		cin >> day;
		if (day < 6 && day>0)
			break;
		cout << "��������" << endl;
	}
	

	cout << "��ѡ��ԤԼ��ʱ��" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	int time;
	while (true)
	{
		cin >> time;
		if (time == 1 || time == 2)
			break;
		cout << "��������" << endl;
	}

	cout << "��ѡ��ԤԼ�Ľ���" << endl;
	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << comList[0].M_size << endl;
	cout << "2�Ż���������" << comList[1].M_size << endl;
	cout << "3�Ż���������" << comList[2].M_size << endl;
	int room;
	while (true)
	{
		cin >> room;
		if (room > 0 && room < 4)
			break;
		cout << "��������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out|ios::app);
	ofs << day << " ";
	ofs << time << " ";
	ofs << this->p_name << " ";
	ofs << this->m_id << " ";
	ofs << room << " ";
	ofs << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}

void student::showMyOrder()
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

	while (ifs>>date&&ifs>>time&&ifs>>name&&ifs>>id&&ifs>>room&&ifs>>state)
	{
		if (id == this->m_id)
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
	}
	system("pause");
	system("cls");
}

void student::showAllOrder()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	int date;
	int time;
	string name;
	int id;
	int room;
	int state;

	while (ifs >> date && ifs >> time && ifs >> name && ifs >> id && ifs >> room && ifs >> state)
	{
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
	}
	system("pause");
	system("cls");
}

void student::cancelOrder()
{
	orderFile odF;

	if (odF.o_num == 0)
	{
		cout << "���޼�¼��ȡ��" << endl;
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
		if (id == this->m_id)
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
	}
	ifs.close();

	cout << "ѡ��ȡ����ԤԼ" << endl;
	int c_index;
	while (true)
	{
		cin >> c_index;
		if (c_index <= odF.order.size())
			break;
		else
			cout << "wrong selection" << endl;
	}
	odF.order[c_index - 1].a_state = 0;
	odF.updateOrder();
	cout << "ԤԼȡ���ɹ�" << endl;
	system("pause");
	system("cls");
}

student::~student()
{

}