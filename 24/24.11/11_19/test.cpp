#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		cout << "����ƽ������ʱ�䣺";
		double sec;
		cin >> sec;
		double v = 0.2 / sec;
		//cout << "������¶��µ��ٶȣ�";
		//cin >> v;
		if (v == -1)
			break;
		double ans = 0.04059247 / (19.66752 * v);
		cout << "���¶��µ�ճ��ϵ��Ϊ��" << ans << endl;

		double re = (v * 0.772 * 0.001 * 950) / ans;
		cout << "Re:" << re << endl;
		if (re < 0.1)
			cout << "����������" << endl;
		else
		{
			cout << "��Ҫ����������";
			double ans2 = ans - (3 * v * 0.772 * 0.001 * 950) / 16;
			cout << "�������ֵΪ��" << ans2 << endl;
		}
	}
	return 0;
}