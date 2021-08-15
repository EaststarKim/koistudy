int f(int n){
    int s=0;
    for(;n;n/=10)s=s*10+n%10;
    return s;
}
bool is_Pal(int n){return n==f(n);}
