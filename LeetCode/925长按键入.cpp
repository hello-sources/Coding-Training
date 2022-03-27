bool isLongPressedName(char * name, char * typed){
    int len1 = strlen(name), len2 = strlen(typed);
    if (len2 < len1) return false;
    int ind = 0;
    char temp;
    for (int i = 0; i < len2; i++) {
        if (name[ind] == typed[i]) {
            temp = name[ind++];
        } else if (temp == typed[i]) {
            continue;
        } else {
            return false;
        }
    }
    return ind == len1;
}