#include <iostream>
#include <vector>

// using namespace std;

void permutationsUtil(int depth, std::string str, std::vector<bool> vis, std::vector<int> stk, std::vector<std::string>& acc)
{
	int n = vis.size();

	if (depth == n) {
		std::string s = "";
		for (int i : stk)
		{
			s.push_back(str.at(i));
		}
		acc.push_back(s);
	} else {
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				stk.push_back(i);
				vis[i] = true;
				permutationsUtil(depth+1, str, vis, stk, acc);
				vis[i] = false;
				stk.pop_back();
			}
		}
	}
}

std::vector<std::string> permutations(std::string str)
{
	std::vector<bool> vis(str.size(), false);
	std::vector<int> stk;
	std::vector<std::string> acc;
	permutationsUtil(0, str, vis, stk, acc);
  return acc;
}

int main(int argc, char const *argv[]) {
	std::cout << "Given a string str, the task is to print all the permutations of str. A permutation is an arrangement of all or part of a set of objects, with regard to the order of the arrangement. For example, if given abb, the output should be abb abb bab bba bab bba" << std::endl;

	std::string input = "abb";
	std::vector<std::string> output = permutations(input);

	for (std::string o : output)
		std::cout << o << std::endl;
}