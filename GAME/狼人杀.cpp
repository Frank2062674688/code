#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
struct IDname
{
    int geshu;
    string NAME;
};
IDname jue_se[100];
struct ID
{
    int num;
    bool life;
    string name;
    int know;
    int how;
};
ID player[21];
int n, MY, kill1, kill2;
char a;
bool jieyao = 1, duyao = 1;
int lieren, shouwei = 0;
void init1()
{
    jue_se[1].NAME = "���� ";
    jue_se[2].NAME = "���� ";
    jue_se[3].NAME = "Ů�� ";
    jue_se[4].NAME = "Ԥ�Լ� ";
    jue_se[5].NAME = "���� ";
    jue_se[6].NAME = "���� ";
}
void init2(int nn)
{
    switch (nn)
    {
    case 6:
        jue_se[1].geshu = 3;
        jue_se[2].geshu = 2;
        jue_se[3].geshu = 1;
        jue_se[4].geshu = 0;
        jue_se[5].geshu = 0;
        jue_se[6].geshu = 0;
        break;
    case 7:
        jue_se[1].geshu = 3;
        jue_se[2].geshu = 2;
        jue_se[3].geshu = 1;
        jue_se[4].geshu = 1;
        jue_se[5].geshu = 0;
        jue_se[6].geshu = 0;
        break;
    case 8:
        jue_se[1].geshu = 3;
        jue_se[2].geshu = 3;
        jue_se[3].geshu = 1;
        jue_se[4].geshu = 1;
        jue_se[5].geshu = 0;
        jue_se[6].geshu = 0;
        break;
    case 9:
        jue_se[1].geshu = 3;
        jue_se[2].geshu = 3;
        jue_se[3].geshu = 1;
        jue_se[4].geshu = 1;
        jue_se[5].geshu = 1;
        jue_se[6].geshu = 0;
        break;
    case 10:
        jue_se[1].geshu = 4;
        jue_se[2].geshu = 3;
        jue_se[3].geshu = 1;
        jue_se[4].geshu = 1;
        jue_se[5].geshu = 1;
        jue_se[6].geshu = 0;
        break;
    case 11:
        jue_se[1].geshu = 4;
        jue_se[2].geshu = 4;
        jue_se[3].geshu = 1;
        jue_se[4].geshu = 1;
        jue_se[5].geshu = 1;
        jue_se[6].geshu = 0;
        break;
    case 12:
        jue_se[1].geshu = 4;
        jue_se[2].geshu = 4;
        jue_se[3].geshu = 1;
        jue_se[4].geshu = 1;
        jue_se[5].geshu = 1;
        jue_se[6].geshu = 1;
        break;
    default:
        cout << "�������,�ټ�" << endl;
        exit(0);
        break;
    }
}
int van[10] = { 7,4,6,43,35,1,2,8,20,19 };
void init3(int nn)
{
    srand(time(0));
    Sleep(rand() % 44);
    int x = 10000;
    int t = rand();
    srand(time(NULL));
    int y = van[(rand() % 100 * van[rand() % 10] + t) % 10];
    if (nn <= 6)
        x = abs(x * 6 / y) % 3 + 1;
    else if (nn <= 8)
        x = abs(x * 7 / y) % 4 + 1;
    else if (nn <= 11)
        x = abs(x * 8 / y) % 5 + 1;
    else if (nn <= 14)
        x = abs(x * 9 / y) % 6 + 1;
    do
    {
        if (nn <= 6)
            x = x % 3 + 1;
        else if (nn <= 8)
            x = x % 4 + 1;
        else if (nn <= 11)
            x = x % 5 + 1;
        else if (nn <= 14)
            x = x % 6 + 1;
        if (jue_se[x].geshu > 0)
        {
            player[nn].name = jue_se[x].NAME;
            if (player[nn].name == "���� ")
                lieren = nn;
            if (player[nn].name == "���� ")
                shouwei = nn;
            player[nn].life = 1;
            player[nn].num = nn;
            player[nn].know = 0;
            jue_se[x].geshu--;
            player[nn].how = 0;
            break;
        }
    } while (jue_se[x].geshu == 0);
}
void printhhh()
{
    int cm = 0;
    int sz = 0;
    for (int i = 1; i <= n; i++)
    {
        if (player[i].life == 0)
            continue;
        else if (player[i].name == "���� ")
            cm++;
        else if (player[i].name == "Ů�� " || player[i].name == "Ԥ�Լ� " || player[i].name == "���� " || player[i].name == "���� ")
            sz++;
    }
    if (sz == 0 || cm == 0)
        cout << "������Ӫʤ��" << endl;
    else
        cout << "������Ӫʤ��" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << left << setw(3) << player[i].num << ": " << player[i].name << " ";
        if (player[i].life == 0)
            cout << "����" << "\t";
        else
            cout << "���" << "\t";
        if (player[i].how == 0)
            cout << "���մ�� " << endl;
        else if (player[i].how == 1)
            cout << "���ձ�����ɱ��" << endl;
        else if (player[i].how == 2)
            cout << "���ձ�ͶƱͶ��" << endl;
        else if (player[i].how == 3)
            cout << "���ձ�Ů�׶���" << endl;
        else if (player[i].how == 4)
            cout << "���ձ�������ɱ" << endl;
    }
    system("pause");
    system("pause");
    system("pause");
}
void print(int day, int ti)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (ti == 0)
        SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
    else
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "\t\t\t\t��" << day << "�� ";
    if (ti == 0)
        cout << "����" << endl;
    else
        cout << "ҹ��" << endl;
    cout << "�ҵ�λ��:" << MY << "��" << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << player[i].num << "��λ ";
    }
    cout << endl;
    for (int i = 1; i <= 6; i++)
    {
        if (player[i].life == 1)
        {
            if (ti == 0)
                SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            else
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << "��� ";
        }
        else
        {
            if (ti == 0)
                SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED);
            else
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "������ ";
        }
    }
    if (ti == 0)
        SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
    else
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl;
    for (int i = 1; i <= 6; i++)
    {
        if (player[i].know == 0)
            cout << "δ֪ ";
        else if (player[i].know == 1)
        {
            if (player[i].name == "���� ")
                cout << "���� ";
            else
                cout << "���� ";
        }
        else if (player[i].know == 2)
            cout << player[i].name << " ";
    }
    cout << endl << endl;
    for (int i = 7; i <= n; i++)
    {
        if (i < 10)
            cout << player[i].num << "��λ ";
        else
            cout << player[i].num << "��λ ";
    }
    cout << endl;
    for (int i = 7; i <= n; i++)
    {
        if (player[i].life == 1)
        {
            if (ti == 0)
                SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            else
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << "��� ";
        }
        else
        {
            if (ti == 0)
                SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED);
            else
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "������ ";
        }
    }
    if (ti == 0)
        SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
    else
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl;
    for (int i = 7; i <= n; i++)
    {
        if (player[i].know == 0)
            cout << "δ֪ ";
        else if (player[i].know == 1)
        {
            if (player[i].name == "���� ")
                cout << "���� ";
            else
                cout << "���� ";
        }
        else if (player[i].know == 2)
            cout << player[i].name << " ";
    }
    cout << endl << endl;
}
int shou = 0;
void shoushui(int hhh, int hhhh)
{
    int x;
    Sleep(3000);
    system("cls");
    print(hhh, hhhh);
    cout << "��~��~��~��~��~~~" << endl;
    Sleep(3000);
    system("cls");
    print(hhh, hhhh);
    if (MY == shouwei && player[MY].life == 1)
    {
        cout << "������Ҫ�ػ�˭?" << endl << "����:";
        cin >> x;
        while (x == shou || x<1 || x>n || player[x].life == 0)
        {
            cout << "�������,����������" << endl << "����:";
            cin >> x;
        }
        shou = x;
    }
    else if (player[shouwei].life == 1)
    {
        cout << "������Ҫ�ػ�˭?" << endl;
        Sleep(rand() % 98);
        srand(time(0));
        x = rand() % n + 1;
        while (x == shou || player[x].life == 0)
        {
            Sleep(rand() % 98);
            srand(time(0));
            x = rand() % n + 1;
        }
        shou = x;
    }
    else
    {
        cout << "������Ҫ�ػ�˭?" << endl;
        Sleep(3000);
        shou = -1;
    }
    Sleep(3000);
    system("cls");
    print(hhh, hhhh);
    cout << "��~��~��~��~��~~~" << endl;
}
struct tou
{
    int xxx;
    int num;
    int toupiaoquan;
};
tou TOU[13];
bool cmp(tou x, tou y)
{
    if (x.xxx == y.xxx)
        return x.num < y.num;
    return x.xxx > y.xxx;
}
bool cmp1(tou x, tou y)
{
    return x.num < y.num;
}
void toupiao(int ddd, int nnn)
{
    //--------1--------
    int x;
    Sleep(2000);
    system("cls");
    print(ddd, nnn);
    cout << "���ڴ����ͶƱ";
    for (int i = 1; i <= 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        TOU[i].num = i;
        TOU[i].toupiaoquan = 1;
        TOU[i].xxx = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (player[i].life == 1)
        {
            Sleep(3000);
            if (i == MY)
            {
                cout << "��ͶƱ...(0��Ȩ)" << endl;
                cin >> x;
                while (player[x].life == 0 && x != 0)
                {
                    cin >> x;
                }
                if (x == 0)
                    cout << MY << "�������Ȩ" << endl;
                else
                    cout << MY << "�����Ͷ����" << x << "�����" << endl;
            }
            else
            {
                srand(time(0));
                if (player[i].name == "���� ")
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || player[x].name == "���� " || x == i))
                    {
                        Sleep(rand() % 98);
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
                else if (player[i].name == "Ԥ�Լ� ")
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || player[x].name != "���� " || x == i))
                    {
                        Sleep(rand() % 98);
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
                else
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || x == i))
                    {
                        Sleep(rand() % 98);
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
            }
            if (x != 0)
                TOU[x].xxx++;
        }
    }
    Sleep(3000);
    sort(TOU + 1, TOU + n + 1, cmp);
    if (TOU[2].xxx != TOU[1].xxx)
    {
        cout << "ͶƱ����," << TOU[1].num << "��ͶƱ����" << endl;
        player[TOU[1].num].life = 0;
        player[TOU[1].num].how = 2;
        Sleep(3000);
        return;
    }
    else
    {
        TOU[1].toupiaoquan = 0;
        TOU[2].toupiaoquan = 0;
        system("cls");
        print(ddd, nnn);
        cout << TOU[1].num << "��," << TOU[2].num << "��";
        int i;
        for (i = 3; i <= n; i++)
        {
            if (TOU[i].xxx == TOU[1].xxx)
            {
                TOU[i].toupiaoquan = 0;
                cout << "," << TOU[i].num << "��";
            }
            else
                break;
        }
        if (i == n + 1)
        {
            for (int i = 1; i <= n; i++)
                TOU[i].toupiaoquan = 1;
        }
        cout << "ƽƱ" << endl;
    }
    //--------2--------
    sort(TOU + 1, TOU + n + 1, cmp1);
    cout << "���ٴ�ͶƱ";
    for (int i = 1; i <= 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (player[i].life == 1 && TOU[i].toupiaoquan == 1)
        {
            Sleep(3000);
            if (i == MY)
            {
                cout << "��ͶƱ...(0��Ȩ)" << endl;
                cin >> x;
                while ((player[x].life == 0 || TOU[x].toupiaoquan == 1) && x != 0)
                {
                    cin >> x;
                }
                if (x == 0)
                    cout << MY << "�������Ȩ" << endl;
                else
                    cout << MY << "�����Ͷ����" << x << "�����" << endl;
            }
            else
            {
                srand(time(0));
                if (player[i].name == "���� ")
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || player[x].name == "���� " || x == i || TOU[x].toupiaoquan == 1))
                    {
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
                else if (player[i].name == "Ԥ�Լ� ")
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || player[x].name != "���� " || x == i || TOU[x].toupiaoquan == 1))
                    {
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
                else
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || x == i || TOU[x].toupiaoquan == 1))
                    {
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
            }
            if (x != 0 && TOU[i].toupiaoquan == 1)
                TOU[x].xxx++;
        }
    }
    Sleep(3000);
    sort(TOU + 1, TOU + n + 1, cmp);
    if (TOU[2].xxx != TOU[1].xxx)
    {
        cout << "ͶƱ����," << TOU[1].num << "��ͶƱ����" << endl;
        player[TOU[1].num].life = 0;
        player[TOU[1].num].how = 2;
        Sleep(3000);
        return;
    }
    else
    {
        TOU[1].toupiaoquan = 0;
        TOU[2].toupiaoquan = 0;
        system("cls");
        print(ddd, nnn);
        cout << TOU[1].num << "��," << TOU[2].num << "��";
        int i;
        for (i = 3; i <= n; i++)
        {
            if (TOU[i].xxx == TOU[1].xxx)
            {
                TOU[i].toupiaoquan = 0;
                cout << "," << TOU[i].num << "��";
            }
            else
                break;
        }
        if (i == n + 1)
        {
            for (int i = 1; i <= n; i++)
                TOU[i].toupiaoquan = 1;
        }
        cout << "ƽƱ" << endl;
    }
    //--------3--------
    sort(TOU + 1, TOU + n + 1, cmp1);
    cout << "���ٴ�ͶƱ";
    for (int i = 1; i <= 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (player[i].life == 1 && TOU[i].toupiaoquan == 1)
        {
            Sleep(3000);
            if (i == MY)
            {
                cout << "��ͶƱ...(0��Ȩ)" << endl;
                cin >> x;
                while ((player[x].life == 0 || TOU[x].toupiaoquan == 1) && x != 0)
                {
                    cin >> x;
                }
                if (x == 0)
                    cout << MY << "�������Ȩ" << endl;
                else
                    cout << MY << "�����Ͷ����" << x << "�����" << endl;
            }
            else
            {
                srand(time(0));
                if (player[i].name == "���� ")
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || player[x].name == "���� " || x == i || TOU[x].toupiaoquan == 1))
                    {
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
                else if (player[i].name == "Ԥ�Լ� " || player[i].name == "���� ")
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || player[x].name != "���� " || x == i || TOU[x].toupiaoquan == 1))
                    {
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
                else
                {
                    x = rand() % (n + 1);
                    while (x != 0 && (player[x].life == 0 || x == i || TOU[x].toupiaoquan == 1))
                    {
                        srand(time(0));
                        x = rand() % (n + 1);
                    }
                    if (x == 0)
                        cout << i << "�������Ȩ" << endl;
                    else
                        cout << i << "�����Ͷ����" << x << "�����" << endl;
                }
            }
            if (x != 0 && TOU[i].toupiaoquan == 1)
                TOU[x].xxx++;
        }
    }
    Sleep(3000);
    sort(TOU + 1, TOU + n + 1, cmp);
    if (TOU[2].xxx != TOU[1].xxx)
    {
        cout << "ͶƱ����," << TOU[1].num << "��ͶƱ����" << endl;
        player[TOU[1].num].life = 0;
        player[TOU[1].num].how = 2;
    }
    else
    {
        cout << "ͶƱ����,���˳���" << endl;
    }
    Sleep(5000);
}
bool game_over()
{
    int pingmin = 0;
    int langren = 0;
    int shenzhi = 0;
    for (int i = 1; i <= n; i++)
    {
        if (player[i].life == 0)
            continue;
        if (player[i].name == "���� ")
            langren++;
        else if (player[i].name == "���� ")
            pingmin++;
        else if (player[i].name == "Ů�� " || player[i].name == "Ԥ�Լ� " || player[i].name == "���� ")
            shenzhi++;
    }
    if (shenzhi == 0 || langren == 0 || pingmin == 0)
        return 1;
    return 0;
}
void night()
{
    system("cls");
    system("color 0f");
    print(1, 1);
    cout << "��~��~��~��~��~~~" << endl;
    if (n >= 12)
        shoushui(1, 1);
    Sleep(3000);
    system("cls");
    print(1, 1);
    cout << "��~��~��~��~��~~~" << endl;
    if (player[MY].name == "���� ")
    {
        Sleep(1000);
        cout << "���ͬ����:";
        for (int i = 1; i <= n; i++)
        {
            if (i == MY)
                continue;
            if (player[i].name == "���� ")
            {
                cout << player[i].num << "�� ";
                player[i].know = 2;
            }
        }
        Sleep(3000);
        cout << endl << "��������Ҫɱ˭:" << endl << "����:";
        cin >> kill1;
        Sleep(1500);
        system("cls");
        print(1, 1);
        cout << "��������Ҫɱ����" << kill1 << "�����" << endl;
    }
    else
    {
        Sleep(4000);
        system("cls");
        print(1, 1);
        cout << "��������Ҫɱ˭?" << endl;
        do
        {
            Sleep(rand() % 18);
            srand(time(0));
            int x = rand() % n + 1;
            if (player[x].name != "���� " && player[x].life == 1)
            {
                kill1 = x;
                break;
            }
        } while (1);
        Sleep(5000);
    }
    Sleep(3000);
    system("cls");
    print(1, 1);
    cout << "��~��~��~��~��~~~" << endl;
    Sleep(2000);
    system("cls");
    print(1, 1);
    cout << "Ů~��~��~��~��~~~" << endl;
    Sleep(2000);
    system("cls");
    print(1, 1);
    if (player[MY].name == "Ů�� " && player[MY].life == 1)
    {
        Sleep(1000);
        if (jieyao == 1)
        {
            cout << "����" << kill1 << "����ұ�ɱ" << endl;
            Sleep(500);
            cout << "������Ҫ����???" << endl << "A. �� B.����" << endl << "����:";
            cin >> a;
            if (a == 'A')
            {
                system("cls");
                print(1, 1);
                cout << "������Ҫ����???" << endl;
                Sleep(2000);
                system("cls");
                print(1, 1);
                cout << "����" << kill1 << "����ұ�����" << endl;
                jieyao = 0;
                if (shou != kill1)
                    kill1 = 0;
            }
            else
            {
                if (shou == kill1)
                    kill1 = 0;
                Sleep(2000);
                system("cls");
                print(1, 1);
                cout << "������Ҫ����???" << endl << "A. �� B.����" << endl << "����:";
                cin >> a;
                if (a == 'A')
                {
                    cout << "������Ҫ��˭???" << endl << "����:";
                    cin >> kill2;
                    while (player[kill2].life != 1)
                    {
                        cout << "�������,����������:" << endl;
                        cin >> kill2;
                    }
                    duyao = 0;
                }
            }
        }
        else
        {
            if (shou == kill1)
                kill1 = 0;
            Sleep(2000);
            system("cls");
            print(1, 1);
            cout << "������Ҫ����???" << endl << "A. �� B.����" << endl << "����:";
            cin >> a;
            if (a == 'A')
            {
                cout << "������Ҫ��˭???" << endl << "����:";
                cin >> kill2;
                while (player[kill2].life != 1)
                {
                    cout << "�������,����������:" << endl;
                    cin >> kill2;
                }
                duyao = 0;
            }
        }
    }
    else
    {
        bool b = 0;
        cout << "�������Ƿ�Ҫ�ý�ҩ???" << endl;
        int FFF = 0, kkkk;
        for (int i = 1; i <= n; i++)
        {
            if (player[i].life == 1 && player[i].name == "���� ")
                FFF++;
            if (player[i].name == "Ů�� ")
                kkkk = i;
        }
        if (jieyao == 1 && player[kkkk].life == 1)
        {
            if (FFF == 1)
            {
                if (shou == kill1)
                    jieyao = 1;
                else
                    jieyao = 0;
                kill1 = 0;
                b = 1;
            }
            else
                for (int i = 1; i <= n; i++)
                {
                    if (player[i].name == "Ů�� " && kill1 == i)
                    {
                        kill1 = 0;
                        if (shou == kill1)
                            jieyao = 1;
                        else
                            jieyao = 0;
                        b = 1;
                        break;
                    }
                    else if (player[i].name == "Ԥ�Լ� " && kill1 == i)
                    {
                        kill1 = 0;
                        if (shou == kill1)
                            jieyao = 1;
                        else
                            jieyao = 0;
                        b = 1;
                        break;
                    }
                }
        }
        Sleep(3000);
        if (b == 0 && duyao == 1 && player[kkkk].life == 1)
        {
            system("cls");
            print(1, 1);
            cout << "�������Ƿ�Ҫ�ö�ҩ???" << endl;
            srand(time(0));
            int x = rand() % 2;
            Sleep(1500);
            cout << "������Ҫ��˭???" << endl;
            if (x == 1)
            {
                duyao = 0;
                int y = rand() % n + 1;
                while ((player[y].name == "Ů�� " || player[y].name == "Ԥ�Լ� " || y == kill1) || player[y].life == 0)
                    y = rand() % n + 1;
                kill2 = y;
            }
        }
        else
        {
            Sleep(3000);
            system("cls");
            print(1, 1);
            cout << "�������Ƿ�Ҫ�ö�ҩ???" << endl;
            Sleep(3000);
            cout << "������Ҫ��˭???" << endl;
            Sleep(3000);
        }
    }
    Sleep(3000);
    system("cls");
    print(1, 1);
    cout << "Ů~��~��~��~��~~~" << endl;
    if (n > 6)
    {
        Sleep(3000);
        system("cls");
        print(1, 1);
        cout << "Ԥ~��~��~��~��~��~~~" << endl;
        if (player[MY].name == "Ԥ�Լ� ")
        {
            Sleep(3000);
            cout << "�����������˭???" << endl << "����:";
            int x;
            cin >> x;
            player[x].know = 1;
            Sleep(2000);
            system("cls");
            print(1, 1);
            cout << "���������:";
            if (player[x].name == "���� ")
                cout << "����" << endl;
            else
                cout << "����" << endl;
            Sleep(3000);
        }
        else
        {
            Sleep(3000);
            cout << "�����������˭???" << endl;
            Sleep(3000);
            system("cls");
            print(1, 1);
            cout << "���������:......";
            Sleep(3000);
        }
        Sleep(3000);
        system("cls");
        print(1, 1);
        cout << "Ԥ~��~��~��~��~��~~~" << endl;
    }
    Sleep(3000);
    if (kill1 != 0)
        player[kill1].life = 0;
    if (kill2 != 0)
        player[kill2].life = 0;
    player[kill1].how = 1;
    player[kill2].how = 3;
    system("cls");
    system("color F0");
    print(2, 0);
}
void night2(int hhh, int hhhh)
{
    system("cls");
    system("color 0f");
    print(hhh, hhhh);
    cout << "��~��~��~��~��~~~" << endl;
    if (n >= 12)
        shoushui(hhh, hhhh);
    Sleep(3000);
    system("cls");
    print(hhh, hhhh);
    cout << "��~��~��~��~��~~~" << endl;
    if (player[MY].name == "���� " && player[MY].life == 1)
    {
        Sleep(3000);
        cout << endl << "��������Ҫɱ˭:" << endl << "����:";
        cin >> kill1;
        Sleep(1500);
        system("cls");
        print(hhh, hhhh);
        cout << "��������Ҫɱ����" << kill1 << "�����" << endl;
    }
    else
    {
        Sleep(4000);
        system("cls");
        print(hhh, hhhh);
        cout << "��������Ҫɱ˭?" << endl;
        do
        {
            srand(time(0));
            int x = rand() % n + 1;
            if (player[x].name != "���� " && player[x].life == 1)
            {
                kill1 = x;
                break;
            }
        } while (1);
        Sleep(5000);
    }
    Sleep(3000);
    system("cls");
    print(hhh, hhhh);
    cout << "��~��~��~��~��~~~" << endl;
    Sleep(2000);
    system("cls");
    print(hhh, hhhh);
    cout << "Ů~��~��~��~��~~~" << endl;
    Sleep(2000);
    system("cls");
    print(hhh, hhhh);
    if (player[MY].name == "Ů�� " && player[MY].life == 1)
    {
        Sleep(1000);
        if (jieyao == 1)
        {
            cout << "����" << kill1 << "����ұ�ɱ" << endl;
            Sleep(500);
            cout << "������Ҫ����???" << endl << "A. �� B.����" << endl << "����:";
            cin >> a;
            if (a == 'A')
            {
                system("cls");
                print(hhh, hhhh);
                cout << "������Ҫ����???" << endl;
                Sleep(2000);
                system("cls");
                print(hhh, hhhh);
                cout << "����" << kill1 << "����ұ�����" << endl;
                jieyao = 0;
                if (shou != kill1)
                    kill1 = 0;
            }
            else
            {
                if (shou == kill1)
                    kill1 = 0;
                Sleep(2000);
                system("cls");
                print(hhh, hhhh);
                cout << "������Ҫ����???" << endl << "A. �� B.����" << endl << "����:";
                cin >> a;
                if (a == 'A')
                {
                    cout << "������Ҫ��˭???" << endl << "����:";
                    cin >> kill2;
                    while (player[kill2].life != 1)
                    {
                        cout << "�������,����������:" << endl;
                        cin >> kill2;
                    }
                    duyao = 0;
                }
            }
        }
        else if (duyao == 1)
        {
            if (shou == kill1)
                kill1 = 0;
            Sleep(2000);
            system("cls");
            print(hhh, hhhh);
            cout << "������Ҫ����???" << endl << "A. �� B.����" << endl << "����:";
            cin >> a;
            if (a == 'A')
            {
                cout << "������Ҫ��˭???" << endl << "����:";
                cin >> kill2;
                while (player[kill2].life != 1)
                {
                    cout << "�������,����������:" << endl;
                    cin >> kill2;
                }
                duyao = 0;
            }
        }
        else
        {
            Sleep(2000);
            system("cls");
            print(hhh, hhhh);
            cout << "������Ҫ����???" << endl;
        }
    }
    else
    {
        bool b = 0;
        cout << "�������Ƿ�Ҫ�ý�ҩ???" << endl;
        int FFF = 0, kkkk;
        for (int i = 1; i <= n; i++)
        {
            if (player[i].life == 1 && player[i].name == "���� ")
                FFF++;
            if (player[i].name == "Ů�� ")
                kkkk = i;
        }
        if (jieyao == 1 && player[kkkk].life == 1)
        {
            if (FFF == 1)
            {
                if (shou == kill1)
                    jieyao = 1;
                else
                    jieyao = 0;
                kill1 = 0;
                b = 1;
            }
            else
                for (int i = 1; i <= n; i++)
                {
                    if (player[i].name == "Ů�� " && kill1 == i)
                    {
                        kill1 = 0;
                        if (shou == kill1)
                            jieyao = 1;
                        else
                            jieyao = 0;
                        b = 1;
                        break;
                    }
                    else if (player[i].name == "Ԥ�Լ� " && kill1 == i)
                    {
                        kill1 = 0;
                        if (shou == kill1)
                            jieyao = 1;
                        else
                            jieyao = 0;
                        b = 1;
                        break;
                    }
                }
        }
        Sleep(3000);
        if (b == 0 && duyao == 1 && player[kkkk].life == 1)
        {
            system("cls");
            print(hhh, hhhh);
            cout << "�������Ƿ�Ҫ�ö�ҩ???" << endl;
            srand(time(0));
            int x = rand() % 2;
            Sleep(1500);
            cout << "������Ҫ��˭???" << endl;
            if (x == 1)
            {
                duyao = 0;
                int y = rand() % n + 1;
                while ((player[y].name == "Ů�� " || player[y].name == "Ԥ�Լ� " || y == kill1) || player[y].life == 0)
                    y = rand() % n + 1;
                kill2 = y;
            }
        }
        else
        {
            Sleep(3000);
            system("cls");
            print(hhh, hhhh);
            cout << "�������Ƿ�Ҫ�ö�ҩ???" << endl;
            Sleep(3000);
            cout << "������Ҫ��˭???" << endl;
            Sleep(3000);
        }
    }
    Sleep(3000);
    system("cls");
    print(hhh, hhhh);
    cout << "Ů~��~��~��~��~~~" << endl;
    if (n > 6)
    {
        Sleep(3000);
        system("cls");
        print(hhh, hhhh);
        cout << "Ԥ~��~��~��~��~��~~~" << endl;
        if (player[MY].name == "Ԥ�Լ� " && player[MY].life == 1)
        {
            Sleep(3000);
            cout << "�����������˭???" << endl << "����:";
            int x;
            cin >> x;
            player[x].know = 1;
            Sleep(2000);
            system("cls");
            print(hhh, hhhh);
            cout << "���������:";
            if (player[x].name == "���� ")
                cout << "����" << endl;
            else
                cout << "����" << endl;
            Sleep(3000);
        }
        else
        {
            Sleep(3000);
            cout << "�����������˭???" << endl;
            Sleep(3000);
            system("cls");
            print(hhh, hhhh);
            cout << "���������:......";
            Sleep(3000);
        }
        Sleep(3000);
        system("cls");
        print(hhh, hhhh);
        cout << "Ԥ~��~��~��~��~��~~~" << endl;
    }
    Sleep(3000);
    if (kill1 != 0)
        player[kill1].life = 0;
    if (kill2 != 0)
        player[kill2].life = 0;
    player[kill1].how = 1;
    player[kill2].how = 3;
    system("cls");
    system("color F0");
    print(hhh + 1, 0);
}
bool lr = 0;
void panduanlieren()
{
    if (lr == 1)
        return;
    if (MY == lieren)
    {
        cout << "����ɱһ�����" << endl;
        int x;
        cin >> x;
        while (player[x].life != 1)
        {
            cout << "�������,����������" << endl;
            cin >> x;
        }
        Sleep(1000);
        cout << lieren << "�����˷�������,��ǹ������" << x << "��" << endl;
        player[x].life = 0;
        player[x].how = 4;
    }
    else if (n >= 9)
    {
        srand(time(0));
        int x = rand() % n + 1;
        while (player[x].life != 1)
        {
            x = rand() % n + 1;
        }
        Sleep(1000);
        cout << lieren << "�����˷�������,��ǹ������" << x << "��" << endl;
        player[x].life = 0;
        player[x].how = 4;
    }
    lr = 1;
}
void print1()
{
    cout << "������,����";
    if (kill1 != 0 || kill2 != 0)
    {
        cout << kill1 << "��";
        if (kill2 != 0)
        {
            cout << "," << kill2 << "��";
            kill2 = 0;
        }
        cout << "��ɱ" << endl;
    }
    else
        cout << "��ƽ��ҹ" << endl;
}
int main()
{
    system("cls");
    cout << " " << "����ɱonline" << endl;
    cout << "��������������:" << endl;
    scanf("%d", &n);
    cout << "����ʱ�䳤�������ĵȴ�";
    init1();
    init2(n);
    int k = 1;
    do
    {
        srand(time(0));
        init3(k);
        cout << ".";
        Sleep(17);
        k++;
    } while (k <= n);
    system("cls");
    system("color F0");
    cout << "��Ϸ������ʼ";
    for (int i = 1; i <= 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    Sleep(1500);
    cout << endl << endl << "���Ҳ鿴�����......" << endl;
    Sleep(45);
    srand(time(0));
    MY = rand() % n + 1;
    cout << "���������:" << player[MY].name << endl;
    Sleep(500);
    cout << "��" << player[MY].num << "��λ��" << endl;
    system("pause");
    system("cls");
    player[MY].know = 2;
    print(1, 0);
    cout << "��������ҹ��";
    for (int i = 1; i <= 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    night();
    print1();
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    toupiao(2, 0);
    system("cls");
    print(2, 0);
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    else if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    cout << "��������ҹ��";
    for (int i = 1; i <= 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    night2(2, 1);
    print1();
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    toupiao(3, 0);
    system("cls");
    print(3, 0);
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    else if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    cout << "��������ҹ��";
    for (int i = 1; i <= 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    night2(3, 1);
    print1();
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    if (player[lieren].life == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    toupiao(4, 0);
    system("cls");
    print(4, 0);
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    else if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    cout << "��������ҹ��";
    for (int i = 1; i <= 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    night2(4, 1);
    print1();
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    if (player[lieren].life == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    toupiao(5, 0);
    system("cls");
    print(5, 0);
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    else if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    cout << "��������ҹ��";
    for (int i = 1; i <= 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    night2(5, 1);
    print1();
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    if (player[lieren].life == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    toupiao(6, 0);
    system("cls");
    print(6, 0);
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    else if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    cout << "��������ҹ��";
    for (int i = 1; i <= 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    night2(6, 1);
    print1();
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    if (player[lieren].life == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    toupiao(7, 0);
    system("cls");
    print(7, 0);
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    else if (player[lieren].life == 0 && lr == 0)
    {
        panduanlieren();
    }
    if (game_over())
    {
        Sleep(1000);
        system("cls");
        cout << "��Ϸ����" << endl; printhhh();
        return 0;
    }
    while (1)
        system("pause");
    return 0;
}
