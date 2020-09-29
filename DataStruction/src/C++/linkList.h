/*
@file:		linkListC.h
@brief:		链表和操作函数的C++定义
@author:	Adlexer Xu
@date:		20/9/25
*/

#pragma once

#include <iostream>

namespace struction {

	template<typename ElemType>
	class LinkList {
	protected:
		typedef uint32_t typename Status;
		typename Status ERROR = 0;
		typename Status OK = 1;

	public:
		LinkList();

		Status init();

		Status clear();

		//Status destroy();

		Status traverse();

		bool empty();

		int length();

		ElemType get();

		int locate();

		Status insert();

		Status erase();

		// 友元函数，允许外部函数访问内部成员
		friend LinkList<ElemType> create(int length);

	private:
		typedef struct Node Node;
		struct Node {
			ElemType elem;
			Node* next;
		};
		Node* head;
	};

	template<typename ElemType>
	LinkList<ElemType> create(int length);
}

