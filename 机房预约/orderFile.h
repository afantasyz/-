#pragma once
#include<string>
using namespace std;
#include<map>
#include"defineFILE.h"
#include<fstream>
#include"aorder.h"

class orderFile
{
public:
	int o_num;
	map<int, aorder> order;

	orderFile();
	void updateOrder();
};

