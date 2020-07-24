#include "SumList.h"

LinkedList<int> sumList(LinkedList<int> * l1, LinkedList<int> * l2){
	int sum;
	/*int n1, n2, n3;
	n1 = l1->getNum();
	n2 = l2->getNum();
	*/
	sum = toNum(l1) + toNum(l2);
	return toList(sum, maxNum(l1->getNum(), l2->getNum()));
}


int toNum(LinkedList<int> * list){
	int d;
	int n=list->getNum();
	int sum=0;
	//while(list->isMore()){
	//while(true){
	while(n>0){
		d = (int) pow(10, (n-1));
		sum+=d*(list->getCurr());
		list->next();
		n--;
	}
	list->reset();
	return sum;
}

int maxNum(int n1, int n2){
	if(n1>=n2){
		return n1;
	} else {
		return n2;
	}
}

LinkedList<int> toList(int sum, int n) {
	int digit;
	LinkedList<int> * List = new LinkedList<int>();
	while(sum/(int)(pow(10, (n-1)))>9){
		n++;
	}
	
	for(int i=0; i<n; i++){
		digit = sum / (int) pow(10, (n-1)-i);
		List->insert(digit);
		sum-=digit*(int) pow(10, (n-1)-i);
	}
	return *List;
}
