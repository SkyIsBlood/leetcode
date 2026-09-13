#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>




#define log(x) cout<<x<<endl
using namespace std;
class Solution {
public:
    bool notvalid(char c)
    {
            //numbers          & lowercase           & uppercase
        if ((c >= '0' && c <= '9') ||  ((c >= 'a'  ) && (c<='z')) || (c >= 'A' && c <= 'Z')) 
        {
            return false;
        };
        return true;
    }

    bool isPalindrome(string & s) 
    {
        int l = 0;
        int r = s.size()-1;
        while (l < r )
        {
            while (notvalid(s[l]) && l < r) {++l;}
            while (notvalid(s[r]) && l < r) {--r;}
            char lc = s[l];
            char rc = s[r];
            if(lc >='A' && lc <='Z') lc +=32;
            if(rc >='A' && rc <='Z') rc +=32;
            if (lc != rc)
            {
            return false;
            }
            --r;
            ++l;
        }
    return true;
    }
};



int main() {
    Solution sol;
    string test = ".,";
    cout << "Output: " << sol.isPalindrome(test) << "\n";

    return 0;
}




// the first solution 



        #if 0
        string ts;
        string rs ;
        for (const char & c :s)
        }   
            if (c < 48 ||c > 123 ){continue;}
            if( c > 64 && c < 91)
            {
                ts += c+32;
                rs.insert(rs.begin(),c+32);
                continue;
            }
            else if ((c > 96  ) || (c < 58)) 
            {
                ts += c;
                rs.insert(rs.begin(),c);
                continue;
            }
        }
        log(ts);
        log(rs);
        

        return (ts == rs);
        #endif 0
//