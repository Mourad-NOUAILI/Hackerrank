N= input()
num = map(int,raw_input().split())
val = [0] * 1001
for i in num:
    val[i] += 1
counter = N

ans = [N]
for i in val:
    if i > 0:
        counter -= i
        ans.append(counter)

# This removes the last element from the result
# If the input array were empty, removes the value N
# If not, then removes the value 0
ans.pop()

for i in ans:
    print i
