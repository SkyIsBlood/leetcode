#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        const int n = static_cast<int>(nums.size());
        if (n < 3) return result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // Prune: Smallest element > 0 means sum cannot be 0
            if (nums[i] > 0) break;

            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                const int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    ++left;
                    --right;
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> test = {0,0,0};
    auto solution = sol.threeSum(test);
    cout<< "Output: "<<"\n" ;
    for (auto c : solution)
    {
        cout<<"[";
        for (auto j:c)
        {
            cout << j <<",";
        } 
        cout<<"],"<<"\n";
    }
    

    return 0;
}