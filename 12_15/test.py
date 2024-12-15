def calcsum(begin, end):
    sum = 0
    for i in range(begin, end + 1):
        sum += i
    return sum

print(clacsum(0,100))