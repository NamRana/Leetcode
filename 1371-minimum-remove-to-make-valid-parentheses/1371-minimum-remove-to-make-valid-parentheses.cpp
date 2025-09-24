class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk; //store indices for '('
        unordered_set<int> toRemove; //store indices for invalid parentheses

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);  //unmatched '('
            }
            else if(s[i]==')'){
                if(!stk.empty()){
                    stk.pop();  //matched '('
                }else{
                    toRemove.insert(i);  //unmatched ')'
                }
            }
        }

        //any leftover '(' in stack are unmatched
        while(!stk.empty()){
            toRemove.insert(stk.top());
            stk.pop();
        }

    //building the final valid string
    string res="";
    for(int i=0;i<s.size();i++){
        if(toRemove.find(i)==toRemove.end()){
            res+=s[i];
        }
    }
    return res;
        
    }
};