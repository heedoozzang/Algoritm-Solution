#include<iostream>
#include<vector>

#define endl "\n"
#define BACK 1
#define DOWN 2
#define FRONT 3
#define LEFT 4
#define RIGHT 5
#define UP 6
using namespace std;
// 1 = µÞ¸é, 2 = ¹Ø¸é, 3 = ¾Õ¸é, 4 = ¿ÞÂÊ¸é, 5 = ¿À¸¥ÂÊ¸é, 6 = À­¸é

vector<int> Cube[7], C_Cube[7];

void Input()
{
    int Idx = 1;
    int Cnt = 0;
    for (int i = 0; i < 24; i++)
    {
        int a; cin >> a;
        Cube[Idx].push_back(a);
        Cnt++;

        if (Cnt == 4)
        {
            Cnt = 0;
            Idx++;
        }
    }
}

void Remake_Cube()
{
    int Temp;
    Temp = Cube[1].at(0);
    Cube[1].at(0) = Cube[1].at(1);
    Cube[1].at(1) = Temp;
    Temp = Cube[1].at(2);
    Cube[1].at(2) = Cube[1].at(3);
    Cube[1].at(3) = Temp;

    Temp = Cube[2].at(0);
    Cube[2].at(0) = Cube[2].at(1);
    Cube[2].at(1) = Temp;
    Temp = Cube[2].at(2);
    Cube[2].at(2) = Cube[2].at(3);
    Cube[2].at(3) = Temp;

    Temp = Cube[3].at(0);
    Cube[3].at(0) = Cube[3].at(2);
    Cube[3].at(2) = Temp;
    Temp = Cube[3].at(1);
    Cube[3].at(1) = Cube[3].at(3);
    Cube[3].at(3) = Temp;

    Temp = Cube[4].at(1);
    Cube[4].at(1) = Cube[4].at(2);
    Cube[4].at(2) = Temp;

    Temp = Cube[5].at(0);
    Cube[5].at(0) = Cube[5].at(3);
    Cube[5].at(3) = Temp;

    Temp = Cube[6].at(0);
    Cube[6].at(0) = Cube[6].at(1);
    Cube[6].at(1) = Temp;
    Temp = Cube[6].at(2);
    Cube[6].at(2) = Cube[6].at(3);
    Cube[6].at(3) = Temp;
}

void Resetting(int Idx, int Dir)
{
    if (Dir == 0)
    {
        int Temp = C_Cube[Idx].at(0);
        C_Cube[Idx].at(0) = C_Cube[Idx].at(2);
        C_Cube[Idx].at(2) = C_Cube[Idx].at(3);
        C_Cube[Idx].at(3) = C_Cube[Idx].at(1);
        C_Cube[Idx].at(1) = Temp;
    }
    else
    {
        int Temp = C_Cube[Idx].at(0);
        C_Cube[Idx].at(0) = C_Cube[Idx].at(1);
        C_Cube[Idx].at(1) = C_Cube[Idx].at(3);
        C_Cube[Idx].at(3) = C_Cube[Idx].at(2);
        C_Cube[Idx].at(2) = Temp;
    }
}


