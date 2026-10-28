#include <stdio.h>
#include <string.h>

/* S -> A101A, A -> 0A | 1A | epsilon
   Language: all binary strings containing substring 101. */
int main(void) {
    char s[1000];
    printf("Enter a binary string: ");
    if (scanf("%999s", s) != 1) return 1;

    int valid = 1, found = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != '0' && s[i] != '1') valid = 0;

    for (int i = 0; s[i] && s[i+1] && s[i+2]; i++)
        if (s[i] == '1' && s[i+1] == '0' && s[i+2] == '1') found = 1;

    printf((valid && found) ? "Accepted by the CFG.\\n" : "Rejected by the CFG.\\n");
    return 0;
}
