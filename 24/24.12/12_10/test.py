
# a = 10
# print(f"a的值为{a}")

# print(2 ** 2) # 2的2次方
# print(2 ** 0.5) # 乘方
# print(2 // 3) # 整除（地板除）

# print(0.1 + 0.2 == 0.3) # 精度在计算机中不准确

# print(0.1 + 0.2) # 输出0.30000000000000004

# # 交换两个变量
# a = 2
# b = 3
# print(a,b)
# a, b = b, a
# print(a,b)


'''
a = 10;
int a = 10
b = true
a = 'aaa' + 10
'''

pass # 空语句，啥也不干

# num = 0
# while num <= 10:
#     print(num,end = '')
#     num += 1
# print()

i = 1
ans = 0
while i in range(1,6):
    ret = 1
    n = 1
    while n <= i:
        ret *= n
        n += 1
    ans += ret
    i += 1
print(ans)

# for i in range(2, 11, 2):
#     print(i,end = "")
# print()

