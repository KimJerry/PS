# boj_1439
N = int(input())
arr = [int(input()) for _ in range(N)]

length = len(arr)

ans = 0
for i in range(2, length+1):
    if arr[-i] >= arr[1-i]:
        ans += arr[-i] - arr[1-i] + 1
        arr[-i] = arr[1-i] - 1
print(ans)
