#define _CRT_SECURE_NO_WARNINGS  1
#include<fstream>
#include"workManager.h"



workManager::workManager()
{
	ifstream ifs;
	ifs.open(filename, ios::in);//in读取文件
	//文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->Emparray = NULL;
		this->_Empnum = 0;
		this->fileEmpty = true;
		ifs.close();
		return;
	}
	//文件存在且为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->Emparray = NULL;
		this->_Empnum = 0;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，并且记录数据
	int num = this->get_num();
	//cout << "职工人数为：" << num << endl;
	this->_Empnum = num;

	this->Emparray = new worker * [this->_Empnum+1];
	this->init_emp();

	//for (size_t i = 0; i < this->_Empnum; i++)
	//{
	//	cout <<"职工编号：" << this->Emparray[i]->_id << " "
	//		<< "职工姓名："<<this->Emparray[i]->_name << " "
	//		<< "部门编号："<<this->Emparray[i]->_dept_id << endl;

	//}
}

void workManager::init_emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);//in读取文件

	int id;
	string name;
	int dept;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dept)
	{
		worker* w = NULL;
		if (dept == 1)
		{
			w = new employee(id, name, 1);
		}
		else if (dept == 2)
		{
			w = new manager(id, name, 2);
		}
		else
		{
			w = new boss(id, name, 3);
		}
		this->Emparray[index] = w;
		++index;
	}
	ifs.close();
}


int workManager::get_num()
{
	ifstream ifs;
	ifs.open(filename, ios::in);//in读取文件

	int id;
	string name;
	int dept;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dept)
	{
		++num;
	}
	ifs.close();

	return num;
}



void workManager::show_emp()
{
	if (this->fileEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		for (size_t i = 0; i < this->_Empnum; i++)
		{
			this->Emparray[i]->showinfo();
		}
	}

	system("pause");
	system("cls");
}



