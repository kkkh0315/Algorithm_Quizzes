# 미로 찾기 프로그램(그래프 탐색)
# 입력: 미로 정보 g, 출발점 start, 도착점 end
# 출력: 미로를 나가기 위한 이동 경로는 문자열, 나갈 수 없는 미로면 "Route not found." 출력

def solve_maze(maze, start, end):
    queue = []                  # 현재까지 탐색된 루트를 문자열로 큐에 저장.
    visited = set()             # 집합 자료형. 방문한 꼭지점을 저장. 중복 방지.

    queue.append(start)
    visited.add(start)

    while queue:
        route = queue.pop(0)
        last_in_route = route[-1]
        if last_in_route == end:
            return route
        for p in maze[last_in_route]:
            if p not in routes:
                queue.append(route + p)
                visited.add(p)
    return "Route not found."


maze_info = {
    'a': ['e'],
    'b': ['c', 'f'],
    'c': ['b', 'd'],
    'd': ['c'],
    'e': ['a', 'i'],
    'f': ['b', 'g', 'j'],
    'g': ['f', 'h'],
    'h': ['g', 'l'],
    'i': ['e', 'm'],
    'j': ['f', 'k', 'n'],
    'k': ['j', 'o'],
    'l': ['h', 'p'],
    'm': ['i', 'n'],
    'n': ['m', 'j'],
    'o': ['k'],
    'p': ['l']
}

print(solve_maze(maze_info, 'a', 'p'))

출처: https://stricky.tistory.com/213

