#pragma once
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