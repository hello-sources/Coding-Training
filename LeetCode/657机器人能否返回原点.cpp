bool judgeCircle(char * moves){
    int x = 0, y = 0;
    for (int i = 0; moves[i]; i++) {
        switch (moves[i]) {
            case 'U': y++; break;
            case 'D': y--; break;
            case 'L': x--; break;
            case 'R': x++; break; 
        }
    }
    return x == 0 && y == 0;
}