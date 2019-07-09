

bool isValid(char * s){
    char* newstr = (char*)calloc(sizeof(char), 10000);
    int k = -1;
    while (*s != '\0') {
        if (*s == '(' || *s == '[' || *s == '{') {
            newstr[++k] = *s;
        } else if (*s == ')' && k >= 0 && newstr[k] == '(') {
            k--;
        } else if (*s == ']' && k >= 0 && newstr[k] == '[') {
            k--;
        } else if (*s == '}' && k >= 0 && newstr[k] == '{') {
            k--;
        } else {
            return false;
        }
        s++;
    }
    if (k != -1) {
        return false;
    } else {
        return true;
    }
}
