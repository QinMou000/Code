# sum = 0
# for x in range(101):
#     sum += 1
# print(sum)


# sum = 0
# for x in range(2, 101, 2): 
#     if x % 2 == 0:
#         sum += 1
# print(sum) 

# 猜数字

# import random
# answer = random.randint(1, 100)
# counter = 0
# while True:
#     counter += 1
#     num = int(input("请输入："))
#     if num > answer:
#         print("猜大了")
#     elif num < answer:
#         print("猜小了")
#     else:
#         print("猜中了")
#         break
# print("你用了%d次猜中了数字%d"%(counter,answer))


# for i in range(1, 10):
#     for j in range(1, i + 1):
#         print("%d * %d = %d"%(j, i, i * j), end = "\t")
#     print()


# 打印三角形图案
row = int(input("输入行数："))
for i in range(row):
    for _ in range(i + 1):
        print("*",end = " ")
    print()
for i in range(row):
    for j in range(row):
        if j < row - i - 1:
            print(" ",end = " ")
        else:
            print("*",end = " ")
    print()
for i in range(row):
    for _ in range(row - i - 1):
        print(" ",end = " ")
    for _ in range(2 * i + 1):
        print("*",end = " ")
    print()

# 输入两个正整数计算它们的最大公约数和最小公倍数
x = int(input('x = '))
y = int(input('y = '))
# 如果x大于y就交换x和y的值
if x > y:
    # 通过下面的操作将y的值赋给x, 将x的值赋给y
    x, y = y, x
# 从两个数中较小的数开始做递减的循环
for factor in range(x, 0, -1):
    if x % factor == 0 and y % factor == 0:
        print('%d和%d的最大公约数是%d' % (x, y, factor))
        print('%d和%d的最小公倍数是%d' % (x, y, x * y // factor))
        break

# 判断素数
from math import sqrt

def is_pirme(num):
    end = int(sqrt(num))
    is_prime = True
    if num == 1:
        is_pirme = False
    for i in range(2, end + 1):
        if num % i == 0:
            is_prime = False
            break
    return is_prime

num = int(input("输入一个正整数："))
print(is_pirme(num))