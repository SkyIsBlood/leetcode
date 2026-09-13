#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>





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
    bool isPalindrome(const string & s) 
    {
        int l = 0 ;
        int r = s.size()-1;
        while (l < r )
        {
            while ( l < r && notvalid(s[l])) {++l;}
            while (l < r && notvalid(s[r]) ) {--r;}
            if (tolower(s[l]) != tolower(s[r]))
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