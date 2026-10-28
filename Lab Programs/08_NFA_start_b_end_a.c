#include <stdio.h>
#include <string.h>

/* NFA over {a,b}: strings that start with b and end with a.
   q0 --b--> q1; q1 loops on a,b and may move on a to final q2.
   Bit positions: q0=1, q1=2, q2=4. */
int main(void) {
    char s[1000];
    printf("Enter a string over {a,b}: ");
    if (scanf("%999s", s) != 1) return 1;

    int states = 1; /* {q0} */
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            printf("Invalid input: use only a and b.\\n");
            return 0;
        }
        int next = 0;
        if (states & 1) { /* q0 */
            if (s[i] == 'b') next |= 2;
        }
        if (states & 2) { /* q1 */
            next |= 2;          /* loop on a or b */
            if (s[i] == 'a') next |= 4; /* guess this is final symbol */
        }
        states = next;
    }

    printf((states & 4) ? "Accepted by the NFA.\\n" : "Rejected by the NFA.\\n");
    return 0;
}
