"""
주어진 인접행렬에서, Prim 알고리즘을 통해 최소 신장 트리를 구한다.

입력: 인접 행렬, 시작 정점
출력: 시작 정점에서 만든 최소 신장 트리

알고리즘:
1. dist 배열을 INF로 초기화
2. dist[start] = 0
3. 우선 순위 큐 queue에 모든 정점 삽입(우선 순위는 dist[])
4. i는 0부터 n-1까지 반복
    1). u에 weight가 가장 작은 간선 삽입
    2). u의 인접 정점들인 v를 반복
        v가 Q의 원소이고, weight[u][v] < dist[v]라면
            dist[v]에 weight[u][v]를 할당

설명:
0. 프림 알고리즘은 시작 정점을 최초의 신장 트리로 놓는다.
1. 시작 정점만이 포함된 신장 트리에서, 더 포함시킬 수 있는 노드들을 찾아놓는다.
2. 더 포함시킬수 있는 노드 중, 비용(가중치)가 가장 작은 노드를 포함시킨다.
3. 2에서 포함된 정점에서 가장 낮은 비용으로 도달할 수 있는 노드를 찾아서, 
	그 노드를 신장 트리에 포함시킨다.
"""

INF = 999
adj_mat = [[0, 29, INF, INF, INF, 10, INF],
           [29, 0, 16, INF, INF, INF, 15],
           [INF, 16, 0, 12, INF, INF, INF],
           [INF, INF, 12, 0, 22, INF, 18],
           [INF, INF, INF, 22, 0, 27, 25],
           [10, INF, INF, INF, 27, 0, INF],
           [INF, 15, INF, 18, 25, INF, 0]]

node_num = len(adj_mat)
visited = [False] * node_num
distances = [INF] * node_num


"""
get_min_node 메소드
1. i가 0부터 node 갯수만큼 반복한다.
    i 노드가 방문한 적 없는 노드라면, 
        v에 i를 저장한다. 
        멈춘다. 
    
2. i가 0부터 node_num 만큼 반복한다.
        i가 방문하지 않았고, 방금 저장한 v보다 비용이 작은(기존의 신장트리로부터의 거리가 작은) 
        노드 i를 발견한다면
            v에 i를 덮어쓴다. 
    
    v를 리턴한다. 
"""


def get_min_node(node_num):
    print("get_min_node 함수 진입했다")
    for i in range(node_num):
        if not visited[i]:
            v = i
            break
    print("아직 방문하지 않은 v: ", v)
    for i in range(node_num):
        if not visited[i] and distances[i] < distances[v]:
            print("i: ", i, "\tv: ", v)
            print("distaces[i], distances[v]: ", distances[i], distances[v])
            v = i
            print("아직 방문 안됐고, 기존 v보다 distances값 작은 정점 발견 교체, 최종 v: ", v)

    return v


def prim(start, node_num):
    # distances 배열과 visted 배열 초기화
    for i in range(node_num):
        visited[i] = False
        distances[i] = INF

    # 시작노드의 distance 값을 0으로 초기화
    distances[start] = 0
    for i in range(node_num):
        print("--------------------")
        print("prim 메소드 내부 반복 시작, 반복 회차: ", i)
        node = get_min_node(node_num)
        visited[node] = True    # node 를 방문했다 표시
        print("\nget_min_node 에서 선택된 노드: ", node)

        for j in range(node_num):
            if adj_mat[node][j] != INF:
                if not visited[j] and adj_mat[node][j] < distances[j]:
                    print("방금 포함된 ", node, "와 연결되어있고, "
                                           "아직 방문하지 않았으며, "
                                           "기존의 신장트리로부터의 거리보다 작은 경로가 발견되어, "
                                           "distances[j]의 값을 갱신해야 하는 j: ", j)
                    distances[j] = adj_mat[node][j]

        print("distances: ", distances)
        print("--------------------")


print(prim(0, node_num))
print("distances: ", distances)
print("minimum cost: ", sum(distances))