#include <stdio.h>

int main(void) {
    char s[1000];
    int last = -1;
    printf("Enter a binary string: ");
    if (scanf("%999s", s) != 1) return 1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '0' && s[i] != '1') {
            printf("Invalid input: use only 0 and 1.\\n");
            return 0;
        }
        last = s[i] - '0';
    }

    if (s[0] == '0' && last == 1)
        printf("Accepted: string starts with 0 and ends with 1.\\n");
    else
        printf("Rejected.\\n");
    return 0;
}
