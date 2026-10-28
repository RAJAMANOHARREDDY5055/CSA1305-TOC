#include <stdio.h>

/* NFA over {0,1}: strings that start with 0 and end with 1.
   q0 --0--> q1; q1 loops on 0,1 and may move on 1 to final q2. */
int main(void) {
    char s[1000];
    printf("Enter a binary string: ");
    if (scanf("%999s", s) != 1) return 1;

    int states = 1; /* {q0} */
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '0' && s[i] != '1') {
            printf("Invalid input: use only 0 and 1.\\n");
            return 0;
        }
        int next = 0;
        if (states & 1) {
            if (s[i] == '0') next |= 2;
        }
        if (states & 2) {
            next |= 2;
            if (s[i] == '1') next |= 4;
        }
        states = next;
    }

    printf((states & 4) ? "Accepted by the NFA.\\n" : "Rejected by the NFA.\\n");
    return 0;
}
