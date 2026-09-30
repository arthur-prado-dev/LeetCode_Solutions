#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int hash[256] = {0};

        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;

        int convertedValue = 0;

        for(int i = 0; i < s.size(); i++){

            convertedValue += hash[s[i]];

            if(i > 0 && hash[s[i]] > hash[s[i-1]]){
                convertedValue -= 2 * hash[s[i-1]];
            }             
        }

        return convertedValue;
    }
};