
char** letterCombinations(char* digits, int* returnSize)
{
    char *c[8]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    *returnSize=0;
    char**a;
    if(digits[0]=='\0')
        return a;
    *returnSize=1;
    for(int i=0; i<strlen(digits); i++)
        (*returnSize)*=strlen(c[digits[i]-'2']);
    int size=*returnSize;//个数
    //printf("%d\n\n",size);
    a=(char**)malloc(sizeof(char*)*size);
    for(int i=0; i<size; i++)
    {
        a[i]=(char*)malloc(sizeof(char)*strlen(digits)+1);
    }


    int d[strlen(digits)];
    for(int i=0; i<strlen(digits); i++)
        d[i]=digits[i]-'2';//d输入的整数数字

    int b[strlen(digits)];
    for(int i=0; i<strlen(digits); i++)
        b[i]=strlen(c[digits[i]-'2']);//d数字的位数
    if(strlen(digits)==1)
    {
        for(int i=0; i<b[0]; i++)
        {
            a[i][0]=c[d[0]][i];
            a[i][1]='\0';
        }
        return a;
    }
    int tmp=0;
    int mid[size][strlen(digits)];
    for(int i=0; i<size; i++)
    {
        for(int j=strlen(digits)-1; j>0; j--)
        {
            if(j==strlen(digits)-1)
            {
                mid[i][j]=tmp%b[j];
                mid[i][j-1]=tmp/b[j];
            }
            else
            {
                mid[i][j-1]=mid[i][j]/b[j];
                mid[i][j]=mid[i][j]%b[j];
            }
        }
        tmp++;
    }
    for(int i=0; i<size; i++)
        for(int j=0; j<sizeof(char)*strlen(digits)+1; j++)
        {
            if(j==strlen(digits))
                a[i][j]='\0';
            else
                a[i][j]=c[d[j]][mid[i][j]];
        }
    return a;

}


