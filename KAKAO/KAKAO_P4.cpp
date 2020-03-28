#include <string>
#include <vector>

using namespace std;

long long getResult(long long i){
    
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++){
        long long idx = room_number[i];
        long long room_num = getResult(idx);
        answer.push_back(room_num);
    }
    return answer;
}