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
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        const int len = (int)nums.size();
        if (len < 3){return result;}



        sort(nums.begin(),nums.end());
        
        for (int i = 0 ; i < len-2 ;i++)
        {
            
            if (nums[i] > 0){return result;}
            int left = i + 1;
            int right = len - 1;

            while(left<right)
            {
                int sum=nums[i]+ nums[left] + nums[right];
                if ( sum > 0){--right;}
                else if (sum<0){++left;}
                else {result.push_back({nums[i],nums[left],nums[right]});}
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;
                --right;
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