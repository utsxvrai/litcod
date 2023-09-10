//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
         
        int n = a.size();
        int m = b.size();

        // If the lengths of the strings are different, they cannot be anagrams.
        if (n != m)
            return false;

        // Sort both strings and compare them.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // If the sorted strings are the same, they are anagrams.
        return a == b;
    
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends