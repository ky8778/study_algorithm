
#include<cstdio>

using namespace std;

const long long num = 1000000007;
long long N,K;

int main(){
    scanf("%lld %lld",&N,&K);
    long long a = 1;
    for(long long i=2;i<=N;i++){
        a = (i*a)%num;
    }
    long long b = 1;
    for(long long k=2;k<=K;k++){
        b = (k*b)%num;
    }
    long long c = 1;
    for(long long n=2;n<=N-K;n++){
        c = (c*n)%num;
    }
    printf("%lld\n",a/(b*c));
    return 0;
}