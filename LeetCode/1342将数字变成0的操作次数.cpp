int numberOfSteps(int num){
    int ans = 0;
    while (num) {
        if (num % 2 == 0) num /= 2;
        else num -= 1;
        ans++;
    }
    return ans;
}