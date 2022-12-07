class Solution {
public:
    int trap(vector<int>& height) {
        int il = 0, ir = height.size() - 1, ans = 0;
        int ml = height[0], mr = height[ir], mm;
        if (ml > mr) mm = mr; else mm = ml;
        while (il < ir) {
            if (ml < mr) {
                il++; 
                if (ml < height[il]) {
                    ml = height[il];
                    if (ml > mr) mm = mr; else mm = ml;
                }
                if (height[il] < mm) ans += mm - height[il];

            } else {
                ir--; 
                if (mr < height[ir]) {
                    mr = height[ir];
                    if (ml > mr) mm = mr; else mm = ml;
                }
                if (height[ir] < mm) ans += mm - height[ir];

            }

        } 
        return ans;
    }
};
