//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
        // Code here.
        int XOR = 0;
            int n = arr.size();
    // XOR all elements to get XOR of two distinct numbers
    for (int i = 0; i < n; i++) {
        XOR ^= arr[i];
    }

    // Find the rightmost set bit in XOR (it will be a set bit in one of the distinct numbers)
    int rightmostSetBit = XOR & -XOR;

    int num1 = 0, num2 = 0;

    // Divide the numbers into two groups based on the rightmost set bit
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmostSetBit) {
            num1 ^= arr[i];
        } else {
            num2 ^= arr[i];
        }
    }

    // Ensure num1 is smaller than num2
    if (num1 > num2) {
        swap(num1, num2);
    }

    vector<int> result = {num1, num2};
    return result;
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends