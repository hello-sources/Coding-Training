bool lemonadeChange(int* bills, int billsSize){
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) cnt0++;
        else if (bills[i] == 10) {
            if (cnt0 < 1) return false;
            else {
                cnt0--;
                cnt1++;
            }
        } else if (bills[i] == 20) {
            if (cnt0 > 0 && cnt1 > 0) {
                cnt1--;
                cnt0--;
            } else if (cnt0 >= 3) {
                cnt0 -= 3;
            } else return false;
        }
    }
    return true;
}