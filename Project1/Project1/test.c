#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
using namespace std;
#include <string.h>

typedef char DataType;


//��������Ԫ�ؽṹ
typedef struct node
{
    DataType info;
    struct node* next;
}QueueData;

typedef struct queueRecord {
    QueueData* front, * rear;
}LINKQUEUE;

typedef struct queueRecord* PLinkQueue;

PLinkQueue createEmptyQueue_link()
{
    //����һ���ն��У�ʵ�ʣ�����һ��LINKQUEUE���͵Ľ�㣬����front �� rear ��Ա��ֵ
     //���ڴ˴���д���룬�����Ӧ����
     /*-------begin----------*/

    PLinkQueue p;
    p.*front = p.*fear = 0;
    return p;
    /*-------end----------*/

}

int isEmptyQueue_link(PLinkQueue  queue)
{ //�ж������Ƿ�Ϊ�գ�ʵ�ʣ� �����е�frontָ���Ƿ�Ϊ�գ���Ϊ�գ������Ϊ��

  //���ڴ˴���д���룬�����Ӧ����
    /*-------begin----------*/



    /*-------end----------*/
}

void enQueue_link(DataType x, PLinkQueue queue)
{
    //������Ԫ��x�����β��ʵ�ʣ�����һ��struct node���͵Ľ�㣬������Ӧ��Ա��ֵ������β
     //���ڴ˴���д���룬�����Ӧ����
     /*-------begin----------*/



     /*-------end----------*/
}

void enQueue_link(QueueData* p, PLinkQueue Q)
{
    //�������Ĺ����ǽ� struct node ���͵Ľ������β����enQueue_link(DataType x, PLinkQueue queue)�������ǣ�����Ҫ���ɽ��

       //���ڴ˴���д���룬�����Ӧ����
      /*-------begin----------*/



      /*-------end----------*/

}

DataType deQueue_link(PLinkQueue Q)
{
    //���ӣ�ʵ�ʣ� ȡ��Q���еĶ��׽�㣬���ظý�������Ԫ�أ������ý��ʹ��enQueue_link(QueueData *p,PLinkQueue Q)�����β
    //������Ϊ��Ա�ʵ��������ƣ���ʵ����Կ��ѭ��ʹ��
    //���ڴ˴���д���룬�����Ӧ����
   /*-------begin----------*/



   /*-------end----------*/

}

void decrypt(char src[], char key[], char dest[])
{
    /*  ������ src �ŵ���Դ�� �� key �ŵ�����Կ �� dest �ż��ܺ������
       ���ܺ����� ������ʾ
       1. ��ʼ��һ���ն���Q
       2. ��key�����Ԫ������������Q
       3. �������src�����Դ�ģ������ܣ� ʹ��deQueue_link(Q)�����ɵõ�������Կ����ʹ��Կѭ��ʹ��
    */

}

int main(void)
{
    char src[80], key[20], dest[80];

    cin >> src;

    cin >> key;
    decrypt(src, key, dest);
    cout << dest;
}


