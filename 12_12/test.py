import random

print("+-----------------------------------------------------------+")
print("|                                                           |")
print("|                    花有重开日，人无再少年                   |")
print("|                    欢迎来到人生重开模拟器                   |")
print("|                                                           |")
print("+-----------------------------------------------------------+")

# 设置初始属性
while True:
    print("请设置初始属性(可用点数20)")
    face = int(input("设定 颜值(1-10):"))
    strong = int(input("设定 体制(1-10):"))
    iq = int(input("设定 智力(1-10):"))
    home = int(input("设定 家境(1-10):"))
    if face < 1 or face > 10:
        print("尼玛的，输错了")
        break
    if strong < 1 or strong > 10:
        print("尼玛的，输错了")
        break
    if iq < 1 or iq > 10:
        print("尼玛的，输错了")
        break
    if home < 1 or home > 10:
        print("尼玛的，输错了")
        break
    if (face + strong + iq + home > 20):
        print("尼玛的，别贪")
        break
    print("初始值设定完成")
    break

point = random.randint(1, 6) #掷骰子
if point % 2 == 1:
    gender = 'boy'
    print("You are a boy")
else:
    gender = 'girl'
    print("You are a girl")

point = random.randint(1, 3) #掷骰子
if home == 10:
    print("你出身在帝都，父母都是高管政要")
    home += 1
    iq += 1
    face += 1
elif 7 <= home <= 10:
    if point == 1:
        print("你出生在大城市,父母是公务员")
        face += 2
    elif point == 2:
        print("你出生在大城市,父母是大企业高管")
        home += 2
    else:
        print("你出生在大城市,父母是大学教授")
        iq += 2
elif 4 <= home <= 6:
    if point == 1:
        print("你出生在三线城市, 你的父母是教师")
        iq += 1
    elif point == 2:
        print("你出生在镇上, 你的父母是医生")
        strong += 1
    else:
        print("你出生在镇上, 你的父母是个体户")  
else:
    if point == 1:
        print("你出生在村里, 你的父母是辛苦劳作的农民")
        strong += 1
        face -= 2
    elif point == 2:
        print("你出生在穷乡僻壤, 你的父母是无业游民")
        home -= 1
    else:
        print("你出生在镇上, 你父母感情不和")
        strong -= 1

import sys
import time
death = 0
for age in range(1, 11):
    info = f"你今年{age}岁了，"
    point = random.randint(1, 3)
    # 性别触发事件
    if strong < 0:
        info += "你死了"
        death = 1 
    elif gender == "girl" and home <= 3 and point == 1:
        info += "你家里人重男轻女思想非常严重，你被抛弃了"
        print(info)
        print("Game Over!!!")
        sys.exit(0)
    # 体质触发的事件
    elif strong < 6 and point != 3:
        info = "你生了一场大病，"
        if home >= 5:
            info += "在父母的进行照料下，你恢复了健康"
            strong += 1
            home -= 1
        else:
            info += "你的父母没时间管你，你的身体情况更糟糕了"
            strong -= 1
    elif face < 4 and age >= 7:
        info += "因为你长得太丑，别的小朋友不喜欢你，"
        if iq > 5:
            info += "你决定用学习填充自己"
            iq += 1
        else:
            if gender == "boy":
                info += "你和别的小朋友经常打架"
                iq -= 1
                strong += 1
            else:
                info += "你经常被别的小朋友欺负"
                strong -= 1
    # 智商触发的事件
    elif iq < 5:
        info += "你看起来傻傻的，"
        if home >= 8 and age >= 6:
            info += "你的父母把你送到更好的学校学习"
        elif 4 <= home <= 7:
            if gender == "boy":
                info += "你父母经常鼓励你多运动，加强身体素质"
                strong += 1
            else:
                info += "你父母鼓励你多打扮自己"
                face += 1
        else:
            info += "你的父母为此经常吵架"
            if point == 1:
                strong -= 1
            elif point == 2:
                iq -= 1
    # 健康成长
    else:
        info += "你健康成长，"
        if point == 1:
            info += "看起来更聪明了"
            iq += 1
        elif point == 2:
            info += "看起来更好看了"
            face += 1
        else:
            info += "看起来更结实了"
            strong += 1

    print("------------------------------------------------------------")
    print(info)
    print(f"strong={strong} ,face={face},iq={iq},home={home}")
    time.sleep(1)
    if death == 1:
        break
