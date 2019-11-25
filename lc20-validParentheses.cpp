class Solution {
public:
    bool isValid(string s) {
        if(s.empty())   return true;
        int sLen = s.length();
        stack<char> match;
        for(int i = 0; i < sLen; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')   match.push(s[i]);
            else{
                if(match.empty())   return false;
                if(s[i] == ')' && match.top() == '(') match.pop();
                else if(s[i] == ']' && match.top() == '[')  match.pop();
                else if(s[i] == '}' && match.top() == '{')  match.pop();
                else    return false;
            }
        }
        return match.empty();
    }
};