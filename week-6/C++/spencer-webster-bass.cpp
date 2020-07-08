// C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "spencer-webster-bass1.cpp"

void maxDiffUtil(Node* n, int maxVal, int& maxDiff)
{
    if (n->left)
    {
        if (maxVal - n->left->val > maxDiff)
            maxDiff = maxVal - n->left->val;

        maxDiffUtil(n->left, (n->left->val > maxVal) ? n->left->val : maxVal, maxDiff);
    }

    if (n->right)
    {
        if (maxVal - n->right->val > maxDiff)
            maxDiff = maxVal - n->right->val;

        maxDiffUtil(n->right, (n->right->val > maxVal) ? n->right->val : maxVal, maxDiff);
    }

    return;
}

int maxDiff(Tree* t)
{
    int maxDiff = INT_MIN;
    maxDiffUtil(t->root, t->root->val, maxDiff);
    return maxDiff;
}

void printLeafPathUtil(Node* n, std::vector<int>& p)
{
    p.push_back(n->val);
    if (n->isLeaf())
    {
        std::string path = "";
        for (int i = p.size() - 1; i > 0; i--)
            path.append(std::to_string(p.at(i)) + " -> ");

        path.append(std::to_string(p.at(0)));
        std::cout << path << std::endl;
    } else {
        if (n->left)
            printLeafPathUtil(n->left, p);
        if (n->right)
            printLeafPathUtil(n->right, p);
    }
    p.pop_back();
}

void printLeafPath(Tree* t)
{
    std::vector<int> path = std::vector<int>();
    printLeafPathUtil(t->root, path);
}

void mirrorTree(Node* n)
{
    if (n->left || n->right)
    {
        Node* temp = n->left;
        n->left = n->right;
        n->right = temp;
        if (n->left)
            mirrorTree(n->left);
        if (n->right)
            mirrorTree(n->right);
    }
    else {
        return;
    }
}

int main()
{
    
    Node n8 = Node(8);
    Node n9 = Node(9);

    Node n6 = Node(6, &n8, &n9);
    Node n7 = Node(7);

    Node n3 = Node(3, &n6, &n7);

    Node n4 = Node(4);
    Node n5 = Node(5);

    Node n2 = Node(2, &n4, &n5);

    Node n1 = Node(1, &n2, &n3);

    Tree tA = Tree(&n1);

    std::cout << "Print Leaf Paths Test: " << std::endl;
    printLeafPath(&tA);
    std::cout << std::endl;

    std::cout << "Mirror Tree Test: " << std::endl;
    tA.printTree();
    std::cout << std::endl;
    mirrorTree(tA.root);
    tA.printTree();
    std::cout << std::endl;


    Node n1B = Node(1);
    Node n7B = Node(7);
    Node n2B = Node(2, &n1B, &n7B);

    Node n4B = Node(4);
    Node n8B = Node(8, &n2B, &n4B);

    Node n3B = Node(3);
    Node n6B = Node(6, &n3B, &n8B);

    Tree tB = Tree(&n6B);

    std::cout << "Maximum Difference Test: " << std::endl;
    std::cout << maxDiff(&tB);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
