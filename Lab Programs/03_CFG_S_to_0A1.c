#include <stdio.h>
#include <string.h>

/* S -> 0A1, A -> 0A | 1A | epsilon
   Language: 0(0|1)*1 */
int main(void) {
    char s[1000];
    printf("Enter a binary string: ");
    if (scanf("%999s", s) != 1) return 1;

    int n = (int)strlen(s), valid = (n >= 2 && s[0] == '0' && s[n-1] == '1');
    for (int i = 0; i < n; i++)
        if (s[i] != '0' && s[i] != '1') valid = 0;

    printf(valid ? "Accepted by the CFG.\\n" : "Rejected by the CFG.\\n");
    return 0;
}
