int countCollisions(char * directions) {
    int len = strlen(directions);
    int indexLeft = 0, indexRight= 1, count = 0;
    while(indexRight < len) {
        if(directions[indexLeft] == 'R' ) {
            if(directions[indexRight] == 'L' ) {
                count += indexRight - indexLeft + 1;
                indexLeft = indexRight;
                directions[indexRight] = 'S';      
            } else if(directions[indexRight] == 'S') {
                count += indexRight - indexLeft;
                indexLeft = indexRight;
            }
        } else if(directions[indexLeft] == 'S') {
            if(directions[indexRight] == 'L') {
                directions[indexRight] = 'S';
                count++;
            } else {
                indexLeft = indexRight;
            }
        } else {
            indexLeft = indexRight;
        }
        indexRight++;
    }
    return count;
}

int countCollisions(char * directions){
    int res=0,temp=0;
    int i,len=strlen(directions);
    for(i=0;i<len;i++){
        if(directions[i]=='R'||directions[i]=='S') temp=1;
        if(directions[i]=='L'&&temp) res++;
    }
    temp=0;
    for(i=len-1;i>=0;i--){
        if(directions[i]=='L'||directions[i]=='S') temp=1;
        if(directions[i]=='R'&&temp) res++;
    }
    return res;
}