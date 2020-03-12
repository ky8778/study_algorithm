
//! 20200122
// TODO BruteForce
// BJ2580 : https://www.acmicpc.net/problem/2580
#include<cstdio>
#include<vector>
using namespace std;

int N;
int inputMap[15][15];
vector <pair<int,int>> mission;

void checkNum(pair <int,int> point,vector <int> *numList){
    int listNum[10] = {0,};
    int rowPoint = point.first;
    int colPoint = point.second;
    // printf("(%d, %d)\n",rowPoint,colPoint);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int idx = inputMap[rowPoint][i*3+j];
            listNum[idx] = 1;
            // printf("(%d,%d) idx : %d\n",rowPoint,i*3+j,idx);
            
            idx = inputMap[i*3+j][colPoint];
            listNum[idx] = 1;
            // printf("(%d,%d) idx : %d\n",i*3+j,colPoint,idx);
            
            idx = inputMap[(rowPoint/3)*3+i][(colPoint/3)*3+j];
            listNum[idx] = 1;
            // printf("(%d,%d) idx : %d\n",idx);
        }
    }
    for(int n=1;n<=9;n++){
        if(listNum[n]==0){
            // printf("push %d ",n);
            (*numList).push_back(n);
        }
    }
}

bool getResult(int n){
    vector <int> numberList;
    // printf("n : %d ,N : %d\t",n,N);
    if(n>=N) return true;
    else{
        checkNum(mission[n],&numberList);
        int row = mission[n].first;
        int col = mission[n].second;
        for(int i=0;i<numberList.size();i++){
            inputMap[row][col] = numberList[i];
            // printf("inputMap[%d][%d] : %d\n",row,col,inputMap[row][col]);
            // printf("number : %d",numberList[i]);
            if(getResult(n+1)){
                // printf("true!!\n");
                return true;
            }
        }
        // printf("\n");
        inputMap[row][col] = 0;
        return false;
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&inputMap[i][j]);
            if(inputMap[i][j]==0) mission.push_back(make_pair(i,j));
        }
    }

    N = mission.size();
    // printf("N : %d",N);
    getResult(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",inputMap[i][j]);
        }
        printf("\n");
    }

    return 0;
}