/////////////
c[0][0] = 1;
for (int i = 1; i < MAXN; i++)
{
	c[i][0] = 1;
	for (int j = 1; j <= i; j++)
	{
		c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}

///////////////
long long choose(int n, int r)
{
	r = min(r, n - r);
	long long result = 1;
	for (int i = 0; i < n; i++)
	{
		if (i <= r && i > 0)
		{
			result /= (i);
		}
		if (i <= r - 1)
		{
			result *= (n - i);
		}
		if (i > r && i > r - 1)
		{
			break;
		}
	}
	return result;
}