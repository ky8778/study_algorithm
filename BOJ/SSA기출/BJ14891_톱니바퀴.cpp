
//! 2020.02.05
// TODO BJ14891 : acmicpc.net/problem/14891
#include<cstdio>
#include<deque>
#include<vector>

using namespace std;

const int MAX = 105;
const int CLOCK = 1;
const int reClock = -1;
const int S = 1;
const int N = 0;
int K;
deque <int> inData[5];
pair<int,int> rotInfo[MAX];
int rot[5];

void getStatus(int idx,int dir){
    for(int i=0;i<4;i++){
        rot[i] = 0;
    }
    rot[idx] = dir;
    for(int i=idx;i<3;i++){
        if(inData[i][2]!=inData[i+1][6]){
            rot[i+1] = -rot[i];
        }else{
            break;
        }
    }
    for(int i=idx;i>=1;i--){
        if(inData[i][6]!=inData[i-1][2]){
            rot[i-1] = -rot[i];
        }else{
            break;        
        }
    }
}

void rotating(){
    for(int i=0;i<4;i++){
        if(rot[i]==CLOCK){
            int tmp = inData[i].back();
            inData[i].pop_back();
            inData[i].push_front(tmp);
        }else if(rot[i]==reClock){
            int tmp = inData[i].front();
            inData[i].pop_front();
            inData[i].push_back(tmp);
        }
    }
}

int getResult(){
    int ret = 0;

    for(int k=0;k<K;k++){
        int number = rotInfo[k].first;
        int dir = rotInfo[k].second;
        getStatus(number,dir);
        // printf("kth : %d\n",k);
        // for(int i=0;i<4;i++){
        //     printf("%d ",rot[i]);
        // }
        // printf("\n");
        rotating();
        // printf("current\n");
        // for(int i=0;i<4;i++){
        //     for(int j=0;j<8;j++){
        //         printf("%d ",inData[i][j]);
        //     }
        //     printf("\n");
        // }
    }
    
    for(int i=0;i<4;i++){
        // printf("1<<i : %d\n",1<<i);
        if(inData[i].front()==S) ret+=(1<<i);
        // printf("ret : %d\n",ret);
    }
    return ret;
}

int main(){
    for(int i=0;i<4;i++){
        char tmp[10];
        scanf("%s",tmp);
        for(int j=0;j<8;j++){
            inData[i].push_back(tmp[j]-'0');
        }
    }
    scanf("%d",&K);
    for(int k=0;k<K;k++){
        int a,b;
        scanf("%d %d",&a,&b);
        rotInfo[k] = make_pair(a-1,b);
    }

    printf("%d\n",getResult());
    return 0;
}