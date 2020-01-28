
//! 20200128
// TODO Divide & Conquer
// AS_QUADTREE : https://www.algospot.com/judge/problem/read/QUADTREE

#include<cstdio>
#include<string>

using namespace std;

int N;
const int MAX = 50;

string getResult(int& index,char* input){
    string ret;
    if(input[index]=='x'){
        string tmp[4];
        for(int cnt = 0;cnt<4;cnt++){
            index++;
            tmp[cnt] = getResult(index,input);
        }
        for(int i=0;i<tmp[2].size();i++){
            ret.push_back(tmp[2][i]);
        }
        for(int i=0;i<tmp[3].size();i++){
            ret.push_back(tmp[3][i]);
        }
        for(int i=0;i<tmp[0].size();i++){
            ret.push_back(tmp[0][i]);
        }
        for(int i=0;i<tmp[1].size();i++){
            ret.push_back(tmp[1][i]);
        }
        return ret;
    }else{
        ret.push_back(input[index]);
        index++;
        return ret;
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char input[MAX];
        string output;
        scanf("%s",input);
        int idx = 0;
        output = getResult(idx,input);
        printf("%s\n",output.c_str());
    }
    return 0;
}