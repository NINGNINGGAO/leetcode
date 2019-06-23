#define MIN(a, b) ((a < b) ? a : b)

char *longestPalindrome(char *s) 
{
    int len1 = strlen(s);
    int len2 = 2 * len1 + 1;
    if (len1 < 1) return "";
    
    char *s1 = malloc(sizeof(char) * (len2));
    int j = 0;
    int k = 0;
    while (j < len1) {
        s1[k++] = '#';
        s1[k++] = s[j++];
    }
    s1[len2 - 1] = '#';
    
    int MaxRight = 0;
    int pos = 0;
    int MaxRL = 0;
    int MaxPos = 0;
    int RL[len2];
    
    for (int i = 0; i < len2; i++) {
        if (i < MaxRight) {
            RL[i] = MIN(RL[2 * pos - i], MaxRight - i);
        } else {
            RL[i] = 1;
        }
        
        while (i - RL[i] >= 0 && i + RL[i] < len2 && s1[i - RL[i]] == s1[i + RL[i]])
            RL[i] += 1;
        
        if (RL[i] + i - 1 > MaxRight) {
            MaxRight = RL[i] + i - 1;
            pos = i;
        }
        
        if (MaxRL <= RL[i]) {
            MaxRL = RL[i];
            MaxPos = i;
        }
    }
    char *p = malloc(sizeof(char) * (MaxRL));
    strncpy(p, s + (MaxPos - MaxRL + 1) / 2, MaxRL - 1);
    p[MaxRL - 1] = '\0';
    return p;
}
