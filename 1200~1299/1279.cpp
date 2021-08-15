int f(int n){return n<2?1:1+(n%2?f(n*3+1):f(n/2));}
