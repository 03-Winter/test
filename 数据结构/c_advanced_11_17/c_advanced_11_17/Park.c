#define _CRT_SECURE_NO_WARNINGS  1
#include"Parking.h"
//ȫ�ֱ��� n��ʾ�û�����ͣ����ͣ�ŵĳ�  cost�γ�ͣ���ѣ�truck������VANС����
int cost = 5, j = 0, k = 0, truck = 15, van = 10;
void WaitTopark(park* sc, sidewalkLink* swl)//������ϵĳ����복��
{
	if (swl->front == swl->rear)//���û�г� 
		printf("���û�г�����ʻ��ͣ����\n");
	else {
		//���� 
		sidewalk* S;
		S = swl->front->next;//Sָ���ͷ 
		swl->front->next = S->next;//Sָ��Ķ�ͷ����
		if (swl->rear == S)//���S�����һ���������ö�βָ��ָ���ͷ����ֹ��ָ 
			swl->rear = swl->front;
		//��ջ
		sc->count[sc->top + 1].carname = S->count1[k].carname;
		sc->count[sc->top + 1].ch = S->count1[k].ch;
		sc->count[sc->top + 1].type = S->count1[k].type;
		sc->count[sc->top + 1].time = S->count1[k].time;
		k++;
		sc->top++;
	}

}
void outcar(park* sc, char ch, char type, int car, int time)//ʻ������ 
{
	//��ȷ����û�г�����û�г���ĳ�������У���ǰ��ĳ���ջ����ʱ��ջ�
	//����Ҫ�����ĳ�����֮����˳���ջ 
	TemporaryCar tc;//��ʱͣ��
	InitTemporaryCar(&tc);
	int timesum;//����ʱ�� 
	if (sc->top == -1)
		printf("ͣ������û�г�\n");
	else if (IfTheCar(sc, car)) {
		printf("ͣ������û�д˳���\n");
	}
	else
	{
		while (sc->count[sc->top].carname != car)//�ڴ˳�ǰ��ĳ������ε���ʱͣ���� 
		{
			tc.data[tc.top + 1].carname = sc->count[sc->top].carname;
			tc.data[tc.top + 1].ch = sc->count[sc->top].ch;
			tc.data[tc.top + 1].time = sc->count[sc->top].time;
			tc.top++;
			sc->top--;//����	
		}
		timesum = time - sc->count[sc->top].time;
		if (timesum > 24)
			timesum = 24;//ͣ���ѷⶥ��Ϊ24Сʱ
		//�жϳ������ͼ���ͣ������
		if (sc->count[sc->top].type == 'c' || sc->count[sc->top].type == 'C')
			printf("������%d��ͣ��ͣ����ʱ����%d��ͣ��������%d\n", 
				sc->count[sc->top].carname, timesum, timesum * cost);
		else if (sc->count[sc->top].type == 't' || sc->count[sc->top].type == 'T')
			printf("������%d��ͣ��ͣ����ʱ����%d��ͣ��������%d\n",
				sc->count[sc->top].carname, timesum, timesum * truck);
		else printf("������%d��ͣ��ͣ����ʱ����%d��ͣ��������%d\n",
			sc->count[sc->top].carname, timesum, timesum * van);
		sc->top--;//���˳���ջ
		while (tc.top != -1)//��ʱͣ�������ν���ͣ���� 
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
void ArrivalCar(park* sc, sidewalkLink* wcl, char ch, char type, int car, int time)//ʻ�뺯�� 
{
	//��ͣ��������ʱ��������A��ʱ���ڱ���� 
	sidewalk* wc = (sidewalk*)malloc(sizeof(sidewalk));//�������ӽڵ�ָ�� 
	wc->next = NULL;
	if ((sc->top + 1) < MAXSIZE)//ͣ����û���� 
	{
		sc->count[sc->top + 1].ch = ch;//���복��״̬
		sc->count[sc->top + 1].type = type;//����γ�����
		sc->count[sc->top + 1].carname = car;//���복�ƺ�
		sc->count[sc->top + 1].time = time;//���복��ʻ��ʱ��
		sc->top++;

	}
	else//���ˣ������ 
	{
		wc->count1[j].carname = car;
		wc->count1[j].ch = ch;
		wc->count1[j].type = type;
		wc->count1[j].time = time;//ͬ��
		wc->next = NULL;
		wcl->rear->next = wc;
		wcl->rear = wc;
		j++;
	}
}
int IfTheCar(park* sc, char car)//�ж�ͣ�����Ƿ��������������
{
	int i = 0;
	while (i < sc->top + 1)//��ͷ����
	{
		if (sc->count[i].carname == car)
			return 0;
		i++;
	}
	return 1;
}
void Initpark(park* sc)//ͣ������ʼ�� 
{
	sc->top = -1;
}
int InitWaitCarLink(sidewalkLink* wcl) {//�����ʼ�� 
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
void InitTemporaryCar(TemporaryCar* tc)//��ʱͣ����ʼ��
{
	tc->top = -1;
}