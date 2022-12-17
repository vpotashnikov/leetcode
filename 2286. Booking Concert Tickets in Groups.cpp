class tree {
    public:
    tree* leaf_left = 0;
    tree* leaf_right = 0;
    int range_left, range_right;
    long long sum;
    int max, m;
    long long init(int range_left, int range_right, int m) {
        this->m = m;
        this->max = m;
        this->range_right = range_right;
        this->range_left = range_left;
        // if end leaf
        if (range_right - range_left == 1) {
            this->sum = (long long)m;
            return (long long)m;
        }
        // if not
        long long sm = 0;
        int  n = range_right - range_left;
        int centr = range_left / 2 + range_right / 2; // Centr point. Left to be use first
        if (n != 0 && range_left - centr == 0) centr++;
        
        this->leaf_left = new tree();
        sm += this->leaf_left->init(range_left, centr, m);

        if (range_right - centr >= 1) {
            this->leaf_right = new tree();
            sm += this->leaf_right->init(centr, range_right, m);
        };
        this->sum = sm;
        return sm;
    }
    vector<int> gather(int k, int maxRow) {
        if (k > this->max || this->range_left > maxRow) return vector<int> ();
        if (this->range_right - this->range_left == 1) {
            vector<int> rs = {this->range_left, this->m - this->max};
            this->max -= k;
            this->sum -= (long long)k;
            return rs;
        }
        if (this->leaf_left->max >= k) {
            vector<int> rs = this->leaf_left->gather(k, maxRow);
            if (rs.size() == 0) return rs;
            this->update_max();
            this->sum -= (long long)k;
            return rs;
        }
        if (this->leaf_right != 0 && this->leaf_right->max >= k) {
            vector<int> rs = this->leaf_right->gather(k, maxRow);
            if (rs.size() == 0) return rs;
            this->update_max();
            this->sum -= (long long)k;
            return rs;
        }
        return vector<int> ();
    }
    void update_max() {
        this->max = this->leaf_left->max;
        if (this->leaf_right != 0 && this->leaf_right->max > this->max)
            this->max = this->leaf_right->max;
    } 
    bool scatter(int k, int maxRow) {
        if ((long long)k > this->sum || this->range_left > maxRow) return false;
        // End point
        if (this->range_right - this->range_left == 1) {
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
        if (!fl && this->leaf_right != 0 && this->leaf_right->range_left <= maxRow) {
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
    tree tree;  // Tree for count sum & max length 
public:
    BookMyShow(int n, int m) {
        this->tree.init(0, n, m);
    }
    vector<int> gather(int k, int maxRow) {
        return this->tree.gather(k, maxRow);
    }
    bool scatter(int k, int maxRow) {
        return this->tree.scatter(k, maxRow);
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

 