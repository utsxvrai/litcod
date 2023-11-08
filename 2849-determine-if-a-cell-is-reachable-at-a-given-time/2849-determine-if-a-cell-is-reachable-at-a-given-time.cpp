class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(fx==sx && sy==fy && t==1) return false;
        if(t<max(abs(sx-fx),abs(sy-fy))) return false;
        return true;  
    }
};