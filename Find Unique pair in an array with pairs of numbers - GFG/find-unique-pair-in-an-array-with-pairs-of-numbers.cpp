//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    vector<int> findUniquePair(int arr[], int n)
    {
    	// Complete the function and return the sorted vector.
    	int x=0;
    	for(int i = 0 ; i < n ; i++){
    	    x^=arr[i];
    	}
    	int rm = x & (-x);
    	int a=0;
    	vector<int> an;
    	
    	for(int i = 0 ; i < n ; i++){
    	    if((arr[i]&rm)) an.push_back(arr[i]);
    	}
    	for(int i = 0 ; i < an.size() ; i++){
    	    a^=an[i];
    	}
    	int b=x^a;
    	if(a>b) return {b,a};
    	return {a,b};
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n; 
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    vector<int> v;
	    Solution ob;
	    v = ob.findUniquePair(a, n);
	    cout<<v[0]<<" "<<v[1]<<endl;
	}
	return 0;
}

// } Driver Code Ends