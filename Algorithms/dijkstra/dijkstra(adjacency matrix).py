# 다익스트라 알고리즘 (인접 행렬 활용)
# 입력: (그래프 정보(전역 변수)), 출발 노드 start
# 출력: 다른 모든 노드로의 최소 비용을 저장한 리스트

INF = float('inf')
distance_map = [[0, 2, 5, 1, INF, INF],         # 인접 행렬 형태의 그래프 정보
                [2, 0, 3, 2, INF, INF],
                [5, 3, 0, 3, 1, 5],
                [1, 2, 3, 0, 1, INF],
                [INF, INF, 1, 1, 0, 2],
                [INF, INF, 5, INF, 2, 0]]


def get_min_index(visit, cost):                      # 최소 비용들이 저장된 리스트에서 방문하지 않은 최솟값의 인덱스 구하기 
    index = 0
    min_ = INF
    for i, c in enumerate(cost):
        if c < min_ and not vi[i]:
            min_ = c
            index = i
    return index


def dijkstra(start):
    visited = [False] * 6                       # 방문 여부 저장 리스트
    costs = [0] * 6                             # 최소 비용 저장 리스트
    start -= 1                                  # 입력값은 출발 노드, 리스트에서 해당 노트를 탐색할 땐 인덱스로 탐색하기 때문에 1을 빼줌
    points = len(distance_map)                  # 노드의 갯수 points 변수에 저장

    costs = distance_map[start]                 # 출발 노드에서 모든 다른 노드들로의 이동 비용을 최소 비용 저장 리스트에 저장

    visited[start] = True                       # 출발 노드 방문

    for i in range(points - 2):                 # 출발 노드와 마지막 남은 노드는 탐색 불필요. 따라서 'points - 2'만큼 반복
        cur = get_min_index(visited, costs)     # 최소 비용들이 저장된 리스트에서 현재 방문하지 않은 최솟값의 인덱스 저장
        visited[cur] = True                     # 해당 노드 방문
        for j in range(points):                 # 다른 모든 노드들을 대상으로 탐색하되
            if not visited[j]:                  # 방문하지 않은 노드만 탐색
                if costs[cur] + distance_map[cur][j] < costs[j]:  # 해당 노드까지의 최소 비용과 해당 노드에서 인접 노드까지의 비용의 합산이 인접 노드까지의 현재 최소 비용보다 작다면
                    costs[j] = costs[cur] + distance_map[cur][j]  # 최소 비용을 전자로 갱신
    return costs


print(dijkstra(1))
