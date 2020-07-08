#include <iostream>
#include <string>
#include <ostream>
using namespace std;


struct Node{
    char data;
    Node* next;
};

// Function to create newNode
// in a linked list
Node* add(char data);

//Create the linkedlist from String text
// Function to convert the string to Linked List.
Node* CreatLinkedList(string text, Node* head);

// This function prints contents of linked list
// starting from the given node
void printList(Node* current);

//function that reverse a given string
// without changing the words
Node* reverse(Node* head);

void String_Test(){
    Node* head = NULL;
    string s = "I love My Life";
    cout << s<< endl;
    head = CreatLinkedList(s, head);


    cout << "Before reverse Call : " <<endl;
    printList(head);

    head = reverse(head);

    cout << "\nAfter reverse Call : " <<endl;
    printList(head);
}

// Driver code
int main()
{
    String_Test();

    return 0;
}

//-------------------------------------------------Implementation------------------------------------
// Function to create newNode
// in a linked list
Node* add(char data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
};

//Create the linkedlist from String text
// Function to convert the string to Linked List.
Node* CreatLinkedList(string text, Node* head)
{
    head = add(text[0]);
    Node* curr = head;

    // curr pointer points to the current node
    // where the insertion should take place
    for (int i = 1; i < text.size(); i++) {
        curr->next = add(text[i]);
        curr = curr->next;
    }
    return head;
}


// This function prints contents of linked list
// starting from the given node
void printList(Node* current)
{
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

//function that reverse a given string
// without changing the words
Node* reverse(Node* head){
    if(head==NULL){
        return  head;
    }

    Node* wordStartP = NULL;
    Node* endOfSentence = NULL;
    Node* sentenceStartP = NULL;

    //Initialize wordStartP to head
    //for example 'I' first letter of the string "I love You"
    wordStartP = head;

    //Navigate through the linkedlist until a space (' ')
    while(head !=NULL && head->data != ' '){
        //keep track of the previous node
        //this will become the last of the LinkedList
        endOfSentence = head;

        //keep moving to the next node
        head = head->next;
    }

    //after the above while loop
    //endOfSentence point to

    if(head == NULL){
        head = wordStartP;
        return head;
    }

    do{
        //Swapping the space
        //convert 'practice<space>' to
        //'<space>practice'

        Node* temp = head->next;
        head->next = wordStartP;
        wordStartP = head;
        head  = temp;
        Node* prev = NULL;

        //Setting setenseStartPosition to node
        sentenceStartP = head;

        //Again Navigate the linked list until
        //a space(' ') is found or head = null end of the linkedList
        while (head != NULL && head->data != ' '){
            prev = head;
            head = head->next;
        }
        //when the next space is found
        //change the pointer to point the previous space
        prev->next = wordStartP;

        //Newly found space will point to

        wordStartP = sentenceStartP;
        if(head == NULL){
            break;
        }
    }while (head != NULL);

    head = sentenceStartP;

    //set the last node's next to null
    endOfSentence->next = NULL;
    return head;
}
