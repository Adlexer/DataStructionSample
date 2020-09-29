#include "sequnenceList.h"

template<typename ElemType>
SqList<ElemType>::SqList(Status& status) {
	elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (elem == nullptr) exit(OVERFLOW);
	length = 0;
	size = LIST_INIT_SIZE;
	status = OK;
}

template<typename ElemType>
typename SqList<ElemType>::Status SqList<ElemType>::Init() noexcept {
	Status status;
	SqList(status);
	return status;
}

template<typename ElemType>
void SqList<ElemType>::Show() noexcept{
	if (length == 0) {
		cout << "empty list" << endl;
		return;
	}
	for (ElemType* pointer = elem; pointer <= elem + length - 1; pointer++) {
		cout << *pointer << " ";
	}
	cout << endl;
}

template<typename ElemType>
typename SqList<ElemType>::Status SqList<ElemType>::Insert(int index, ElemType elem) noexcept {

}

template<typename ElemType>
SqList<ElemType> SqList_Merge(const SqList<ElemType>& List1, const SqList<ElemType>& List2) {
	SqList newList;
	newList.length = List1.length + List2.length;
	newList.size = List1.size + List2.size;
	newList.elem = (ElemType*)malloc(newList.length * sizeof(ElemType));
	if (newList.elem == nullptr) exit(OVERFLOW);

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

template<typename ElemType>
SqList<ElemType> SqList_Merge_Inf(int num, ...) {
	va_list args;
	SqList<ElemType> Lists, newList;
	newList.Init();

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