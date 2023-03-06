#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int crack(int len) {
    len++; // to account for '\0'
    FILE *file = fopen("text.txt", "w");
    if (!file) {
        printf("File opening error\n");
        return 1;
    }

    setvbuf(stdout, NULL, _IONBF, 0);
    char *str = malloc(len);
    char *check_str = malloc(len);
    str[len - 1] = '\0';
    check_str[len - 1] = '\0';
    int idx = len - 2;

    for (int i = 0; i < len - 1; i++) {
        str[i] = '\0';
    }

    for (int i = 0; i < len - 1; i++) {
        check_str[i] = '~';  // '~' is the char with lowest ascii value
    }

    while (strcmp(str, check_str)) {
        if (idx == len - 2) { // for last char index
            /* (len - 2) will always be the one where it will go through
            all characters without obstructions */
            for (char c = ' '; c <= '~'; c++) {
                str[idx] = c;
                for (int i = 0; i < len - 1; i++) {
                    if (str[i] != '\0') { // make sure the leading part of string isn't '\0'
                        fprintf(file, "%c", str[i]);
                    }
                }
                fprintf(file, "\n");
            }
            idx--; // Make it go to the previous index to increment that after going through all chars
        }

        else if (str[idx] == '~') {
            str[idx] = ' '; // if that previous index is `~', set it to ' '
            idx--; // and decrement idx, so the else statement can take place
        }

        else {
            if (str[idx] == '\0')
                str[idx] = ' ';
            char ch = str[idx];
            ch++; // increment that char by 1
            // don't have to worry about '~' getting incremented, because previous block takes care of it
            str[idx] = ch;
            idx++; // increase the idx so the same logic can be applied for next one
            // if that index needs to be incremented too, the next iteration will do it
            str[len - 2] = ' '; // make sure you set the last string char to ' '
            /* This is because (len - 2) will always be the one where it will go through
            all characters without obstructions */
        }
    }
}

int main() {
    int len = 10;
    crack(len);
}
