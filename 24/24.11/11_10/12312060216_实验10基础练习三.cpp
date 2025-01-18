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
    std::cout << "������ѧ������ n��n �� 80����";
    std::cin >> n;

    std::vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        std::cout << "������� " << i + 1 << " ��ѧ����ѧ�š���������ѧ�ɼ���Ӣ��ɼ���������ɼ���";
        std::cin >> students[i].id >> students[i].name >> students[i].mathScore >> students[i].englishScore >> students[i].computerScore;
        students[i].averageScore = (students[i].mathScore + students[i].englishScore + students[i].computerScore) / 3.0;
    }

    // ����ȷ������
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

    // �������ߵʹ������ÿ��ѧ��������
    std::cout << "�������ߵʹ����ѧ�����Σ�" << std::endl;
    for (const auto& student : students) {
        std::cout << "ѧ�ţ�" << student.id << ", ������" << student.name << ", ���Σ�" << student.rank << std::endl;
    }

    // ���������ÿ��ѧ�������������
    std::cout << "���������ѧ�������������" << std::endl;
    for (int rank = 1; rank <= n; rank++) {
        for (const auto& student : students) {
            if (student.rank == rank) {
                std::cout << "���Σ�" << rank << ", ������" << student.name << ", ƽ��������" << student.averageScore << std::endl;
                break;
            }
        }
    }
    return 0;
}