visited = []

def dfs(i, n, computers):
    global visited
    visited[i] = 1
    for j in range(n):
        if computers[i][j] == 1 and visited[j] == 0:
            dfs(j, n, computers)
    return
        
def solution(n, computers):
    answer = 0
    global visited
    visited = [0] * n
    for i in range(n):
        if visited[i] == 0:
            answer += 1
            dfs(i, n, computers)
    return answer