bool Turn(int Idx, int Dir)    // Dir = 0 ½Ã°è¹æÇâ, 1 = ¹Ý½Ã°è¹æÇâ
{
    for (int i = 1; i < 7; i++) C_Cube[i] = Cube[i];

    // 1 = µÞ¸é, 2 = ¹Ø¸é, 3 = ¾Õ¸é, 4 = ¿ÞÂÊ¸é, 5 = ¿À¸¥ÂÊ¸é, 6 = À­¸é

    if (Idx == 1)
    {
        if (Dir == 0)
        {
            int Temp, Temp2;
            Temp = C_Cube[UP].at(0);
            Temp2 = C_Cube[UP].at(1);

            C_Cube[UP].at(0) = C_Cube[RIGHT].at(1);
            C_Cube[UP].at(1) = C_Cube[RIGHT].at(3);

            C_Cube[RIGHT].at(1) = C_Cube[DOWN].at(0);
            C_Cube[RIGHT].at(3) = C_Cube[DOWN].at(1);

            C_Cube[DOWN].at(0) = C_Cube[LEFT].at(2);
            C_Cube[DOWN].at(1) = C_Cube[LEFT].at(0);

            C_Cube[LEFT].at(2) = Temp;
            C_Cube[LEFT].at(0) = Temp2;
        }
        else
        {
            int Temp, Temp2;
            Temp = C_Cube[UP].at(0);
            Temp2 = C_Cube[UP].at(1);

            C_Cube[UP].at(0) = C_Cube[LEFT].at(2);
            C_Cube[UP].at(1) = C_Cube[LEFT].at(0);

            C_Cube[LEFT].at(2) = C_Cube[DOWN].at(0);
            C_Cube[LEFT].at(0) = C_Cube[DOWN].at(1);

            C_Cube[DOWN].at(0) = C_Cube[RIGHT].at(1);
            C_Cube[DOWN].at(1) = C_Cube[RIGHT].at(3);

            C_Cube[RIGHT].at(1) = Temp;
            C_Cube[RIGHT].at(3) = Temp2;

        }
    }
    else if (Idx == 2)
    {
        if (Dir == 0)
        {
            int Temp, Temp2;
            Temp = C_Cube[FRONT].at(2);
            Temp2 = C_Cube[FRONT].at(3);

            C_Cube[FRONT].at(2) = C_Cube[LEFT].at(2);
            C_Cube[FRONT].at(3) = C_Cube[LEFT].at(3);

            C_Cube[LEFT].at(2) = C_Cube[BACK].at(2);
            C_Cube[LEFT].at(3) = C_Cube[BACK].at(3);

            C_Cube[BACK].at(2) = C_Cube[RIGHT].at(2);
            C_Cube[BACK].at(3) = C_Cube[RIGHT].at(3);

            C_Cube[RIGHT].at(2) = Temp;
            C_Cube[RIGHT].at(3) = Temp2;
        }
        else
        {
            int Temp, Temp2;
            Temp = C_Cube[FRONT].at(2);
            Temp2 = C_Cube[FRONT].at(3);

            C_Cube[FRONT].at(2) = C_Cube[RIGHT].at(2);
            C_Cube[FRONT].at(3) = C_Cube[RIGHT].at(3);

            C_Cube[RIGHT].at(2) = C_Cube[BACK].at(2);
            C_Cube[RIGHT].at(3) = C_Cube[BACK].at(3);

            C_Cube[BACK].at(2) = C_Cube[LEFT].at(2);
            C_Cube[BACK].at(3) = C_Cube[LEFT].at(3);

            C_Cube[LEFT].at(2) = Temp;
            C_Cube[LEFT].at(3) = Temp2;
        }
    }
    else if (Idx == 3)
    {
        if (Dir == 0)
        {
            int Temp, Temp2;
            Temp = C_Cube[UP].at(2);
            Temp2 = C_Cube[UP].at(3);

            C_Cube[UP].at(2) = C_Cube[LEFT].at(3);
            C_Cube[UP].at(3) = C_Cube[LEFT].at(1);

            C_Cube[LEFT].at(3) = C_Cube[DOWN].at(0);
            C_Cube[LEFT].at(1) = C_Cube[DOWN].at(1);

            C_Cube[DOWN].at(0) = C_Cube[RIGHT].at(0);
            C_Cube[DOWN].at(1) = C_Cube[RIGHT].at(2);

            C_Cube[RIGHT].at(0) = Temp;
            C_Cube[RIGHT].at(2) = Temp2;

        }
        else
        {
            int Temp, Temp2;
            Temp = C_Cube[UP].at(2);
            Temp2 = C_Cube[UP].at(3);

            C_Cube[UP].at(2) = C_Cube[RIGHT].at(0);
            C_Cube[UP].at(3) = C_Cube[RIGHT].at(2);

            C_Cube[RIGHT].at(0) = C_Cube[DOWN].at(0);
            C_Cube[RIGHT].at(2) = C_Cube[DOWN].at(1);

            C_Cube[DOWN].at(0) = C_Cube[LEFT].at(3);
            C_Cube[DOWN].at(1) = C_Cube[LEFT].at(1);

            C_Cube[LEFT].at(3) = Temp;
            C_Cube[LEFT].at(1) = Temp2;
        }
    }
    else if (Idx == 4)
    {
        if (Dir == 0)
        {
            int Temp, Temp2;
            Temp = C_Cube[FRONT].at(0);
            Temp2 = C_Cube[FRONT].at(2);

            C_Cube[FRONT].at(0) = C_Cube[UP].at(0);
            C_Cube[FRONT].at(2) = C_Cube[UP].at(2);

            C_Cube[UP].at(0) = C_Cube[BACK].at(3);
            C_Cube[UP].at(2) = C_Cube[BACK].at(1);

            C_Cube[BACK].at(3) = C_Cube[DOWN].at(1);
            C_Cube[BACK].at(1) = C_Cube[DOWN].at(3);

            C_Cube[DOWN].at(1) = Temp;
            C_Cube[DOWN].at(3) = Temp2;
        }
        else
        {
            int Temp, Temp2;
            Temp = C_Cube[FRONT].at(0);
            Temp2 = C_Cube[FRONT].at(2);

            C_Cube[FRONT].at(0) = C_Cube[DOWN].at(1);
            C_Cube[FRONT].at(2) = C_Cube[DOWN].at(3);

            C_Cube[DOWN].at(1) = C_Cube[BACK].at(3);
            C_Cube[DOWN].at(3) = C_Cube[BACK].at(1);

            C_Cube[BACK].at(3) = C_Cube[UP].at(0);
            C_Cube[BACK].at(1) = C_Cube[UP].at(2);

            C_Cube[UP].at(0) = Temp;
            C_Cube[UP].at(2) = Temp2;
        }
    }
    else if (Idx == 5)
    {
        if (Dir == 0)
        {
            int Temp, Temp2;
            Temp = C_Cube[UP].at(1);
            Temp2 = C_Cube[UP].at(3);

            C_Cube[UP].at(1) = C_Cube[FRONT].at(1);
            C_Cube[UP].at(3) = C_Cube[FRONT].at(3);

            C_Cube[FRONT].at(1) = C_Cube[DOWN].at(0);
            C_Cube[FRONT].at(3) = C_Cube[DOWN].at(2);

            C_Cube[DOWN].at(0) = C_Cube[BACK].at(2);
            C_Cube[DOWN].at(2) = C_Cube[BACK].at(0);

            C_Cube[BACK].at(2) = Temp;
            C_Cube[BACK].at(0) = Temp2;
        }
        else
        {
            int Temp, Temp2;
            Temp = C_Cube[UP].at(1);
            Temp2 = C_Cube[UP].at(3);

            C_Cube[UP].at(1) = C_Cube[BACK].at(2);
            C_Cube[UP].at(3) = C_Cube[BACK].at(0);

            C_Cube[BACK].at(2) = C_Cube[DOWN].at(0);
            C_Cube[BACK].at(0) = C_Cube[DOWN].at(2);

            C_Cube[DOWN].at(0) = C_Cube[FRONT].at(1);
            C_Cube[DOWN].at(2) = C_Cube[FRONT].at(3);

            C_Cube[FRONT].at(1) = Temp;
            C_Cube[FRONT].at(3) = Temp2;
        }
    }
    else if (Idx == 6)
    {
        if (Dir == 0)
        {
            int Temp, Temp2;
            Temp = C_Cube[FRONT].at(0);
            Temp2 = C_Cube[FRONT].at(1);

            C_Cube[FRONT].at(0) = C_Cube[RIGHT].at(0);
            C_Cube[FRONT].at(1) = C_Cube[RIGHT].at(1);

            C_Cube[RIGHT].at(0) = C_Cube[BACK].at(0);
            C_Cube[RIGHT].at(1) = C_Cube[BACK].at(1);

            C_Cube[BACK].at(0) = C_Cube[LEFT].at(0);
            C_Cube[BACK].at(1) = C_Cube[LEFT].at(1);

            C_Cube[LEFT].at(0) = Temp;
            C_Cube[LEFT].at(1) = Temp2;
        }
        else
        {
            int Temp, Temp2;
            Temp = C_Cube[FRONT].at(0);
            Temp2 = C_Cube[FRONT].at(1);

            C_Cube[FRONT].at(0) = C_Cube[LEFT].at(0);
            C_Cube[FRONT].at(1) = C_Cube[LEFT].at(1);

            C_Cube[LEFT].at(0) = C_Cube[BACK].at(0);
            C_Cube[LEFT].at(1) = C_Cube[BACK].at(1);

            C_Cube[BACK].at(0) = C_Cube[RIGHT].at(0);
            C_Cube[BACK].at(1) = C_Cube[RIGHT].at(1);

            C_Cube[RIGHT].at(0) = Temp;
            C_Cube[RIGHT].at(1) = Temp2;
        }
    }
    Resetting(Idx, Dir);

    for (int i = 1; i < 7; i++)
    {
        int Temp = C_Cube[i].at(0);
        for (int j = 0; j < C_Cube[i].size(); j++)
        {
            if (C_Cube[i][j] != Temp) return false;
        }
    }
    return true;

}

void Solution()
{
    Remake_Cube();
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool T = Turn(i, j);
            if (T == true)
            {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
    return;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}