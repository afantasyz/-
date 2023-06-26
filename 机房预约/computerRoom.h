#pragma once
#include<iostream>
using namespace std;

class computerRoom
{
public:
	int M_size;
	int R_id;

	computerRoom(int id, int size)
	{
		this->R_id = id;
		this->M_size = size;
	}
};

