class MyStack {
    Queue<Integer> queIn;
    Queue<Integer> queOut;

    public MyStack() {
        queIn = new LinkedList<>();
        queOut = new LinkedList<>();
    }
    
    public void push(int x) {
        queOut.offer(x);
        while (!queIn.isEmpty()) {
            queOut.offer(queIn.poll());
        }
        Queue<Integer> tempQue = new LinkedList<>();
        tempQue = queIn;
        queIn = queOut;
        queOut = tempQue;
        return ;
    }
    
    public int pop() {
        return queIn.poll();
    }
    
    public int top() {
        return queIn.peek();
    }
    
    public boolean empty() {
        return queIn.isEmpty() && queOut.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */

 /*
  * 队列初始化 Queue<Integer> que = new LinkedList<>();
  * 添加元素 que.offer(x), que.add(x);
  * 返回队列第一个元素，并且删除 que.poll(), que.remove()
  * 返回第一个元素，que.element()
  * 返回第一个元素， que.peek()
  */