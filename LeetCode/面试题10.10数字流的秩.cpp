class StreamRank {
public:
    StreamRank() {}
    int lowbit(int x) {
        return x & (-x);
    }

    void track(int x) {
        x++;
        while (x <= 50005) {
            vec[x]++;
            x += lowbit(x);
        }
        return ;
    }
    
    int getRankOfNumber(int x) {
        int sum = 0;
        x++;
        while (x) {
            sum += vec[x];
            x -= lowbit(x);
        }
        return sum;
    }

private :
    vector<int> vec = vector<int>(50005, 0);
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */