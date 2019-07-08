const short lens[8] = {3,3,3,3,3,4,3,4}; 
const char digitsLetter[8][5] = {"abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    
    if(!digits || *digits == '\0')  
    {
        *returnSize = 0;
        return  NULL;
    }
    
    char *head = digits;
    
    int count = 1;
    int len = 0;
    while(*head != '\0')
    {
        count *= lens[*head-'2'];
        len++;
        head++;
    }
    
    *returnSize = count;
    char** result = (char**)malloc(sizeof(char*) * count);
    int i;
    for(i = 0; i < count; i++)
    {
        char *temp = (char*)malloc(sizeof(char) * (len + 1));
        temp[len] = '\0';
        result[i] = temp;
    }
    
    head = digits;
    
    int pos = 0;
    int index = 0;
    int preLen = 1;
    for(i = 0; i< len; i++)
    {
        pos = 0;
        int numberIndex = digits[i] - '2';
        preLen = lens[numberIndex]*preLen;
        int size = count / preLen ;
        while(pos < count)
        {
            index = pos / size % lens[numberIndex];
            result[pos][i] = digitsLetter[numberIndex][index];
            pos++;
        }
    }
    
    return result;
}

