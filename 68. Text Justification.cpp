class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i, j, k, cur_len, need_length, need_length_plus_one;
        vector<string> results;
        string tmp, tmp2;
        // Try to fill one string as large as possible
        i = 0;
        while (i < words.size()) {
            // Add first word
            k = i;
            cur_len = words[k].size(); 
            k++;
            // Start all other new words
            while (k < words.size() && words[k].size() + 1 + cur_len <= maxWidth) {
                cur_len += words[k].size() + 1;
                k++;
            }
            // Merge words
            tmp = "";
            if (k - i == 1 || k == words.size()) {
                tmp = words[i];
                for (j = i + 1; j < k; j++)
                    tmp += " " + words[j];

                while (tmp.size() != maxWidth)
                    tmp = tmp + " ";

            } else {
                need_length = (maxWidth - cur_len) / (k - i - 1);
                need_length_plus_one = maxWidth - need_length * (k - i - 1) - cur_len;
                tmp2 = " ";
                tmp = "";
                for (j = 0; j != need_length; j++)
                    tmp2 = tmp2 + " ";
                for (j = i; j < k - 1; j++) {
                    tmp += words[j] + tmp2;
                    if (j - i < need_length_plus_one) tmp += " ";
                }
                tmp += words[k - 1];
            }
            i = k;
            results.push_back(tmp);
        }
        return results;
    }
};
