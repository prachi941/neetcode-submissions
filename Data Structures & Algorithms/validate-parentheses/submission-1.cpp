class Solution {
public:
    bool isMatching(char open, char close) {

        if(open == '(' && close ==')') 
         return true;

        if(open == '{' && close == '}') 
         return true;

        if(open == '[' && close == ']')
         return true;

        return false;
    }

    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            
            else {

                if(st.empty()) // if initially in s closing brackets are there; then nothing to push so no opening ones so return false immediately
                return false;

                if(isMatching(st.top(), ch)){
                    st.pop();
                } 
                
                else {
                    return false;
                }
            }

        }
        return st.empty();
    }
};
