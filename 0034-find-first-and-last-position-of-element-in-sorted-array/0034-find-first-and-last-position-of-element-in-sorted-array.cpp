class Solution {
    public:
    vector<int> searchRange(vector<int>& a, int x) {
        int n=a.size();
      int l=0,r=n-1,ans1=-1;
      while(l<=r){
        int mid= l + (r-l)/2;
         if(a[mid]>=x){
           if(a[mid] == x)
           ans1=mid;
           r=mid-1;
         }
        else
        l=mid+1;
      }
        l=0,r=n-1;
      int ans2=n;
      while(l<=r){
        int mid= l + (r-l)/2 ;
         if(a[mid]<=x){
           if(a[mid] == x)
            ans2=mid;
           l=mid+1;
         }
        else
        r=mid-1;
      }
      vector<int>ans;
      if(ans1 == -1){
          ans.push_back(-1);
          ans.push_back(-1);
      }
      else{
          ans.push_back(ans1);
          ans.push_back(ans2);
      }
      return ans;

    }
};