class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0 ; i < tokens.size() ; i++){
            string s = tokens[i];
            if((s == "+" or s == "-" or s =="*" or s == "/") && !st.empty()){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int res;
                string op = s;
                if(op == "+")  res = a+b;
                else if(op == "-") res = b -a;
                else if(op == "*") res = b * a;
                else res = b/a;
                
                st.push(res);
                
                
            }
            else{
                int n = stoi(s);
                st.push(n);
            }
            
        }
        return st.top();
        
    }
};