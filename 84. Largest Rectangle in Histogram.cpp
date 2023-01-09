class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Use monotonic stack for calculate bar square
        stack<int> pos, val;
        int i, mx = 0, tmp, i_last;
        for (i = 0; i != heights.size(); i++) {
            // Prepare stack to push && calculate if any temporary maximum
            i_last = i;
            while (val.size() != 0 && val.top() >= heights[i]) {
                tmp = (i - pos.top()) * val.top();
                i_last = pos.top();
                if (tmp > mx) mx = tmp;
                val.pop(); 
                pos.pop();
            }
            // Push to stack
            pos.push(i_last);
            val.push(heights[i]);
        }

        // Calculate square by stack
        while (val.size() != 0) {
            tmp = (i - pos.top()) * val.top();
            if (tmp > mx) mx = tmp;
            val.pop(); pos.pop();
        }


        return mx;
    }
};


