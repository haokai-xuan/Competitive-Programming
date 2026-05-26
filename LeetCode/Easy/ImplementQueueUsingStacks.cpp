class MyQueue {
    stack<int> in;
    stack<int> out;
    void transfer() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        else {
            while (!out.empty()) {
                in.push(out.top());
                out.pop();
            }
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        if (in.empty()) transfer();
        in.push(x);
    }
    
    int pop() {
        if (out.empty()) transfer();
        int top = out.top();
        out.pop();
        return top;
    }
    
    int peek() {
        if (out.empty()) transfer();
        return out.top(); 
    }
    
    bool empty() {
        return out.empty() && in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */