#pragma once
#include<iostream>
#define filename "wen.txt"

using namespace std;
#include"worker.h"
class workManager
{
public:
	workManager();
	int get_num();
	bool fileEmpty;
	void save();
	void init_emp();
	void show_menu();
	void ExitSystem();
	void add_emp();
	void show_emp();
	void del_emp();
	int isexist(int id);
	void mod_emp();
	void find_emp();

	void sort_emp();

	void clear_file();
	worker** Emparray;
	~workManager();
private:
	int _Empnum;

};
