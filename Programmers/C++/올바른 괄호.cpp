#include<string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<int> stack;
    for (auto& c: s) {
        if (!stack.empty() && stack.top() == '(' && stack.top() != c) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    return stack.size() == 0;
}