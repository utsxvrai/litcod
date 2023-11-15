//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	   int lps[s.length()] = {0};
	    int len = 0;
	    int i = 1;
	    while(i < s.length()){
	        // tring to extend previous prefix
	        if(s[len] == s[i]){
	            len++;
	            lps[i] = len;
	            i++;
	        }else{
	            // we can't extend previous prefix and lenght of previous prefix is 0 then lenght of current prefix will also 0
	            if(len == 0){
	                lps[i] = 0;
	                i++;
	            }else{
	                // we will try to extend previous of previous prefix
	                len = lps[len - 1];
	            }
	        }
	    }
	    return lps[s.length()-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends