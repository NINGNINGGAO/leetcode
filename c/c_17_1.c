const int lens[8] = {3,3,3,3,3,4,3,4};
const char digitsletter[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

char ** letterCombinations(char * digits, int* returnSize){
    if (!digits || *digits =='\0') {
        *returnSize = 0;
        return NULL;
    }
    
    char *head = digits;
    
    int count = 1;
    int len = 0;
    while(*head != '\0') {
        count *= lens[*head - '2'];
        len++;
        head++;
    }
    *returnSize = count;
    
    head = digits;
    char** result = (char**)malloc(sizeof(char*) * count);
    for (int i = 0; i < count; i++) {
        result[i] = (char*)malloc(sizeof(char) * (len + 1));
        result[i][len] = '\0';
    }
    
    int prelen = 1;
    int index = 0;
    int pos;
    for (int i = 0; i < len; i++) {
        pos = 0;
        int numberindex = digits[i] - '2';
        prelen = lens[numberindex] * prelen;
        int siz = count / prelen;
        while (pos < count) {
            index = pos / siz % lens[numberindex];
            result[pos][i] = digitsletter[numberindex][index];
            pos++;
        }
    }
    return result;
}



