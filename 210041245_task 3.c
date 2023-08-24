#include <stdio.h>
#include <string.h>

int main() {
    int length;
    char dubstep[100000];
    scanf("%d", &length);
    scanf("%s", dubstep);


    int i;
    char originalLyric[100000];
    int originalIndex=0;

    while (i < length) {
        if (i <= length - 3 && strncmp(&dubstep[i], "dub",3) == 0) {
            if (originalIndex > 0 ) {
                originalLyric[originalIndex] = ' ';
                originalIndex++;
            }
            i =i+3;
        } else {
            originalLyric[originalIndex] = dubstep[i];
            originalIndex++;
            i++;
        }
    }


    originalLyric[originalIndex] = '\0';


    printf("%s\n", originalLyric);

    return 0;
}
