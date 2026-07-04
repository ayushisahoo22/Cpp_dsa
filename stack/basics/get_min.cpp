#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
public:
    stack<long long> st;
    long long mini;
    void push(int data) {
        if(st.empty()) {
            st.push(data);
            mini = data;
        }
        else if(data >= mini) {
            st.push(data);
        }
        else {
            st.push(2LL * data - mini);
            mini = data;
        }
    }

    void pop() {
        if(st.empty()) return;

        if(st.top() < mini) {
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }

    int top() {
        if(st.empty()) return -1;

        if(st.top() >= mini)
            return st.top();
        return mini;
    }

    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};

int main() {
    int q;
    cin >> q;
    SpecialStack s;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(type == 2) {
            s.pop();
        }
        else if(type == 3) {
            cout << s.top() << endl;
        }
        else if(type == 4) {
            cout << s.getMin() << endl;
        }
    }
    return 0;
}