void workManager::show_menu()
{
	cout << "*************************************************" << endl;
	cout << "***********     欢迎使用职工管理系统   **********" << endl;
	cout << "*****************  0.退出管理程序  **************" << endl;
	cout << "*****************  1.增加职工信息  **************" << endl;
	cout << "*****************  2.显示职工信息  **************" << endl;
	cout << "*****************  3.删除离职职工  **************" << endl;
	cout << "*****************  4.修改职工信息  **************" << endl;
	cout << "*****************  5.查找职工信息  **************" << endl;
	cout << "*****************  6.按照编号排序  **************" << endl;
	cout << "*****************  7.清空所有文档  **************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

void workManager::save()
{
	ofstream ofs;
	//文件路径  打开方式out‘写’的方式
	ofs.open(filename, ios::out);

	for (size_t i = 0; i < this->_Empnum; i++)
	{
		ofs << this->Emparray[i]->_id << " " << this->Emparray[i]->_name << " " << this->Emparray[i]->_dept_id << endl;

	}
	ofs.close();
}

void workManager::add_emp()
{
	cout << "请输入添加员工数量" << endl;
	int num = 0;
	cin >> num;
	if (num > 0)
	{
		int newsize = this->_Empnum + num;
		worker** newspace = new worker * [newsize];
		if (this->_Empnum != NULL)
		{
			for (size_t i = 0; i < this->_Empnum; i++)
			{
				newspace[i] = this->Emparray[i];
			}
		}

		for (size_t i = 1; i <= num; i++)
		{
			int id;
			string name;
			int dept;


			cout << "请输入第"<<i<<"个新职工编号" << endl;
			cin >> id;
			cout << "请输入第"<<i<<"个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dept;

			worker* w = NULL;
			switch (dept)
			{
			case 1:
				w = new employee(id, name, 1);
				break;
			case 2:
				w = new manager(id, name, 2);

				break;
			case 3:
				w = new boss(id, name, 3);

				break;
			default:
				break;
			}
			newspace[this->_Empnum + i - 1] = w;

		}
		delete[] this->Emparray;
		this->Emparray = newspace;
		this->_Empnum = newsize;
		this->fileEmpty = false;
		cout << "添加成功" << num <<endl;

		this->save();
	}
	else
	{
		cout << "输入数据错误！" << endl;
	}

	system("pause");
	system("cls");

}



int workManager::isexist(int id)
{
	int index = -1;
	for (size_t i = 0; i < this->_Empnum; i++)
	{
		if (this->Emparray[i]->_id == id)
		{

			return i;
		}
	}
	return -1;
}

void workManager::del_emp()
{
	if (this->fileEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		int id;
		cout << "请输入想要删除的职工编号：" << endl;
		cin >> id;
		int index = isexist(id);
		if (index != -1)
		{
			for (size_t i = index; i < this->_Empnum; i++)
			{
				this->Emparray[i] - this->Emparray[i + 1];
			}
			this->_Empnum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "该职工不存在" << endl;
		}

	}

	system("pause");
	system("cls");
}


void workManager::mod_emp()
{
	if (this->fileEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		int id;
		cout << "请输入想修改的职工编号：" << endl;
		cin >> id;
		int index = isexist(id);
		if (index != -1)
		{
			delete this->Emparray[index];

			int newid;
			string newname;
			int newdept;

			cout << "请输入新职工编号" << endl;
			cin >> newid;
			cout << "请输入新职工姓名" << endl;
			cin >> newname;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newdept;

			worker* w = NULL;
			switch (newdept)
			{
			case 1:
				w = new employee(newid, newname, 1);
				break;
			case 2:
				w = new manager(newid, newname, 2);

				break;
			case 3:
				w = new boss(newid, newname, 3);

				break;
			default:
				break;
			}

			this->Emparray[index] = w;
			cout << "修改成功" << endl;

			this->save();
		}
		else
		{
			cout << "该职工不存在" << endl;
		}

	}

	system("pause");
	system("cls");
}



void workManager::find_emp()
{
	if (this->fileEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入查询的方式" << endl << "1.编号" << endl << "2.姓名" << endl;
		int choose;
		cin >> choose;
		if (choose == 1)
		{
			int id;
			cout << "请输入查找的编号：" << endl;
			cin >> id;
			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "查询成功，该职工信息如下：" << endl;
				this->Emparray[ret]->showinfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (choose == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			int flag = false;
			for (size_t i = 0; i < this->_Empnum; i++)
			{
				if (this->Emparray[i]->_name == name)
				{
					flag = true;
					cout << "查询成功，职工编号为：" << i << "的信息如下："<< endl;
					this->Emparray[i]->showinfo();
				}
			}
			if(false==flag)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");

}




void workManager::sort_emp()
{
	if (this->fileEmpty)
	{
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "1.按职工号升序" << endl;
		cout << "2.按职工号降序" << endl;

		int select;
		cin >> select;
		for (size_t i = 0; i < this->_Empnum; i++)
		{
			int c = i,b;
			for (size_t j = i+1; j < this->_Empnum; j++)
			{
				if (select == 1)
				{
					if (this->Emparray[c]->_id > this->Emparray[j]->_id)
					{
						c = j;
					}
				}
				else
				{
					if (this->Emparray[c]->_id < this->Emparray[j]->_id)
					{
						c = j;
					}
				}
			}
			if (c != i)
			{
				swap(this->Emparray[c], this->Emparray[i]);
			}
		}

		cout << "排序成功" << endl;
		this->save();
		this->show_emp();
	}
}


void workManager::clear_file()
{

	cout << "确认清空：" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select;
	cin >> select;
	if (select)
	{
		ofstream ofd(filename, ios::trunc);
		ofd.close();
		if (this->Emparray != NULL)
		{
			for (size_t i = 0; i < this->_Empnum; i++)
			{
				if (this->Emparray[i] != NULL)
				{
					delete this->Emparray[i];
				}
			}
			delete[] this->Emparray;
			this->_Empnum = 0;
			this->Emparray = NULL;
			this->fileEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

void workManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

workManager::~workManager()
{
	if (this->Emparray != NULL)
	{
		for (size_t i = 0; i < this->_Empnum; i++)
		{
			if (this->Emparray[i] != NULL)
			{
				delete this->Emparray[i];
			}
		}
		delete[] this->Emparray;
		this->Emparray = NULL;
		
	}
} 



