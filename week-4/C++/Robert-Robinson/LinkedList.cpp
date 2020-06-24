#include "LinkedList.h"
using namespace std;

template <typename T>
void LinkedList<T>::insert(T data){
	Node<T> * temp = new Node<T>;
	temp->data = data;
	temp->next=nullptr;
	num++;

	if(head == nullptr){
		head = curr = tail = temp;
		temp->prev = nullptr;
		return;
	}
	
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}

template <typename T>
int LinkedList<T>::next(){
	if(curr==tail){
		//printf("no more elements");
		return 0;
	}
	curr = curr->next;
	return 1;
}

template <typename T>
T LinkedList<T>::getCurr(){
	return curr->data;
}

template <typename T>
int LinkedList<T>::getNum(){
	return this->num;
}

template <typename T>
void LinkedList<T>::reset(){
	curr=head;
}

template <typename T>
bool LinkedList<T>::isMore(){
	if(curr->next!=nullptr){
		return true;
	}
	return false;
}

template <typename T>
void LinkedList<T>::print(){
	Node<T> * temp = head;
	while(temp!=nullptr){
		printf("%d ", temp->data);
	//	cout << temp->data + " ";
		temp = temp->next;
	}
	//cout << "\n";
	printf("\n");
}

template <>
void LinkedList<string>::print(){
	Node<string> * temp = head;
	while(temp!=nullptr){
		//printf("%s ", temp->data);
		cout << temp->data + " ";
		temp = temp->next;
	}
	//cout << "\n";
	printf("\n");
}

template <>
string LinkedList<string>::pop(){
	this->reset(); //////////////////////////////////////////////////////////
	string ret=tail->data;
	Node<string> * temp;
	if(head==nullptr){
		return nullptr;
	}
	
	if(tail == head){
		//ret=tail->data;
		temp = tail;
		head=tail=curr=nullptr;
		delete temp;
		num--;
		return ret;
	}
	
	//ret=tail->data;
	temp = tail;
	tail=tail->prev;
	tail->next=nullptr;
	delete temp;
	num--;
	return ret;
}

template class LinkedList<int>;
template class LinkedList<string>;
