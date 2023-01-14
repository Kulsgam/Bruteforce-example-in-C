#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* len should include '\0' */
int crack(int len) {
    FILE *file = fopen("text.txt", "w");
    if (!file) {
        printf("File opening error\n");
        return 1;
    }

    setvbuf(stdout, NULL, _IONBF, 0);
    char *str = malloc(4);
    char *check_str = malloc(4);
    str[len - 1] = '\0';
    check_str[len - 1] = '\0';
    int idx = len - 2;

    for (int i = 0; i < len - 1; i++) {
        str[i] = ' ';
    }

    for (int i = 0; i < len - 1; i++) {
        check_str[i] = '~';
    }

    while (strcmp(str, check_str)) {
        if (idx != len - 2) {
            if (str[idx] != '~') {
                char ch = str[idx];
                ch++;
                str[idx] = ch;
                idx++;
                str[len - 2] = ' ';
                continue;
            }
            else {
                str[idx] = ' ';
                idx--;
                continue;
            }
        }
        for (char c = ' '; c <= '~'; c++) {
            str[idx] = c;
            fprintf(file, "%s\n", str);
        }
        idx--;
    }
}

int main() {
    int len = 5;
    crack(len + 1);
}