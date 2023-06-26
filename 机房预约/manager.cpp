#include "manager.h"

manager::manager()
{
}

//有参构造
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
	cout << "欢迎管理员：" << this->p_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//选择菜单
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

//添加账号  
void manager::addPerson()
{
	string filename;
	cout << "选择添加的身份" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "请输入添加学生学号" << endl;
		filename = STUDENT_FILE;
	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		cout << "请输入添加教师职工号" << endl;
	}
	else
	{
		cout << "错误输入" << endl;
		return;
	}

	int id;
	string name;
	string password;
	cin >> id;
	cout << "请输入添加用户名" << endl;
	cin >> name;
	cout << "请输入用户密码" << endl;
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
			cout << "该用户已注册" << endl;
			ifs.close();
			return;
		}
	}
	ifs.close();

	ofstream ofs;
	ofs.open(filename, ios::app | ios::out);
	ofs << id << " " << name << " " << password << endl;
	cout << "添加成功" << endl;
	ofs.close();
	this->initVector();
	system("pause");
	system("cls");
}

//查看账号
void manager::showPerson()
{
	int select;
	cout << "选择查看的身份" << endl;
	cout << "1、查看学生" << endl;
	cout << "2、查看老师" << endl;
	cin >> select;

	if (select == 1)
	{
		for (vector<student>::iterator it = stuList.begin(); it != stuList.end(); it++)
		{
			cout << "学号： " << it->m_id << " 姓名" << it->p_name << " 密码" << it->p_password << endl;
		}
	}
	if (select == 2)
	{
		for (vector<teacher>::iterator it = teaList.begin(); it != teaList.end(); it++)
		{
			cout << "职工号： " << it->m_EmpId << " 姓名" << it->p_name << " 密码" << it->p_password << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看机房信息
void manager::showComputer()
{
	for (vector<computerRoom>::iterator it = comList.begin(); it != comList.end(); it++)
	{
		cout << "机房号： " << it->R_id << " 机房容量" << it->M_size << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "记录清空成功" << endl;
	system("pause");
	system("cls");
}