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
	map<string, string> M = { {"proportion","比例;部分;均匀"} ,{"nuisance","令人讨厌的东西，讨厌的人骚乱"} };

	/*:
征服;破除conguer
冒犯的，攻击性的offensive
进攻
transmission 播送;传送,传染melt (使)融化;(使)消散
scratch 抓;刮擦;抓,搔;抓痕
halt 停住,暂停
formal 正式的,形式上的
瞥glimpse
sketch 草;梗概;素描,速写;绘
…的略图;概述
consent 同意 (to)同意
legal 法律(上)的;合法的
tension 紧张、绷紧;张力
气候;风气climate
superb 极好的,高质量的
wit 风趣;智力;才智
riot 暴乱;极度丰富 聚众闹事
absorb 吸收;使全神贯注
，处罚,罚金penalty
scatter 撒;使散开 消散
diagram 图解,简图,图表
helpful 有益的;给予帮助的
presumably 大概
supplement 增补(物);增刊
补充
vertical垂直的
令人讨厌的;难弄的,严重nasty
的;下流的
motel 汽车旅馆manufacture 制造制造品
residential 居住的,住宅的，寄
宿的
transportation 运输
mere 仅仅的;纯粹的
spite 恶意,怨恨
凌乱状态;困境;弄糟rness*/
	for(auto e : M)
	{
		cout << e.first <<" : ";
		cout << e.second << endl;
	}
}