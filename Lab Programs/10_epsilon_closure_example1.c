#include <stdio.h>

/* Example epsilon-NFA:
   states q0,q1,q2,q3
   epsilon transitions: q0->q1, q1->q2, q2->q1, q2->q3
   Prints epsilon-closure of each state. */
#define N 4
int eps[N][N] = {
    {0,1,0,0},
    {0,0,1,0},
    {0,1,0,1},
    {0,0,0,0}
};

void closure(int start) {
    int seen[N] = {0}, stack[N * N], top = 0;
    stack[top++] = start;
    seen[start] = 1;
    while (top > 0) {
        int u = stack[--top];
        for (int v = 0; v < N; v++) {
            if (eps[u][v] && !seen[v]) {
                seen[v] = 1;
                stack[top++] = v;
            }
        }
    }
    printf("E-closure(q%d) = {", start);
    int first = 1;
    for (int i = 0; i < N; i++) if (seen[i]) {
        printf("%sq%d", first ? "" : ", ", i);
        first = 0;
    }
    puts("}");
}

int main(void) {
    for (int i = 0; i < N; i++) closure(i);
    return 0;
}
