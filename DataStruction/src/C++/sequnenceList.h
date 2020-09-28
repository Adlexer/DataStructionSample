/*
@file:		sequnenceListC.h
@brief:		顺序表和操作函数的C++定义
@author:	Adlexer Xu
@date:		20/9/8
*/

#pragma once
#include <iostream>
#include <stdarg.h>
using namespace std;

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;

template<typename ElemType>
class SqList {
private:
	ElemType* elem;
	int length;
	int size;
public:
	SqList(Status& status);
	ElemType& operator[](int index) {
		return elem[index];
	}
	Status Init() noexcept;
	void Show() noexcept;
	Status Insert(int index, ElemType elem) noexcept;
	Status pushBack(ElemType elem) noexcept;
	Status Delete(int index) noexcept;
	int Locate(ElemType elem, bool(*compare)(ElemType, ElemType));
	friend SqList<ElemType> SqList_Merge(const SqList<ElemType>& List1, const SqList<ElemType>& List2);
	friend SqList<ElemType> SqList_Merge_Inf(int num, ...);
};

template<typename ElemType>
SqList<ElemType> SqList_Merge(const SqList<ElemType>& List1, const SqList<ElemType>& List2);

template<typename ElemType>
SqList<ElemType> SqList_Merge_Inf(int num, ...);