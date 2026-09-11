#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string & s) 
    {
        unordered_map<char, char> dict = {{'(',')'},{'{','}'},{'[',']'}};
        std::vector<char> stack;
        for (char c:s)
        {
            if (!stack.empty()&& c == dict[stack.back()])
            {

                stack.pop_back();
                continue;
            }
            stack.push_back(c);
        }
        return stack.empty();
    }
};

int main() {
    Solution sol;
    string test = "{}()";
    cout << "Output: " << sol.isValid(test) << "\n";

    return 0;
}