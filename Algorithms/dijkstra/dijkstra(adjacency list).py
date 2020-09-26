import heapq

INF = float('inf')
distance_map = {
    1: {2: 2, 3: 5, 4: 1},
    2: {1: 2, 3: 3, 4: 2},
    3: {1: 5, 2: 3, 4: 3, 5: 1, 6: 5},
    4: {1: 1, 2: 2, 3: 3, 5: 1},
    5: {3: 1, 4: 1, 6: 2},
    6: {3: 5, 5: 2}
}


def dijkstra(start):
    global distance_map
    distances = {node: INF for node in distance_map}
    distances[start] = 0
    pri_queue = []
    heapq.heappush(pri_queue, [distances[start], start])

    while pri_queue:
        cur_distance, cur_node = heapq.heappop(pri_queue)
        if distances[cur_node] < cur_distance:
            continue
        for adj, cost in distance_map[cur_node].items():
            new_distance = cur_distance + cost
            if new_distance < distances[adj]:
                distances[adj] = new_distance
                heapq.heappush(pri_queue, [new_distance, adj])
    return distances


print(dijkstra(1))
