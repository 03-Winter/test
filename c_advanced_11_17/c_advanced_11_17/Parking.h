#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXSIZE 100//Ԥ����ͣ����������
//������������Ϣ
typedef struct {
	char ch;//������ʶ��������������ȥ
	char type;//��������
	int time;//ͣ����ʱ��
	int carname;//���ƺ� 
}Car;
//˳��ջʵ��ͣ���� 
typedef struct {
	Car count[MAXSIZE];//ͣ����������ͣ��100������ 
	int top;
}park;
//����ʵ�ֱ���Ŷӽ�ͣ����
typedef struct WaitCar {
	Car count1[MAXSIZE];//���������ͣ��100������ 
	struct WaitCar* next;
}sidewalk;
typedef struct {
	sidewalk* front;
	sidewalk* rear;
}sidewalkLink;//���Ӷ���
//˳��ջʵ�ָ���ʱ������������·
typedef struct {
	Car data[MAXSIZE];//��ʱͣ��������ͣ��100������ 
	int top;
}TemporaryCar;

void Initpark(park*);//ͣ������ʼ�� 
int InitWaitCarLink(sidewalkLink*);//��ʼ����� 
void InitTemporaryCar(TemporaryCar*);//��ʱͣ����ʼ�� 

void ArrivalCar(park*, sidewalkLink*, char, char, int, int);//��⺯�� 
void outcar(park*, char, char, int, int);//�뿪���� 
int IfTheCar(park*, char);//�ж��Ƿ�������������� 
void WaitTopark(park*, sidewalkLink*);//������ϵĳ����복��