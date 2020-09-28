#include "linkList.h"

template<typename ElemType>
LinkList<ElemType>::LinkList() {

}

template<typename ElemType>
typename LinkList<ElemType>::Status LinkList<ElemType>::init() {
	head = new Node;
	head->elem = 0;
	head->next = nullptr;
	return OK;
}

template<typename ElemType>
typename LinkList<ElemType>::Status LinkList<ElemType>::clear() {
	Node *prevNode, *nextHead;
	if (!head || !head->next) return Status::ERROR;

	prevNode = head->next;

	while (prevNode) {
		nextHead = prevNode->next;
		delete prevNode;
		prevNode = nextHead;
	}
	return Status::OK;
}

template<typename ElemType>
typename LinkList<ElemType>::Status LinkList<ElemType>::destroy() {
	delete this;
	return Status::OK;
}

template<typename ElemType>
typename LinkList<ElemType>::Status LinkList<ElemType>::traverse() {
	Node* prevNode;
	prevNode = head->next;
	while (prevNode != nullptr) {
		printf("%d ", (int)prevNode->elem);
		prevNode = prevNode->next;
	}
	return Status::OK;
}

template<typename ElemType>
bool LinkList<ElemType>::empty() {
	return (head->next == nullptr) ? 1 : 0;
}

template<typename ElemType>
int LinkList<ElemType>::length() {
	Node* prevNode;
	int length = 0;
	if (!list.next) return 0;
	prevNode = list.next;

	while (prevNode) {
		length++;
		prevNode = prevNode->next;
	}

	return length;
}


template<typename ElemType>
typename LinkList<ElemType>::Status LinkList<ElemType>::destroy() {
	delete this;
	return Status::OK;
}

template<typename ElemType>
LinkList<ElemType> create(int length) {

}