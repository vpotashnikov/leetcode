class Solution {
    std::set<int> hash;
public:
    bool isMatch(string s, string p) {
        return find_match(s.c_str(), s.length(), p.c_str(), p.length());
    }
private:
    bool find_match(const char* sc, int sn, const char* pc, int pn) {
        // Remove head
        int i = 0;
        while (i < sn && i < pn && pc[i] != '*' && (pc[i] == '?' || pc[i] == sc[i])) i++;

        // Return result if sn finish
        if (i == sn) {
            while (i < pn && pc[i] == '*') i++;
            return (pn == i);
        }
        // Template end, but there is string 
        if (i >= pn || pc[i] != '*') return false;

        // Update string & try work with "*" 
        sc += i; pc += i; sn -= i; pn -= i;

        i = 0;
        while (i + 1 < pn && pc[i + 1] == '*') i++;
        pc += i; pn -= i;

        // Check if it try and store
        int hsh = (sn * 2001 + pn);
        if (hash.count(hsh)) return false;
        hash.insert(hsh);

        // BFS search
        for (i = 0; i <= sn; i++) 
            if (find_match(sc + i, sn - i, pc + 1, pn - 1)) return true;

        return false;
    }
};
