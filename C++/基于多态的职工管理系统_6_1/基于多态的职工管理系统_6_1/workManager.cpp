#define _CRT_SECURE_NO_WARNINGS  1
#include<fstream>
#include"workManager.h"



workManager::workManager()
{
	ifstream ifs;
	ifs.open(filename, ios::in);//in��ȡ�ļ�
	//�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->Emparray = NULL;
		this->_Empnum = 0;
		this->fileEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->Emparray = NULL;
		this->_Empnum = 0;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_num();
	//cout << "ְ������Ϊ��" << num << endl;
	this->_Empnum = num;

	this->Emparray = new worker * [this->_Empnum+1];
	this->init_emp();

	//for (size_t i = 0; i < this->_Empnum; i++)
	//{
	//	cout <<"ְ����ţ�" << this->Emparray[i]->_id << " "
	//		<< "ְ��������"<<this->Emparray[i]->_name << " "
	//		<< "���ű�ţ�"<<this->Emparray[i]->_dept_id << endl;

	//}
}

void workManager::init_emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);//in��ȡ�ļ�

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
	ifs.open(filename, ios::in);//in��ȡ�ļ�

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
		cout << "�ļ�������" << endl;
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
	cout << "***********     ��ӭʹ��ְ������ϵͳ   **********" << endl;
	cout << "*****************  0.�˳��������  **************" << endl;
	cout << "*****************  1.����ְ����Ϣ  **************" << endl;
	cout << "*****************  2.��ʾְ����Ϣ  **************" << endl;
	cout << "*****************  3.ɾ����ְְ��  **************" << endl;
	cout << "*****************  4.�޸�ְ����Ϣ  **************" << endl;
	cout << "*****************  5.����ְ����Ϣ  **************" << endl;
	cout << "*****************  6.���ձ������  **************" << endl;
	cout << "*****************  7.��������ĵ�  **************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

void workManager::save()
{
	ofstream ofs;
	//�ļ�·��  �򿪷�ʽout��д���ķ�ʽ
	ofs.open(filename, ios::out);

	for (size_t i = 0; i < this->_Empnum; i++)
	{
		ofs << this->Emparray[i]->_id << " " << this->Emparray[i]->_name << " " << this->Emparray[i]->_dept_id << endl;

	}
	ofs.close();
}

void workManager::add_emp()
{
	cout << "���������Ա������" << endl;
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


			cout << "�������"<<i<<"����ְ�����" << endl;
			cin >> id;
			cout << "�������"<<i<<"����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		cout << "��ӳɹ�" << num <<endl;

		this->save();
	}
	else
	{
		cout << "�������ݴ���" << endl;
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
		cout << "�ļ�������" << endl;
	}
	else
	{
		int id;
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "��ְ��������" << endl;
		}

	}

	system("pause");
	system("cls");
}


void workManager::mod_emp()
{
	if (this->fileEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		int id;
		cout << "���������޸ĵ�ְ����ţ�" << endl;
		cin >> id;
		int index = isexist(id);
		if (index != -1)
		{
			delete this->Emparray[index];

			int newid;
			string newname;
			int newdept;

			cout << "��������ְ�����" << endl;
			cin >> newid;
			cout << "��������ְ������" << endl;
			cin >> newname;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;

			this->save();
		}
		else
		{
			cout << "��ְ��������" << endl;
		}

	}

	system("pause");
	system("cls");
}



void workManager::find_emp()
{
	if (this->fileEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "�������ѯ�ķ�ʽ" << endl << "1.���" << endl << "2.����" << endl;
		int choose;
		cin >> choose;
		if (choose == 1)
		{
			int id;
			cout << "��������ҵı�ţ�" << endl;
			cin >> id;
			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "��ѯ�ɹ�����ְ����Ϣ���£�" << endl;
				this->Emparray[ret]->showinfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (choose == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			int flag = false;
			for (size_t i = 0; i < this->_Empnum; i++)
			{
				if (this->Emparray[i]->_name == name)
				{
					flag = true;
					cout << "��ѯ�ɹ���ְ�����Ϊ��" << i << "����Ϣ���£�"<< endl;
					this->Emparray[i]->showinfo();
				}
			}
			if(false==flag)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}


	system("pause");
	system("cls");

}




void workManager::sort_emp()
{
	if (this->fileEmpty)
	{
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "1.��ְ��������" << endl;
		cout << "2.��ְ���Ž���" << endl;

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

		cout << "����ɹ�" << endl;
		this->save();
		this->show_emp();
	}
}


void workManager::clear_file()
{

	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

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
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void workManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
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



