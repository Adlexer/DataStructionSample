/*
@file:		StackC.h
@brief:		C语言链表栈的实现
@author:	Adlexer Xu
@date:		20/9/27
*/

#include "StackC.h"

Status InitStack(StackPtr stack) {
	InitLinkList(&(stack->list));
	stack->length = 0;
	return OK;
}

Status ClearStack(StackPtr stack) {
	ClearLinkList(&(stack->list));
	stack->length = 0;
	return OK;
}

Status DestroyStack(StackPtr stack) {
	DestroyLinkList(&(stack->list));
	free(stack);
	return OK;
}

bool Stack_Empty(Stack stack) {
	return stack.length == 0 ? 1 : 0;
}

int Stack_Length(Stack stack) {
	return stack.length;
}

ElemType Stack_Back(Stack stack) {
	return LinkList_GetElem(stack.list, stack.length);
}
Status Stack_pushBack(StackPtr stack, ElemType elem) {
	stack->length++;
	return LinkList_Insert(&(stack->list), stack->length, elem);
}
Status Stack_popBack(StackPtr stack) {
	return LinkList_Delete(&(stack->list), stack->length);
}