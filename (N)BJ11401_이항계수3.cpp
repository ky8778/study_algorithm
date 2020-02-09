
#include<cstdio>

using namespace std;

const long long num = 1000000007;
long long N,K;

int main(){
    scanf("%lld %lld",&N,&K);
    long long a = 1;
    for(long long i=K+1;i<=N;i++){
        a = (i*a)%num;
    }
    long long c = 1;
    for(long long n=2;n<=K;n++){
        c = (c*n)%num;
    }
    printf("%lld\n",(a/c)%num);
    return 0;
}