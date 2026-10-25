#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int counter = 0;

        while(s[i] == ' ') i--;
        while(i >= 0 && s[i--] != ' ') counter ++;

        return counter;
    }
};