class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int lf = k, rt = k, mn = nums[k], mx = nums[k];
        while ((lf > 0 || rt < nums.size() - 1) && mx < mn * nums.size()) {
            // Try go to left
            while (lf != 0 && nums[lf - 1] >= mn) lf--;
            // Try go to right
            while (rt != nums.size() - 1 && nums[rt + 1] >= mn) rt++;

            // Update maximum
            if ((rt - lf + 1) * mn > mx) mx = (rt - lf + 1) * mn;

            // Move one step to left or right
            if (lf > 0 || rt < nums.size() - 1) {
                if (lf == 0 || (rt < nums.size() - 1 && nums[lf - 1] < nums[rt + 1])) {
                    rt++; mn = nums[rt];
                } else {
                    lf--; mn = nums[lf];
                }
            }
        }
        if ((rt - lf + 1) * mn > mx) mx = (rt - lf + 1) * mn;
        return mx;
    }
};

