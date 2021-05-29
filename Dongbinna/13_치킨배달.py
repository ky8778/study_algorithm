# 2021.03.07 치킨배달
# 삼성전자 SW 역량테스트
# https://www.acmicpc.net/problem/15686

''' 풀이
1. 집과 치킨집 pair 모두를 탐색하며, 각 집에서 치킨집까지 거리를 기록한다. (2N * 13) = O(26N)
2. 집[] = (거리, 치킨집번호) 로 기록한뒤, sorting 한다. => (2N * 13log13) = O(20N)
=> O(46N)
3. 치킨집 중 M개를 고른다. (Combination) => 2N combination 13
4. 집마다 돌면서 M개 중 최소인 거리를 확인한다. (2N * 13)
'''

import sys
sys.stdin = open('input.txt', 'r')
from itertools import combinations

def getResult(_inMap):
    ret = 987654321
    # map에서 집과 치킨집을 각각 담기
    homeList = []
    storeList = []
    for y in range(N):
        for x in range(N):
            if _inMap[y][x] == 1:
                homeList.append((y, x))
            elif _inMap[y][x] == 2:
                storeList.append((y,x))
    # 1. 집과 치킨집 pair 탐색하며, 각 집에서 치킨집까지 거리 기록.
    distList = [[] for _ in range(len(homeList))]
    for n in range(len(homeList)):
        for m in range(len(storeList)):
            tmp = abs(homeList[n][0] - storeList[m][0]) + abs(homeList[n][1] - storeList[m][1])
            distList[n].append((tmp, m))
    # 2. sorting
    for i in range(len(homeList)):
        distList[i].sort()
        # print('distList : ' + str(distList[i]))
        
    # 3. M개 뽑기
    idxStoreList = [n for n in range(len(storeList))]
    MStoreList = list(combinations(idxStoreList, M))
    # print(MStoreList)
    # 4. 돌면서 M개중 최소거리 더해주기
    for storeSet in MStoreList:
        minDist = 0
        # print('M : ' +str(M))
        for home in range(len(homeList)):
            for dist in distList[home]:
                if dist[1] in storeSet:
                    minDist += dist[0]
                    # print('dist[1] : ' + str(dist[1]))
                    # print('home : ' + str(home) + ' dist : ' + str(dist))
                    break
        # print('minDist : ' + str(minDist))
        ret = min(minDist, ret)
        # print(ret)

    return ret

N, M = map(int, input().split())
inMap = [list(map(int, input().split())) for _ in range(N)]
print(getResult(inMap))