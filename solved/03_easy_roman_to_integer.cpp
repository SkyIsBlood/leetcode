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
        //the first way of doing it 
        //static std::unordered_map<char, int> dict = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int result = 0;
        const int l = s.size();
        for (std::size_t i = 0 ; i < l;i++)
        {
             
            //short current_number = dict[s[i]];//first way
            short current_number = value(s[i]); 
            //short next_number = (i+1<l)?(dict[s[i+1]]):(0);//first way
            short next_number = value(s[i+1]);
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
    short value(char c) 
    {
        switch (c) 
        {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
        }
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