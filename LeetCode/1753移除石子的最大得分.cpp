class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> prq;
        prq.push(a);
        prq.push(b);
        prq.push(c);
        int ans = 0;
        while (prq.size() > 1) {
            int ta = prq.top();
            prq.pop();
            int tb = prq.top();
            prq.pop();
            ta--;
            tb--;
            ans++;
            if (ta) prq.push(ta);
            if (tb) prq.push(tb);
        }
        return ans;
    }
};

/*************************法二*******************/
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        a = nums[0];
        b = nums[1];
        c = nums[2];
        if (a + b <= c) return a + b;
        return c + (a + b - c) / 2;
    }
};