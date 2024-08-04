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
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;

		case 1://添加职工
			wm.add_emp();
			break;

		case 2://显示职工
			wm.show_emp();
			break;

		case 3://删除职工
			wm.del_emp();
			break;

		case 4://修改职工
			wm.mod_emp();
			break;

		case 5://查找职工
			wm.find_emp();
			break;

		case 6://排序职工
			wm.sort_emp();
			break;

		case 7://清空文件
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