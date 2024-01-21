#define _CRT_SECURE_NO_WARNINGS  1
#include"Parking.h"
//全局变量 n表示用户输入停车场停放的车  cost轿车停车费，truck卡车，VAN小货车
int cost = 5, j = 0, k = 0, truck = 15, van = 10;
int main()
{
	int car, time = 1;//  time存放时间 
	char ch = ' ';//车的状态（驶入或驶出），  car 车牌号 
	char type;
	char eat;
	park sc;//停车场 
	Initpark(&sc);
	sidewalkLink swl;//便道
	InitWaitCarLink(&swl);
	//sidewalk* wc;//创建节点指针 
	while (ch != 'E')
	{
		printf("\n请输入车的状态（A驶入,D驶出），车辆类型，车牌号，驶入或者驶出的时间：");
		printf("\n例：A t 2 5");
		printf("\nc为轿车，t为卡车，v为小货车，大小写均可\n");
		scanf("%c %c %d %d", &ch, &type, &car, &time);
		if (ch == 'A')
			ArrivalCar(&sc, &swl, ch, type, car, time);
		else if (ch == 'D')
		{
			outcar(&sc, ch, type, car, time);
			WaitTopark(&sc, &swl);//不需要判断车库有没有车，当执行出库的时候，车库已经有位置了 
		}
		else {
			printf("请输入正确的编号,A是驶入，D是驶出！\n");
		}
		printf("\n如需退出请输入E 0 0 0\n");
		eat = getchar();//用来吞掉换行符		
	}
	return 0;
}
