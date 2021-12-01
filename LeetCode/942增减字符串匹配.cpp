/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * s, int* returnSize){
    int len = strlen(s), i = 0, j = 0;
    int *temp = (int *)malloc(sizeof(int) * (len + 1));
    while (s[i]) {
        if (s[i] == 'I') {
            temp[i] = j;
            j++;
        } else {
            temp[i] = len;
            len--;
        }
        i++;
    }
    temp[i] = j;
    *returnSize = strlen(s) + 1;
    return temp;
}
/***
    1.起始题目为,s中有N个字母可使用N+1个数(0,1...N):
        (1).若s[0]=='I',为满足A[0]<A[1],选A[0]=0一定可以满足;
        (2).若s[0]=='D',为满足A[0]>A[1],选A[0]=N一定可以满足.
    2.考虑字符串中的第2个字母时，题目变为s中的N-1个字母可使用N个数,剩余的N个数为[1,2...N]或[0,1,...N-1]:
        (1).若s[0]=='I',A[1]选择1或者0;
        (2).若s[0]=='D',A[1]选择N或者N-1.
    3.依次类推,我们每次会把可以使用的数的集合中的最小值或最大值取出，并放到当前的位置，因此可以使用的数的集合总是连续的，。
    4.为什么最后一项arr[N]=剩下的那个数min/len,会满足题设嘛?
    考虑字符串中的第N个字母时,s中有1个字母可使用2个数:
        (1).若s[N-1]=='I',为满足A[N-1]<A[N],选A[N-1]=待选择数中较小的那个;
        (1).若s[N-1]=='D',为满足A[N-1]>A[N],选A[N-1]=待选择数中较大的那个;
***/
