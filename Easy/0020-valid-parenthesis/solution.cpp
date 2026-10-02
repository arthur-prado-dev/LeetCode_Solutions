#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {')', '('}, 
            {']', '['}, 
            {'}', '{'}
        };

        stack<char> stack;

        for (char c : s) {

            if (map.count(c)) {
                if (stack.empty() || stack.top() != map[c]) {
                    return false;
                }
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};