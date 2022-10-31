class MyQueue {
    Stack<Integer> staIn;
    Stack<Integer> staOut;

    public MyQueue() {
        staIn = new Stack<>();
        staOut = new Stack<>();
    }
    
    public void push(int x) {
        staIn.push(x);
    }
    
    public int pop() {
        copyIntoOut();
        return staOut.pop();
    }
    
    public int peek() {
        copyIntoOut();
        return staOut.peek();
    }
    
    public boolean empty() {
        return staIn.isEmpty() && staOut.isEmpty();
    }

    public void copyIntoOut() {
        if (!staOut.isEmpty()) return ;
        while (!staIn.isEmpty()) {
            staOut.push(staIn.pop());
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */