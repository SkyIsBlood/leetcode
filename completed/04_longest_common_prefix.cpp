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
        const string pivot = strs.back();
        strs.pop_back();
        if (!strs.size()) {return pivot;}
        for (size_t j = 0 ; j < pivot.size() ; j++)
        {
            for (const string & s: strs)
            {
                if (pivot[j] != s[j]){return pivot.substr(0,j);}
            }
        }
        return pivot ;
    }
};

int main() {
    Solution sol;
    vector<string> test = {"jn","jn","jn","jn"};
    cout << "Output: " << sol.longestCommonPrefix(test) << "\n";

    return 0;
}