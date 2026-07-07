class MinStack {
    stack<pair<int,int>>st;// pair for storing value as well as minVlue at each insertion of new val so we don't have to find min val separately
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val,val});
        }
        else {
            int minVal = min(val, st.top().second);// here second is the second element of the pair
            st.push({val,minVal});
        }
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
    }
};
