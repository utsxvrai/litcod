//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        
        vector<int> ans(n,0);
        vector<int> siu;
        for(int i = 0 ; i < n ; i++){
            ans[arr[i]]++;
        }
        for(int i = 0 ; i < n ; i++){
            if(ans[i]>1) siu.push_back(i);
        }
        if(siu.size()==0) siu.push_back(-1);
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