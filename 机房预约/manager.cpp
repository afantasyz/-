#include "manager.h"

manager::manager()
{
}

//�вι���
manager::manager(string name, string pwd)
{
	this->p_name = name;
	this->p_password = pwd;
	this->initVector();

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

void manager::initVector()
{
	this->teaList.clear();
	this->stuList.clear();

	ifstream ifs;
	int f_id;
	string f_name;
	string f_password;

	ifs.open(STUDENT_FILE, ios::in | ios::app);
	student* stu = NULL;
	while (ifs >> f_id && ifs >> f_name && ifs >> f_password)
	{
		stu = new student(f_id, f_name, f_password);
		stuList.push_back(*stu);
	}
	ifs.close();
	stu = NULL;
	delete stu;

	ifs.open(TEACHER_FILE, ios::in | ios::app);
	teacher* tea = NULL;
	while (ifs >> f_id && ifs >> f_name && ifs >> f_password)
	{
		tea = new teacher(f_id, f_name, f_password);
		teaList.push_back(*tea);
	}
	ifs.close();
	tea = NULL;
	delete tea;
}

void manager::Menu()
{
	cout << "��ӭ����Ա��" << this->p_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//ѡ��˵�
void manager::openMenu()
{
	int select;
	while (true)
	{
		this->Menu();
		cin >> select;
		switch (select)
		{
		case 1:
			this->addPerson();
			break;
		case 2:
			this->showPerson();
			break;
		case 3:
			this->showComputer();
			break;
		case 4:
			this->cleanFile();
			break;
		case 0:
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//����˺�  
void manager::addPerson()
{
	string filename;
	cout << "ѡ����ӵ����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "���������ѧ��ѧ��" << endl;
		filename = STUDENT_FILE;
	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		cout << "��������ӽ�ʦְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
		return;
	}

	int id;
	string name;
	string password;
	cin >> id;
	cout << "����������û���" << endl;
	cin >> name;
	cout << "�������û�����" << endl;
	cin >> password;

	ifstream ifs;
	int f_id;
	string f_name;
	string f_password;
	ifs.open(filename, ios::in);
	while (ifs >> f_id && ifs >> f_name && ifs >> f_password)
	{
		if (f_id == id)
		{
			cout << "���û���ע��" << endl;
			ifs.close();
			return;
		}
	}
	ifs.close();

	ofstream ofs;
	ofs.open(filename, ios::app | ios::out);
	ofs << id << " " << name << " " << password << endl;
	cout << "��ӳɹ�" << endl;
	ofs.close();
	this->initVector();
	system("pause");
	system("cls");
}

//�鿴�˺�
void manager::showPerson()
{
	int select;
	cout << "ѡ��鿴�����" << endl;
	cout << "1���鿴ѧ��" << endl;
	cout << "2���鿴��ʦ" << endl;
	cin >> select;

	if (select == 1)
	{
		for (vector<student>::iterator it = stuList.begin(); it != stuList.end(); it++)
		{
			cout << "ѧ�ţ� " << it->m_id << " ����" << it->p_name << " ����" << it->p_password << endl;
		}
	}
	if (select == 2)
	{
		for (vector<teacher>::iterator it = teaList.begin(); it != teaList.end(); it++)
		{
			cout << "ְ���ţ� " << it->m_EmpId << " ����" << it->p_name << " ����" << it->p_password << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void manager::showComputer()
{
	for (vector<computerRoom>::iterator it = comList.begin(); it != comList.end(); it++)
	{
		cout << "�����ţ� " << it->R_id << " ��������" << it->M_size << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��¼��ճɹ�" << endl;
	system("pause");
	system("cls");
}