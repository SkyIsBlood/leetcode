#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <map>

#define log(x) cout<<x<<endl
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        set<int> seen;
        for(const int & i :nums)
        {
            seen.insert(i);
        }
        nums.clear()
        for (const int & i :seen)
        {
            nums.push_back(i);
        }
        return seen.size();
    }
};
int main() {
    Solution sol;
    vector<int> test = {1,2,3,2,4};
    cout << "Output: " << sol.removeDuplicates(test) << "\n";

    return 0;
}