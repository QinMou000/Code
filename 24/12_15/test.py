
# # 函数
# def calcsum(begin, end):
#     sum = 0
#     for i in range(begin, end + 1):
#         sum += i
#     return sum

# print(calcsum(0,100))

# # 列表,元组

# list1 = [1,2,3,4,5]
# print(list1[0])
# print(list1)
# print(list1[-1])

# print(list1[1:4])
# print(list1[1:-1])

# print(list1[::2])
# print(list1[::3])

# print(list1[::-1]) # 反向迭代器
# print(list1[::-2])

# list1.append("hello")

# # 查找
# print(9 in list1)
# print(1 in list1)

# # 返回下标
# print(list1.index(2))
# # print(list1.index(10)) # 抛异常

# # 删除元素
# list1.pop()
# list1.pop(2)
# list1.remove(4)
# print(list1)

# list2 = [7, 9, 11]
# List = list1 + list2
# print(List)

# list1.extend(list2)
# print(list1)
# print(list2)

# # 元组和列表语法差不多，元组里的元素在定义时就定好了不能修改

# dict = {1:"汪钦",2:"汪如欽"}
# print(dict[1])
# print(2 in dict)

# dict[2] = "汪如丹"
# print(dict)

# # dict.pop(1)
# # dict.pop(2)
# # print(dict)

# for key in dict:
#     print(key,dict[key])

# print(dict.keys())
# print(dict.values())
# print(dict.items())


# # 合法的 key 类型
# # 不是所有的类型都可以作为字典的 key. 
# # 字典本质上是一个 哈希表, 哈希表的 key 要求是 "可哈希的", 也就是可以计算出一个哈希值. 
# # 可以使用 hash 函数计算某个对象的哈希值. 
# # 但凡能够计算出哈希值的类型, 都可以作为字典的 key.
# print(hash(0))
# print(hash(3.14))
# print(hash('hello'))
# print(hash(True))
# print(hash(())) # () 是一个空的元组

# # print(hash([1, 2, 3]))
# # print(hash({'id':1}))

# f = open('d:/test.txt','w')
# f.write("hello world")
# f.close

# f = open('d:/test.txt','r')
# ret = f.read()
# print(ret)
# f.close()

# f = open('d:/test.txt', 'r')
# for line in f:
#     print(f'line = {line}')
# f.close()

import datetime

brith = datetime.datetime(2004,12,21)
now = datetime.datetime(2024,12,18)
print(now - brith)

# def reverse_words(s): # 字符串逆置
#     tokens = s.split() # 以空格拆分字符串，存进列表
#     tokens.reverse() # 对列表进行逆置
#     return ' '.join(tokens) # 用str的join方法拼接字符串，合并列表

# print(reverse_words('i am a student.'))

# def rotate_string(s, goal): # 旋转字符串
#     return len(s) == len(goal) and goal in s + s # 判断goal是否在两个s的拼接字符串里
    
# print(rotate_string('abcde', 'cdeab'))


# def count_prefixes(words, s):
#     ans = 0
#     for word in words:
#         if s.startswith(word):
#             ans += 1
#     return ans

# print(count_prefixes(["a","b","c","ab","bc","abc"], "abc"))

# import os

# input_path = input('输入待搜索路径:')
# pattern = input('输入待搜索关键词:')

# for dirpath,dirname,filename in os.walk(input_path):
#     for f in filename:
#         if pattern in f:
#             print(f'{dirpath}/{f}')        

import qrcode
img = qrcode.make('人生不过三万天\n今天是你人生的第7302天\n刘怡萱同学\t祝你20岁生日快乐\n又老一岁奥！~~\n(〜￣▽￣)〜 to Sherry')
img.save('./qr.png')
