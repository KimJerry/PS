# boj_11501
T = int(input())
while T != 0:
    day = int(input())
    cost = list(map(int, input().split()))

    n = len(cost)
    max_val = cost[-1]
    max_arr = list()
    for i in range(1, n+1):
        if max_val < cost[-i]:
            max_val = cost[-i]
        max_arr.append(max_val)
    max_arr.reverse()

    result = 0
    stock = list()
    for i in range(n):
        if cost[i] == max_arr[i]:
            result += sum(map(lambda x: cost[i]-x, stock))
            stock.clear()
        else:
            stock.append(cost[i])
    print(result)
    T -= 1
