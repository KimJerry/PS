# boj_1744
N = int(input())
array = [int(input()) for _ in range(N)]
array.sort()

result = 0
length = len(array)

flag = False
idx = 0
for i in range(length):
    if flag:
        flag = False
        continue
    if array[i] > 0:
        idx = i
        break
    if i == length-1:
        result += array[i]
        break
    if array[i+1] > 0:
        result += array[i]
        idx = i+1
        break
    result += array[i]*array[i+1]
    flag = True

flag = False
for i in range(1, length+1):
    if flag:
        flag = False
        continue
    if array[-i] < 0:
        break
    if i == length or length-i == idx:
        result += array[-i]
        break
    if array[-i] == 1 or array[-1-i] == 1:
        result += array[-i]
    else:
        result += array[-i]*array[-i-1]
        flag = True

print(result)
