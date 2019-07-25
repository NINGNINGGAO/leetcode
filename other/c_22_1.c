/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//回溯算法
//left:可加入左括号数；right:可加入右括号数
//i用来记录某一种可能组合的字符存储下标，max=n;
void gen(int left, int right, int i, int max, int* ptr, char* s, char** res)
{
	if (i == (2 * max))//所有括号都已经加入
	{
		s[i] = '\0';
		res[*ptr] = (char*)malloc(sizeof(char) * (i + 1));
		if (res[*ptr])
		{
			int j=0;
			while (s[j] != '\0')
			{
				res[*ptr][j] = s[j];
				j++;
			}
			res[*ptr][j] = '\0';
		}
		(*ptr)++;
		return;
	}
	else
	{
		if (left > 0)
		{
			s[i] = '(';
			gen(left - 1, right, i + 1, max, ptr, s, res);
		}
		if (right > 0 && right > left)
		{
			s[i] = ')';
			gen(left, right - 1, i + 1, max, ptr, s, res);
		}
	}
}

char** generateParenthesis(int n, int* returnSize) {
	*returnSize = 0;
	char** res = (char**)malloc(sizeof(char*) * 1500);
	char* s = (char*)malloc(sizeof(char) * (2 * n + 1));
	if (s)
	{
		s[2 * n] = '\0';
	}
	gen(n, n, 0, n, returnSize, s, res);
	return res;
}
