class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
    
    for(char br : s) {

        if(br == '(' || br == '[' || br =='{') {
            st.push(br);
        }

        else {

            if(st.empty()) {
                return false;
            }
            
            if((br == ')' && st.top() == '(') ||
                (br == ']' && st.top() == '[') ||
                (br == '}' && st.top() == '{'))  {

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
