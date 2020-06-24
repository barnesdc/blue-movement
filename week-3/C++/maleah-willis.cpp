#include <iostream>
#include <string>
using namespace std;

/* A Linked List class data structure. It has two protected elements, 'data' and 'next'.
'Data' will hold the element of that node, while 'next' holds the location of the next
node in the list. The insert function will be used to insert into the Linked List. */
class LinkedList
{
    public:
    string data;
    LinkedList * next;
    void insert(LinkedList * head, string s);
};

/* An insertion function for the LinkedList. */
void LinkedList::insert(LinkedList * head, string s)
{
    LinkedList * l;
    l->data = s;
    l->next = head;
    head = l;
}


/* This method will take two linked lists, 'A' and 'B', where each are a list of integers.
The list will create a whole integer (i.e., 1->2->3 = 123). The method will add both list-integers
together and return their sum as a linked list. */
LinkedList * addTwoNumbers(LinkedList * listA, struct LinkedList * listB)
{
    LinkedList * sum, * tempA, * tempB;

    // turn both list elements into strings
    string strnum1 = "";
    string strnum2 = "";
    tempA = listA;
    tempB = listB;

    while (tempA != NULL)
    {
        strnum1 = strnum1 + tempA->data;
        tempA = tempA->next;
    }

    while (tempB != NULL)
    {
        strnum1 = strnum1 + tempB->data;
        tempB = tempB->next;
    }

    

    // convert the strings to ints and add them

    int intnum1 = stoi(strnum1);
    int intnum2 = stoi(strnum2);
    int intsum = intnum1 + intnum2;
    string strsum = to_string(intsum);

    // convert the sum into a linked list and return it

    for (int i = 0; i < strsum.size(); ++i)
    {
        //sum.insert(strsum[i]);
    }
    
    return sum;
}

/* The reverseString method will take in a LinkedList that creates some sentence and reverse the sentence,
without reversing the letters. (i.e., I->love->math returns math->love->I). */
LinkedList * reverseString(LinkedList * l)
{
    LinkedList * reversed, * temp;
    temp = l;
    string curr_word = "";
    vector<string> words;

    // create words from the nodes of the list & put them in a vector
    while (temp != NULL)
    {
        if (temp->data != " ")
        {
            curr_word += temp->data;
        }

        else
        {
            if (curr_word != "")
            {
                words.push_back(curr_word);
            }
        }
    }

    // Add the words into a new linked list in the reverse order
    string to_add= "";
    while (words.size() > 0)
    {
        to_add = words.front();
        for (int i = 0; i < to_add.size(); ++i)
        {
            reversed->insert(reversed, &to_add[i]);
        }
        words.erase(words.begin());
    }

    // return the reversed list
    return reversed;
}

int main()
{
    return 0;
}
