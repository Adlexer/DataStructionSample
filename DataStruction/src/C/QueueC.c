#include "QueueC.h"

Status InitQueue(QueuePtr stack) {
	InitLinkList(&(stack->list));
	stack->length = 0;
	return OK;
}

Status ClearQueue(QueuePtr stack) {
	ClearLinkList(&(stack->list));
	stack->length = 0;
	return OK;
}

Status DestroyQueue(QueuePtr stack) {
	DestroyLinkList(&(stack->list));
	free(stack);
	return OK;
}

bool Queue_Empty(Queue stack) {
	return stack.length == 0 ? 1 : 0;
}

int Queue_Length(Queue stack) {
	return stack.length;
}

ElemType Queue_Front(Queue stack) {
	return LinkList_GetElem(stack.list, 1);
}

Status Queue_pushBack(QueuePtr stack, ElemType elem) {
	stack->length++;
	return LinkList_Insert(&(stack->list), stack->length, elem);
}

Status Queue_popFront(QueuePtr stack) {
	return LinkList_Delete(&(stack->list), 1);
}