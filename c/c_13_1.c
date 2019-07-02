int romanToInt(char * s){
    int data = 0;
    char *p = s;
    while (*s != '\0') {
        switch (*s) {
            case 'M' : 
                data += 1000; 
                break;
            case 'D' : 
                data += 500; 
                break;
            case 'C' : 
                p++;
                switch (*p) {
                    case 'M' : 
                        data += 900;
                        s++;
                        break;
                    case 'D' :
                        data += 400;
                        s++;
                        break;
                    default:
                        data += 100;
                        break 
                }
                break;
            case 'L':
                data += 50;
                break;
            case 'X':
                p++;
                switch (*p) {
                    case 'C' :
                        data += 90;
                        s++;
                        break;
                    case 'L' :
                        data += 40;
                        s++;
                        break;
                    default:
                        data += 10;
                }
            case 'V':
                data += 5;
                break;
            case 'I':
                p++;
                switch (*p) {
                    case 'X':
                        data += 9;
                        s++;
                        break;
                    case 'V':
                        data += 4;
                        s++;
                        break;
                    default:
                        data += 1;
                        break;
                }
            break;
        }
        s++;
        p = s;
    }
    return data;
}
