/*
@file:		StackC.h
@brief:		C语言链表栈的定义
@author:	Adlexer Xu
@date:		20/9/27
*/

#pragma once
#include "linkList.h"

typedef struct stack {
	int length;
	LinkList list;
}Stack;

typedef Stack* StackPtr;

Status InitStack(StackPtr stack);
Status ClearStack(StackPtr stack);
Status DestroyStack(StackPtr stack);
bool Stack_Empty(Stack stack);
int Stack_Length(Stack stack);
ElemType Stack_Back(Stack stack);
Status Stack_pushBack(StackPtr stack, ElemType elem);
Status Stack_popBack(StackPtr stack);