#include <stdio.h>

int main() {
    int n, r;
    scanf("%d %d", &n, &r);

    int soldiers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &soldiers[i]);
    }

    int rounds[r];
    for (int i = 0; i < r; i++) {
        scanf("%d", &rounds[i]);
    }

    for (int i = 0; i < r; i++) {
        int power = rounds[i];
        int killed = 0;
        int totalPoints = 0;

        for (int j = 0; j < n; j++) {
            if (soldiers[j] <= power) {
                killed++;
                totalPoints += soldiers[j];
            }
        }

        printf("%d %d\n", killed, totalPoints);
    }

    return 0;
}
