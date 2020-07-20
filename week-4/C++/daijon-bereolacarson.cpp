#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
//Linked List Class
class Node{
    public:
    int data;
    char c;
    Node* next;
};

//Create a new node
Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

Node* newCharNode(char c){
    Node* node = new Node();
    node->c = c;
    node->next = NULL;
    return node;
}
/*-------------------Prompt 1------------------*/

//inserting the node at the start of the linked list
void push(Node** headRef, int data){
    Node* node = newNode(data);
    node->next = *headRef;
    *headRef = node;
}

//reverse the linked list
Node* reverseList(Node** headRef){
    Node* out = NULL;
    Node* curr = *headRef;

    //linked list traversal
    while(curr){
        Node* next = curr->next;
        curr->next = out;
        out = curr;
        curr = next;
    }
    *headRef = out;
    return *headRef;
}

void reverseCharList(Node** head){
    //function to reverse string without reversing words
}

//adds the nodes in the two linked lists
void addNodes(Node* p, Node* q, Node** head){
    Node *prevNode = NULL;
    int carry = 0;

    //sum = p + q (if there is carry p + q + carry)
    while(p || q){
        int sum = 0;
        if(p)
            sum += p->data;
        if(q)
            sum += q->data;
        sum += carry;

        //if sum of 2-digit number, reduce it and update carry
        carry = sum / 10;
        sum = sum % 10;
        Node *node = newNode(sum);

        //if the list is empty
        if(*head == NULL){
            prevNode = node;
            *head = node;
        }
        else{
            prevNode->next = node;
            prevNode = node;
        }
        
        //iterate to the next part of the list
        if(p)
            p = p->next;
        if(q)
            q = q->next;
    }
    if (carry > 0){
        prevNode->next = newNode(carry);
    }
}

//adds lists p and q
Node* addLists(Node* p, Node* q){
    Node* out = NULL;

    //reverse p and q
    reverseList(&p);
    reverseList(&q);

    addNodes(p, q, &out);
    reverseList(&out);

    return out;
}
/*-------------------Prompt 2------------------*/
//create a linked list from a string
Node* createList(string s){
    Node* head = NULL;
    Node* temp = NULL;

    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        Node* node = newCharNode(c);

        if(head == NULL){
            head = node;
            temp = head;
        }
        else{
            temp->next = node;
            temp = temp->next;
        }
    }
    return head;
}

//prints linked list
void printList(Node* node){
    while(node != NULL){
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL";
}

void printCharList(Node* node){
    while(node != NULL){
        cout << node->c << " -> ";
        node = node->next;
    }
    cout << "NULL";
}

int main(void){
    cout << "-----Prompt 1-----\n\n";
    int x, y;
    string s;

    cout << "Enter your first number: ";
    cin >> x;

    cout << "\n";

    cout << "Enter your second number: ";
    cin >> y;

    Node* X = NULL;
    while(x){
        push(&X, x % 10);
        x = x/10;
    }

    Node* Y = NULL;
    while(y){
        push(&Y, y % 10);
        y = y/10;
    }
    cout << "\nResult: ";
    
    printList(addLists(X, Y));

    cout << "\n\n-----Prompt 2-----\n\n";
    
    cout << "Enter a string: ";
    cin >> s;

    Node* str = createList(s);

    reverseList(&str);

    cout << "\n";
    printCharList(str);

    return 0;
}