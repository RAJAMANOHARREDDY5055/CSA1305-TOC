#include <stdio.h>
#include <string.h>

/* S -> 0S0 | A, A -> 1A | epsilon
   Language: 0^n 1^m 0^n, where n,m >= 0. */
int main(void) {
    char s[1000];
    printf("Enter a string over {0,1} (use # for epsilon): ");
    if (scanf("%999s", s) != 1) return 1;
    if (strcmp(s, "#") == 0) s[0] = '\0';

    int n = (int)strlen(s), left = 0, right = n - 1, valid = 1;
    while (left < n && s[left] == '0') left++;
    while (right >= 0 && s[right] == '0') right--;

    for (int i = 0; i < n; i++)
        if (s[i] != '0' && s[i] != '1') valid = 0;

    /* The number of outer zeros must match. */
    int leading = left;
    int trailing = n - 1 - right;
    if (leading != trailing) valid = 0;

    /* Between the matching zero blocks, only 1s may occur. */
    for (int i = leading; i < n - trailing; i++)
        if (s[i] != '1') valid = 0;

    printf(valid ? "Accepted by the CFG.\\n" : "Rejected by the CFG.\\n");
    return 0;
}
