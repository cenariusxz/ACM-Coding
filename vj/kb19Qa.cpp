#include<stdio.h>
#include<string.h>
#include<math.h>
long long int N, B;
long long int a[100][5], b[5];
void pow_mod(long long int n, int e)
{
    if(n == 1)
    {
        a[e][0] = a[e][1] = a[e][2] = 1;
        a[e][3] = 0;
        return ;
    }
    pow_mod(n / 2, e + 1);
    a[e][0] = (a[e + 1][0] * a[e + 1][0] + a[e + 1][1] * a[e + 1][2]) % B;
    a[e][1] = (a[e + 1][0] * a[e + 1][1] + a[e + 1][1] * a[e + 1][3]) % B;
    a[e][2] = (a[e + 1][2] * a[e + 1][0] + a[e + 1][3] * a[e + 1][2]) % B;
    a[e][3] = (a[e + 1][2] * a[e + 1][1] + a[e + 1][3] * a[e + 1][3]) % B;
    if(n % 2)
    {
        b[0] = (a[e][0] * a[0][0] + a[e][1] * a[0][2]) % B;
        b[1] = (a[e][0] * a[0][1] + a[e][1] * a[0][3]) % B;
        b[2] = (a[e][2] * a[0][0] + a[e][3] * a[0][2]) % B;
        b[3] = (a[e][2] * a[0][1] + a[e][3] * a[0][3]) % B;
        a[e][0] = b[0], a[e][1] = b[1], a[e][2] = b[2], a[e][3] = b[3];
    }
}
void solve()
{
    a[0][0] = a[0][1] = a[0][2] = 1;
    a[0][3] = 0;
    if(N == 0)
    {
        printf("1\n");
        return ;
    }
    pow_mod(N, 1);
    printf("%lld\n", (2 * a[1][0] + B - 1) % B);
}
int main()
{
    int t = 0;
    for(;;)
    {
        scanf("%lld%lld", &N, &B);
        if(!N && !B)
            break;
        printf("Case %d: %lld %lld ", ++ t, N, B);
        solve();
    }
    return 0;
}
