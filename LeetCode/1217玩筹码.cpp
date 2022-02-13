int minCostToMoveChips(int* position, int positionSize){
    int num1 = 0, num2 = 0;
    for (int i = 0; i < positionSize; i++) {
        if (position[i] % 2 == 0) {
            num1++;
            continue;
        }
        num2++;
    }
    return num1 > num2 ? num2 : num1;
}