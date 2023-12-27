#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//销毁
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;  //保存下一个
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
//队尾入
void QueuePudh(Queue* pq, QDataType x)  
{
	assert(pq);
	QNode* newnode =(QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-0);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;//尾的下一个指向新node
		pq->tail = newnode;//更新尾为新node
	}
}
void QueuePop(Queue* pq)               //队头出
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)//队列中只有一个数据时
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next; //现保存它的下一个
		free(pq->head);
		pq->head = next; //更新head
	}
}
//返回队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//返回队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//遍历队列 统计节点的个数
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
}
//判断队列中是否有数据
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}