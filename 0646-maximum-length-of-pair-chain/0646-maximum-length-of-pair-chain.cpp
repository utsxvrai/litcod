class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2)
   {
     return v1[1]<v2[1];
   }
    int findLongestChain(vector<vector<int>>& pairs) {
          sort(pairs.begin(),pairs.end(),comp);
      int sm=pairs[0][1];
        int ct=1;
        for(int i=1;i<pairs.size();i++)
          {
            if(sm<pairs[i][0])
              {
                sm=pairs[i][1];
                ct++;
              }
          }
          return ct;
    }
};