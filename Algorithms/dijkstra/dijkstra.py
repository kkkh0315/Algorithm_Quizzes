INF = float('inf')

distance_map = [[0, 2, 5, 1, INF, INF],
                [2, 0, 3, 2, INF, INF],
                [5, 3, 0, 3, 1, 5],
                [1, 2, 3, 0, 1, INF],
                [INF, INF, 1, 1, 0, 2],
                [INF, INF, 5, INF, 2, 0]]

visited = [False] * 6
distance = [0] * 6


def get_min_index():
    global visited, distance
    index = 0
    min_ = INF
    for i, d in enumerate(distance):
        if d < min_ and not visited[i]:
            min_ = d
            index = i
    return index


def dijkstra(start):
    global visited, distance
    start -= 1
    points = len(distance_map)

    distance = distance_map[start]

    visited[start] = True

    for i in range(points - 2):
        cur = get_min_index()
        visited[cur] = True
        for j in range(points):
            if not visited[j]:
                if distance[cur] + distance_map[cur][j] < distance[j]:
                    distance[j] = distance[cur] + distance_map[cur][j]
    return distance


print(dijkstra(1))
