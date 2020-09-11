def dfs(numbers, target, i, ans):
    if (i == len(numbers)):
        if (sum(numbers) == target):
            ans += 1
        return ans
    else:
        ans = dfs(numbers, target, i+1, ans)
        numbers[i] *= -1
        ans = dfs(numbers, target, i+1, ans)
    return ans

def solution(numbers, target):
    answer = dfs(numbers, target, 0, 0)
    return answer