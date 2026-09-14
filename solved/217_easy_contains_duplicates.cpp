#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>

#define log(x) cout<<x<<endl
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> seen;
        for(const int & i :nums)
        {
            if(seen.contains(i))
            {
                return true;
            }
            seen.insert(i);
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> test = {1,2,3,2,4};
    cout << "Output: " << sol.containsDuplicate(test) << "\n";

    return 0;
}