//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;
    vector<int> last_occurrence(256, -1);

    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        dp[i] = (dp[i - 1] * 2) % 1000000007;

        if (last_occurrence[c] != -1) {
            int idx = last_occurrence[c];
            dp[i] = (dp[i] - dp[idx - 1] + 1000000007) % 1000000007;
        }

        last_occurrence[c] = i;
    }

    return dp[n] % 1000000007;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends