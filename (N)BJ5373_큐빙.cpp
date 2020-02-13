//! 2020.02.13

// TODO BJ5373_큐빙

#include<cstdio>

#include<deque>

using namespace std;

 

const int MAX = 10;

const char box[6] = { 'U','D','F','B','L','R' };

const char color[6] = { 'w','y','r','o','g','b' };

char myCube[6][3][3];		// 0 : 윗면 1 : 아랫면 2 : 앞면 3 : 뒷면 4 : 왼쪽 5 : 오른쪽

char howToTurn[MAX];

int N,T;

int turnIdx[6][4] = { {2,5,3,4},{3,5,2,4},{1,5,0,4},{0,5,1,4}, {1,2,0,3},{1,3,0,2} };

int turnInfo[6][4][2] = { {{0,0},{0,0},{2,2},{0,0}},{{0,0},{2,2},{2,2},{2,0}},{{0,0},{2,0},{2,2},{0,2}},

						{{0,0},{0,2},{2,2},{2,0}},{{2,0},{2,0},{2,0},{2,0}},{{0,2},{0,2},{0,2},{0,2}} };

int blockIdx[2][2][3][2] = {{{{0,0},{0,1},{0,2}},{{0,2},{1,2},{2,2}}},

								{{{2,0},{1,0},{0,0}},{{2,2},{2,1},{2,0}}}};

deque <char> myDeq;

 

void resetCube() {

	for (int d = 0; d < 6; d++) {

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				myCube[d][i][j] = color[d];

			}

		}

	}

}

 

 

void turnCube(int num, char d) {

	int tmpCube[3][3];

 

	if (d == '+') {

		for (int i = 0; i < 3; i++) {

			char tmp = myDeq.front();

			myDeq.pop_front();

			myDeq.push_back(tmp);

			for (int j = 0; j < 3; j++) {

				tmpCube[i][j] = myCube[num][i][j];

			}

		}

		for (int i = 0; i < 3; i++) myCube[num][i][2] = tmpCube[0][i];

		for (int i = 0; i < 3; i++) myCube[num][i][0] = tmpCube[2][i];

		myCube[num][0][1] = tmpCube[1][0];

		myCube[num][2][1] = tmpCube[1][2];

	}

	else if (d == '-') {

		for (int i = 0; i < 3; i++) {

			char tmp = myDeq.back();

			myDeq.pop_back();

			myDeq.push_front(tmp);

			for (int j = 0; j < 3; j++) {

				tmpCube[i][j] = myCube[num][i][j];

			}

		}

		for (int i = 0; i < 3; i++) myCube[num][2-i][0] = tmpCube[0][i];

		for (int i = 0; i < 3; i++) myCube[num][2-i][2] = tmpCube[2][i];

		myCube[num][0][1] = tmpCube[1][2];

		myCube[num][2][1] = tmpCube[1][0];

	}

}

 

void doNext(char num,char dir) {

	int boxIdx=-1;

	for (int i = 0; i < 6; i++) {

		if (num == box[i]) {

			boxIdx = i;

			break;

		}

	}

 

	for(int i=0;i<4;i++){

		int idx = turnIdx[boxIdx][i];

		int r = turnInfo[boxIdx][i][0];

		int c = turnInfo[boxIdx][i][1];

		for (int j = 0; j < 3; j++) {

			int y = blockIdx[r / 2][c / 2][j][0];

			int x = blockIdx[r / 2][c / 2][j][1];

			myDeq.push_back(myCube[idx][y][x]);

		}

	}

	turnCube(boxIdx,dir);

 

	int cnt = 0;

	for (int i = 0; i < 4; i++) {

		int idx = turnIdx[boxIdx][i];

		int r = turnInfo[boxIdx][i][0];

		int c = turnInfo[boxIdx][i][1];

		for (int j = 0; j < 3; j++) {

			int y = blockIdx[r / 2][c / 2][j][0];

			int x = blockIdx[r / 2][c / 2][j][1];

			myCube[idx][y][x] = myDeq[i*3+j];

		}

	}

	deque <char> empty;

	empty.swap(myDeq);

}

 

int main() {

	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {

		scanf("%d", &N);

		resetCube();

		for (int n = 0; n < N; n++) {

			scanf("%s", howToTurn);

			//printf("%s\n", howToTurn);

			doNext(howToTurn[0], howToTurn[1]);

		}

		//for(int n=0;n<6;n++){

		for(int i=0;i<3;i++){

			for (int j = 0; j < 3; j++) {

				printf("%c", myCube[0][i][j]);

			}

			printf("\n");

		}

		//}

	}

	return 0;

}