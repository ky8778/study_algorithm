#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = board[0].size();
    
    vector <int> myS;
    int top = -1;
    
    for(int i = 0 ; i < moves.size() ; i++){
        int idx = moves[i] - 1;
        for(int j=0;j < N;j++){
            if(board[j][idx]!=0){
                if(top>=0 && myS[top]==board[j][idx]){
                    myS.pop_back();
                    top--;
                    answer+=2;
                }else{
                    myS.push_back(board[j][idx]);
                    top++;
                }
                board[j][idx] = 0;
                break;
            }
        }
    }
    
    return answer;
}