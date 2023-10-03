//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
         string ans="";
       while(n){
            long long int m=n%26;
            n/=26;
            if(m==0){
                ans+='Z';
                n--;
            }
            else{
                char c='A'+m-1;
                ans+=c;
            }
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends