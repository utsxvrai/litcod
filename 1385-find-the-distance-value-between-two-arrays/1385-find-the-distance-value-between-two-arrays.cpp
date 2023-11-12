class Solution {
public:
    bool check(vector<int>& a,int x,int y){
        int l=0,h=a.size()-1;

        while(l<=h){
            int m = (l+h)/2;
            if(a[m]>=x && a[m]<=y) return false;
            else if(a[m]<x) l=m+1;
            else if(a[m]>y) h=m-1;
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr2.begin(),arr2.end());
        int c=0;
        for(int i=0;i<arr1.size();i++){
            int x = arr1[i]-d;
            int y = arr1[i]+d;

            if(check(arr2,x,y)) c++;
        }
        return c;
    }
};