class Solution {
public:
    bool isNumber(string s) {
        const char* c = s.c_str();
        int n = s.length(), i = 0; 
        // remove first sign if any
        if (c[0] == '+' || c[0] == '-') i++;

        bool pnt = false, mts = false, dgt = false;

        while (i < n) {
            // Check correct symbol
            if (!((c[i] >= '0' && c[i] <= '9') ||
                (c[i] == '.' || c[i] == 'e' || c[i] == 'E'))) return false;
            // number without digit isn't valid
            if (c[i] >= '0' && c[i] <= '9') dgt = true;
            // check is point appropriate
            if (c[i] == '.') {
                // have to be once, before "e", and digit befor or after
                if (mts || pnt || !(dgt || (n - i > 1 && c[i + 1] >= '0' && c[i + 1] <= '9'))) return false;
                pnt = true; 
            }
            // check "e"
            if (c[i] == 'e' || c[i] == 'E') {
                // have to be once and have to be any digit before
                if (mts || n - i == 1 || !dgt) return false; mts = true;
                // remove sign after e, if any
                if (c[i + 1] == '+' || c[i + 1] == '-') i++;
                // ahve to be any digit after
                if (n - i == 1) return false;
                // after "e" & sign valid only digits, so check it
                i++;
                while (i < n) {
                     if (!(c[i] >= '0' && c[i] <= '9')) return false;
                    i++;
                }
            }
            i++;
        }
        

        return dgt;
    }
};