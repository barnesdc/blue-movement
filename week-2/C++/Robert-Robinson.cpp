#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;
//given a string, find the longest substring which is a palindrome. For example, if the given string is "abababad", the output should be "abababa"

//Given a string str, the task is to print all the permutations of str. A permutation is an arrangement of all or a part of a set of objects, with regard to the order of the arrangement. For example, if given "abb", the output should be "abb abb bab bba bab bba"
//
void constructTree(string str);
void constructTree(string remaining, string word, char curr);
/*string toString(char * seq){
	string str = seq;
	return str = seq;
}*/
void printMatrix(int ** mat, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			
		}
		printf("\n");
	}
}

int ** initMatrix(string str){
	//initialize matrix
	int ** mat = (int**) malloc(str.length()*sizeof(int*));
	for(int i=0; i<str.length(); i++){
		//mat[i]=(int*) calloc(str.length(), sizeof(int));
		mat[i]=(int*) malloc(str.length()*sizeof(int));
	}
	for(int i=0; i<str.length(); i++){
		for(int j=0; j<str.length(); j++){
			mat[i][j]=0;
		}
	}
	return mat;
}

int * setMatrix(int ** mat, string str){
	//int ** mat = initMatrix(str);
	int * c = (int*) malloc(2*sizeof(int));
	for(int i=0; i<str.length(); i++){
		for(int j=0; j<str.length(); j++){
			if(str[i]==str[(str.length()-1)-j]) {// && ((j!=(str.length()-1)-i) || (j==i))){
				//if(((i-1)>=0&&(j-1)>=0)){
					if((i==0&&j==0 || (i==0 && j==str.length()-1)) || mat[i-1][j-1]<1){
						mat[i][j]=1;
					} else {
						mat[i][j] = mat[i-1][j-1]+1;
						if(mat[c[0]][c[1]]<mat[i][j]){
							c[0]=i;
							c[1]=j;
						}
					}
				//}
				
			}
		}
	}
	return c;
}

void longestPalindrome(string str){
	int ** matrix = initMatrix(str);
	int* coordinates=setMatrix(matrix, str);
	/*for(int i=0; i<str.length(); i++){
		for(int j=0; j<str.length(); j++){
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}*/
	//if(matrix[coordinates[0]][coordinates[1]]<3){
	//	cout<<"no palindromes found\n";
	//	return;
	//}
	for(int i=coordinates[0]; i>=(coordinates[0]+1)-matrix[coordinates[0]][coordinates[1]]; i--){
		cout<<str[i];
	}
}

void permutations(string str){
	//use trees
	//recursive functions
	//construct tree first?
	//if there are no remaining print result and go back and try next letter in generation
	constructTree(str);
}

int main(){
	bool c = true;
	string input;
	while(c){
		cout << "\nWhat would you like to do today?\nSelect 'a' to search for the longest palindromic substring\nSelect 'b' to display all permutations of a given string\nSelect 'q' to quit\n";
		char choice;
		scanf("%c", &choice);
		switch(choice){
			case 'a':
				cout<<"please input string\n";
				cin >> input;
				longestPalindrome(input);
				break;
			case 'b':
				cout<<"please input string\n";
				cin >> input;
				permutations(input);
				cout<<"\n";
				break;
			case 'q':
				cout << "have a nice day!\n";
				c = false;
				break;
			default:
				cout<< "please select one of the provided options\n";
		} 
	}

}


void constructTree(string str){
	for(int i=0; i<str.length(); i++){
		char first = str.c_str()[i];
		constructTree(str, str.substr(i, 1), first);
	}
}

void constructTree(string remaining, string word, char curr){
	size_t currPos=remaining.find_first_of(curr, 0);
	remaining.assign(remaining.erase(currPos, 1));
	//BrASE CASE
	if(remaining.length()<1){
		cout << word+" ";
		return;
	}
	//RECURSIVE CASE
	
	for(int i=0; i<remaining.length(); i++){
		constructTree(remaining, word+=remaining[i], remaining[i]); //NOT j++
		word.pop_back();
	}
}

