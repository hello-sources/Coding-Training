class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> sta;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long num1 = sta.top();
                sta.pop();
                long num2 = sta.top();
                sta.pop();
                if (s == "+") {
                    sta.push(num1 + num2);
                } else if (s == "-") {
                    sta.push(num2 - num1);
                } else if (s == "*") {
                    sta.push(num1 * num2);
                } else {
                    sta.push(num2 / num1);
                }
            } else {
                sta.push(stoll(s));
            }
        }
        return sta.top();
    }
};

//CPP中，switch只能是int或者是char类型，不能是字符串类型
//stol，就是将字符串转换为long ，stoll是将字符串转换为long long