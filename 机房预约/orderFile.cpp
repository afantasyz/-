#include "orderFile.h"

orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in | ios::app);
	int date;
	int time;
	string name;
	int id;
	int room;
	int state;
	aorder* ptr = NULL;
	this->o_num = 0;

	while (ifs >> date && ifs >> time && ifs >> name && ifs >> id && ifs >> room && ifs >> state)
	{
		ptr = new aorder;
		ptr->a_date = date;
		ptr->a_time = time;
		ptr->a_name = name;
		ptr->a_id = id;
		ptr->a_room = room;
		ptr->a_state = state;
		order.insert(make_pair(o_num, *ptr));
		this->o_num++;
	}
	ifs.close();
	delete ptr;
}

void orderFile::updateOrder()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	for (map<int, aorder>::iterator it = this->order.begin(); it != this->order.end(); it++)
	{
		ofs << it->second.a_date << " ";
		ofs << it->second.a_time << " ";
		ofs << it->second.a_name << " ";
		ofs << it->second.a_id << " ";
		ofs << it->second.a_room << " ";
		ofs << it->second.a_state << endl;
	}
	ofs.close();

}