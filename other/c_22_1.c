
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backTrack(char** mtxRes, int nCnt, int nOpen, int nClose, char* szTemp, int nTempLen, int* returnSize)
{
    if(nTempLen == 2*nCnt)
    {
        int nCurRow = *returnSize;
        mtxRes[nCurRow] = (char*)malloc(sizeof(char) * (2*nCnt+1));
        strncpy(mtxRes[nCurRow], szTemp, (2*nCnt+1));
        *returnSize = *returnSize + 1;
        return;
    }
    if(nOpen < nCnt)
    {
        szTemp[nTempLen] = '(';
        backTrack(mtxRes, nCnt, nOpen+1, nClose, szTemp, nTempLen+1, returnSize);
    }
    if(nClose < nOpen)
    {
        szTemp[nTempLen] = ')';
        backTrack(mtxRes, nCnt, nOpen, nClose+1, szTemp, nTempLen+1, returnSize);
    }
}
char ** generateParenthesis(int n, int* returnSize){
    if(n == 0)
        return NULL;
    char** mtxRes = (char**)malloc(sizeof(char*) * 20000);
    char* szTemp = (char*)malloc(sizeof(char) * (2*n+1));
    szTemp[(2*n)] = '\0';
    *returnSize = 0;
    backTrack(mtxRes, n, 0, 0, szTemp, 0, returnSize);
    return mtxRes;
}
