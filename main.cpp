//Author: Lixiang
#include <stdio.h>
#include "solve.h"
int main()
{
    freopen("data.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solve sol;
    sol.init();
    sol.input();
    sol.solve();
    return 0;
}