#include<iostream>
using namespace std;
#include"defineFILE.h"
#include"manager.h"
#include"person.h"
#include"student.h"
#include"teacher.h"
#include<fstream>

void showMenu()
{
	cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
}

void logIn(string filename,int type)
{
	person* identity = NULL;
	string name;
	string password;
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	if (type == 1)
	{
		cout << "�������¼ѧ���û���" << endl;
		cin >> name;
		cout << "�������¼ѧ������" << endl;
		cin >> password;
	}
	else if (type == 2)
	{
		cout << "�������¼��ʦ�û���" << endl;
		cin >> name;
		cout << "�������¼��ʦ����" << endl;
		cin >> password;
	}
	else if (type == 3)
	{
		cout << "���������Ա�û���" << endl;
		cin >> name;
		cout << "���������Ա����" << endl;
		cin >> password;
	}
	
	if (type == 1)
	{
		int fid;
		string fname;
		string fpassword;
		while (ifs>>fid&&ifs>>fname&&ifs>>fpassword)
		{
			if (name == fname && password == fpassword)
			{
				identity = new student(fid, fname, fpassword);
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				identity->openMenu();
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (name == fname && password == fpassword)
			{
				identity = new teacher(fid, fname, fpassword);
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				identity->openMenu();
				return;
			}
		}
	}
	else if (type == 3)
	{
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (name == fname && password == fpassword)
			{
				identity = new manager(fname, fpassword);
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				identity->openMenu();
				return;
			}
		}
	}
	cout << "�û������������" << endl;
	identity = NULL;
	delete identity;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "welcome the next time!" << endl;
			exit(0);
			break;
		case 1:
			logIn(STUDENT_FILE, 1);
			break;
		case 2:
			logIn(TEACHER_FILE, 2);
			break;
		case 3:
			logIn(MANAGER_FILE, 3);
			break;
		default:
			cout << "error input" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}