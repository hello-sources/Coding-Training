bool isMatchCore(char *s, char *p) {
  if(*s == '\0' && *p == '\0') return true;
  if(*p == '\0' && *s != '\0') return false;
  if(*(p + 1) == '*') {  
    if(*p == *s ) {
      return isMatchCore(s + 1, p) || isMatchCore(s, p + 2);
    }
    if(*p != *s && *p != '.') {
      return isMatchCore(s, p + 2);
    }
    if(*p == '.' && *s != '\0') {
      return isMatchCore(s + 1, p) ||isMatchCore(s, p + 2);
    } else if(*p == '.' && *s =='\0') return isMatchCore(s, p + 2);
  }
  if((*p == '.' && *s != '\0') || *p == *s) {
    return isMatchCore(s + 1, p + 1);
  }
  return false;
}

bool isMatch(char* s, char* p){
    if(s == NULL || p == NULL) return false;
    return isMatchCore(s, p);
}