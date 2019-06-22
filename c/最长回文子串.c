char g_subStr[1002] = {0};
#define MIN(a, b) ((a < b) ? a : b)

char *longestPalindrome(char *s) 
{
	int i = 0;
	int j = 0;
	int len;
	int max = 0;
	int center = 0;
	int rPos = 0;
	int r_center = 0;
	int p[2003] = {0};
	char extendStr[2003] = {0};

	if (s == NULL) {
		return NULL;
	}

	len = strlen(s);
	if (len == 0 || len == 1) {
		return s;
	}

	extendStr[i++] = '(';
	while (i < (len * 2 + 1)) {
		extendStr[i++] = '#';
		extendStr[i++] = s[j++];
	}
	extendStr[i++] = '#';
	extendStr[i] = 0;

	for (i = 1; i < len * 2 + 2; i++) {
		p[i] = (i<rPos) ? (MIN(rPos - i, p[r_center * 2 - i])) : 1;
		
		while (extendStr[i - p[i]] == extendStr[i + p[i]]) {
			p[i]++;
		}
		
		if (i + p[i] > rPos) {
			rPos = i + p[i];
			r_center = i;
		}

		if (p[i] > max) {
			max = p[i];
			center = i;
		}
	}

	j = (center - max + 1) / 2;
	for (i = 0; i < max - 1; i++) {
		g_subStr[i] = s[j++];
	}
	g_subStr[i] = 0;
	return g_subStr;
}
