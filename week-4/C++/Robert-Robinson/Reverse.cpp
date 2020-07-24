#include "Reverse.h"

//DELETE UNUSED LISTS
LinkedList<string> * reverse(LinkedList<string> * list){
	LinkedList<string> * wordStack = new LinkedList<string>();
	LinkedList<string> * temp=new LinkedList<string>();
	LinkedList<string> * ret=new LinkedList<string>();
	list->reset();

	while(list->isMore()){
		while(list->getCurr()!=" "){
			wordStack->insert(list->getCurr());
			list->next();
			if(!list->isMore()){ 
				wordStack->insert(list->getCurr());
				break;
			}
		}
		//wordStack->insert(list->getCurr);		

		while(wordStack->isMore()){
			temp->insert(wordStack->pop());
		}
		temp->insert(wordStack->pop());
		temp->insert(" ");
		list->next();
	}

	//temp->insert(wordStack->pop()); 
	
	while(temp->isMore()){
		ret->insert(temp->pop());
	}
	ret->insert(temp->pop());

	delete wordStack;
	delete temp;
	
	return ret;
}

LinkedList<string> * toList(string str){
	LinkedList<string> * ret = new LinkedList<string>();
	for(int i=0; i<str.length(); i++){
		ret->insert(str.substr(i, 1));
	}
	return ret;
}
