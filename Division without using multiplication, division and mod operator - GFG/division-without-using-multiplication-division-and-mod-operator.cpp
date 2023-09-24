//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert both dividend and divisor to positive
    long long ldividend = abs((long long)dividend);
    long long ldivisor = abs((long long)divisor);

    // Initialize the quotient
    long long quotient = 0;

    // Perform the division using bitwise operations
    while (ldividend >= ldivisor) {
        long long temp = ldivisor;
        long long multiple = 1;

        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        ldividend -= temp;
        quotient += multiple;
    }

    return sign * quotient;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends