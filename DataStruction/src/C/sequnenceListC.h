/*
@file:		sequnenceListC.h
@brief:		顺序表和操作函数的C语言定义
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
@brief			初始化顺序表
@param	List:	引用顺序表地址
@return			状态
*/
Status InitSqList(SqListPtr List);

/*
@brief			显示顺序表中所有元素(int)
@param	List:	引用顺序表地址
*/
void ShowSqList(SqListPtr List);

/*
@brief			根据索引从顺序表中插入一个元素
@param	List:	引用顺序表地址
@param  index:	插入索引
@param	elem:	插入元素
@return			状态
*/
Status SqList_Insert(SqListPtr List, int index, ElemType elem);

/*
@brief			在顺序表最后插入一个元素
@param	List:	引用顺序表地址
@param	elem:	插入元素
@return			状态
*/
Status SqList_pushBack(SqListPtr List, ElemType elem);

/*
@brief			根据索引从顺序表中删除一个元素
@param	List:	引用顺序表地址
@param  index:	删除索引
@return			状态
*/
Status SqList_Delete(SqListPtr List, int index);

/*
@brief			根据值找到顺序表中的元素并返回索引
@param	List:	引用顺序表地址
@param  index:	元素值
@param  compare:比较函数
@return			索引
*/
int SqList_Locate(SqListPtr List, ElemType elem, bool(*compare)(ElemType, ElemType));

/*
@brief			将两个顺序表合并并返回新顺序表
@param	List1:	头顺序表
@param	List2:	尾顺序表
@return			合并后的新顺序表
*/
SqList MergeSqList(SqList List1, SqList List2);

/*
@brief			不定数量的顺序表合并并返回新顺序表
@param	num:	顺序表数量
@param	...:	顺序表
@return			合并后的新顺序表
*/
SqList MergeSqList_Inf(int num, ...);