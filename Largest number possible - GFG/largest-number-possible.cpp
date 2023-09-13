//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string temp="";
        string zero="0";
    if (S > N*9 ){
        return "-1";
        }
        
    if (N > 1 && S == 0){
        return "-1";
    }
    string number="";
    for(int i=1;i<=N;i++){
        if (S>9){
            temp="9";
            //string number=number+temp;
            number.append(temp);
            S=S-9;
        }
        else if(S > 0){
            int num=S;
         
    std::string temp = std::to_string(num);
        
           number.append(temp);
           S=0;
        }
        
        else{
            number.append(zero);
        }
    }
    return number;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends