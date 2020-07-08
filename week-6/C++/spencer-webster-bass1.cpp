#include <queue>
#include <iostream>
#include <iomanip>

class Node {

public:
	int val;
	Node* left;
	Node* right;

	Node() :
		val(0), left(nullptr), right(nullptr)
	{}

	Node(int v) :
		val(v), left(nullptr), right(nullptr)
	{}

	Node(int v, Node* l, Node* r) :
		val(v), left(l), right(r)
	{}

	bool isLeaf()
	{
		return left == nullptr && right == nullptr;
	}
};

class Tree {

public:
	Node* root;

	Tree(Node* r) : 
		root(r)
	{}

	void printTree()
	{
		// postorder(root, 0);
		// return;

		// parent value, node pointer pair
		std::cout << "Each pair is parent, node value. The 1st encounter with a child of a particular node is the left child, otherwise the pair is the right child of the parent." << std::endl;
		std::queue<std::pair<int,Node*>> q = std::queue<std::pair<int,Node*>>();
		q.push(std::pair<int,Node*>(0,root));
		while (!q.empty())
		{
			if (q.front().second->left)
				q.push(std::pair<int, Node*>(q.front().second->val, q.front().second->left));
			if (q.front().second->right)
				q.push(std::pair<int, Node*>(q.front().second->val, q.front().second->right));
			std::cout << q.front().first << "," << q.front().second->val << " ";
			q.pop();
		}
		std::cout << std::endl;
	}

	void postorder(Node* p, int indent)
	{
		if (p != NULL) {
			if (p->right) {
				postorder(p->right, indent + 4);
			}
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
			std::cout << p->val << "\n ";
			if (p->left) {
				std::cout << std::setw(indent) << ' ' << " \\\n";
				postorder(p->left, indent + 4);
			}
		}
	}
};