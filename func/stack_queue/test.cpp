#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"stack_queue.h"

int main()
{
	Qin::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	Qin::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	return 0;
}

