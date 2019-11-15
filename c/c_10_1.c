/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:36:39
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:39:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}
bool isMatch(char * s, char * p){
    if (strlen(p) == 0) return (strlen(s) == 0);
    bool flag = ((strlen(s) != 0) && (p[0] == s[0] || p[0] == '.'));
    if (strlen(p) >= 2 && p[1] == '*'){
        return (isMatch(s, p+2) || (flag && isMatch(s+1,p)));
    } else {
        return (flag && isMatch(s+1,p+1));
    }
}
