#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;
#define red \
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED) // ��ɫ
#define nop \
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY) // ԭɫ
#define white \
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) // ��ɫ
void ycgb() {
    // ������ز���
    CONSOLE_CURSOR_INFO cciCursor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
        cciCursor.bVisible = FALSE;
        SetConsoleCursorInfo(hStdOut, &cciCursor);
    }
}
void ycbj() {
    // �رտ��ٱ༭
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode &= ~ENABLE_QUICK_EDIT_MODE; //�Ƴ����ٱ༭ģʽ
    mode &= ~ENABLE_INSERT_MODE; //�Ƴ�����ģʽ
    mode &= ~ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, mode);
}
string mapp[50][50] = { // ��ͼ��#��ʾǽ�ڣ�P��ʾĿ��λ�ã�o��ʾ����λ�ã�s��ʾС�ˣ�@��ʾ��װ�����ӵ�Ŀ��λ�� 
    {""},
    {
        "  ###   ",
        "  #P#   ",
        "  # ####",
        "###o oP#",
        "#P os###",
        "####o#  ",
        "   #P#  ",
        "   ###  ",
    },
    {
        "#####    ",
        "#s  #    ",
        "# oo# ###",
        "# o # #P#",
        "### ###P#",
        " ##    P#",
        " #   #  #",
        " #   ####",
        " #####   "
    },
    {
        " #######  ",
        " #     ###",
        "##o###   #",
        "# so   o #",
        "# PP# o ##",
        "##PP#   # ",
        " ######## "
    },
    {
        " #### ",
        "##  # ",
        "#so # ",
        "##o ##",
        "## o #",
        "#Po  #",
        "#PP@P#",
        "######"
    },
    {
        " #####  ",
        " #  ### ",
        " #so  # ",
        "### # ##",
        "#P# #  #",
        "#Po  # #",
        "#P   o #",
        "########"
    },
    {
        "   #######   ",
        "####     #   ",
        "#   P### #   ",
        "# # #    ##  ",
        "# # o o#P #  ",
        "# #  @  # #  ",
        "# P#o o # #  ",
        "##    # # ###",
        " # ###P    s#",
        " #     ##   #",
        " ############",
    },
    {
        "   #######",
        "  ##  # s#",
        "  #   #  #",
        "  #o o o #",
        "  # o##  #",
        "### o # ##",
        "#PPPPP  # ",
        "######### "
    },
    {
        "   ###### ",
        " ###    # ",
        "##P o## ##",
        "#PPo o  s#",
        "#PP o o ##",
        "######  # ",
        "     #### "
    },
    {
        " ######### ",
        " #  ##   # ",
        " #   o   # ",
        " #o ### o# ",
        " # #PPP# # ",
        "## #PPP# ##",
        "# o  o  o #",
        "#     # s #",
        "###########"
    },
    {
        "  ######",
        "  #    #",
        "###ooo #",
        "#s oPP #",
        "# oPPP##",
        "####  # ",
        "   #### "
    },
    {
        " ####  #####",
        "##  #  #   #",
        "# o ####o  #",
        "#  oPPPP o #",
        "##    # s ##",
        " ########## "
    },
    {
        "  ##### ",
        "###  s# ",
        "#  oP ##",
        "#  PoP #",
        "### @o #",
        "  #   ##",
        "  ##### ",
    },
    {
        "  ####  ",
        "  #PP#  ",
        " ## P## ",
        " #  oP# ",
        "## o  ##",
        "#  #oo #",
        "#  s   #",
        "########"
    },
    {
        "########",
        "#  #   #",
        "# oPPo #",
        "#soP@ ##",
        "# oPPo #",
        "#  #   #",
        "########"
    },
    {
        " #######",
        "##    ##",
        "# o oo #",
        "#PPPPPP#",
        "# oo o #",
        "### s###",
        "  ####  "
    },
    {
        "  ######  ",
        "  #    ###",
        "  # o    #",
        "### o ## #",
        "#PPP o   #",
        "#PPPo#o ##",
        "#### # o #",
        "   #  s  #",
        "   #######"
    },
    {
        "######   ",
        "#    #   ",
        "# ooo##  ",
        "#  #PP###",
        "##  PPo #",
        " # s    #",
        " ########"
    },
    {
        "  ########",
        "  #   #P #",
        " ##  oPPP#",
        " #  o #@P#",
        "## ##o# ##",
        "#   o  o #",
        "#   #    #",
        "#######  #",
        "      ####"
    },
    {
        " #######  ",
        " #PPPP #  ",
        "###PPPo###",
        "#  o#o o #",
        "# oo  #o #",
        "#    #   #",
        "#### s ###",
        "   #####  "
    },
    {
        "#######",
        "#PPoPP#",
        "#PP#PP#",
        "# ooo #",
        "#  o  #",
        "# ooo #",
        "#  #s #",
        "#######"
    },
    {
        "   ######  ",
        "   # PPP#  ",
        "####PPPP#  ",
        "#  ###o ###",
        "# o o  oo #",
        "#s o o    #",
        "#   ###   #",
        "##### #####"
    },
    {
        "######## ",
        "#      # ",
        "# #oo  # ",
        "# PPP# # ",
        "##PPPo ##",
        " # ## o #",
        " #o  o  #",
        " #  #  s#",
        " ########"
    },
    {
        "  #####   ",
        "###   ####",
        "#   o o  #",
        "# o   o s#",
        "###oo#####",
        "  #  PP#  ",
        "  #PPPP#  ",
        "  ######  "
    },
    {
        "######   #####",
        "#    ### #  P#",
        "#  o o # #PPP#",
        "# #  o ###  P#",
        "#  ooo   o sP#",
        "###  o  o#  P#",
        "  #  o#o #PPP#",
        "  ##     #  P#",
        "   ###########"
    },
    {
        "     ######",
        " #####P   #",
        " #  #PP## #",
        " #  oPP   #",
        " #  # P# ##",
        "### ##o#  #",
        "# o    oo #",
        "# #o#  #  #",
        "#s  #######",
        "#####      "
    },
    {
        " #########   ",
        " #   ##  ####",
        " # o        #",
        " ##o### ##  #",
        " #  ## @ # ##",
        " # oPPPPPP # ",
        "## ### P # # ",
        "#     o###o# ",
        "#   #    os# ",
        "#####o# #### ",
        "    #   #    ",
        "    #####    "
    },
    {
        "      #########",
        "      #       #",
        "      # # # # #",
        "      #  o o# #",
        "#######   o   #",
        "#PP#  ## o o# #",
        "#PP   ## o o  #",
        "#PP#  ## ######",
        "#PP# # o o #   ",
        "#PP     o  #   ",
        "#  ### s ###   ",
        "#### #####     "
    },
    {
        "    ####        ",
        "#####  #        ",
        "#  o o # #######",
        "#   o  # #@P@P@#",
        "## o o ###P@P@P#",
        " #o o  #  @P@P@#",
        " #so o    P@P@##",
        " #o o  #  @P@P@#",
        "## o o ###P@P@P#",
        "#   o  # #@P@P@#",
        "#  o o # #######",
        "#####  #        ",
        "    ####        "
    },
    {
        "######## ",
        "#PPPPPP# ",
        "#  o # ##",
        "# o # o #",
        "##o o o #",
        " #  s   #",
        " ########"
    },
    {
        "  ##########",
        "###   P    #",
        "#   ##o##  #",
        "# soP P Po##",
        "## o##o## # ",
        " #    P   # ",
        " ########## "
    },
    {
        "   ######",
        "####P  s#",
        "#  ooo  #",
        "#P##P##P#",
        "#   o   #",
        "#  oP# ##",
        "####   # ",
        "   ##### "
    },
    {
        " ###### ",
        " #P PP# ",
        " #P oP# ",
        "###  o##",
        "# o  o #",
        "# #o## #",
        "#   s  #",
        "########"
    },
    {
        "    ######    ",
        "  ###    ###  ",
        "  #   #o   ###",
        "  #   o   oo #",
        "  # oo #o    #",
        "  ##   o   o #",
        "###### #o#####",
        "#PPs #o  #    ",
        "#P#PP  o##    ",
        "#PPPPo# #     ",
        "#PPPP   #     ",
        "#########     "
    },
    {
        "###############",
        "#      #      #",
        "# o #o # o##o #",
        "# #  o #      #",
        "#   ##o#o##oo #",
        "# # # PPP #   #",
        "# o  P # Po # #",
        "# o#soPPP  #  #",
        "#    P # P  o #",
        "# ##Po###oP # #",
        "# # oPPPPP ## #",
        "#             #",
        "###############"
    },
    {
        "######### ",
        "#   ##  # ",
        "# # o o # ",
        "#  @P#  # ",
        "## #PsP## ",
        "##o###@###",
        "#        #",
        "#   ## # #",
        "######   #",
        "     #####"
    },
    {
        "########       ",
        "#      #       ",
        "# oo   ###     ",
        "#  o ooo ##### ",
        "## ## PPP    ##",
        " # #s#PPP###o #",
        " # # oPPP     #",
        "## # oPPPo # ##",
        "#  ##### ### # ",
        "#      o   o # ",
        "###########  # ",
        "          #### "
    },
    {
        "   ##### ",
        "   # s # ",
        "   #ooo# ",
        "####   # ",
        "#   P#o##",
        "# oPoP P#",
        "#  #P#P##",
        "######## "
    },
    {
        "############",
        "#PPP #     #",
        "#PP  # ##  #",
        "#PP     #  #",
        "#PP  # o## #",
        "#PPP #o o  #",
        "######  oo #",
        " ##  o oo  #",
        " #s ooo  # #",
        " ## o ##   #",
        "  #        #",
        "  ##########"
    },
    {
        "#########  ",
        "#       #  ",
        "#  o o o#  ",
        "## #o## #  ",
        " # PP PP## ",
        " ##PP PP # ",
        "  # ##o# ##",
        "  #o o o  #",
        "  #      s#",
        "  #########"
    },
    {
        "     #####",
        " #####   #",
        " # PP o# #",
        " # #P@   #",
        "## @P#o ##",
        "# o  o  # ",
        "#   ## s# ",
        "######### "
    }
};
int hang[50] = { 0, 8, 9, 7, 8, 8, 11, 8, 7, 9, 7,
                6, 7, 8, 7, 7, 9, 7, 9, 8, 8,
                8, 8, 8, 9, 10, 12, 12, 13, 7, 7,
                8, 8, 12, 13, 10, 12, 8, 12, 10, 8
};
int lie[50] = { 0, 8, 9, 10, 6, 8, 13, 10, 10, 11, 8,
               12, 8, 8, 8, 8, 10, 9, 10, 10, 7,
               11, 9, 10, 14, 11, 13, 15, 16, 9, 12,
               9, 8, 14, 15, 10, 15, 9, 12, 11, 10
};

