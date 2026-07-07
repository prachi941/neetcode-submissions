class Solution {
public:
    int evalRPN(vector<string>& tokens) {

         stack<int> st;

         for( string token : tokens){

            if(token.size() > 1 || isdigit(token[0])){ // if it is an operand; number checking
                st.push(stoi(token));
            }

            else{ // if it is a operator 

                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if(token == "+") st.push(a + b);
                if(token == "-") st.push(a - b);
                if(token == "*") st.push(a * b);
                if(token == "/") st.push(a / b);
            }
         }

         return st.top();

        
    }
};
