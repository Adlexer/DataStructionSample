/*
@file:		sequnenceListC.c
@brief:		顺序表和操作函数的C语言实现
@author:	Adlexer Xu
@date:		20/9/7
*/

#include "sequnenceListC.h"

Status InitSqList(SqListPtr List) {
	List->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!List->elem) exit(OVERFLOW);
	List->length = 0;
	List->size = LIST_INIT_SIZE;
	return OK;
}

void ShowSqList(SqListPtr List) {
	if (List->length == 0) {
		printf("empty list\n");
		return;
	}
	for (ElemType* pointer = List->elem; pointer <= List->elem + List->length - 1; pointer++) {
		printf("%d ", (int)*pointer);
	}
	printf("\n");
}

Status SqList_Insert(SqListPtr List, int index, ElemType elem) {
	if (index < 1 || index > List->length + 1) return ERROR;
	if (List->length >= List->size) {
		ElemType* newSpace = (ElemType*)realloc(List->elem, ((long long)List->size + LIST_INCREMENT) * sizeof(ElemType));
		if (!newSpace) exit(OVERFLOW);
		List->elem = newSpace;
		List->size += LIST_INCREMENT;
	}

	ElemType* pos = &(List->elem[index - 1]);
	for (ElemType* pointer = &(List->elem[List->length - 1]); pointer >= pos; pointer--) *(pointer + 1) = *pointer;

	*pos = elem;
	List->length++;
	return OK;
}

Status SqList_pushBack(SqListPtr List, ElemType elem) {
	return SqList_Insert(List, List->length + 1, elem);
}

Status SqList_Delete(SqListPtr List, int index) {
	if (index < 1 || index > List->length) return ERROR;
	for (ElemType* pointer = &(List->elem[index - 1]); pointer <= List->elem + List->length + 1; pointer++) {
		*(pointer - 1) = *pointer;
	}

	List->length--;
	return OK;
}

int SqList_Locate(SqListPtr List, ElemType elem, bool(*compare)(ElemType, ElemType)) {
	int index = 1;
	ElemType* pointer = List->elem;
	while (index <= List->length && !compare(*(pointer++), elem)) index++;

	if (index <= List->length) return index;
	else return 0;
}

SqList MergeSqList(SqList List1, SqList List2) {
	SqList newList;
	newList.length = List1.length + List2.length;
	newList.size = List1.size + List2.size;
	newList.elem = (ElemType*)malloc(newList.length * sizeof(ElemType));
	if (!newList.elem) exit(OVERFLOW);

	ElemType* pointer1 = List1.elem;
	ElemType* pointer2 = List2.elem;

	for (ElemType* pointer = newList.elem; pointer <= newList.elem + List1.length - 1; pointer++, pointer1++) {
		*pointer = *pointer1;
	}

	for (ElemType* pointer = newList.elem + List1.length; pointer <= newList.elem + newList.length - 1; pointer++, pointer2++) {
		*pointer = *pointer2;
	}

	return newList;
}

SqList MergeSqList_Inf(int num, ...) {
	va_list args;
	SqList Lists, newList;
	InitSqList(&newList);

	va_start(args, num);

	ElemType* prev_pointer = newList.elem;
	for (int i = 0; i < num; i++) {
		Lists = va_arg(args, SqList);
		newList.length += Lists.length;
		newList.size += Lists.size;
		newList.elem = (ElemType*)realloc(newList.elem, newList.length * sizeof(ElemType));

		ElemType* list_pointer = Lists.elem;
		for (ElemType* pointer = prev_pointer; pointer <= prev_pointer + Lists.length - 1; pointer++, list_pointer++) {
			*pointer = *list_pointer;
		}

		prev_pointer += Lists.length;
	}

	va_end(args);
	
	return newList;
}