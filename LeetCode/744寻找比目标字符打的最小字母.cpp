char nextGreatestLetter(char* letters, int lettersSize, char target){
    int low = 0, high = lettersSize - 1, mid;
    while (low < high) {
        mid = (low + high) >> 1;
        if (letters[mid] > target) high = mid;
        else low = mid + 1; 
    }
    if (letters[low] > target) {
        return letters[low];
    } else {
        return letters[0];
    }
}