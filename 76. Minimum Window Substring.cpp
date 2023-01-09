#include <stdio.h>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        const char* sc = s.c_str();
        const char* tc = t.c_str();
        // lf, rt left side and right side substring s that consist t
        int i, lf = 0, rt = 0, n = s.length();
        // lfb, rtb left side and right side substring s that consist t best case
        int lfb = -1, rtb = n;
        
        // Consist all symbols substring
        map<char, int> consist_in_substring;
        for (i = 0; i != n; i++) {
            if (consist_in_substring.find(sc[rt]) == consist_in_substring.end())
                consist_in_substring[tc[i]] = 0;
            consist_in_substring[tc[i]] += 1;
        }
        
        // Not enought symbol in substring 
        int need_value = t.length(); 

        // Find first substring contain all t
        while(rt < n) {
            // Try find rt that consist substring
            if (consist_in_substring.find(sc[rt]) != consist_in_substring.end()) {
                consist_in_substring[sc[rt]]--;
                if (consist_in_substring[sc[rt]] >= 0) {
                    need_value--;
                    // if find need substring 
                    if (!need_value) {
                        // try move left side that consist t
                        while (!need_value) {
                            if (consist_in_substring.find(sc[lf]) != consist_in_substring.end()) {
                                consist_in_substring[sc[lf]]++;
                                if (consist_in_substring[sc[lf]] == 1) need_value = 1;
                            }
                            lf++;
                        }
                        lf--; need_value = 0; consist_in_substring[sc[lf]] = 0;
    
                        // if (rtb - lfb > rt - lf) {
                            lfb = lf; 
                            rtb = rt;
                            printf("%d - %d\n", lf, rt);
                        // }

                        lf++; need_value = 1; consist_in_substring[sc[lf]] = 1;

                    }
                }
            }
            rt++;
        }

        // 


        string tmp;
        return tmp; 
    }
};

int main() {
  Solution sln;
  sln.minWindow(string("ADOBECODEBANC"), string("ABC"));
  return 0;
}

