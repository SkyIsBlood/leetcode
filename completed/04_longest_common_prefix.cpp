#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    { 
        if (strs.empty()) return {};
        const auto [min_it , max_it] = std::minmax_element(strs.begin(),strs.end());
        std::string_view first = * min_it;
        std::string_view last = * max_it;

        const size_t limit = std::min(first.size(),last.size());
        size_t idx = 0;
        while (idx < limit && first[idx] == last[idx])
        {
            idx ++;
        }
        return std::string(first.substr(0,idx));


        #if 0 
        if (strs.empty()) return {};
        string_view pivot = strs[0];
        for (size_t j = 0 ; j < pivot.size() ; j++)
        {
            for (const string & s: strs)
            {
                if (pivot[j] != s[j]){return string(pivot.substr(0,j));}
            }
        }
        return string(pivot) ;
        #endif 0
    }
};

int main() {
    Solution sol;
    vector<string> test = {"n","l"};
    cout << "Output: " << sol.longestCommonPrefix(test) << "\n";

    return 0;
}