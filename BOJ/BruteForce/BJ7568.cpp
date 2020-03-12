//! 20200122
// TODO BruteForce
// BJ7568 : https://www.acmicpc.net/problem/7568

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

vector <pair<int,int>> peoples;
vector <int> result;

void getResult(const vector <pair<int,int>> data){
    for(int i=0;i<data.size();i++){
        int cnt = 1;
        for(int j=0;j<data.size();j++){
            if(i==j) continue;
            // printf("i : %d, j : %d\n",i,j);

            if(data[i].first < data[j].first){
                if(data[i].second < data[j].second){
                    cnt++;
                }
            }

        }
        result.push_back(cnt);
    }
}

int main(){
    scanf("%d",&N);
    for(int n=1;n<=N;n++){
        int x,y;
        scanf("%d %d",&x,&y);
        peoples.push_back(make_pair(x,y));
    }
    
    getResult(peoples);
    for(int i=0;i<N;i++){
        printf("%d ",result[i]);
    }

    return 0;
}

