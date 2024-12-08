
#while True:


# username = input("请输入用户名：")
# password = input("请输入密码：")
# if username == "admin" and password == "123456":
#     print("登录成功！")
# else:
#     print("登录失败!")


# x = float(input("x = "))
# if(x > 1):
#     y = 3 * x - 5
# elif(x >= -1):
#     y = x + 2
# else:
#     y = 5 * x + 3
    
# print("f(%.2f) = %.2f" % (x, y))

import random
#  剪刀：0 石头：1 布：2
dict = {0:"剪刀",1:"石头",2:"布"}
#  输入-1退出

while(True):
    player = int(input("你要出啥："))
    if player in (0,1,2):
        computer = random.randint(0,2)
        if(player == 0 and computer == 2 or player == 1 and computer == 0 or player == 2 and computer == 1):
            print("玩家出的%s电脑出的%s,玩家获胜"%(dict[player],dict[computer]))
        elif(player == computer):
            print("玩家和电脑都出的%s"%dict[player])
        else:
            print("玩家出的%s电脑出的%s,电脑获胜"%(dict[player],dict[computer]))
    elif(player == -1):
        print("退出游戏！")
        break
    else:
        print("输入不规范,请重新输入0到2之间的数字")