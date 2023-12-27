#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;
//用单向链表实现
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;

}QNode;

//记录头和尾
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePudh(Queue* pq, QDataType x);  //队尾入
void QueuePop(Queue* pq);                //队头出

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);