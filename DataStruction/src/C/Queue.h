#pragma once
#include "linkList.h"

typedef struct queue {
	int length;
	LinkList list;
}Queue;

typedef Queue* QueuePtr;

Status InitQueue(QueuePtr stack);
Status ClearQueue(QueuePtr stack);
Status DestroyQueue(QueuePtr stack);
bool Queue_Empty(Queue stack);
int Queue_Length(Queue stack);
ElemType Queue_Front(Queue stack);
Status Queue_pushBack(QueuePtr stack, ElemType elem);
Status Queue_popFront(QueuePtr stack);