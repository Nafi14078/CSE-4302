#include <stdio.h>
#include <string.h>

void getHint(char *secret, char *guess, int secretLength) {
    int bulls = 0, cows = 0;
    int secretDigitCount[10] = {0};
    int guessDigitCount[10] = {0};

    for (int i = 0; i < secretLength; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secretDigitCount[secret[i] - '0']++;
            guessDigitCount[guess[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        cows += (secretDigitCount[i] < guessDigitCount[i]) ? secretDigitCount[i] : guessDigitCount[i];
    }

    printf("%dB%dC\n", bulls, cows);
}

int main() {
    char secret[1000];
    char guess[1000];

    scanf("%s", secret);
    scanf("%s", guess);

    int secretLength = strlen(secret);

    getHint(secret, guess, secretLength);

    return 0;
}
