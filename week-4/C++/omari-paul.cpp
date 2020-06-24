#include <iostream>
#include <vector>
#include <list>
using namespace std;

void stringReverse();

struct Node
{
    int data;
    Node *next;
};

vector<int> List;
Node *Head1, *Tail1, *Head2, *Tail2, *Head3, *Tail3;
int number1 = 0, number2 = 0, number3;

void first1(int data)
{
    Node *n = new Node();
    n->data = data;
    n->next = NULL;
    Head1 = n;
    Tail1 = n;
}
void first2(int data)
{
    Node *n = new Node();
    n->data = data;
    n->next = NULL;
    Head2 = n;
    Tail2 = n;
}
void first3(int data)
{
    Node *n = new Node();
    n->data = data;
    n->next = NULL;
    Head3 = n;
    Tail3 = n;
}

void insert1(int data)
{
    if (Head1 == NULL)
    {
        first1(data);
    }
    else
    {
        Node *n = new Node();
        n->data = data;
        n->next = NULL;
        Tail1->next = n;
        Tail1 = Tail1->next;
    }
}
void insert2(int data)
{
    if (Head2 == NULL)
    {
        first2(data);
    }
    else
    {
        Node *n = new Node();
        n->data = data;
        n->next = NULL;
        Tail2->next = n;
        Tail2 = Tail2->next;
    }
}
void insert3(int data)
{
    if (Head3 == NULL)
    {
        first3(data);
    }
    else
    {
        Node *n = new Node();
        n->data = data;
        n->next = NULL;
        Tail3->next = n;
        Tail3 = Tail3->next;
    }
}

void renderAndStoreList1()
{
    vector<int> TempList;
    int decimal = 1;
    Node *n = Head1;
    cout << "Link List 1: ";
    while (n != NULL)
    {
        TempList.push_back(n->data);
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL";
    for (int i = TempList.size() - 1; i >= 0; i--)
    {
        number1 = number1 + TempList[i] * decimal;
        decimal = decimal * 10;
    }
    cout << endl
         << "Integer 1: " << number1;
}
void renderAndStoreList2()
{
    vector<int> TempList;
    int decimal = 1;
    Node *n = Head2;

    cout << "Link List 2: ";
    while (n != NULL)
    {
        TempList.push_back(n->data);
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL";
    for (int i = TempList.size() - 1; i >= 0; i--)
    {
        number2 = number2 + TempList[i] * decimal;
        decimal = decimal * 10;
    }
    cout << endl
         << "Integer 2: " << number2;
}

void renderAndStoreList3()
{
    number3 = number1 + number2;
    cout << "Integer 1 + Integer 2: " << number3;
    int digit = 0;

    while (number3 > 0)
    {
        digit = number3 % 10;
        number3 = number3 / 10;
        List.push_back(digit);
    }

    for (int i = List.size() - 1; i >= 0; i--)
    {
        insert3(List[i]);
    }

    cout << endl;

    Node *n = Head3;
    vector<int> TempList;

    cout << "Link List 3: ";
    while (n != NULL)
    {
        TempList.push_back(n->data);
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL";
}

int main()
{
    // insert1(5);
    // insert1(6);
    // insert1(3);
    // renderAndStoreList1();
    // cout << endl;
    // insert2(8);
    // insert2(4);
    // insert2(2);
    // renderAndStoreList2();
    // cout << endl;
    // renderAndStoreList3();

    stringReverse();
}

void stringReverse()
{
    list<int> list1 = {5, 2, 4, 6, 2};
    list1.sort();
    for (auto &elm : list1)
        cout << elm << " ";
}