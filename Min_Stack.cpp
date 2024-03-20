

class MinStack {
public:
    stack<int> st, minSt;

    MinStack() {}

    void push(int x) {
        if(st.empty()) {
            st.push(x);
            minSt.push(x);
            return;
        }
        st.push(x);
        minSt.push(min(minSt.top(), x));
        return;
    }

    void pop() {
        if(st.empty()) return;
        st.pop();
        minSt.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};