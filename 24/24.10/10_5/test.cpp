#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);

        dp[0] = s[0] != '0';
        if (n == 1) return dp[0];

        if (s[1] >= '1' && s[1] <= '9') dp[1] += dp[0];
        int t = (s[0] - '0') * 10 + s[1] - '0';
        if (t >= 10 && t <= 26)
            dp[1]++;

        for (int i = 2; i < n; i++)
        {
            if (s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];
            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (t >= 10 && t <= 26) dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
    //if (s[i] >= '1' && s[i] <= '9')
    //    dp[i] += dp[i - 1];
    //else
    //    return 0;
    //if (s[i - 1] <= '2' && s[i] <= '6' && s[i] >= '1')
    //    dp[i] += dp[i - 2];
    //else
    //    return 0;
};

int main()
{
	//FILE* pfile = fopen("dictionary.txt", "r");
	//if (pfile == nullptr)
	//	perror("file is null!");
	map<string, string> M = { {"proportion","����;����;����"} ,{"nuisance","��������Ķ������������ɧ��"} };

	/*:
����;�Ƴ�conguer
ð���ģ������Ե�offensive
����
transmission ����;����,��Ⱦmelt (ʹ)�ڻ�;(ʹ)��ɢ
scratch ץ;�β�;ץ,ɦ;ץ��
halt ͣס,��ͣ
formal ��ʽ��,��ʽ�ϵ�
Ƴglimpse
sketch ��;����;����,��д;��
������ͼ;����
consent ͬ�� (to)ͬ��
legal ����(��)��;�Ϸ���
tension ���š�����;����
����;����climate
superb ���õ�,��������
wit ��Ȥ;����;����
riot ����;���ȷḻ ��������
absorb ����;ʹȫ���ע
������,����penalty
scatter ��;ʹɢ�� ��ɢ
diagram ͼ��,��ͼ,ͼ��
helpful �����;���������
presumably ���
supplement ����(��);����
����
vertical��ֱ��
���������;��Ū��,����nasty
��;������
motel �����ù�manufacture ��������Ʒ
residential ��ס��,סլ�ģ���
�޵�
transportation ����
mere ������;�����
spite ����,Թ��
����״̬;����;Ū��rness*/
	for(auto e : M)
	{
		cout << e.first <<" : ";
		cout << e.second << endl;
	}
}