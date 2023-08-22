//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
  int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> col(n,0);
        vector<int> row(n,0);
        int maxsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                col[j]=col[j]+matrix[i][j];
                row[i]=row[i]+matrix[i][j];
                maxsum=max(maxsum,col[j]);
                maxsum=max(maxsum,row[i]);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int maxi=max(col[j],row[i]);
                int inc=maxsum-maxi;
                if(inc==0){
                    continue;
                }else{
                    col[j]=col[j]+inc;
                    row[i]=row[i]+inc;
                    count=count+inc;
                }
            }
        }
        return count;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends