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
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        size_t len = nums.size();
        vector<int> result;
        unordered_map<int, size_t> seen;
        for(size_t i = 0; i < len ; i++)
        {
            int diff = target - nums[i];
            if (seen.find(diff) != seen.end())
            {
                result = {(int)seen[diff],(int)i};
                break;
            }
            seen[nums[i]] = i;
        }
    return result;
    }
};

int main() 
{
    // Fast I/O for competitive programming
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);

    Solution sol;

    std::vector<int> test = {3,2,4};
    int Target = 6;
    std::vector<int> result = sol.twoSum(test,Target);

    std::cout << "Output: " << "["<< result[0] <<","<<result[1]<<"]" << "\n";

    return 0;
}