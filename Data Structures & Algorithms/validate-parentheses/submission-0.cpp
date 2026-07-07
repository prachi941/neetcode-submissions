class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s){

            if(c == '(' || c =='{' || c == '[') {
                st.push(c);
            }

            else {

                if(st.empty()) return false; //in case when the string is ")(" so in this case string will be empty as no '(' before ')' so return false
                
                char top = st.top(); // declaring top variable
                st.pop();

                    if((c == ')' && top != '('|| 
                        c == '}' && top != '{'|| 
                        c == ']' && top != '[')) {
                        return false;
                }
            }
        }
        return st.empty();
    }
};
