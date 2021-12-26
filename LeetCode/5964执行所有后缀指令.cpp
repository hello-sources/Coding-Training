

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* executeInstructions(int n, int* startPos, int startPosSize, char * s, int* returnSize){
    int *sum = (int *)malloc(sizeof(int) * 505);
    int curx, cury, cnt = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int step = 0, flag = 0;
        curx = startPos[0], cury = startPos[1];
        for (int j = i; j < len; j++) {
            switch (s[j]) {
                case 'L' : {
                    cury--;
                    if (cury < 0 || cury >= n || curx < 0 || curx >= n) { 
                        flag = 1;    
                        break;
                    }
                    step++;
                    break;
                }
                case 'R' : {
                    cury++;
                    if (cury < 0 || cury >= n || curx < 0 || curx >= n) { 
                        flag = 1;    
                        break;
                    }
                    step++;
                    break;
                }
                case 'U' : {
                    curx--;
                    if (cury < 0 || cury >= n || curx < 0 || curx >= n) { 
                        flag = 1;    
                        break;
                    }
                    step++;
                    break;
                }
                case 'D' : {
                    curx++;
                    if (cury < 0 || cury >= n || curx < 0 || curx >= n) { 
                        flag = 1;    
                        break;
                    }
                    step++;
                    break;
                }
            }
            if (flag) break;
        }
        sum[cnt++] = step;
    }
    *returnSize = cnt;
    return sum;
}