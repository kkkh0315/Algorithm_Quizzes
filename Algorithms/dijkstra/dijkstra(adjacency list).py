# 다익스트라 알고리즘 (인접 리스트와 우선순위 큐 활용)
# 입력: (그래프 정보(전역 변수)), 출발 노드 start
# 출력: 다른 모든 노드로의 최소 비용을 저장한 딕셔너리

import heapq

INF = float('inf')
distance_map = {                # 인접 리스트 형태의 그래프 정보 {departing node: {destination node: cost}}
    1: {2: 2, 3: 5, 4: 1},
    2: {1: 2, 3: 3, 4: 2},
    3: {1: 5, 2: 3, 4: 3, 5: 1, 6: 5},
    4: {1: 1, 2: 2, 3: 3, 5: 1},
    5: {3: 1, 4: 1, 6: 2},
    6: {3: 5, 5: 2}
}


def dijkstra(start):
    global distance_map
    distances = {node: INF for node in distance_map}            # start 노드에서 각 노드들로 가는 최소 비용을 저장할 딕셔너리
    distances[start] = 0                                        # start 인덱스의 값은 0으로 초기화
    pri_queue = []                                              # 탐색 대상을 저장할 우선순위 큐 (최소힙)
    heapq.heappush(pri_queue, [distances[start], start])        # [0, start 노드] 우선순위 큐에 Push

    while pri_queue:                                            # 우선순위 큐가 빌 때까지 반복
        cur_distance, cur_node = heapq.heappop(pri_queue)       # 우선순위 큐에 있는 [최소 비용, 노드] Pop
        if distances[cur_node] < cur_distance:                  # 꺼낸 최소 비용이 기존 최소 비용보다 크다면 탐색 스킵
            continue
        for adj, cost in distance_map[cur_node].items():        # 우선순위 큐에서 꺼낸 노드의 인접 노드들을 대상으로 탐색
            new_distance = cur_distance + cost                  
            if new_distance < distances[adj]:                   # 노드까지의 비용과 그 노드에서 인접 노드까지의 비용 합산이 기존 딕셔너리에 저장된 최소 비용보다 작다면
                distances[adj] = new_distance                   # 새로운 최소 비용 갱신
                heapq.heappush(pri_queue, [new_distance, adj])  # 해당 인접 노드까지의 최소 비용과 노드 우선순위 큐에 Push
    return distances


print(dijkstra(1))
