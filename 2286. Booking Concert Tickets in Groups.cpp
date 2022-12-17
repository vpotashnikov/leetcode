class tree {
    // Balance tree with max & sum for left & right leaf
    tree* leaf_left;
    tree* leaf_right;
    int range_left, max;
    long long sum;
    bool end_leaf;
    public:
    // Init tree, return sum of childs
    tree(int range_left, int range_right, int m) {
        this->max = m;
        this->range_left = range_left;
        this->end_leaf = (range_right - range_left == 1); 
        // if end leaf
        if (this->end_leaf) {
            this->sum = (long long)m;
            return;
        }

        // if not
        int centr = (range_left + range_right + 1) / 2;
        this->leaf_left = new tree(range_left, centr, m);
        this->leaf_right = new tree(centr, range_right, m);
        this->sum = this->leaf_left->sum + this->leaf_right->sum;
    }
    vector<int> gather(int k, int maxRow) {
        if (k > this->max || this->range_left > maxRow) return vector<int> ();
        if (this->end_leaf) {
            vector<int> rs = {this->range_left, this->max};
            this->max -= k;
            this->sum -= (long long)k;
            return rs;
        }
        vector<int> rs;
        if (this->leaf_left->max >= k) {
            rs = this->leaf_left->gather(k, maxRow);
        } else if (this->leaf_right->max >= k) {
            rs = this->leaf_right->gather(k, maxRow);
        }
        if (rs.size() == 0) return rs;
        this->update_max();
        this->sum -= (long long)k;
        return rs;
    }
    void update_max() {
        this->max = this->leaf_left->max;
        if (this->leaf_right->max > this->max)
            this->max = this->leaf_right->max;
    } 
    bool scatter(int k, int maxRow) {
        if ((long long)k > this->sum || this->range_left > maxRow) return false;
        // End point
        if (this->end_leaf) {
            this->max -= k;
            this->sum -= (long long)k;
            return true;
        }
        bool fl = false;
        // Left leaf enought
        if (this->leaf_left->sum >= (long long)k) {
            fl = this->leaf_left->scatter(k, maxRow);
        }
        // Try right
        if (!fl && this->leaf_right->range_left <= maxRow) {
            fl = this->leaf_right->scatter((long long)k - this->leaf_left->sum, maxRow);
            if (fl) this->leaf_left->scatter(this->leaf_left->sum, maxRow);
        }
        if (!fl) return false;
        // Update value if scatter possible
        this->sum -= (long long)k;
        this->update_max();
        return true;
    }
};
class BookMyShow {
private:
    tree* root;  // Tree for count sum & max length 
    int m;
public:
    BookMyShow(int n, int m) {
        this->m = m;
        this->root = new tree(0, n, m);
    }
    vector<int> gather(int k, int maxRow) {
        vector<int> rs = this->root->gather(k, maxRow);
        if (rs.size() != 0) rs[1] =  this->m - rs[1];
        return rs;
    }
    bool scatter(int k, int maxRow) {
        return this->root->scatter(k, maxRow);
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
 