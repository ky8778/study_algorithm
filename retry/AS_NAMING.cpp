//! 2020.04.08 ~ 09
// TODO KMP https://www.algospot.com/judge/problem/read/NAMING
#include<iostream>
#include<string>
#include<vector>

using namespace std;
string S;

vector<int> getPartialMatch(const string& s){
    int size_S = s.size();
    vector<int> ret(size_S,0);
    int start = 1, matched = 0;
    while(start + matched < size_S){
        if(s[start + matched] == s[matched]){
            matched++;
            ret[start + matched - 1] = matched;
        }else{
            if(matched == 0) start++;
            else{
                start += matched - ret[matched - 1];
                matched = ret[matched - 1];
            }
        }
    }
    return ret;
}

vector<int> KMP(const string& inS){
    int size_S = inS.size();
    vector<int> ret;
    vector<int> pi_table = getPartialMatch(inS);
    int start = 0, matched = 0;
    while(start <= size_S - 1){
        if(matched < size_S && inS[start + matched] == inS[matched]){
            matched++;
        }else{
            if(matched==0) start++;
            else{
                start += matched - pi_table[matched-1];
                matched = pi_table[matched-1]; 
            }
        }
        // printf("start : %d, matched : %d\n",start,matched);
        if(matched == size_S - start && matched != 0) ret.push_back(matched);
    }
    return ret;
}

int main(){
    string S1,S2;
    getline(cin,S1);
    getline(cin,S2);
    S+=S1;
    S+=S2;
    
    // cout << S << endl;
    vector<int> result = KMP(S);
    
    for(int i = result.size() - 1; i >= 0 ; i--){
        printf("%d ",result[i]);
    }
    printf("\n");

    return 0;
}