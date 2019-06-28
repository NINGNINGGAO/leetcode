typedef struct {
    bool used;
    bool rslt;
} ysc;

bool isDp(ysc g_rslt[100][100], char * s, char * p, int i, int j)
{
    bool matched = false;
    bool rslt = false;

    if (g_rslt[i][j].used) return g_rslt[i][j].rslt;

    if (strlen(p) == j) {
        rslt = (strlen(s) == i) ? true : false;
    } else {
        if ((i < strlen(s)) && (p[j] == s[i] || p[j] == '.')) {
            matched = true;
        }

        if ((j + 1 < strlen(p)) && (p[j+1] == '*')) {
            rslt = isDp(g_rslt, s, p, i, j+2);
            if (!rslt && matched) {
                rslt = rslt || isDp(g_rslt, s, p, i+1, j);
            }
        } else {
            if (matched) {
                rslt = isDp(g_rslt, s, p, i+1, j+1);
            }
        }
    }
    g_rslt[i][j].rslt = rslt;
    g_rslt[i][j].used = true;
    return g_rslt[i][j].rslt;
}

bool isMatch(char * s, char * p){
    ysc g_rslt[100][100] = {0};
    return isDp(g_rslt, s, p, 0, 0);
}

