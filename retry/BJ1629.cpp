
//! 20200129
//! Can solve just with Divide&Conquer
// TODO Divide & Conquer + DP
// BJ1629 : https://www.acmicpc.net/problem/1629
#include<cstdio>

using namespace std;

const int MAX = 10000000;
long long A,B,C;
int DP[MAX];
bool check[MAX];

int square(long long inA,long long inC,long long size){
    // printf("size : %d\n",size);
    if(size < MAX && check[size]) return DP[size]; 
    else{
        if(size==1){
            check[size] = true;
            return DP[size] = inA%inC;
        }else{
            long long tmp = square(inA,inC,size/2)%inC;
            
            if(size%2==0){
                tmp*=tmp;
            }
            else{
                tmp*=tmp;
                tmp%=inC;
                tmp*=inA;
            }

            int result = tmp%inC;
            if(size < MAX){
                check[size] = true;
                return DP[size] = result;
            }else{
                return result;
            }
        }
    }
}

int main(){
    scanf("%lld %lld %lld",&A,&B,&C);
    int result = square(A,C,B);
    printf("%d\n",result);
    return 0;
}