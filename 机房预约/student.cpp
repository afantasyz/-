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
	cout << "欢迎学生代表：" << this->p_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
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
			cout << "注销登入成功" << endl;
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
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int day;
	while (true)
	{
		cin >> day;
		if (day < 6 && day>0)
			break;
		cout << "输入有误" << endl;
	}
	

	cout << "请选择预约的时段" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	int time;
	while (true)
	{
		cin >> time;
		if (time == 1 || time == 2)
			break;
		cout << "输入有误" << endl;
	}

	cout << "请选择预约的教室" << endl;
	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << comList[0].M_size << endl;
	cout << "2号机房容量：" << comList[1].M_size << endl;
	cout << "3号机房容量：" << comList[2].M_size << endl;
	int room;
	while (true)
	{
		cin >> room;
		if (room > 0 && room < 4)
			break;
		cout << "输入有误" << endl;
	}
	cout << "预约成功！审核中" << endl;

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
				cdate = "一";
				break;
			case 2:
				cdate = "二";
				break;
			case 3:
				cdate = "三";
				break;
			case 4:
				cdate = "四";
				break;
			case 5:
				cdate = "五";
				break;
			default:
				break;
			}
			cout << "预约日期： 周" << cdate << " ";
			cout << " 时间段： " << (time == 1 ? "上午" : "下午") << " ";
			cout << " 学号： " << id << " ";
			cout << " 机房号： " << room << " ";
			string cstate;
			if (state == 1)
				cstate = "审核中";
			if (state == 0)
				cstate = "已取消";
			if (state == -1)
				cstate = "未通过";
			if (state == 2)
				cstate = "审核成功";
			cout << " 状态： " << cstate << " ";
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
			cdate = "一";
			break;
		case 2:
			cdate = "二";
			break;
		case 3:
			cdate = "三";
			break;
		case 4:
			cdate = "四";
			break;
		case 5:
			cdate = "五";
			break;
		default:
			break;
		}
		cout << "预约日期： 周" << cdate << " ";
		cout << " 时间段： " << (time == 1 ? "上午" : "下午") << " ";
		cout << " 学号： " << id << " ";
		cout << " 机房号： " << room << " ";
		string cstate;
		if (state == 1)
			cstate = "审核中";
		if (state == 0)
			cstate = "已取消";
		if (state == -1)
			cstate = "未通过";
		if (state == 2)
			cstate = "审核成功";
		cout << " 状态： " << cstate << " ";
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
		cout << "暂无记录可取消" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "当前共有" << odF.o_num << "条记录" << endl;


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
				cdate = "一";
				break;
			case 2:
				cdate = "二";
				break;
			case 3:
				cdate = "三";
				break;
			case 4:
				cdate = "四";
				break;
			case 5:
				cdate = "五";
				break;
			default:
				break;
			}
			cout << "预约日期： 周" << cdate << " ";
			cout << " 时间段： " << (time == 1 ? "上午" : "下午") << " ";
			cout << " 学号： " << id << " ";
			cout << " 机房号： " << room << " ";
			string cstate;
			if (state == 1)
				cstate = "审核中";
			if (state == 0)
				cstate = "已取消";
			if (state == -1)
				cstate = "未通过";
			if (state == 2)
				cstate = "审核成功";
			cout << " 状态： " << cstate << " ";
			cout << endl;
			index++;
		}
	}
	ifs.close();

	cout << "选择取消的预约" << endl;
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
	cout << "预约取消成功" << endl;
	system("pause");
	system("cls");
}

student::~student()
{

}