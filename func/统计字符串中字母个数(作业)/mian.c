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
    int count[26] = { 0 };//��26����ĸ�ֱ𶼴���һ����Ӧ��count�������ִ�Сд��
    int i, j, len, max_count;

    printf("������һ���ַ�����");
    fgets(str, 100, stdin);//gets�������ڻ���������ķ���,�����ø���ȫ�ĺ���:fgets

    len = strlen(str);

    for (i = 0; i < len; i++) //����str��Ԫ��
    {
        if (str[i] >= 'a' && str[i] <= 'z') //�ж�str[i],���Ҹ���Ӧ��count[]�Լ�
        {
            count[str[i] - 'a']++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') //���ڲ����ִ�Сд����Ȼ����ͬ�������Լ�
        {
            count[str[i] - 'A']++;
        }
    }

    printf("\nͳ�ƽ�����£�\n");
    max_count = 0;
    for (i = 0; i < 26; i++) 
    {
        if (count[i] != 0) 
        {
            printf("%c: %d\n", i + 'a', count[i]);
            if (count[i] > max_count) //�ó�max_count
            {
                max_count = count[i];
            }
        }
    }

    printf("\n����ĸ���ֵĴ��������\n");
    for (i = max_count; i > 0; i--) //�������
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
