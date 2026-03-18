#include <bits/stdc++.h>

using namespace std;

class DSU{
    public:

    vector<int> par, size;

    DSU(int n){
        par.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findPar(int u){
        if(u == par[u])
            return u;

        return par[u] = findPar(par[u]);
    }


    void UBS(int u, int v){
        int u_p = findPar(u);
        int v_p = findPar(v);

        if(u_p == v_p)
            return;
        
        if(size[u_p] > size[v_p]){
            par[v_p] = u_p;
            size[u_p] += size[v_p];
        }
        else{
            par[u_p] = v_p;
            size[v_p] += size[u_p];
        }
    }
};
class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        /*
        I have a set of unique (x, y) pairs

        every point in the same x or same y coordinate is activated
        so groups with the same (x) or same (y) belong to the same group

        how do i group them, on basis of x AND y

        (1, 1)
        merge with group whose x coordinate = 1, and group whose y coordinate = 1
        consider x and y to be same entities
        DSU by size preferably

        DSU by size is done on the indices based on x and y coordinate
        now the main task : where do i add the point

        find all the disconnected segments, and join the largest two?
        lesgoo it works
        */

        int n = points.size();
        DSU ds(n);
        /*
    
        a single component im using index to represent it (x1, y1) 
        each component is an index from 0 -> size(points)
        to merge some i with some j, they must share the same x or y coordinate
        yup this strategy works
        DSU size = no of points

        map each unique x, y to its index, unionize current x, y to those mapped indices
        */
        int curr = 0;
        unordered_map<int, int> mpx, mpy;

        for(int i = 0; i < n; i++){
            if(!mpx.count(points[i][0]))
                mpx[points[i][0]] = i;
            if(!mpy.count(points[i][1]))
                mpy[points[i][1]] = i;
            
            ds.UBS(mpx[points[i][0]], i);
            ds.UBS(mpy[points[i][1]], i);
        }
        
        vector<int> comp_sizes;
        int first = 0, second = 0;
        for(int i = 0; i < n; i++){
            int u_p = ds.findPar(i);
            if(u_p == i){
                if(ds.size[u_p] > first){
                    swap(first, second);
                    first = ds.size[u_p];
                }
                else if(ds.size[u_p] > second)
                    second = ds.size[u_p];

                comp_sizes.push_back(ds.size[u_p]);
            }
        }

        
        return first + second + 1;
    }
};