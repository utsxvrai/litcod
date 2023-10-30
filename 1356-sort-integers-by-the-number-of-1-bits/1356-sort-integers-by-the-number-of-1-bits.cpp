class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()<=2)
            return arr;
        vector<int> temp(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            int n=arr[i];
            int count=0;
            while(n!=0)
            {
                count+=((n&1)==1)?1:0;
                n>>=1;
            }
            temp[i]=count;
        }
        vector<int> ans(temp.size());
        int a=0;
        for(int i=0;i<=14;i++)
            for(int j=0;j<temp.size();j++)
                if(temp[j]==i)
                    ans[a++]=arr[j];
        return ans;
    }
};