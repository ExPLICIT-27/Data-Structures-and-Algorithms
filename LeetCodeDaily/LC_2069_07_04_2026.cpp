#include <bits/stdc++.h>

using namespace std;

class Robot {
public:
    /*
    robot will only move across the border
    east => y = 0
    north => x = width - 1
    west => y = height - 1
    south => x = 0


    flatten the border into 1 D x and y arr for easy computation
    */

    vector<int> X, Y;
    int w, h, ci, n;

    bool hasMoved = false;
    Robot(int width, int height) {
        w = width, h = height;


        n = 2*w + 2*h - 4;
        X.resize(n); // overcnt at the corners
        Y.resize(n);


        // east
        int idx = 0;
        for(int i = 0; i < w; i++){
            X[idx] = i, Y[idx++] = 0;
        }

        // north
        for(int j = 1; j < h; j++){
            X[idx] = w - 1, Y[idx++] = j;
        }

        // west
        for(int i = w - 2; i >= 0; i--){
            X[idx] = i, Y[idx++] = h - 1;
        }

        // south

        for(int j = h - 2; j > 0; j--){
            X[idx] = 0, Y[idx++] = j;
        }

        ci = 0;
    }
    
    void step(int num) {
        ci = (ci + num)%n;
        hasMoved = true;

    }
    
    vector<int> getPos() {
        return {X[ci], Y[ci]};
    }
    
    string getDir() {
        if(!hasMoved)
            return "East";
        
        if(X[ci] == 0){
            if(Y[ci] == h - 1)
                return "West";
            return "South";
        }

        if(X[ci] == w - 1){
            if(Y[ci] == 0)
                return "East";
            return "North";
        }

        if(Y[ci] == 0){
            if(X[ci] == 0)
                return "South";
            return "East";
        }

        if(Y[ci] == h - 1){
            if(X[ci] == w - 1)
                return "North";
            
            return "West";
        }

        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */