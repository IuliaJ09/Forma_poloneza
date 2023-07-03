#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prior(char a)
{
	if (strchr("()", a) != 0)
		return 0;
	else
		if (strchr("*/", a))
			return 1;
		else
			if (strchr("+-", a))
				return 2;
}

int main()
{
	int i, top_st = -1, top_fp = -1,v[30],n,stv[101],aux,top_stv=-1;
	char s[101], op;
	char st[101], fp[101];
	scanf("%s", s);
	printf("nr de variabile:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			fp[++top_fp] = s[i];
		else
			st[++top_st] = s[i];
		if (prior(s[i]) == 2)
		{
			op = st[top_st];
			top_st--;
			while (prior(st[top_st]) == 1)
			{
				fp[++top_fp] = st[top_st];
				top_st--;
			}
			st[++top_st] = op;
		}
		else
			if (s[i] == ')')
			{
				top_st--;
				while (st[top_st] != '(')
				{

					fp[++top_fp] = st[top_st];
					top_st--;
				}
				top_st--;
			}


	}
	for (i = 0; i <= top_st; i++)
		fp[++top_fp] = st[top_st - i];

	for (i = 0; i <= top_fp; i++)
		printf("%c", fp[i]);
	printf("\n");
	for (i = 0; i <= top_fp; i++)
	{
		if (fp[i] >= 'a' && fp[i] <= 'z')
			stv[++top_stv] = v[fp[i] - 'a'];
		else
		{
			if (fp[i] == '+')
			{
				aux = stv[top_stv] + stv[top_stv-1];
				top_stv--;
				stv[top_stv] = aux;
			}
			if (fp[i] == '*')
			{
				aux = stv[top_stv] * stv[top_stv - 1];
				top_stv--;
				stv[top_stv] = aux;
			}
			if (fp[i] == '/')
			{
				aux = stv[top_stv-1] / stv[top_stv ];
				top_stv--;
				stv[top_stv] = aux;
			}
			if (fp[i] == '-')
			{
				aux = stv[top_stv - 1] -stv[top_stv];
				top_stv--;
				stv[top_stv] = aux;
			}
		}
	}
	printf("%d\n", stv[0]);
	system("pause");
	return 0;
}