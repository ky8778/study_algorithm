//! 2020.02.18
// TODO AS_JLIS (Joined Longest Increasing Subsequence)
#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 105;
int numN[MAX];
int numM[MAX];
int C,N,M;

void getSubset(int start,vector<int>& subN){
    for(int s=start+1;s<N;s++){
        
    }
}

void getResult(){

}

int main(){
    scanf("%d",&C);
    for(int c=0;c<C;c++){
        scanf("%d %d",&N,&M);
        for(int n=0;n<N;n++) scanf("%d",&numN[n]);
        for(int m=0;m<M;m++) scanf("%d",&numM[m]);
        getResult();
    }
    return 0;
}