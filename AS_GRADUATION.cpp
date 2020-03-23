//! 2020.03.23
// TODO AS_GRADUATION
#include<cstdio>

using namespace std;

const int INF = 987654321;
const int MAX = 15;
int T,N,K,M,L;

int getSetSize(int set){
    int cnt = 0;
    for(int i=0;i<M;i++){
        if(set&(1<<i)) cnt++;
    }
    return cnt;
}

int getMin(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

//! need to complete
// 휴학하지 않을 학기를 선택했을 때 그 경우의 수에서 졸업요건을 만족하는지 확인하는 함수.
bool isPossible(int set){
    for(int i=0;i<M;i++){
        if(set&(1<<i)){

        }
    }
}

// 다니는 학기 수의 모든 조합을 뽑는 함수
int getResult(){
    int minSize = INF;
    for(int set=1;set<(1<<M);set++){
        printf("%d\n",getSetSize(set));
        if(isPossible(set)) minSize = getMin(minSize,getSetSize(set));
    }
    return minSize;
}

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d %d %d",&N,&K,&M,&L);
        int result = getResult();
        if(result>=INF) printf("IMPOSSIBLE\n");
        else printf("%d\n",result);
    }
    return 0;
}