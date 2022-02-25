/**
 * *********************************************************************
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int getElement(ArrayReader *, int index);
 */
#define MAX_N 2147483647
int search(struct ArrayReader* reader, int target) {
    int left = 0, right = MAX_N;
    while (left < right) {
        int mid = (left + right) / 2;
        if (getElement(reader, mid) != MAX_N) left = mid + 1;
        else right = mid;
    }
    left = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        if (getElement(reader, mid) > target) right = mid;
        else if (getElement(reader, mid) < target)  left = mid + 1;
        else return mid;
    }
    return -1;
}