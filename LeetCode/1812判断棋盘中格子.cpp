bool squareIsWhite(char * coordinates){
    if ((coordinates[0] - 'a') % 2 == 0) {
        if ((coordinates[1] - '0') % 2 == 1) return false;
        else return true;
    } else {
        if ((coordinates[1] - '0') % 2 == 1) return true;
        else return false;
    }
    return true;
}