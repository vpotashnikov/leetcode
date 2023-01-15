class Solution {
public:
    string longestPalindrome(string s) {
        const char* sc = s.c_str();
        int i, r, b_st = 0, b_en = 0, n = s.length();

        for (i = 1; i < n; i++) {
            // Check noncentre polynome
            r = 0; 
            while (i - r >= 0 && i + r < n && sc[i - r] == sc[i + r]) r++;
            r--;
            if (2 * r > b_en - b_st) {b_st = i - r; b_en = i + r;}
            // Check centre polynome
            r = 0; 
            while (i - r - 1 >= 0 && i + r < n && sc[i - r - 1] == sc[i + r]) r++;
            r--;
            if (2 * r + 1 > b_en - b_st) {b_st = i - r - 1; b_en = i + r;}
            
        }

        return s.substr(b_st, b_en - b_st + 1);
    }
};


