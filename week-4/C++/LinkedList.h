/********************************************
* IBM Blue Movement
* Week 4
* Hezekiah Branch
* 06/20/2020
* 
* LinkedList <T> Interface & Implementation
* Class interface for the list ADT
*********************************************/

using namespace std; 

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// Node T data type
template <typename T> 
struct Node {
	// Protected data
	T data;
	// Access within data structure
	Node<T> * next;
    // Check if to be replaced
    bool replace;
};

template <typename T>
class LinkedList 
{
    public:
        // Constructors
        // Default constructor 
        LinkedList(); 
        // Parameterized constructor 
        LinkedList(T val);

        // Destroy all memory
        void terminate();
        
        // Getters
        int size(); 
        T& elementAt(int pos); 

        // Print
        void print();

        // Inserts 
        void insert(T val); 

        // Removes
        void replace(T val, int pos);
        void removeAt(int pos); 

    private: 
        // Any private attributes or functions go here
		Node<T> * head;
		Node<T> * tail;
};

// Implementation of Linked List Template
// Default constructor 
template<typename T>
LinkedList<T>::LinkedList()
{
	// Set head to null
	head = nullptr;
	// Create and update Node for insertion
	Node<T> * insert = new Node<T>;
	insert -> data = 0;
	insert -> next = nullptr;
    insert -> replace = true;
	// Set head and tail to newly created Node
	head = insert;
	tail = insert;
}

// Parameterized constructor 
// Parameters: int for max length and initial value 
// Does: Instantiates an object using parameters
template<typename T>
LinkedList<T>::LinkedList(T val)
{
	// Validate input from value
	if (val < 0 || val > 9) {
		throw range_error("Invalid digit.");
	}
	// Populate list with values from parameters
	Node<T> * insert = new Node<T>;
	insert -> data = val;
	insert -> next = nullptr;
    insert -> replace = true;
	// Add new node to list
	head = insert;
    tail = insert;
}

// Function destroy()
// Parameters: none
// Returns: nothing
// Does: Destroys the Linked List
template<typename T>
void LinkedList<T>::terminate()
{
	// Delete each node within list
	for (Node<T> * temp = head; temp -> next; 
    temp = temp -> next) {
		delete temp;
	}
	// Dellocate memory and set head to null
	delete head;
	head = nullptr;
}

// Function size()
// Parameters: none
// Returns: integer
// Does: Returns the size of the list
template<typename T>
int LinkedList<T>::size() 
{
    // Store the size in an integer
    int size = 0;
    // Designate temporary node
    Node<T> * temp = head;
    // Traverse list and count each visited
   for (Node<T> * temp = head; temp != nullptr; 
   temp = temp -> next) {
		size += 1;
	}
    // Return the size of the list
    return size;
}

// Function print()
// Parameters: none
// Returns: none
// Does: Prints all values in list
template<typename T>
void LinkedList<T>::print()
{
    Node<T> * temp = head;
    while (temp != nullptr) {
        if (temp -> next)
            // Stylistic choice to display arrow
            cout << temp -> data << " -> ";
        else
            // Indicate we're at the end of the list
            cout << temp -> data << " -> NULL";
        temp = temp -> next;
    }
    cout << endl;
}

// Function insert()
// Parameters: int for data
// Returns: none
// Does: Appends node into list and prints iteration
template<typename T>
void LinkedList<T>::insert(T val) 
{
    // Validate input from value
	//if (val < 0 || val > 9) {
		//throw range_error("Invalid digit.");
	//}
    // Create node to insert into list
    Node<T> * insert = new Node<T>;
    insert -> data = val;
    insert -> next = nullptr;
    // Check if head is empty and update
    if (head -> replace) {
        head -> data = val;
       // cout << "Updating head with first node 
       // of value " << val << endl;
        head = insert;
    } else {
        // Go to second to last node and insert
        Node<T> * temp = head;
        while (temp && temp -> next) {
            temp = temp -> next;
        }
       // cout << "Inserting node with value " << val << endl;
        temp -> next = insert;
    }
    // Print list
    // this -> print();
    // Make sure head is fixed
    head -> replace = false;
}

// Function elementAt()
// Parameters: int for position
// Returns: T data
// Does: Returns object data at given position
template<typename T>
T& LinkedList<T>::elementAt(int pos)
{
    Node<T> * temp = head;
    // O(n) list traversal for element
    for (int i = 1; i <= pos; i++) {
        if (i == pos) { // If arrived
            return temp -> data;
        } else { // Else, keep going
            temp = temp -> next;
        }
    }
    // When data not available
    return head -> data;
}

#endif 
