#include <iostream>
#include <string>
#include <stdio.h>
#include "Reverse.h"
#include "SumList.h"
using namespace std;


int main(){
	
	LinkedList<int> l1;
	LinkedList<int> l2;

	LinkedList<int> l3; 
	
	LinkedList<string> * sList;
	
	LinkedList<string> * outList;
	string in;

	//Prompt1////////////////////////////////////////////////////////////////////////////////


	int n1, n2;
	cout << "please input numbers\n";
	//cin >> n1;
	//cin >> n2;
	scanf("%d", &n1);
	scanf("%d", &n2);

	l1 = toList(n1, 1);
	l2 = toList(n2, 1);
	
	l1.print();
	l2.print();
		
	l3 = sumList(&l1, &l2);
	l3.print();
	


	//Prompt 2////////////////////////////////////////////////////////////////////////////////

	/*cout<<"Please input String\n";
	//cin >> in;
	getline(cin, in);
	
	sList = new LinkedList<string>();
	sList=toList(in);

	sList->print();

	cout << "\n";

	outList = new LinkedList<string>();
	outList = reverse(sList);

	outList->print();
	cout<<"Have a good day!";
	quit=true;
	cout<<"Please use valid input";*/

	///////////////////////////////////////////////////////////////////////////////////////////

}
