#include <bits/stdc++.h>


using namespace std;



class DSU{
    public:

    vector<int> parent, size, parity;

    DSU(int n){
        size.resize(n, 1);
        parent.resize(n);
        parity.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    // path compression should return root + parity

    pair<int, int> findParent(int u){
        if(u == parent[u])
            return {u, 0}; // parity with itself 0
        
        auto [up, par] = findParent(parent[u]);

        parent[u] = up; // normal dsu step

        parity[u] = (parity[u] + par)%2; // add parent parity

        return {up, parity[u]};
    }

    bool UBS(int u, int v, int w){
        auto [up, pu] = findParent(u);
        auto [vp, pv] = findParent(v);

        if(up == vp){
            // cycle formation, check if it leads to odd weight

            return (pu + pv + w)%2 == 0;
        }

        // make up always up > vp
        if(size[up] < size[vp]){
            swap(up, vp);
            swap(pu, pv);
        }

        size[up] += size[vp];
        parent[vp] = up;


        // now important parity update
        // parity of v which you are adding to the u family becomes, 
        // parity till u + parity till v  + w

        parity[vp] = (pu + pv + w)%2; // youre merging up with vp, hence vp parity is what should be updated
        


        return true;
    }

};
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        /*
        DSU but you store the parity of each node, 
        i.e the parity you would get if you travelled from the ultimate 
        parent of the node to the other node
        
        even if ultimate parent is not part of the cycle, it doesnt matter because
                1
                |
                2
                |
                3
               / \
               4  5

               we are going to add edge from 4-5, but parity takes count of parity from
                1 to 4, and 1 to 5, we need parity only of 3-4, 3-5
                when you calculate parities
                you take 1-3 twice, once for 1-4, and once for 1-5, thereby cancelling it out
                if its odd, it becomes even (0) and even doubles to be even (0)
                effectively making it seem like we never took it

        */

        DSU ds(n);

        int ans = 0;
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];

            if(ds.UBS(u, v, w))
                ans++;
        }

        return ans;
    }
};