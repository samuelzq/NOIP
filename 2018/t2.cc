#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define LL long long
int main()
{
    int n, i, m, p1, p2;
    LL s1, s2;
    cin >> n;
    LL c[n + 1];
    for(i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    LL lPower = 0; // 龙势力
    for(i = 1; i < m; i++)
    {
        lPower += c[i] * (m - i);
    }
    LL rPower = 0;
    for(i = m + 1; i <= n; i++)
    {
        rPower += c[i] * (i - m);
    }

    LL gap = abs(lPower - rPower); // 双方的气势差
    p2 = m;          // 暂放在m的位置上
    float dist = gap * 1.0 / s2; // s2离m兵营的距离
    if(rPower > lPower)  // 虎势力大，s2要放在龙方
    {
        //这里floor()也可以改为int()
        p2 = m - floor(dist + 0.5);
        if(p2 < 1)
        {
            p2 = 1; // 不能越界
        }
    }
    else if(rPower < lPower)
    {
        // 注意，这里0.5是要舍弃掉的，大于0.5才加1
        p2 = m + ceil(dist - 0.5);
        if(p2 > n)
        {
            p2 = n; // 不能越界
        }
    }
    cout << p2 << endl;
    return 0;
}