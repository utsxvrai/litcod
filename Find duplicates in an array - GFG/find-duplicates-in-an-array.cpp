//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
         map<int,int> mp;
         vector<int> siu;
         int c=0;
         for(int i = 0 ; i < n ; i ++){
             mp[arr[i]]++;
         }
         for(auto const & i : mp){
             if(i.second >= 2){
                 siu.push_back(i.first);
                 c++;
             }
         }
         if(c==0) return {-1};
         return siu;
             
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends