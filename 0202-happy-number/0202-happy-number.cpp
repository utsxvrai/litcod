class Solution {
public:
    bool isHappy(int n) {
        int cpy=n;
        int val=0;
        int count=0;
        while(val!=1){
            val=0;
        while(cpy>0){
            int rem=cpy%10;
            val=(rem*rem)+val;
            cpy=cpy/10;
        }
        count++;
        cpy=val;
        if(count>10)
        return false; 
        }
        return true;
        
    }
};