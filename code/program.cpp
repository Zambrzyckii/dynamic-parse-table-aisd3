#include <cstdio>
#include "Program.h"
void Program() {
    int N, MIN, MAX, n, k;
    scanf("%d", &N);
    scanf("%d %d", &MIN, &MAX);
    scanf("%d %d", &n, &k);
    TRI T(n, k);

    for (int i = 0; i < N; i++) {
        char character;
        int j;
        scanf(" %c", &character);
        if (character == 'I') {
            scanf("%d", &j);
            Wstaw(j, n, j, k, T.Root);
        
} else if (character == 'L') {
            scanf("%d", &j);
            Znajdz(j, j, n, T.Root, k);
        
} else if (character == 'D') {
            scanf("%d", &j);
            Usun(j, j, n, k, T.Root);
        
} else if (character == 'P') {
            Pokaz(n, k, T.Root);
            printf("\n");
        
}
    
}
}
