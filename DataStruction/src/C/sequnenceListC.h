/*
@file:		sequnenceListC.h
@brief:		˳���Ͳ���������C���Զ���
@author:	Adlexer Xu
@date:		20/9/7
*/

// Visual Studio 2019
#pragma once

#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int ElemType;
typedef int Status;

typedef _Bool boolean;

typedef struct {
	ElemType* elem;
	int length;
	int size;
}SqList;

typedef SqList* SqListPtr;

/*
@brief			��ʼ��˳���
@param	List:	����˳����ַ
@return			״̬
*/
Status InitSqList(SqListPtr List);

/*
@brief			��ʾ˳���������Ԫ��(int)
@param	List:	����˳����ַ
*/
void ShowSqList(SqListPtr List);

/*
@brief			����������˳����в���һ��Ԫ��
@param	List:	����˳����ַ
@param  index:	��������
@param	elem:	����Ԫ��
@return			״̬
*/
Status SqList_Insert(SqListPtr List, int index, ElemType elem);

/*
@brief			��˳���������һ��Ԫ��
@param	List:	����˳����ַ
@param	elem:	����Ԫ��
@return			״̬
*/
Status SqList_pushBack(SqListPtr List, ElemType elem);

/*
@brief			����������˳�����ɾ��һ��Ԫ��
@param	List:	����˳����ַ
@param  index:	ɾ������
@return			״̬
*/
Status SqList_Delete(SqListPtr List, int index);

/*
@brief			����ֵ�ҵ�˳����е�Ԫ�ز���������
@param	List:	����˳����ַ
@param  index:	Ԫ��ֵ
@param  compare:�ȽϺ���
@return			����
*/
int SqList_Locate(SqListPtr List, ElemType elem, bool(*compare)(ElemType, ElemType));

/*
@brief			������˳���ϲ���������˳���
@param	List1:	ͷ˳���
@param	List2:	β˳���
@return			�ϲ������˳���
*/
SqList MergeSqList(SqList List1, SqList List2);

/*
@brief			����������˳���ϲ���������˳���
@param	num:	˳�������
@param	...:	˳���
@return			�ϲ������˳���
*/
SqList MergeSqList_Inf(int num, ...);