#pragma once
#include "List.h"
template <typename Type>
class NodeTree {
public:
	Type data;
	NodeTree<Type>* father;
	NodeTree<Type>* childs[10]; 
	NodeTree(void) {
		father = NULL;
	}
};

template <typename Type>
class Tree {
private:
	NodeTree<Type>* root;
public:
	Tree(void) {
		root = new NodeTree<Type>;
	}

	~Tree(void) {
	}
	Type& GetData(void) {
		return root->data;
	}
	void SetData(Type data) {
		root->data = data;
	}
	void Father(void) {
		root = root->father;
	}
	void Child(int index) {
		root = root->childs[index];
	}
	void Bruder(int index) {
		root = root->father->childs[index];
	}
	void AddChild(Type& child) {
		root->childs[0] = new NodeTree<Type>;
		root->childs[0]->data = child;
	}
	void AddBruder(Type& bruder) {
		root->father->childs[0] = new NodeTree<Type>;
		root->father->childs[0]->data = bruder;
	}
};

