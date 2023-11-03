class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> siu;
        int j=0;
        for(int i=1;i<=n;i++)
        {
            if(j==target.size())
            break;

            if(i==target[j])
             siu.push_back("Push"), j++;
            else {
                while(i!=target[j])
                {
                    siu.push_back("Push");
                    siu.push_back("Pop");
                    i++;
                }

                siu.push_back("Push");
                j++;
            }
           
        }
        return siu;
    }
};