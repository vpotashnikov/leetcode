class leaf {
    vector<leaf*> child;
    
public:
    int vert;
    int total_child = 0;
    int total_child_distance = 0;
    int total_distance;
    
    // Add child leaf
    void add_child(leaf* edg) {
        child.push_back(edg);
    }

    // Remove parent leaf from child
    void remove_parent(int par) {
        int i = 0;
        if (par != -1) {
            while (i < child.size() && child[i]->vert != par) i++;
            child.erase(child.begin() + i);
        }
        if (!child.size()) return;
        for (i = 0; i != child.size(); i++) 
            child[i]->remove_parent(vert);
    }

    // Calculate total child leaf
    int count_total_child() {
        if (!child.size()) return 0;
        int i, tch = 0;
        for (i = 0; i != child.size(); i++) 
            tch += child[i]->count_total_child() + 1;
        total_child = tch;
        return tch;
    }

     // Calculate total child leaf distance 
    int count_total_child_distance() {
        if (!child.size()) return 0;
        int i, tch = 0;
        for (i = 0; i != child.size(); i++) 
            tch += child[i]->count_total_child_distance() + 1 + child[i]->total_child;
        total_child_distance = tch;
        return tch;
    }

    // Calculate total distance from other leafs
    void count_total_distance(int parent_child_distance, int n) {
        if (!parent_child_distance) {
            total_distance = total_child_distance;
        } else {
            total_distance = parent_child_distance + n - 2 - 2 * total_child;
        }
        int i;
        for (i = 0; i != child.size(); i++) 
            child[i]->count_total_distance(total_distance, n);
    }
};

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        leaf vertex[n];
        int i;
        for (i = 0; i != n; i++) 
            vertex[i].vert = i;
        // Fill tree
        for (i = 0; i != edges.size(); i++) {
            // Add both edges
            vertex[edges[i][0]].add_child(&vertex[edges[i][1]]);
            vertex[edges[i][1]].add_child(&vertex[edges[i][0]]);
        }

        // Remove parents from child
        vertex[0].remove_parent(-1);
        
        // Calculate total child leaf
        vertex[0].count_total_child();

        // Calculate total child leaf distance 
        vertex[0].count_total_child_distance();

        // Final calculation
        vertex[0].count_total_distance(0, n);

        // Add to result
        vector<int> rs;
        for (i = 0; i != n; i++)
            rs.push_back(vertex[i].total_distance);

        return rs;
    }
};

