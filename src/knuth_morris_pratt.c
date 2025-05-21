#include <stdio.h>
#include <string.h>

#define ARRAY_LEN(xs) sizeof(xs)/sizeof(xs[0])

void longest_proper_prefix(const char *pattern, int pattern_len, int *lps)
{
    int lps_len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pattern_len) {
        if (pattern[i] == pattern[lps_len]) {
            lps_len++;
            lps[i] = lps_len;
            i++;
        } else {
            if (lps_len != 0) {
                lps_len = lps[lps_len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char *text, char *pattern) {
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);
    int proper_prefixes[pattern_len];

    longest_proper_prefix(pattern, pattern_len, proper_prefixes);

    int i = 0;
    int j = 0;

    while (i < text_len) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == pattern_len) {
            // found pattern at index i - j
            printf("Found pattern at index %d\n", i - j);
            j = proper_prefixes[j - 1];
        }
        else if (i < text_len && pattern[j] != text[i]) {
            if (j != 0) {
                j = proper_prefixes[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}


int main(void)
{
    const char *my_pattern = "kokoko";
    int my_lps[strlen(my_pattern)];
    longest_proper_prefix(my_pattern, strlen(my_pattern), my_lps);
    for (size_t i = 0; i < ARRAY_LEN(my_lps); ++i) {
        printf("%d", my_lps[i]);
    }
    printf("\n");

    char text[] = "jawdkokoamndwkokosqhduwkoshkosskokookokokokosnuss";
    char pattern[] = "kokos";
    kmp(text, pattern);

    return 0;
}
