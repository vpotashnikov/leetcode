class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i, j, n = matrix.size(); 
        vector<int> cur_best = matrix[n - 1];
        vector<int> tmp;
        
        // Backward calculate minimum span
        for (i = n - 2; i >= 0; i--) {
            tmp = cur_best;
            for (j = 0; j != n; j++) {
                if (j > 0 && cur_best[j - 1] < tmp[j]) tmp[j] = cur_best[j - 1];
                if (j < n - 1 && cur_best[j + 1] < tmp[j]) tmp[j] = cur_best[j + 1];
                tmp[j] += matrix[i][j];
            }
            cur_best = tmp;
        }
        // Find minimum head
        i = cur_best[0];
        for (j = 1; j != n; j++) {
            if (i > tmp[j]) i = tmp[j];
        }

        return i;
    }

};

