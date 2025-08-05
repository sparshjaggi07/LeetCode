class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);  // force long long arithmetic
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini) {
            mini = 2LL * mini - topVal;
        }

        if (st.empty()) {
            mini = LLONG_MAX;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long topVal = st.top();
        return (topVal < mini) ? mini : topVal;
    }

    int getMin() {
        return mini;
    }
};
