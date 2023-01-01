class Solution {
    int best_result;
    void try_pos(
        char* large_word, 
        char* short_word, 
        int large_n,
        int short_n,
        int death_now
        ) {
        
        // if current result worse than best just return
        if (death_now + large_n - short_n > best_result)
            return;

        int i = 0;
        // try remove first symbol
        while (i < short_n && large_word[i] == short_word[i]) i++;
        if (i != 0) {
            large_word += i;
            short_word += i;
            large_n -= i;
            short_n -= i;
        }

        // Check if one word has zero length
        if (short_n == 0) {
            if (best_result > death_now + large_n) best_result = death_now + large_n;
            return;
        }

        // Try find first char in short word
        for (i = 1; i != large_n; i++) {
            if (large_word[i] == short_word[0]) {
                if (large_n - i > short_n) {
                    try_pos(large_word + i, short_word, large_n - i, short_n, death_now + i);
                } else {
                    try_pos(short_word, large_word + i , short_n, large_n - i, death_now + i);
                }
            }
        }

        // Replace firt char short word
        try_pos(large_word + 1, short_word + 1, large_n - 1, short_n - 1, death_now + 1);

        // Remove firt char short word
        try_pos(large_word, short_word + 1, large_n, short_n - 1, death_now + 1);


    }
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length()) {
            string tmp = word1;
            word1 = word2;
            word2 = tmp; 
        } 
        char* large_word = new char[word1.length()];
        memcpy(large_word, word1.c_str(), word1.length());
        int large_n = word1.length();        char* short_word = new char[word2.length()];
        memcpy(short_word, word2.c_str(), word2.length());
        int short_n = word2.length();
        best_result = large_n;

        try_pos(large_word, short_word, large_n, short_n, 0);
        
        return best_result;
    }
};

