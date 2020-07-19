const int MAXN = 101;
const int SIZE = 50001;

int dp[SIZE];
int volume[MAXN], value[MAXN], c[MAXN];
int n, v;           //  总物品数，背包容量

//  01背包
void ZeroOnepark(int val, int vol)
{
    for (int j = v ; j >= vol; j--)
    {
        dp[j] = max(dp[j], dp[j - vol] + val);
    }
}

//  完全背包
void Completepark(int val, int vol)
{
    for (int j = vol; j <= v; j++)
    {
        dp[j] = max(dp[j], dp[j - vol] + val);
    }
}

//  多重背包
void Multiplepark(int val, int vol, int amount)
{
    if (vol * amount >= v)
    {
        Completepark(val, vol);
    }
    else
    {
        int k = 1;
        while (k < amount)
        {
            ZeroOnepark(k * val, k * vol);
            amount -= k;
            k <<= 1;
        }
        if (amount > 0)
        {
            ZeroOnepark(amount * val, amount * vol);
        }
    }
}

int main()
{
    while (cin >> n >> v)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> volume[i] >> value[i] >> c[i];      //   费用，价值，数量
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            Multiplepark(value[i], volume[i], c[i]);
        }
        cout << dp[v] << endl;
    }
    return 0;
}
