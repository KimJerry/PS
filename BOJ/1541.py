array = input().split("-")
result = [i.split("+") for i in array]
array.clear()

for i in result:
    array.append(sum(list(map(int, i))))

print(array[0] - sum(array[1:]))
