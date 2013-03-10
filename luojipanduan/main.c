//A B C D E F G H I J 十名学生参加比赛
//0 1 2 3 4 5 6 7 8 9
//如果A参加，B也参加
//如果C不参加，D也不参加
//A和C中只能有一个人参加
//B和D中有且仅有一个人参加
//D E F G H中至少有2人参加
//C和G或者都参加，或者都不参加
//C E G I中至多只能2人参加
//如果E参加，那么F和G也都参加
//如果F参加，G H就不能参加
//如果I J 都不参加，H必须参加
//列出所有可能，按升序排列
//eg.
//C D G J

#include <stdio.h>

int judge(char s[])
{

    int j1 = (s[0] == 0 || s[1] == 1);
    int j2 = (s[2] == 1 || s[3] == 0);
    int j3 = (s[0] + s[2] <= 1);
    int j4 = (s[1] + s[3] == 1);
    int j5 = (s[3] + s[4] + s[5] + s[6] + s[7] >= 2);
    int j6 = (s[2] == s[6]);
    int j7 = (s[2] + s[4] + s[6] + s[8] <= 2);
    int j8 = (s[4] == 0 || (s[5] + s[6] == 2));
    int j9 = (s[5] == 0 || (s[6] + s[7] == 0));
    int j10 = (s[8] + s[9] >= 1 || s[7] == 1);

    return j1 && j2 && j3 && j4 && j5 && j6 && j7 && j8 && j9 && j10;
}

void pt(char s[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        putchar(s[i] + '0');
    }
    putchar(':');
    for(i = 0; i < len; i++)
    {
        if(s[i]) printf("%c ", 'A' + i);
    }
    putchar('\n');
}

void dtob(char s[], int n)//, int len)
{
    int i;
    char tmp[11];
    itoa(n, tmp, 2);
    sprintf(s, "%10s", tmp);
    for(i = 0; i < 10; i++)
    {
        if(s[i] == '1') s[i] = 1;
        else s[i] = 0;
    }
}

int main()
{
    int i = 0;
    char s[11];
    //dtob(s, 204);
    //pt(s, 10);
    for(i = 0; i < 1024; i++)
    {
        dtob(s, i);
        if(judge(s))
        {
            pt(s,10);
            printf("judge:%d\n", judge(s));
        }
    }


    return 0;
}