string zhuyi[50][50] = { // ���� 
    {
        "  ###   ",
        "  #P#   ",
        "  # ####",
        "###o oP#",
        "#P os###",
        "####o#  ",
        "   #P#  ",
        "   ###  ",
        ""
    },
    {
        "  ###   ",
        "  #P#   ",
        "  # ####",
        "###o oP#",
        "#P o ###",
        "####s#  ",
        "   #@#  ",
        "   ###  ",
        "S"
    },
    {
        "  ###   ",
        "  #P#   ",
        "  # ####",
        "###o oP#",
        "#P os###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "Sw"
    },
    {
        "  ###   ",
        "  #P#   ",
        "  # ####",
        "###o oP#",
        "#Pos ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "Swa"
    },
    {
        "  ###   ",
        "  #P#   ",
        "  # ####",
        "###o oP#",
        "#@s  ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "Swaa"
    },
    {
        "  ###   ",
        "  #P#   ",
        "  # ####",
        "###o oP#",
        "#@ s ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "Swaad"
    },
    {
        "  ###   ",
        "  #P#   ",
        "  #o####",
        "###s oP#",
        "#@   ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "Swaadw"
    },
    {
        "  ###   ",
        "  #@#   ",
        "  #s####",
        "###  oP#",
        "#@   ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "Swaadww"
    },
    {
        "  ###   ",
        "  #@#   ",
        "  # ####",
        "###s oP#",
        "#@   ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "SwaadwwS"
    },
    {
        "  ###   ",
        "  #@#   ",
        "  # ####",
        "### soP#",
        "#@   ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "d"
    },
    {
        "  ###   ",
        "  #@#   ",
        "  # ####",
        "###  s@#",
        "#@   ###",
        "#### #  ",
        "   #@#  ",
        "   ###  ",
        "dd"
    }
};
string s[50];
int n, m;
int bbb, ccc, ex, ey;
string ss[50];
int o[10000][2];
int P[10000][2];
int cnt = 2, flagg = 0;
int zn = 0, tim = 0;
void readcnt() {
    FILE* pf = fopen("�����Ӽ�¼.txt", "r");
    if (pf == NULL) {
        pf = fopen("�����Ӽ�¼.txt", "w");
        fwrite(&cnt, sizeof(int), 1, pf);
    }
    fseek(pf, 0, SEEK_SET);
    fread(&cnt, sizeof(int), 1, pf);
    fclose(pf);
    pf = NULL;
}
void writecnt() {
    FILE* pf = fopen("�����Ӽ�¼.txt", "w");
    if (pf == NULL) {
        printf("д��ʧ��\n");
        exit(0);
    }
    fwrite(&cnt, sizeof(int), 1, pf);
    fclose(pf);
    pf = NULL;
    cout << "д��ɹ���";
}
int jieshu() {
    int flag = 0;
    for (int i = 0; i < bbb; i++) {
        for (int j = 0; j < bbb; j++) {
            if (o[i][0] == P[j][0] && o[i][1] == P[j][1]) {
                s[o[i][0]][o[i][1]] = '@';
                flag++;
                break;
            }
        }
    }
    if (flag == bbb) return 1;
    else return 0;
}
void chushihua() {
    for (int i = 0; i < n; i++) s[i] = ss[i];
    bbb = ccc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'o')
                o[bbb][0] = i, o[bbb][1] = j, bbb++;
            if (s[i][j] == 'P')
                P[ccc][0] = i, P[ccc][1] = j, ccc++;
            if (s[i][j] == '@')
                o[bbb][0] = i, o[bbb][1] = j, bbb++, P[ccc][0] = i, P[ccc][1] = j, ccc++;
            if (s[i][j] == 's')
                ex = i, ey = j;
        }
    }
}
char op[1005], xx[1005];
int cc = 0;
void XIANG(int guan) {
    char t = xx[cc--];
    if (t == 'w') {
        s[ex - 1][ey] = ' ';
        if (mapp[guan][ex][ey] == 'P') {
            s[ex][ey] = '@';
        }
        else {
            s[ex][ey] = 'o';
        }
        ++ex;
        s[ex][ey] = 's';
        for (int i = 0; i < bbb; i++) {
            if (o[i][0] == ex - 2 && o[i][1] == ey) {
                o[i][0]++;
                break;
            }
        }
    }
    if (t == 's') {
        s[ex + 1][ey] = ' ';
        if (mapp[guan][ex][ey] == 'P') {
            s[ex][ey] = '@';
        }
        else {
            s[ex][ey] = 'o';
        }
        --ex;
        s[ex][ey] = 's';
        for (int i = 0; i < bbb; i++) {
            if (o[i][0] == ex + 2 && o[i][1] == ey) {
                o[i][0]--;
                break;
            }
        }
    }
    if (t == 'a') {
        s[ex][ey - 1] = ' ';
        if (mapp[guan][ex][ey] == 'P') {
            s[ex][ey] = '@';
        }
        else {
            s[ex][ey] = 'o';
        }
        ++ey;
        s[ex][ey] = 's';
        for (int i = 0; i < bbb; i++) {
            if (o[i][0] == ex && o[i][1] == ey - 2) {
                o[i][1]++;
                break;
            }
        }
    }
    if (t == 'd') {
        s[ex][ey + 1] = ' ';
        if (mapp[guan][ex][ey] == 'P') {
            s[ex][ey] = '@';
        }
        else {
            s[ex][ey] = 'o';
        }
        --ey;
        s[ex][ey] = 's';
        for (int i = 0; i < bbb; i++) {
            if (o[i][0] == ex && o[i][1] == ey + 2) {
                o[i][1]--;
                break;
            }
        }
    }
}
bool tuixiangzi(int flag, int guan) {
    if (flag == 1) {
        cout << "\n          ������С��Ϸ��" << guan <<
            "�����¿�ʼ��\n\n       ����ո�ʼ��Ϸ�����z���˳���Ϸ��\n";
        while (1) {
            if (kbhit()) {
                char gg = getch();
                if (gg == 'z')
                    return 0;
                if (gg == ' ') {
                    system("cls");
                    break;
                }
            }
        }
    }
    int step = 0;
    system("cls");
    cout << "\n\n                   ��ʼ��Ϸ��\n";
    Sleep(1000);
    system("cls");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char r = s[i][j];
            if (r == ' ') cout << "  ";
            if (r == '#') cout << "��";
            if (r == 's') {
                red;
                cout << "��";
                white;
            }
            if (r == 'o') cout << "��";
            if (r == 'P') cout << "��";
            if (r == '@') cout << "��";
        }
        cout << "\n";
    }
    cc = 0;
    cout << "\n  �ؿ�����" << guan << "��     "
        << "������0��";
    char g;
    while (1) {
        if (kbhit()) {
            g = getch();

            if (g == 'r') {
                chushihua();
                system("cls");
                Sleep(100);
                return tuixiangzi(1, guan);
            }
            // ����
            bool flag = 0;
            if (g == 'z' && cc > 0) {
                ++step;
                if (xx[cc] != ' ') {
                    XIANG(guan);
                }
                else {
                    flag = 1;
                    g = op[cc];
                }
            }
            else if (!(g == 'a' || g == 75 || g == 'd' || g == 77 || g == 'w' || g == 72 || g == 's' || g == 80)) {
                continue;
            }
            else { // ͳһ��ʽ 
                if (g == 'a' || g == 75) op[++cc] = 'd';
                if (g == 'd' || g == 77) op[++cc] = 'a';
                if (g == 'w' || g == 72) op[++cc] = 's';
                if (g == 's' || g == 80) op[++cc] = 'w';
                if (g == 'a' || g == 75) xx[cc] = 'a';
                if (g == 'd' || g == 77) xx[cc] = 'd';
                if (g == 'w' || g == 72) xx[cc] = 'w';
                if (g == 's' || g == 80) xx[cc] = 's';
            }
            // ����
            if (g == 'a' || g == 75) {
                if (s[ex][ey - 1] == ' ' || s[ex][ey - 1] == 'P')
                    s[ex][ey] = ' ', ey--, s[ex][ey] = 's', xx[cc] = ' ';
                else if ((s[ex][ey - 1] == 'o' || s[ex][ey - 1] == '@') && (s[ex][ey - 2] == ' ' || s[ex][ey - 2] == 'P')) {
                    int sx = ex, sy = ey - 1;
                    for (int i = 0; i < bbb; i++) {
                        if (o[i][0] == sx && o[i][1] == sy) {
                            s[sx][sy] = ' ';
                            o[i][1]--;
                            if (s[sx][sy - 1] != 'P') s[sx][sy - 1] = 'o';
                            else s[sx][sy - 1] = '@';
                            break;
                        }
                    }
                    s[ex][ey] = ' ';
                    ey--;
                    s[ex][ey] = 's';
                    step++;
                }
                else {
                    --cc;
                }
            }
            // ����
            if (g == 'd' || g == 77) {
                if (s[ex][ey + 1] == ' ' || s[ex][ey + 1] == 'P')
                    s[ex][ey] = ' ', ey++, s[ex][ey] = 's', xx[cc] = ' ';
                else if ((s[ex][ey + 1] == 'o' || s[ex][ey + 1] == '@') && (s[ex][ey + 2] == ' ' || s[ex][ey + 2] == 'P')) {
                    int sx = ex, sy = ey + 1;
                    // sx, sy : ��ǰ���Ƶ�����
                    for (int i = 0; i < bbb; i++) {
                        if (o[i][0] == sx && o[i][1] == sy) {
                            s[sx][sy] = ' ';
                            o[i][1]++;
                            if (s[sx][sy + 1] != 'P')
                                s[sx][sy + 1] = 'o';
                            else
                                s[sx][sy + 1] = '@';
                            break;
                        }
                    }
                    s[ex][ey] = ' ';
                    ey++;
                    s[ex][ey] = 's';
                    step++;
                }
                else {
                    --cc;
                }
            }
            // ����
            if (g == 'w' || g == 72) {
                if (s[ex - 1][ey] == ' ' || s[ex - 1][ey] == 'P')
                    s[ex][ey] = ' ', ex--, s[ex][ey] = 's', xx[cc] = ' ';
                else if ((s[ex - 1][ey] == 'o' || s[ex - 1][ey] == '@') && (s[ex - 2][ey] == ' ' || s[ex - 2][ey] == 'P')) {
                    int sx = ex - 1, sy = ey;
                    for (int i = 0; i < bbb; i++) {
                        if (o[i][0] == sx && o[i][1] == sy) {
                            s[sx][sy] = ' ';
                            o[i][0]--;
                            if (s[sx - 1][sy] != 'P')
                                s[sx - 1][sy] = 'o';
                            else
                                s[sx - 1][sy] = '@';

                            break;
                        }
                    }
                    s[ex][ey] = ' ';
                    ex--;
                    s[ex][ey] = 's';
                    step++;
                }
                else {
                    --cc;
                }
            }
            // ����
            if (g == 's' || g == 80) {
                if (s[ex + 1][ey] == ' ' || s[ex + 1][ey] == 'P')
                    s[ex][ey] = ' ', ex++, s[ex][ey] = 's', xx[cc] = ' ';
                else if ((s[ex + 1][ey] == 'o' || s[ex + 1][ey] == '@') && (s[ex + 2][ey] == ' ' || s[ex + 2][ey] == 'P')) {
                    int sx = ex + 1, sy = ey;
                    for (int i = 0; i < bbb; i++) {
                        if (o[i][0] == sx && o[i][1] == sy) {
                            s[sx][sy] = ' ';
                            o[i][0]++;

                            if (s[sx + 1][sy] != 'P')
                                s[sx + 1][sy] = 'o';
                            else
                                s[sx + 1][sy] = '@';

                            break;
                        }
                    }
                    s[ex][ey] = ' ';
                    ex++;
                    s[ex][ey] = 's';
                    step++;
                }
                else {
                    --cc;
                }
            }
            if (flag) --cc;
            system("cls");
            // ��ӡ��ͼ 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == ex && j == ey) {
                        red;
                        cout << "��";
                        white;
                    }
                    else {
                        for (int k = 0; k < bbb; k++) {
                            int flag = 0;
                            for (int l = 0; l < bbb; l++) {
                                if (o[l][0] != P[k][0] || o[l][1] != P[k][1])
                                    flag++;
                            }

                            if (flag == bbb)
                                s[P[k][0]][P[k][1]] = 'P';
                        }
                        char r = s[i][j];
                        if (r == ' ')
                            cout << "  ";
                        if (r == '#')
                            cout << "��";
                        if (r == 's') {
                            red;
                            cout << "��";
                            white;
                        }
                        if (r == 'o')
                            cout << "��";
                        if (r == 'P')
                            cout << "��";
                        if (r == '@')
                            cout << "��";
                    }
                }
                cout << "\n";
            }
            cout << "\n  �ؿ�����" << guan << "��     "
                << "������" << step << "��";
            if (jieshu()) {
                Sleep(200);
                break;
            }
        }
    }
    system("cls");
    cout << "\n                ��ϲ��ɹ��ˣ�\n";
    cout << "         �㹲����" << step << "������˵�" << guan << "�ؿ���\n\n";
    cout << "        ��z���˳������ո��������һ�ء�\n";
    while (1) {
        if (kbhit()) {
            char gg = getch();
            if (gg == 'z') {
                if (guan == cnt)
                    cnt++;
                flagg++;
                return 0;
            }
            if (gg == ' ') {
                if (guan == cnt)
                    cnt++;
                guan++, flagg++;
                n = hang[guan], m = lie[guan];
                for (int i = 0; i < n; i++)
                    s[i] = ss[i] = mapp[guan][i];
                bbb = ccc = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (s[i][j] == 'o')
                            o[bbb][0] = i, o[bbb][1] = j, bbb++;
                        if (s[i][j] == 'P')
                            P[ccc][0] = i, P[ccc][1] = j, ccc++;

                        if (s[i][j] == '@')
                            o[bbb][0] = i, o[bbb][1] = j, bbb++, P[ccc][0] = i, P[ccc][1] = j, ccc++;

                        if (s[i][j] == 's')
                            ex = i, ey = j;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}
int sum = 4;
string zhu[15] = { // ѡ����� 
    "",
    "         +---------�� �� ��---------+",
    "",
    "                   ѡ��ؿ�",
    "                -> ��Ϸ����",
    "                   ��ȡ��¼",
    "                   �����¼",
    "                   �鿴��¼",
    "                   �޸ļ�¼",
    "                   �鿴����",
    "                   �˳���Ϸ",
    "",
    "    ����(w)�͡�(s)ѡ����Ŀ�����ո��ȷ�ϡ�"
};
int nn = 13;
void yangli() { // ��ʾ���� 
    while (1) {
        system("cls");
        if (kbhit()) {
            char qqq = getch();

            if (qqq == 'q') {
                return;
            }
        }
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << "              ";
            for (int j = 0; j < 8; j++) {
                char r = zhuyi[zn][i][j];
                if (r == ' ') cout << "  ";
                if (r == '#') cout << "��";
                if (r == 's') {
                    red;
                    cout << "��";
                    white;
                }
                if (r == 'o') cout << "��";
                if (r == 'P') cout << "��";
                if (r == '@') cout << "��";
                if (r == 'w') cout << "��";
                if (r == 'a') cout << "��";
                if (r == 'S') cout << "��";
                if (r == 'd') cout << "��";
            }
            cout << "\n";
        }
        zn = (zn + 1) % 11;
        cout << "\n��Q���˳�";
        Sleep(500);
    }
}
int main() {
    white;
    ycgb(); // ���ع�� 
    ycbj();
    system("mode con cols=46 lines=18"); // ���ô��ڴ�С 
    for (int i = 0; i < nn; i++)
        cout << zhu[i] << "\n";
    while (1) {
        if (kbhit()) {
            char gg = getch();
            if ((gg == 's' || gg == 80) && sum != 10) {
                system("cls");
                zhu[sum + 1][16] = '-', zhu[sum + 1][17] = '>';
                zhu[sum][16] = zhu[sum][17] = ' ';
                for (int i = 0; i < nn; i++) {
                    cout << zhu[i] << "\n";
                }
                sum++;
            }
            if ((gg == 'w' || gg == 72) && sum != 3) {
                system("cls");
                zhu[sum - 1][16] = '-', zhu[sum - 1][17] = '>';
                zhu[sum][16] = zhu[sum][17] = ' ';
                for (int i = 0; i < nn; i++) {
                    cout << zhu[i] << "\n";
                }
                sum--;
            }
            if (gg == ' ') {
                zn = tim = 0;
                if (sum == 10) {
                    system("cls");
                    cout << "����Ϸ�������ף����λdalao���ָ�̣�ͬʱ��ӭ����������������\n\n";
                    system("pause");
                    return 0;
                }
                if (sum == 9) {
                    system("cls");
                    yangli();
                }
                if (sum == 8) {
                    system("cls");
                    cout << "���������ر�ţ�";
                    cin >> cnt;
                    cout << "���ڱ����¼...\n";
                    writecnt();
                    system("pause");
                }
                if (sum == 5) {
                    system("cls");
                    cout << "���ڶ�ȡ��¼...";
                    readcnt();
                    system("cls");
                    cout << "��ȡ��¼�ɹ���\n";
                    cout << "��ǰ��¼Ϊ��";
                    red;
                    cout << cnt << endl;
                    white;
                    system("pause");
                }
                if (sum == 6) {
                    system("cls");
                    cout << "����д���¼...\n";
                    writecnt();
                    cout << endl;
                    system("pause");
                }
                if (sum == 7) {
                    system("cls");
                    cout << "��ǰ��¼Ϊ��";
                    red;
                    cout << cnt << endl;
                    white;
                    system("pause");
                }
                if (sum == 4) {
                    system("cls");
                    cout << "��ϷĿ�꣺\n";
                    cout << "����С��(";
                    red;
                    cout << "��";
                    white;
                    cout << ")����������(��)����ָ���ص�(��)��\n";
                    cout << "��ָ���ص��������ӣ�����ʾ�\n\n";
                    cout << "��Ϸ����\n";
                    cout << "С����û���ϰ���(��)�������ֻ���ƶ�һ�����ӡ�\n";
                    cout << "С��ֻ�������ӣ���������\n\n";
                    cout << "�������ã�\n";
                    cout << "�á�(w)����(s)����(a)����(d)����С���ƶ���\n";
                    cout << "��z��������ע�⣺������ʹ����+1��\n";
                    cout << "��r��������˳���\n";
                    cout << "�Ʋ���ʽ�����������ߵ���Ч����\n";
                    if (cnt > 5)
                        cout << "���v����ת��Ϸ�����ַ\n",
                        cout << "ע�⣬��ַ��˳�򲢷Ǳ���Ϸ��ؿ�˳��\n";
                    else
                        cout << "�����浽�����ػ�����Ϸ���Ŷ��\n\n";
                    cout << "                ���ո���˳���\n";
                    while (1) {
                        if (kbhit()) {
                            char ggg = getch();
                            if (ggg == ' ') {
                                system("cls");
                                for (int i = 0; i < nn; i++)
                                    cout << zhu[i] << "\n";
                                break;
                            }
                            else if (ggg == 'v' && cnt > 5) {
                                system("start http://v.4399pk.com/xiaoyouxi/game_1875.htm");
                            }
                        }
                    }
                }
                if (sum == 3) {
                    white;
                    system("cls");
                    cout << "\n                   ѡ��ؿ�\n\n";
                    int k = cnt;
                    for (int i = 1; i <= 40; i++) {
                        if (i > cnt) nop;
                        else if (i == k) red;
                        else white;
                        printf("%8d", i);
                        if (i % 5 == 0) cout << "\n";
                    }
                    white;
                    cout << "\n    ����(w)����(s)����(a)����(d)ѡ��ؿ���\n           ���ո�����룬��z���˳���\n";
                    while (1) {
                        if (kbhit()) {
                            char ggg = getch();
                            if (ggg == 'z') {
                                system("cls");
                                for (int i = 0; i < nn; i++) cout << zhu[i] << "\n";
                                break;
                            }
                            if (ggg == 'a' || ggg == 75) {
                                if (k - 1 >= 1) {
                                    k--;
                                    white;
                                    system("cls");
                                    cout << "\n                   ѡ��ؿ�\n\n";
                                    for (int i = 1; i <= 40; i++) {
                                        if (i > cnt) nop;
                                        else if (i == k) red;
                                        else white;
                                        printf("%8d", i);
                                        if (i % 5 == 0) cout << "\n";
                                    }
                                    white;
                                    cout << "\n    ����(w)����(s)����(a)����(d)ѡ��ؿ���\n           ���ո�����룬��z���˳���\n";
                                }
                            }
                            if (ggg == 'd' || ggg == 77) {
                                if (k + 1 <= cnt) {
                                    k++;
                                    white;
                                    system("cls");
                                    cout << "\n                   ѡ��ؿ�\n\n";
                                    for (int i = 1; i <= 40; i++) {
                                        if (i > cnt) nop;
                                        else if (i == k) red;
                                        else white;
                                        printf("%8d", i);
                                        if (i % 5 == 0) cout << "\n";
                                    }
                                    white;
                                    cout << "\n    ����(w)����(s)����(a)����(d)ѡ��ؿ���\n           ���ո�����룬��z���˳���\n";
                                }
                            }
                            if (ggg == 'w' || ggg == 72) {
                                if (k - 5 >= 1) {
                                    k -= 5;
                                    white;
                                    system("cls");
                                    cout << "\n                   ѡ��ؿ�\n\n";
                                    for (int i = 1; i <= 40; i++) {
                                        if (i > cnt) nop;
                                        else if (i == k) red;
                                        else white;
                                        printf("%8d", i);
                                        if (i % 5 == 0) cout << "\n";
                                    }
                                    white;
                                    cout << "\n    ����(w)����(s)����(a)����(d)ѡ��ؿ���\n           ���ո�����룬��z���˳���\n";
                                }
                            }
                            if (ggg == 's' || ggg == 80) {
                                if (k + 5 <= cnt) {
                                    k += 5;
                                    white;
                                    system("cls");
                                    cout << "\n                   ѡ��ؿ�\n\n";
                                    for (int i = 1; i <= 40; i++) {
                                        if (i > cnt) nop;
                                        else if (i == k) red;
                                        else white;
                                        printf("%8d", i);
                                        if (i % 5 == 0)
                                            cout << "\n";
                                    }
                                    white;
                                    cout << "\n    ����(w)����(s)����(a)����(d)ѡ��ؿ���\n           ���ո�����룬��z���˳���\n";
                                }
                            }
                            if (ggg == ' ') {
                                flagg = 0;
                                n = hang[k], m = lie[k];
                                for (int i = 0; i < n; i++)
                                    s[i] = ss[i] = mapp[k][i];
                                bbb = ccc = 0;
                                for (int i = 0; i < n; i++) {
                                    for (int j = 0; j < m; j++) {
                                        if (s[i][j] == 'o')
                                            o[bbb][0] = i, o[bbb][1] = j, bbb++;
                                        if (s[i][j] == 'P')
                                            P[ccc][0] = i, P[ccc][1] = j, ccc++;
                                        if (s[i][j] == '@')
                                            o[bbb][0] = i, o[bbb][1] = j, bbb++, P[ccc][0] = i, P[ccc][1] = j, ccc++;
                                        if (s[i][j] == 's')
                                            ex = i, ey = j;
                                    }
                                }
                                tuixiangzi(0, k);
                                k += flagg;
                                white;
                                system("cls");
                                cout << "\n                   ѡ��ؿ�\n\n";
                                for (int i = 1; i <= 40; i++) {
                                    if (i > cnt) nop;
                                    else if (i == k) red;
                                    else white;
                                    printf("%8d", i);
                                    if (i % 5 == 0) cout << "\n";
                                }
                                white;
                                cout << "\n    ����(w)����(s)����(a)����(d)ѡ��ؿ���\n           ���ո�����룬��z���˳���\n";
                            }
                        }
                    }
                }
            }
            system("cls");
            for (int i = 0; i < nn; i++)
                cout << zhu[i] << "\n";
        }
    }
    return 0;
}

