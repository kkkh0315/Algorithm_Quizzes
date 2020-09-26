# 미로 찾기 프로그램(그래프 탐색)
# 입력: 미로 정보 g, 출발점 start, 도착점 end
# 출력: 미로를 나가기 위한 이동 경로는 문자열, 나갈 수 없는 미로면 물음표("?")

def solve_maze(maze, start, end):
    queue = []
    routes = set()

    queue.append(start)
    routes.add(start)

    while queue:
        route = queue.pop(0)
        last_in_route = route[-1]
        if last_in_route == end:
            return route
        for p in maze[last_in_route]:
            if p not in routes:
                queue.append(route + p)
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

