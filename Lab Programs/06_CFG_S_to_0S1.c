#include <stdio.h>
#include <string.h>

/* S -> 0S1 | epsilon
   Language: 0^n 1^n, including epsilon. */
int main(void) {
    char s[1000];
    printf("Enter a string over {0,1} (use # for epsilon): ");
    if (scanf("%999s", s) != 1) return 1;
    if (strcmp(s, "#") == 0) s[0] = '\0';

    int n = (int)strlen(s), zeros = 0, ones = 0, valid = 1, seen_one = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (seen_one) valid = 0;
            zeros++;
        } else if (s[i] == '1') {
            seen_one = 1;
            ones++;
        } else valid = 0;
    }
    if (zeros != ones) valid = 0;
    printf(valid ? "Accepted by the CFG.\\n" : "Rejected by the CFG.\\n");
    return 0;
}
