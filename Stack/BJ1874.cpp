// BJ1874 : https://www.acmicpc.net/problem/1874
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100050;

char result[MAX*2];
vector <int> input;
vector <int> sortedInput;
vector <int> stack;

// sorting된 array를 받아서 push와 pop을 이용해서 해당 수열을 만드는게 가능한지 확인하는 함수.
// index에 해당하는 숫자보다 작거나 같은 수 이면 push 아니면 pop
int getResult(int sizeArr){
    int resultIdx = 0;
    int inputIdx = 0;

    for(int i=0;i<sizeArr;i++){
        while(input[i]>=sortedInput[inputIdx] && inputIdx<sizeArr){
            stack.push_back(sortedInput[inputIdx]);
            result[resultIdx] = '+';
            resultIdx++;
            inputIdx++;
        }
        
        int tempValue;
        if(stack.empty()==1) return 0;
        else{
            tempValue = stack.back();
            stack.pop_back();
            if(tempValue==input[i]){
                result[resultIdx] = '-';
                resultIdx++;
            }else{
                return 0;
            }
        }
    }

    result[resultIdx] = '0';
    return resultIdx;
}

int main(){
    int N;
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        int num;
        scanf("%d",&num);
        input.push_back(num);
        sortedInput.push_back(num);
    }
    
    sort(sortedInput.begin(),sortedInput.end());

    if(getResult(N)==0) printf("NO\n");
    else{
        int index = 0;
        while(result[index]!='0'){
            printf("%c\n",result[index]);
            index++;
        }
    }

    return 0;
}
