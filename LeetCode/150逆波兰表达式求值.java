class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> sta = new Stack<>();
        for (String str : tokens) {
            switch(str) {
                case "+": {
                    sta.push(sta.pop() + sta.pop());
                    break;
                }
                case "-": {
                    sta.push(-sta.pop() + sta.pop());
                    break;
                }
                case "*": {
                    sta.push(sta.pop() * sta.pop());
                    break;
                }
                case "/": {
                    int num1 = sta.pop();
                    int num2 = sta.pop();
                    sta.push(num2 / num1);
                    break;
                }
                default : {
                    sta.push(Integer.valueOf(str));
                }
            }
        }
        return sta.pop();
    }
}