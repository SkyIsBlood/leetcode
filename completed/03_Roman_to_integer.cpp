#include <cstddef>
#include <exception>
#include <iostream>
#include <sys/types.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int romanToInt(string & s) 
    { 
        static std::unordered_map<char, int> dict = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int result = 0;
        for (std::size_t i = 0 ; i < s.size();i++)
        {
            int current_number = dict[s[i]]; 
            int next_number = (i+1<s.size())?(dict[s[i+1]]):(0);
            if (current_number < next_number)
            {   
                result += next_number - current_number;
                i+=1;
            }
            else
            {
                result += current_number;
            }
        } 
    return result;   
    }

};

int main() {
    Solution sol;
    string test = "I";//1
    cout << "Output: " << sol.romanToInt(test) << "\n";
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
    return 0;
}