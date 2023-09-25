class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        auto spaces = [&] (string& s){
            int c=0;
            for(auto i : s){
                if(i==' ') c++;
            }
            return c;
        };
        int siu=0;
        for(auto i : sentences){
            int d = spaces(i)+1;
            siu=max(siu,d);
        }
        return siu;
        
    }
};