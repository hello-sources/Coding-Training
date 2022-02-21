int timeRequiredToBuy(int* tickets, int ticketsSize, int k){
    int time = 0;
    for (int i = 0; i < ticketsSize; i++) {
        if (i <= k) {
            time += fmin(tickets[i], tickets[k]);
        } else {
            time += fmin(tickets[i], tickets[k] - 1);
        }
    }
    return time;
}