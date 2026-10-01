#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        string_view lcp = strs[0];

        for(int i = 1; i < strs.size(); i++){
            string_view current = strs[i];
            size_t minLen = min(lcp.size(),current.size());
            size_t k = 0;

            while(k < minLen && lcp[k] == current[k]){
                k++;
            }

            lcp = lcp.substr(0,k);

            if(lcp.empty()) break;           
        }

        return string(lcp);
    }
};