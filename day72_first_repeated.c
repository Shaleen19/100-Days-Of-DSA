#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};  // for a-z

    // Input
    scanf("%s", s);

    // Traverse string
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (freq[index] == 1) {
            // already seen → first repeated
            printf("%c\n", s[i]);
            return 0;
        }

        freq[index]++;
    }

    // If no repeated character
    printf("-1\n");

    return 0;
}