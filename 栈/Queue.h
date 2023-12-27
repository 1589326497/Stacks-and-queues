#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;
//�õ�������ʵ��
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;

}QNode;

//��¼ͷ��β
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePudh(Queue* pq, QDataType x);  //��β��
void QueuePop(Queue* pq);                //��ͷ��

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);