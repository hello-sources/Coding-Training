class CustomStack {
private :
    vector<int> sta;
    int top;

public:
    CustomStack(int maxSize) {
        sta.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if (top == sta.size() - 1) return ;
        sta[++top] = x;
    }
    
    int pop() {
        if (top == -1) return -1;
        top--;
        return sta[top + 1];
    }
    
    void increment(int k, int val) {
        k = min(k, top + 1);
        for (int i = 0; i < k; i++) sta[i] += val;
        return ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */