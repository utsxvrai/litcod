//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int count0 = 0, count1 = 0, count2 = 0;

    // Count the occurrences of 0s, 1s, and 2s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count0++;
        } else if (arr[i] == 1) {
            count1++;
        } else if (arr[i] == 2) {
            count2++;
        }
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i < count0; i++) {
        arr[index++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        arr[index++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        arr[index++] = 2;
    }
    
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends