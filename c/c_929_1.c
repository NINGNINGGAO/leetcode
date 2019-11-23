/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 11:13:00
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 11:56:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    char local[128];
    char domain[128];
};
int cmp(const void* a, const void* b) {
    return strcmp(((struct Node*)a)->local, ((struct Node*)b)->local);
}
int numUniqueEmails(char ** emails, int emailsSize){
    struct Node *temp = malloc(sizeof(struct Node) * emailsSize);
    memset(temp, 0, sizeof(struct Node) * emailsSize);
    for (int i = 0; i < emailsSize; i++) {
        int eLen = strlen(emails[i]);
        int j = 0;
        while (emails[i][j] != '@') j++;
        emails[i][j] = '\0';
        sprintf(temp[i].local, "%s", emails[i]);
        sprintf(temp[i].domain, "%s", &(emails[i][j + 1]));
    }
    for (int i = 0; i < emailsSize; i++) {
        for (int j = 0; j < strlen(temp[i].local); j++) {
            if (temp[i].local[j] == '+') {
                temp[i].local[j] = '\0';
                break;
            } else if (temp[i].local[j] == '.') {
                char* mid = &((temp[i].local[j + 1]));
                temp[i].local[j] = '\0';
                sprintf(temp[i].local, "%s%s", temp[i].local, mid);
                j--;
            }
        }
    }
    for (int i = 0; i < emailsSize; i++) {
        sprintf(temp[i].local, "%s@%s", temp[i].local, temp[i].domain);
    }
    qsort(temp, emailsSize, sizeof(struct Node), cmp);
    int res = 1;
    for (int i = 1; i < emailsSize; i++) {
        if (strcmp(temp[i].local, temp[i - 1].local) != 0) res++;
    }
    return res;
}

int main() {
    char temp[][100] = {"fg.r.u.uzj+o.pw@kziczvh.com","r.cyo.g+d.h+b.ja@tgsg.z.com","fg.r.u.uzj+o.f.d@kziczvh.com","r.cyo.g+ng.r.iq@tgsg.z.com","fg.r.u.uzj+lp.k@kziczvh.com","r.cyo.g+n.h.e+n.g@tgsg.z.com","fg.r.u.uzj+k+p.j@kziczvh.com","fg.r.u.uzj+w.y+b@kziczvh.com","r.cyo.g+x+d.c+f.t@tgsg.z.com","r.cyo.g+x+t.y.l.i@tgsg.z.com","r.cyo.g+brxxi@tgsg.z.com","r.cyo.g+z+dr.k.u@tgsg.z.com","r.cyo.g+d+l.c.n+g@tgsg.z.com","fg.r.u.uzj+vq.o@kziczvh.com","fg.r.u.uzj+uzq@kziczvh.com","fg.r.u.uzj+mvz@kziczvh.com","fg.r.u.uzj+taj@kziczvh.com","fg.r.u.uzj+fek@kziczvh.com"};
    int num = sizeof(temp) / (sizeof(char) * 100);
    char** a = malloc(sizeof(char*) * num);
    for (int i = 0; i < num; i++) {
        a[i] = temp[i];
    }
    int res = numUniqueEmails(a, num);
    return 0;
}