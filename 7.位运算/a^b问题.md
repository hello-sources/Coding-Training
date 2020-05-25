### a^b问题

#### 题目描述

 求 a 的 b 次方对 p 取模的值。

------

#### 输入

 输入三个整数 a,b,p。（0≤a,b≤109,1≤p≤109）

#### 输出

 输出 a 的 b 次方对 p 取模的值。

------

#### 样例输入

```
5 4 15
```

#### 样例输出

```
10
```

------

#### 数据规模与约定

 时间限制：1 s

 内存限制：256 M

 100% 的数据保证 0≤a,b≤10^9,1≤p≤10^9

- **解题思路**

> 这一类问题被归为快速幂以及位运算问题，就是根据所求解幂次转换为二进制，二进制中对应的1就表示需要进行求解运算对应的幂次的值也进行平方运算，

- **快速幂算法**

1. 一般算法

```c++
int pow2(int a,int b){
    int r=1,base=a;
    while(b!=0){
    if(b%2) r*=base;
    base*=base;
    b/=2;
    }
    return r;
}
```

2. 递归实现

```c++
int f(int m,int n){   //m^n
    if(n==1) return m;
    int temp=f(m,n/2);
    return (n%2==0 ? 1 : m)*temp*temp;
}
```

3. 位运算

```c++
int pow3(int x,int n){
  if(n==0) return 1;
  else {
    while((n&1)==0){
      n>>=1;
      x*=x;
    }
  }
  int result=x;
  n>>=1;
  while(n!=0){
    x*=x;
    if(n&1) result*=x;
    n>>=1;
  }
  return result;
}
```

- **解题代码**

```c++
#include <iostream>
using namespace std;

long long quick_mod(long long a, long long b, long long p) {
	long long temp = a, ans = 1;
	while (b) {
		if (b & 1) ans = ans * temp % p;
		temp = temp * temp % p;
		b >>= 1;
	}
	return ans % p;
}

int main() {
	long long a, b, p;
	cin >> a >> b >> p;
	cout << quick_mod(a, b, p) << endl;
	
	return 0;
}
```