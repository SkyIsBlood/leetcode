#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(std::string_view s) 
    {

        size_t len = s.size();
        if (len % 2 != 0) return false;

        std::vector<char> stack;
        stack.reserve(len);

        for (const char c : s) {
            switch (c) {
                case '(': stack.push_back(')'); break;
                case '{': stack.push_back('}'); break;
                case '[': stack.push_back(']'); break;
                default:
                    if (stack.empty() || stack.back() != c) return false;
                    stack.pop_back();
                    break;
            }
        }




        #if 0 //solution 2
        unordered_map<char, char> dict = {{'(',')'},{'{','}'},{'[',']'}};
        for (const char  c:s)
        {
            if (!stack.empty()&& c == dict[stack.back()])
            {
                stack.pop_back();
                continue;
            }
            stack.push_back(c);
        }
        #endif 0
        return stack.empty();
        
    }
};
int main() {
    Solution sol;
    string test = "{}()";
    cout << "Output: " << sol.isValid(test) << "\n";

    return 0;
}