#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <iostream>

template<typename T>
struct Node{
	//int data;
	T data;
	Node<T> * next;
	Node<T> * prev;
} /*Node*/;

template<typename T>
class LinkedList{
Node<T> * head;
Node<T> * curr;
Node<T> * tail;
int num;
public:
	LinkedList<T>(){
		head = curr = tail = nullptr;
		num=0;
	} 

	void insert(T data);
	T getCurr();
	int getNum();
	int next();
	void reset();
	bool isMore();
	void print();
	T pop();
	void push(T data);


};

#endif
