#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*

*******   *******   *******   
**             **   **   **  
**             **   **   **  
*******   *******   **   **  
     **   **        **   ** 
     **   **        **   **   
*******   *******   *******   

*/
int main()
{
    char str[100];
    int count[26] = { 0 };//给26个字母分别都创建一个相应的count（不区分大小写）
    int i, j, len, max_count;

    printf("请输入一个字符串：");
    fgets(str, 100, stdin);//gets函数存在缓冲区溢出的风险,可以用更安全的函数:fgets

    len = strlen(str);

    for (i = 0; i < len; i++) //遍历str的元素
    {
        if (str[i] >= 'a' && str[i] <= 'z') //判断str[i],并且给相应的count[]自加
        {
            count[str[i] - 'a']++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') //由于不区分大小写，依然用相同的数组自加
        {
            count[str[i] - 'A']++;
        }
    }

    printf("\n统计结果如下：\n");
    max_count = 0;
    for (i = 0; i < 26; i++) 
    {
        if (count[i] != 0) 
        {
            printf("%c: %d\n", i + 'a', count[i]);
            if (count[i] > max_count) //得出max_count
            {
                max_count = count[i];
            }
        }
    }

    printf("\n按字母出现的次数输出：\n");
    for (i = max_count; i > 0; i--) //降序输出
    {
        for (j = 0; j < 26; j++) 
        {
            if (count[j] == i) 
            {
                printf("%c: %d\n", j + 'a', count[j]);
            }
        }
    }

    return 0;
}
