#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100//预定义停放最大的汽车
//汽车的三项信息
typedef struct {
	char ch;//车辆的识别符，到达或者离去
	char type;//车辆类型
	int time;//停车的时间
	int carname;//车牌号 
}Car;
//顺序栈实现停车场 
typedef struct {
	Car count[MAXSIZE];//停车场最大可以停放100量汽车 
	int top;
}park;
//链队实现便道排队进停车场
typedef struct WaitCar {
	Car count1[MAXSIZE];//便道最大可以停放100量汽车 
	struct WaitCar* next;
}sidewalk;
typedef struct {
	sidewalk* front;
	sidewalk* rear;
}sidewalkLink;//链队定义
//顺序栈实现给临时出来的汽车让路
typedef struct {
	Car data[MAXSIZE];//临时停车最大可以停放100量汽车 
	int top;
}TemporaryCar;

void Initpark(park*);//停车场初始化 
int InitWaitCarLink(sidewalkLink*);//初始化便道 
void InitTemporaryCar(TemporaryCar*);//临时停车初始化 

void ArrivalCar(park*, sidewalkLink*, char, char, int, int);//入库函数 
void outcar(park*, char, char, int, int);//离开函数 
int IfTheCar(park*, char);//判断是否有输入的这辆车 
void WaitTopark(park*, sidewalkLink*);//将便道上的车进入车库

int cost = 5, j = 0, k = 0, truck = 15, van = 10;//全局变量 n表示用户输入停车场停放的车  cost轿车停车费，truck卡车，VAN小货车
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
	sidewalk* wc;//创建节点指针 
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
void WaitTopark(park* sc, sidewalkLink* swl)//将便道上的车进入车库
{
	if (swl->front == swl->rear)//便道没有车 
		printf("便道没有车可以驶入停车场\n");
	else {
		//出队 
		sidewalk* S;
		S = swl->front->next;//S指向队头 
		swl->front->next = S->next;//S指向的队头出队
		if (swl->rear == S)//如果S是最后一辆车，则让队尾指针指向队头，防止乱指 
			swl->rear = swl->front;
		//进栈
		sc->count[sc->top + 1].carname = S->count1[k].carname;
		sc->count[sc->top + 1].ch = S->count1[k].ch;
		sc->count[sc->top + 1].type = S->count1[k].type;
		sc->count[sc->top + 1].time = S->count1[k].time;
		k++;
		sc->top++;
	}

}
void outcar(park* sc, char ch, char type, int car, int time)//驶出函数 
{
	//先确定有没有车和有没有出库的车，如果有，则前面的车出栈到临时的栈里，等需要出来的车出来之后，在顺序进栈 
	TemporaryCar tc;//临时停车
	InitTemporaryCar(&tc);
	int timesum;//计算时间 
	if (sc->top == -1)
		printf("停车场内没有车\n");
	else if (IfTheCar(sc, car)) {
		printf("停车场里没有此车！\n");
	}
	else
	{
		while (sc->count[sc->top].carname != car)//在此车前面的车，依次到临时停车区 
		{
			tc.data[tc.top + 1].carname = sc->count[sc->top].carname;
			tc.data[tc.top + 1].ch = sc->count[sc->top].ch;
			tc.data[tc.top + 1].time = sc->count[sc->top].time;
			tc.top++;
			sc->top--;//下移	
		}
		timesum = time - sc->count[sc->top].time;
		if (timesum > 24)
			timesum = 24;//停车费封顶计为24小时
		if (sc->count[sc->top].type == 'c' || sc->count[sc->top].type == 'C')//判断车辆类型计算停车费用
			printf("车牌是%d在停车停留的时间是%d，停车费用是%d\n", sc->count[sc->top].carname, timesum, timesum * cost);
		else if (sc->count[sc->top].type == 't' || sc->count[sc->top].type == 'T')
			printf("车牌是%d在停车停留的时间是%d，停车费用是%d\n", sc->count[sc->top].carname, timesum, timesum * truck);
		else printf("车牌是%d在停车停留的时间是%d，停车费用是%d\n", sc->count[sc->top].carname, timesum, timesum * van);
		sc->top--;//将此车出栈
		while (tc.top != -1)//临时停车区依次进入停车场 
		{
			sc->count[sc->top + 1].carname = tc.data[tc.top].carname;
			sc->count[sc->top + 1].ch = tc.data[tc.top].ch;
			sc->count[sc->top + 1].type = tc.data[tc.top].type;
			sc->count[sc->top + 1].time = tc.data[tc.top].time;
			tc.top--;
			sc->top++;
		}
	}
}
void ArrivalCar(park* sc, sidewalkLink* wcl, char ch, char type, int car, int time)//驶入函数 
{
	//当停车场满的时候，在输入A的时候，在便道上 
	sidewalk* wc;//创建链队节点指针 
	wc = (sidewalk*)malloc(sizeof(sidewalk));
	wc->next = NULL;
	if ((sc->top + 1) < MAXSIZE)//停车场没有满 
	{
		sc->count[sc->top + 1].ch = ch;//存入车辆状态
		sc->count[sc->top + 1].type = type;//存入轿车类型
		sc->count[sc->top + 1].carname = car;//存入车牌号
		sc->count[sc->top + 1].time = time;//存入车辆驶入时间
		sc->top++;

	}
	else//满了，进便道 
	{
		wc->count1[j].carname = car;
		wc->count1[j].ch = ch;
		wc->count1[j].type = type;
		wc->count1[j].time = time;//同上
		wc->next = NULL;
		wcl->rear->next = wc;
		wcl->rear = wc;
		j++;
	}
}
int IfTheCar(park* sc, char car)//判断停车场是否有输入的这辆车
{
	int i = 0;
	while (i < sc->top + 1)//从头遍历
	{
		if (sc->count[i].carname == car)
			return 0;
		i++;
	}
	return 1;
}
void Initpark(park* sc)//停车场初始化 
{
	sc->top = -1;
}
int InitWaitCarLink(sidewalkLink* wcl) {//便道初始化 
	wcl->front = (sidewalk*)malloc(sizeof(sidewalk));
	if (wcl->front != NULL)
	{
		wcl->rear = wcl->front;
		wcl->front->next = NULL;
		return 0;
	}
	else
		return 1;
}
void InitTemporaryCar(TemporaryCar* tc)//临时停车初始化
{
	tc->top = -1;
}