class Solution {

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int x, y, width, mx = 0, height, j;
        // Estimate max right shift
        vector<vector<int>> max_width;
        vector<int> tmp;
        for (x = 0; x != matrix[0].size(); x++) tmp.push_back(0);
        for (y = 0; y != matrix.size(); y++) max_width.push_back(tmp);
        for (y = 0; y != matrix.size(); y++) {
            x = 0; 
            while (x < matrix[0].size()) {
                while (x < matrix[0].size() && matrix[y][x] != '1') x++;
                if (x < matrix[0].size()) {
                    width = 1; 
                    while (x + width < matrix[0].size() && matrix[y][x + width] == '1') width++; 

                    for (j = 0; j < width; j++)
                        max_width[y][x + j] = width - j;
                    x += width;
                }
            }
        }

        // Find max rectangle
        for (y = 0; y != matrix.size() && (matrix.size() - y) * matrix[0].size() > mx; y++) {
            for (x = 0; x != matrix[0].size(); x++) {
                    if (y == 0) j = 1; else j = max_width[y - 1][x] + 1;
                    for (width = max_width[y][x]; width >= j && width * (matrix.size() - y) > mx; width--) {
                        height = 1;
                        while(y + height < matrix.size() && max_width[y + height][x] >= width) height++;
                        if (width * height > mx) mx = width * height;
                    }
                }
        }
        return mx;
    }
};

