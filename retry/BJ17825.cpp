
//! 2020.02.05
// TODO BJ17825 : https://www.acmicpc.net/problem/17825

#include<cstdio>

using namespace std;

int inData[15];
int inMap[4][25] = {
    {1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,100,100,100,100},
    {10,13,16,19,25,30,35,40,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100},
    {20,22,24,25,30,35,40,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100},
    {30,28,27,26,25,30,35,40,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100}
};
int dir[4];
int posi[4];
bool check[4];
int maxResult = -1;

int move(int dist,int horse){
    int curDir = dir[horse];
    int curPosi = posi[horse];
    curPosi += dist;
    if(curDir==0){
        if(curPosi>=21){
            curPosi = 21;
            check[horse] = true;
        }else if(inMap[0][curPosi] == 10){
            curPosi = 0;
            curDir = 1;
        }else if(inMap[0][curPosi] == 20){
            curPosi = 0;
            curDir = 2;
        }else if(inMap[0][curPosi] == 30){
            curPosi = 0;
            curDir = 3;
        }
    }else{
        if((curDir==1||curDir==3) && curPosi>=8){
            curPosi = 8;
            check[horse] = true;
        }else if(curDir==2 && curPosi >= 7){
            curPosi = 7;
            check[horse] = true;
        }
    }
    posi[horse] = curPosi;
    dir[horse] = curDir;
    if(inMap[curDir][curPosi]==100) return 0;

    for(int i=0;i<4;i++){
        if(i==horse) continue;
        int tmp1 = inMap[curDir][curPosi];
        int tmp2 = inMap[dir[i]][posi[i]];
        if(curDir==dir[i] && curPosi==posi[i]){
            return -1;
        }else if(tmp1==tmp2){
            if(tmp1 == 25 || tmp1 == 35 || tmp1 == 40){
                return -1;
            }else if(tmp1 == 30 && curPosi!=0 && posi[i]!=0){
                return -1;
            }
        }
    }

    return inMap[curDir][curPosi];
}

void getResult(int dataIdx,int score){
    // printf("dataIdx : %d\n",dataIdx);
    if(dataIdx>=10){
        if(score > maxResult){
            // for(int i=0;i<4;i++)
            //     printf("score : %d, horse : %d %d %d %d\n",score,inMap[dir[i]][posi[i]]);
            maxResult = score;
        }
        return;
    }else{
        for(int i=0;i<4;i++){
            if(!check[i]){
                int tmpPosi = posi[i];
                int tmpDir = dir[i];
                bool tmpCheck = check[i];
                int next = move(inData[dataIdx],i);
                if(next != -1){
                    getResult(dataIdx+1,score+next);
                }
                dir[i] = tmpDir;
                posi[i] = tmpPosi;
                check[i] = tmpCheck;
            }
        }
    }
}

int main(){
    for(int i=0;i<10;i++){
        scanf("%d",&inData[i]);
    }
    
    getResult(0,0);
    printf("%d\n",maxResult);
    return 0;
}