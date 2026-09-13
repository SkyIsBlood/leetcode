#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>




#define log(x) cout<<x<<endl
using namespace std;

class Solution {
public:
    bool isPalindrome(string & s) 
    {
        string ts;
        string rs ;
        for (const char & c :s)
        {
            int asci_c = c;
            if (asci_c < 48 ||asci_c > 123 ){continue;}
            if( asci_c > 64 && asci_c < 91)
            {
                char l =asci_c + 32;
                ts += l;
                rs.insert(rs.begin(),l);
                continue;
            }
            else if ((asci_c > 96  ) || (asci_c < 58)) 
            {
                ts += c;
                rs.insert(rs.begin(),c);
                continue;
            }
        }
        log(ts);
        log(rs);

        return (ts == rs);
    }
};


int main() {
    Solution sol;
    string test = "Marge, let's \"[went].\" I await {news} telegram.";
    cout << "Output: " << sol.isPalindrome(test) << "\n";

    return 0;
}