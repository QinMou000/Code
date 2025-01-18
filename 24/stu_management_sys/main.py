import sys
import os.path
stus = []

def menu():
    print(" 1. 新增学生信息")
    print(" 2. 显示所有同学信息")
    print(" 3. 根据名字查找学生信息")
    print(" 4. 删除学生信息")
    print(" 0. 退出程序")
    choice = input(" 请输入您的选择: ")
    return int(choice)

def insert():
    print('[新增学生] 开始!')
    stu_id = input('请输入学号:')
    name = input('请输入姓名:')
    gender = input('请输入性别:')
    if gender not in ('男','女'):
        print('性别不符合要求，请重新输入！')
        return
    class_name = input('请输入班级:')
    student = {
        'stu_id':stu_id,
        'name':name,
        'gender':gender,
        'class_name':class_name
    }
    global stus
    stus.append(student)
    save()
    print('[新增学生] 完成!')

def show():
    print('[显示学生] 开始!')
    for s in stus:
        print(f'[{s['stu_id']}]\t{s['name']}\t{s['gender']}\t{s['class_name']}')
    print(f'[显示学生] 完成!\t一共显示了{len(stus)}条记录!')

def find():
    print('[查找学生] 开始!')
    name = input('请输入要查找的学生姓名:')
    count = 0
    for s in stus:
        if name == s['name']:
            print(f'[{s['studentId']}]\t{s['name']}\t{s['gender']}\t{s['className']}')
            count += 1
    print(f'[查找学生] 完毕!共查到{count}条记录!')
    
def delete():
    print('[删除学生] 开始!')
    stu_id = input('请输入要删除同学的学号:')
    count = 0
    for s in stus:
        if s['stu_id'] == stu_id:
            print(f'删除{s['name']}同学的信息!')
            stus.remove(s)
            count += 1
    save()
    print(f'[删除学生] 完成!共删除{count}条记录!')

def save(): # 存档函数
    with open('D:/record.txt','w') as f:
        for s in stus:
            f.write(f'{s['stu_id']}\t{s['name']}\t{s['gender']}\t{s['class_name']}\n')
    print(f'[存档成功] 共储存了{len(stus)}条记录!')

def load():
    # 文件不存在，跳过读档
    if not os.path.exists('D:/record.txt'):
        return
    # 先清空全局变量里的数据
    global stus
    stus = []
    with open('D:/record.txt','r') as f:
        for line in f:
            # 去除末尾换行符
            line = line.strip()
            tokens = line.split('\t')
            if len(tokens) < 4:
                print(f'文件格式有误!line = {line}')
                continue
            stu = {
                'stu_id' : tokens[0],
                'name' : tokens[1],
                'gender' : tokens[2],
                'class_name' : tokens[3]
            }
            stus.append(stu)
    print(f'[读档成功] 共读取了{len(stus)}条记录!')
    

def main(): # 程序入口
    load()
    print('+--------------------------+')
    print('|    欢迎来到学生管理系统    |')
    print('+--------------------------+')
    while True:
        choice = menu()
        if choice == 0:
            sys.exit()
        if choice == 1:
            insert()
        elif choice == 2:
            show()
        elif choice == 3:
            find()
        elif choice == 4:
            delete()
        else:
            print('您的输入有误！请重新输入！')

main()