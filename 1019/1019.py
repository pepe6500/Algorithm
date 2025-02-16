inputNum = int(input())
n = inputNum
s = 1
p = 1
sum = []
for i in range(10):
    sum.append(0)

while n > 0:
    if n <= 9:
        for i in range (1, n+1):
            sum[i] += 1 * p
        break
    
    for i in range (1, 10):
        sum[i] += p
    s = 10

    while n % 10 != 9:
        x = n
        while x > 0:
            sum[x % 10] += p
            x = int(x / 10)
        n -= 1
    
    addCount = int(n / 10) * p
    for i in range (0, 10):
        sum[i] += addCount
    
    p *= 10
    n = int(n / 10)

for i in range (0, 10):
    print(sum[i], end="")
    if i != 9:
        print(' ', end="")