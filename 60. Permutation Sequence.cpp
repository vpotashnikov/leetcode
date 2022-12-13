#include <string>
#include <stdio.h>


using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int i, j = k, per[9];
        char rest[9], rs[10];
        for (i = 0; i != n; i++) rest[i] = '1' + i;

        for (i = n; i != 0; i--) {
            per[i - 1] = j % (n - i + 1);
            j = j / (n - i + 1);
        }
        // for (i = 0; i != n; i++) printf("%d, ", per[i]);

        for (i = 0; i != n; i++) {
            rs[i] = rest[per[i]];
            for (k = per[i]; k < n - i - 1; k++)
                rest[k] = rest[k + 1];
        }
        rs[n] = 0;
        // printf("\n res: %s\n", rs);

        return string(rs, n);
    }
};


int main() {
    Solution dd;
    int i;
    for (i = 0; i != 6; i++) {
        printf("\n--- %d ---\n", i);
        dd.getPermutation(3, i);
    }
    return 0;
}
