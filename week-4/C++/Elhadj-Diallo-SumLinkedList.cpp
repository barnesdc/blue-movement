#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <sstream>
using namespace std;

//-------------------------------------------------Struct------------------------------------------------------------------------------------

struct Node {
    int data;
    Node *next;
};

//-------------------------------------------------add-function------------------------------------------------------------------------------------
// Function to create newNode
// in a linked list
Node *add(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
};

//-------------------------------------------------getSize function------------------------------------------------------------------------------------
//get the linkedList size
int getSize(Node *head) {
    Node *current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

//-------------------------------------------------printList-function------------------------------------------------------------------------------------
// This function prints contents of linked list
// starting from the given node
void printList(Node *current) {
    while (current->next != NULL) {
        cout << (char)current->data << "->";
        current = current->next;
    }
    cout<<(char)current->data;
}

//-------------------------------------------------convertArr-function------------------------------------------------------------------------------------
//convert a linkedList to an array,
// then array to string
// and to an Integer
int convertArr(Node *head) {
    string num = "";

    //integer to be return
    int number = 0;

    // Find the length of the
    // given linked list
    int len = getSize(head);

    // Create an array of the
    // required length
    //vector<int> arr;
    int *arr[len];

    int index = 0;
    Node *curr = head;

    // Traverse the Linked List and add the
    // elements to the array one by one
    while (curr != NULL) {
        arr[index++] = &curr->data;
        curr = curr->next;
    }

    //concatenate the string
    for (auto val: arr) {
        num += std::to_string(*val);
    }

    //convert string to integer
    for (int i = 0; i < len; i++) {
        number *= 10;
        number += *arr[i];
    }
    return number;
}

//-------------------------------------------------sumLinkedList-function------------------------------------------------------------------------------------
//computer the sum of the two linkedList
// and return their sum
int sumLinkedList(Node *L1, Node *L2) {
    //convert the two linkedList
    int n1 = convertArr(L1);
    int n2 = convertArr(L2);
    int sum = n1 + n2;
    return sum;

}

//-------------------------------------------------CreatLinkedList-function------------------------------------------------------------------------------------
//Create the linkedlist from String text
// Function to convert the string to Linked List.
Node *CreatLinkedList(int value, Node *head) {

    // declaring output string stream
    ostringstream str1;

    // Sending a number as a stream into output
    // string
    str1 << value;

    // the str() coverts number into string
    string geek = str1.str();

    vector<char> v;

    //put all string character into the vector
    for(int i=0; i< geek.size(); i++){
        v.push_back(geek[i]);
    }

    //add the first element of the vector the
    //head of the linkedList
    head = add(v[0]);
    Node *curr = head;

    // curr pointer points to the current node
    // where the insertion should take place
    for (int i = 1; i < v.size(); i++) {
        curr->next = add(v[i]);
        curr = curr->next;
    }
    return head;
}


void TEST1(){
    cout<< "TEST1" <<endl;
    Node *L1 = NULL;
    Node *L2 = NULL;

    Node* head = NULL;
    L1 = add(5);
    L1->next = add(6);
    L1->next->next = add(3);

    L2 = add(8);
    L2->next = add(4);
    L2->next->next = add(2);

    int result = sumLinkedList(L1, L2);
    string s = std::to_string(result);

    head = CreatLinkedList(result, head);
    printList(head);
}

void TEST2(){
    cout<< "\n\nTEST1" <<endl;

    Node *L1 = NULL;
    Node *L2 = NULL;

    Node* head = NULL;
    L1 = add(52);
    L1->next = add(62);
    L1->next->next = add(33);
    L1->next->next = add(23);

    L2 = add(81);
    L2->next = add(94);
    L2->next->next = add(23);

    int result = sumLinkedList(L1, L2);
    string s = std::to_string(result);

    head = CreatLinkedList(result, head);
    printList(head);
}
//-------------------------------------------------Driver-Code-Main-----------------------------------------------------------------------------------
int main() {
    TEST1();
    TEST2();

    return 0;
}










