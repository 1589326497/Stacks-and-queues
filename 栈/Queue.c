#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//����
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;  //������һ��
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
//��β��
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
		pq->tail->next = newnode;//β����һ��ָ����node
		pq->tail = newnode;//����βΪ��node
	}
}
void QueuePop(Queue* pq)               //��ͷ��
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)//������ֻ��һ������ʱ
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next; //�ֱ���������һ��
		free(pq->head);
		pq->head = next; //����head
	}
}
//���ض�ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//���ض�β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//�������� ͳ�ƽڵ�ĸ���
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
//�ж϶������Ƿ�������
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}