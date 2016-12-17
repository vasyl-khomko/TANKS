#pragma once
template <typename NODE_TYPE>
class Node{
private:
	Node<NODE_TYPE>* prev;
	NODE_TYPE data;
	Node<NODE_TYPE>* next;
public:
	Node(){
		prev = NULL;
		//data = NULL;
		next = NULL;
	}

	NODE_TYPE* GetData() {	return &data;			}
	NODE_TYPE& Data() {	return data;				}
	Node<NODE_TYPE>* GetNext() { return next;		}
	Node<NODE_TYPE>* GetPrev() { return prev;		}
	void SetData(NODE_TYPE _data){ data = _data;	}
	void SetNext(Node<NODE_TYPE>* _next){ next = _next;		}
	void SetPrev(Node<NODE_TYPE>* _prev){ prev = _prev;		}

};

template <typename LIST_TYPE>
class List {
private:
	Node<LIST_TYPE>* first;
	Node<LIST_TYPE>* last;
	int size;
	Node<LIST_TYPE>* GetNewNode(const LIST_TYPE &value) {
		return new Node<LIST_TYPE>(value);	
	}

public:
	List(){
		first = NULL;
		last = NULL;
		size = 0;
	}
	bool IsEmpty(){
		if(first == NULL)	return true;
		return false;
	}
	LIST_TYPE* GetData(int index) {
		Node<LIST_TYPE>* nodeIndex; 
		nodeIndex = first;
		int i = 0;
		while(nodeIndex != NULL){
			if(i == index)	return nodeIndex->GetData();
			nodeIndex = nodeIndex->GetNext();
			i++;
		}
		return new LIST_TYPE;
	}

	LIST_TYPE& Data(int index) {
		Node<LIST_TYPE>* nodeIndex; 
		nodeIndex = first;
		int i = 0;
		while(nodeIndex != NULL){
			if(i == index)	return nodeIndex->Data();
			nodeIndex = nodeIndex->GetNext();
			i++;
		}
		return *new LIST_TYPE;
	}
	void InsertFront(LIST_TYPE element) {
		Node<LIST_TYPE>* node = new Node<LIST_TYPE>;
		node->SetData(element);
		if(IsEmpty())	first = last = node;
		else{
			first->SetPrev(node);
			node->SetNext( first);
			first = node;
		}
		size++;
	}
	void InsertBack(LIST_TYPE element) {
		Node<LIST_TYPE>* node = new Node<LIST_TYPE>;
		node->SetData(element);
		if(IsEmpty())	first = last = node;
		else {
			last->SetNext(node);
			node->SetPrev(last);
			last = node;
		}
		size++;
	}
	void InsertIndex(LIST_TYPE element, int index){
		Node<LIST_TYPE>* node = new Node<LIST_TYPE>;
		Node<LIST_TYPE>* nodeIndex;
		node->SetData(element);
		nodeIndex = first;	
		int i = 0;
		while(nodeIndex != NULL){
			if(i == index){
				if(nodeIndex == first){	InsertBack(element);	return;	}
				if(nodeIndex == last ){	InsertFront(element);	return;	}
				nodeIndex->GetPrev()->SetNext(node);
				node->SetPrev(nodeIndex->GetPrev());
				node->SetNext(nodeIndex);
				nodeIndex->SetPrev(node);
				size++;
				return;
			}
			nodeIndex = nodeIndex->GetNext();
			i++;
		}
	}
	void DeleteBack(){
		if(first == last) {
			delete first;
			first = last = NULL;
			size--;
			return;
		}

		last = last->GetPrev();
		delete last->GetNext();
		last->SetNext(NULL);
		size--;
	}
	void DeleteFront(){
		if(first == last) {
			delete first;
			first = last = NULL;
			size--;
			return;
		}
		first = first->GetNext();
		delete first->GetPrev();
		first->SetPrev(NULL);
		size--;
	}
	void DeleteIndex(int index){
		Node<LIST_TYPE>* nodeIndex;
		nodeIndex = first;
		int i = 0;
		while(nodeIndex != NULL){
			if(i == index){
				if(nodeIndex == first)	{ DeleteFront();		return;		}
				if(nodeIndex == last )	{ DeleteBack();			return;		}
				nodeIndex->GetPrev()->SetNext(nodeIndex->GetNext());
				nodeIndex->GetNext()->SetPrev(nodeIndex->GetPrev());
				delete nodeIndex;
				size--;
				return;
			}
			nodeIndex = nodeIndex->GetNext();
			i++;
		}
	}
	int Size(){
		return size;
	}
	void Print(){
		if(IsEmpty()){
			printf(" The list is empty ! \n");
			return;
		}
		Node<LIST_TYPE>* given = first;
		printf( " The list is : \n");
		while(given != NULL){ 
			printf(" \t data = %i \n", given->GetData());
			given = given->GetNext();
		}
	}
};