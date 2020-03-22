//! 2020.03.22
// TODO BJ1929_소수구하기
#include<cstdio>
#include<math.h>
using namespace std;

const int MAX = 1000000;
int M,N;
unsigned char check[(MAX+7)/8];

bool isPrime(int k){
    return check[k>>3] & (1<<(k&7));
}

void changeCheck(int k){
    check[k>>3] &= ~(1<<(k&7));
}

void eratosthenes(){
    for(int i=0;i<(MAX+7)/8;i++) check[i] = 255;
    changeCheck(0);
    int sqrtN = int(sqrt(N));
    for(int i=2;i<=sqrtN;i++){
        if(isPrime(i)){
            for(int j=i*i;j<=N;j+=i)
                changeCheck(j);
        }
    }
}

int main(){
    scanf("%d %d",&M,&N);
    eratosthenes();
    for(int i=M;i<=N;i++){
        if(isPrime(i)) printf("%d\n",i);
    }
    return 0;
}