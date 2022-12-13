class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 2) return this->rs;
        if (n == 1) {
            vector<string> tmp;
            tmp.push_back(string("Q", 1));
            this->rs.push_back(tmp);
            return this->rs;
        }
        this->n = n;
        printf("%d\n", this->n);
        int i;
        for (i = 0; i != n; i++) {
            queen_row[0] = i;
            this->find_sol(1);
        }
        return rs;
    }
private:
    int queen_row[9];
    int n;
    vector<vector<string>> rs;

    void find_sol(int lst) {
        int i, n = this->n;
        int busy_row[9];
        for (i = 0; i != n; i++) busy_row[i] = 0;
        for (i = 0; i != lst; i++) {
            busy_row[this->queen_row[i]] = 1;
            if (this->queen_row[i] - lst + i >= 0) busy_row[this->queen_row[i] - lst + i] = 1;
            if (this->queen_row[i] + lst - i < n)  busy_row[this->queen_row[i] + lst - i] = 1;
        }
        if (lst != n - 1) { // add solution
            for (i = 0; i != n; i++)
                if (busy_row[i] == 0) {
                    this->queen_row[lst] = i;
                    this->find_sol(lst + 1);
                }
        } else {

            for (i = 0; i != n; i++)
                if (busy_row[i] == 0) {
                    this->queen_row[lst] = i;
                    vector<string> tmp;
                    char tm2[9]; 
                    int j;
                    for (j = 0; j != n; j++) tm2[j] = '.';
                    for (j = 0; j != n; j++) {
                        tm2[this->queen_row[j]] = 'Q';
                        tmp.push_back(string(tm2, n));
                        tm2[this->queen_row[j]] = '.';
                    }
                    this->rs.push_back(tmp);
                }
        }
    }
};
