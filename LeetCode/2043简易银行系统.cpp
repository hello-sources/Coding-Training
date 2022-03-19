typedef struct {
    long long * money;
    int size;
} Bank;

Bank* bankCreate(long long* balance, int balanceSize) {
    Bank * obj = (Bank *)malloc(sizeof(Bank));
    obj->money = (long long *)malloc(sizeof(long long) * balanceSize);
    obj->size = balanceSize;
    //memcpy(obj->money, balance, sizeof(long long) * balanceSize);
    for (int i = 0; i < balanceSize; i++) {
        obj->money[i] = balance[i];
    }
    return obj;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    if (account1 > obj->size || account2 > obj->size || obj->money[account1 - 1] < money) {
        return false;
    }
    obj->money[account1 - 1] -= money;
    obj->money[account2 - 1] += money;
    return true;
}

bool bankDeposit(Bank* obj, int account, long long money) {
    if (account > obj->size) {
        return false;
    }
    obj->money[account - 1] += money;
    return true;
}

bool bankWithdraw(Bank* obj, int account, long long money) {
    if (account > obj->size || obj->money[account - 1] < money) {
        return false;
    }
    obj->money[account - 1] -= money;
    return true;
}

void bankFree(Bank* obj) {
    free(obj->money);
}