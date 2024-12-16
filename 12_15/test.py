
# 函数
def calcsum(begin, end):
    sum = 0
    for i in range(begin, end + 1):
        sum += i
    return sum

print(calcsum(0,100))

# 列表,元组

list1 = [1,2,3,4,5]
print(list1[0])
print(list1)
print(list1[-1])

print(list1[1:4])
print(list1[1:-1])

print(list1[::2])
print(list1[::3])

print(list1[::-1]) # 反向迭代器
print(list1[::-2])

list1.append("hello")

# 查找
print(9 in list1)
print(1 in list1)

# 返回下标
print(list1.index(2))
# print(list1.index(10)) # 抛异常

# 删除元素
list1.pop()
list1.pop(2)
list1.remove(4)
print(list1)

list2 = [7, 9, 11]
List = list1 + list2
print(List)

list1.extend(list2)
print(list1)
print(list2)

# 元组和列表语法差不多，元组里的元素在定义时就定好了不能修改