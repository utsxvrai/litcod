//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int position = 1;  // Initialize the position of the rightmost bit as 1

    while (m > 0 || n > 0) {
        if ((m & 1) != (n & 1)) {
            return position;  // If the rightmost bits are different, return the position
        }

        // Right-shift both m and n to check the next bit
        m >>= 1;
        n >>= 1;
        position++;
    }

    return -1;
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends