//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int n)
    {
        auto swap= [&] (int arr[], int x, int y){
            int t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;
        };
        
        int max = arr[0];
    for (int i = 0; i < n; i++) {
        max = std::max(arr[i], max);
    }
    int msb = 31;
    for (int i = 31; i >= 0; i--) {
        int ithBit = (max >> i) & 1;
        if (ithBit == 1) {
            msb = i;
            break;
        }
    }
    int index = 0;

    for (int i = msb; i >= 0; i--) {
        int maxIndex = 0;
        int maxEle = INT_MIN;

        for (int j = index; j < n; j++) {
            int setBit = (arr[j] >> i) & 1;
            if (setBit != 0 && arr[j] > maxEle) {
                maxEle = arr[j];
                maxIndex = j;
            }
        }

        if (maxEle == INT_MIN) {
            continue;
        }
        swap(arr, index, maxIndex);

        for (int k = 0; k < n; k++) {
            if (k == index) continue;
            if (((arr[k] >> i) & 1) == 1) {
                arr[k] = arr[k] ^ arr[index];
            }
        }
        index++;
    }

    // Take XOR of all elements
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
// } Driver Code Ends