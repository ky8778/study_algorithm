//! 2020.03.16
// TODO BJ2565_전깃줄
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 505;
const int INF = 987654321;
int N;
vector <pair<int,int>> inData;
int DP[MAX];

int getMax(int number){
    int ret = 0;
    for(int i=1;i<number;i++){
        if(ret<DP[i]) ret = DP[i];
    }
    return ret;
}

int getResult(){
    int maxLen = -1;
    for(int i=0;i<N;i++) DP[inData[i].second] = getMax(inData[i].second)+1;
    for(int i=0;i<N;i++){
        if(maxLen<DP[inData[i].second]) maxLen = DP[inData[i].second];
        // printf("number : %d, DP : %d\n",inData[i].second,DP[inData[i].second]);
    }
    return N-maxLen;   
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        int A,B;
        scanf("%d %d",&A,&B);
        inData.push_back(make_pair(A,B));
    }
    sort(inData.begin(),inData.end());
    for(int i=0;i<=N;i++) DP[i] = -1;
    printf("%d\n",getResult());
    return 0;
}