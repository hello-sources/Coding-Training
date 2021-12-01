char * restoreString(char * s, int* indices, int indicesSize){
    char *ret = (char *)malloc(sizeof(char) * (indicesSize + 1));
    ret[0] = '\0';
    for (int i = 0; i < indicesSize; i++) {
        ret[indices[i]] = s[i];
    }
    ret[indicesSize] = '\0';
    return ret;
}