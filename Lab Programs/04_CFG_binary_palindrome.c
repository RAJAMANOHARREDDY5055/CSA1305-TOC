#include <stdio.h>
#include <string.h>

/* S -> 0S0 | 1S1 | 0 | 1 | epsilon
   Language: all binary palindromes, including epsilon. */
int main(void) {
    char s[1000];
    printf("Enter a binary string (use # for epsilon): ");
    if (scanf("%999s", s) != 1) return 1;
    if (strcmp(s, "#") == 0) s[0] = '\0';

    int n = (int)strlen(s), valid = 1;
    for (int i = 0; i < n; i++)
        if (s[i] != '0' && s[i] != '1') valid = 0;

    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (s[i] != s[j]) valid = 0;

    printf(valid ? "Accepted by the CFG.\\n" : "Rejected by the CFG.\\n");
    return 0;
}
