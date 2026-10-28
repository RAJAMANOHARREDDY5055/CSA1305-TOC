#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1000];
    int state = 0; 
    printf("Enter a string over {a,b}: ");
    if (scanf("%999s", s) != 1) return 1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            printf("Invalid input: use only a and b.\\n");
            return 0;
        }
        if (i == 0) {
            state = (s[i] == 'a') ? 1 : 2;
        } else {
            state = (s[i] == 'a') ? 1 : 2;
        }
    }

    if (s[0] == 'a' && state == 1)
        printf("Accepted: string starts with a and ends with a.\\n");
    else
        printf("Rejected.\\n");
    return 0;
}
