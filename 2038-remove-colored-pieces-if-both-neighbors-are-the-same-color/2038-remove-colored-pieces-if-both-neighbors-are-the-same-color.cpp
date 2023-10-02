class Solution {
public:
    bool winnerOfGame(string colors) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int a=0;
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i]=='A'&&colors[i-1]=='A'&&colors[i+1]=='A')
            {
                a++;
            }
            if(colors[i]=='B'&&colors[i-1]=='B'&&colors[i+1]=='B')
            {
                a--;
            }
        }
        if(a<=0)
        {
            return 0;
        }
        return 1;
    }
};