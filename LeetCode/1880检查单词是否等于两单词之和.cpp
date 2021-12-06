bool isSumEqual(char * firstWord, char * secondWord, char * targetWord){
    int len1 = strlen(firstWord), len2 = strlen(secondWord), len3 = strlen(targetWord);
    int num1 = 0, num2 = 0, num3 = 0;
    for (int i = len1 - 1; i >= 0; i--) {
        num1 += (firstWord[i] - 'a') * pow(10, len1 - 1 - i);
    }
    for (int i = len2 - 1; i >= 0; i--) {
        num2 += (secondWord[i] - 'a') * pow(10, len2 - 1 - i);
    }
    for (int i = len3 - 1; i >= 0; i--) {
        num3 += (targetWord[i] - 'a') * pow(10, len3 - 1 - i);
    }
    if (num1 + num2 == num3) return true;
    return false;
}