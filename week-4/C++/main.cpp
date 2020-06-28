#include <iostream>
#include <cstddef>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    char n;
    Node *next;
    
    
};

void push(Node** head_ref, char new_l)
{
    /* 1. allocate node */
    Node* new_node = new Node();
  
    /* 2. put in the data */
    new_node->n = new_l;
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
  
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}



Node sumlist(Node* a, Node* b ){
    Node* suml=NULL;
    string aa="";
    string bb="";
    string summ="";
    int aaa=0;
    int bbb=0;
    int sum=0;
    while(a!=NULL){
        aa+=a->n;
        a= a->next;
    }
   aaa= stoi(aa);
    while(b!=NULL){
           bb+=b->n;
           b= b->next;
       }    bbb = stoi(bb);
    sum =bbb+aaa;
    
    cout << sum<<endl;
   summ = to_string(sum);
  int size=summ.length();
    for(int i=size-1;i >=0;i--){
        push(&suml,summ[i]);
    }
   
    
    return *suml;

}
void rev(Node* g){
    Node* r=NULL;
    string h="";
    string j="";
   // create string
    while(g!=NULL){
        h+=g->n;
        g=g->next;
    }
    int size=h.length();
    for(int i=0; i < size;i++){
   
    if(h[i]==' '){
        int sizej = j.length();
           
        for(int s=sizej-1;s >=0;s-- ){
                push(&r,j[s]);
            }
            sizej=0;
            j="";
        push(&r,h[i]);

        }
    else if(i==size-1){
         j+=h[i];
        int sizej = j.length();
        for(int s=sizej-1;s >=0;s-- ){
                       push(&r,j[s]);
                   }
        
    }
    
    else
           j+=h[i];
         
    }
    while(r!=NULL){
        cout<<r->n;
        r=r->next;
        
    }

}

int main() {
     Node* nums=NULL;
    push(&nums,'3');
    push(&nums,'6');
    push(&nums,'5');
    
    Node* num2=NULL;
    push(&num2,'2');
    push(&num2,'4');
    push(&num2,'8');
    
    sumlist(nums, num2);
    
    
    
    
    
    
    Node* head=NULL;
    push(&head,'y');
    push(&head,'e');
    push(&head,'r');
    push(&head,'t');
    push(&head,' ');
    push(&head,'i');
    push(&head,'h');
    
    rev(head);
  
    cout <<endl;
    
    
    
    
    
    
    
    return 0;
}


