#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
//#include<system>
using namespace std;

#include"workManager.h"
#include"worker.h"

void choice()
{
	workManager wm;
	int choice;
	while (true)
	{
		wm.show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;

		case 1://���ְ��
			wm.add_emp();
			break;

		case 2://��ʾְ��
			wm.show_emp();
			break;

		case 3://ɾ��ְ��
			wm.del_emp();
			break;

		case 4://�޸�ְ��
			wm.mod_emp();
			break;

		case 5://����ְ��
			wm.find_emp();
			break;

		case 6://����ְ��
			wm.sort_emp();
			break;

		case 7://����ļ�
			wm.clear_file();
			break;

		default:
			system("cls");
			break;


		}
	}


	system("pause");
}




int main()
{
	choice();

	return 0;
}