#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
int main()
{
	while (1)
	{
		cout << "输入平均下落时间：";
		double sec;
		cin >> sec;
		double v = 0.2 / sec;
		//cout << "输入此温度下的速度：";
		//cin >> v;
		if (v == -1)
			break;
		double ans = 0.04059247 / (19.66752 * v);
		cout << "此温度下的粘滞系数为：" << ans << endl;

		double re = (v * 0.772 * 0.001 * 950) / ans;
		cout << "Re:" << re << endl;
		if (re < 0.1)
			cout << "不用修正！" << endl;
		else
		{
			cout << "需要修正！！！";
			double ans2 = ans - (3 * v * 0.772 * 0.001 * 950) / 16;
			cout << "修正后的值为：" << ans2 << endl;
		}
	}
	return 0;
}