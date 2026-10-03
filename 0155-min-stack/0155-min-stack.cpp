class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int value) {
        if (st.empty()) {
            mini = value;
            st.push(value);
        }
        else if (value >= mini) {
            st.push(value);
        }
        else {
            // Encode the value
            st.push(2LL * value - mini);
            mini = value;
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long n = st.top();
        st.pop();

        if (n < mini) {
            // Decode previous minimum
            mini = 2LL * mini - n;
        }
    }
    
    int top() {
        if (st.empty()) return -1;

        long long n = st.top();

        if (n < mini) {
            // Encoded value → actual top is mini
            return mini;
        }

        return n;
    }
    
    int getMin() {
        return mini;
    }
};