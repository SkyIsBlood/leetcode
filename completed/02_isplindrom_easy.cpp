#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <numbers>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        
        
        //solution 1
        if (x < 0)
        {
            return false;
        }
        if (x - 10 < 10)
        {
            return true;
        }
        int power = std::log10(x);
        int r = 0;
        int number = x;
        for (int i = power,j = 0 ; i >= 0 & j <= power  ;--i,++j)
        {

            int p = std::pow(10,i);
            int rp = std::pow(10,j);

            
            int n = (int)(number  / p);
            r += (n * rp) ;
            number -= n * p;
            
        }
        

        return (r - x == 0);




        //solution 2
        #if 0
        string n = to_string(x);
        int len = (int)n.size();
        for (int i = len - 1,j = 0;  i >= len/2 && j < len/2; --i ,++j )
        {
            if (n[i] != n[j])
            {
                return false;
            }
        }
        return true;
        #endif 
        
    }
};

int main() {
    Solution sol;
    int test = 0;
    cout << "Output: " << sol.isPalindrome(test) << "\n";

    return 0;
}