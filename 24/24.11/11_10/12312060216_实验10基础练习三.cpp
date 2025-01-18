#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    int id;
    std::string name;
    double mathScore;
    double englishScore;
    double computerScore;
    double averageScore;
    int rank;
};

bool compareStudents(const Student& s1, const Student& s2) {
    return s1.averageScore > s2.averageScore;
}

int main() {
    int n;
    std::cout << "请输入学生数量 n（n ≤ 80）：";
    std::cin >> n;

    std::vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        std::cout << "请输入第 " << i + 1 << " 个学生的学号、姓名、数学成绩、英语成绩、计算机成绩：";
        std::cin >> students[i].id >> students[i].name >> students[i].mathScore >> students[i].englishScore >> students[i].computerScore;
        students[i].averageScore = (students[i].mathScore + students[i].englishScore + students[i].computerScore) / 3.0;
    }

    // 排序并确定排名
    std::sort(students.begin(), students.end(), compareStudents);
    int currentRank = 1;
    students[0].rank = currentRank;
    for (int i = 1; i < n; i++) {
        if (students[i].averageScore == students[i - 1].averageScore) {
            students[i].rank = students[i - 1].rank;
        }
        else {
            students[i].rank = currentRank;
        }
        currentRank++;
    }

    // 按分数高低次序输出每个学生的名次
    std::cout << "按分数高低次序的学生名次：" << std::endl;
    for (const auto& student : students) {
        std::cout << "学号：" << student.id << ", 姓名：" << student.name << ", 名次：" << student.rank << std::endl;
    }

    // 按名次输出每个学生的姓名与分数
    std::cout << "按名次输出学生姓名与分数：" << std::endl;
    for (int rank = 1; rank <= n; rank++) {
        for (const auto& student : students) {
            if (student.rank == rank) {
                std::cout << "名次：" << rank << ", 姓名：" << student.name << ", 平均分数：" << student.averageScore << std::endl;
                break;
            }
        }
    }
    return 0;
}