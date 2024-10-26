#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void demonstrate()
{
	Assign(s, 'THIS IS A BOOK');
	Replace(s, SubStr(s, 3, 7), 'ESE ARE');
	Assign(t, Concat(s, 's'));
	Assign(u, 'xYxYXYXYXYXY');
	Assign(v, SubStr(u, 6, 3));
	Assign(w, 'w');
	printf('t=%s v=%s u=%s %s', t, v, u, replace(u, v, w));
}