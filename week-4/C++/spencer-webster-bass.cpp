#include <iostream>
#include <forward_list>
#include <stack>

std::forward_list<int> sumLists(std::forward_list<int> L1, std::forward_list<int> L2)
{
    std::forward_list<int> sum = std::forward_list<int>();

    L1.reverse();
    L2.reverse();

    std::forward_list<int>::iterator it1 = L1.begin();
    std::forward_list<int>::iterator it2 = L2.begin();

    int r = 0;

    while (it1 != L1.end() || it2 != L2.end())
    {

        int a = 0;
        int b = 0;

        if (it1 != L1.end())
        {
            a = *it1;
            it1++;
        }

        if (it2 != L2.end())
        {
            b = *it2;
            it2++;
        }

        sum.push_front((r + a + b) % 10);
        r = (r + a + b) / 10;
    }

    if (r != 0)
        sum.push_front(r);

    return sum;
}


std::forward_list<char> reverseSentence(std::forward_list<char> sentence)
{

    std::forward_list<char> reverse = std::forward_list<char>();
    std::stack<char> word = std::stack<char>();

    for (std::forward_list<char>::iterator it = sentence.begin(); it != sentence.end(); it++)
    {
        if (*it == ' ')
        {
            while (!word.empty())
            {
                reverse.push_front(word.top());
                word.pop();
            }
            reverse.push_front(' ');
        }
        else {
            word.push(*it);
        }
    }

    while (!word.empty())
    {
        reverse.push_front(word.top());
        word.pop();
    }

    return reverse;
}

template <typename T>
void printList(std::forward_list<T> L)
{
    std::cout << "{ ";

    for (T t : L)
    {
        std::cout << t << ",";
    }

    std::cout << " }" << std::endl;
}

int main(char** args)
{
    // 1st Prompt...
    std::cout << "1st Prompt:" << std::endl;
    std::forward_list<int> L1 = { 5,6,3 };
    std::forward_list<int> L2 = { 8,4,2 };

    printList(L1);
    std::cout << "+" << std::endl;
    printList(L2);
    std::cout << "=" << std::endl;

    std::forward_list<int> sum = sumLists(L1, L2);
    
    printList(sum);

    // 2nd Prompt...
    std::cout << std::endl << std::endl << "2nd Prompt:" << std::endl;
    std::forward_list<char> sentence = { 'I',' ','l','o','v','e',' ','G','e','e','k','s',' ','f','o','r',' ','G','e','e','k','s' };
    printList(sentence);
    printList(reverseSentence(sentence));

    return 0;
}
