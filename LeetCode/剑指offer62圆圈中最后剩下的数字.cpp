int lastRemaining(int n, int m) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res + m) % i;
    }
    return res;
}

/***推导公式
f(n,m)=[(m-1)%n+x+1]%n
      =[(m-1)%n%n+(x+1)%n]%n
      =[(m-1)%n+(x+1)%n]%n
      =(m-1+x+1)%n
      =(m+x)%n
***/