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
int selectedLine[MAX];
int selectedNum;
int DP[MAX];

bool isSelected(int number){
    for(int i=0;i<selectedNum;i++){
        if(selectedLine[i]==number) return true;
    }
    return false;
}

bool isCrossed(){
    int current = 0;
    for(int i=0;i<=N;i++){
        if(!isSelected(inData[i].first)){
            if(current>inData[i].second) return true;
            current = inData[i].second;
        }
    }
    return false;
}

int getMin(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

int getResult(int n){
    if(n>N){
        if(!isCrossed()) return 0;
        else return INF;
    }
    
    int& ret = DP[n];
    if(ret!=-1) return ret;
    ret = INF;
    
    selectedLine[selectedNum++] = n;
    for(int next=n+1;next<=N+1;next++){
        ret = getMin(ret,getResult(next));
    }

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    inData.push_back(make_pair(0,0));
    for(int n=0;n<N;n++){
        int A,B;
        scanf("%d %d",&A,&B);
        inData.push_back(make_pair(A,B));
    }
    sort(inData.begin(),inData.end());
    for(int i=0;i<=N;i++) DP[i] = -1;
    printf("%d\n",getResult(0));
    return 0;
}