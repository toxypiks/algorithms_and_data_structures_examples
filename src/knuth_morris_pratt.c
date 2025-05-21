#include <stdio.h>
#include <string.h>

#define ARRAY_LEN(xs) sizeof(xs)/sizeof(xs[0])

void compute_longest_proper_prefix(const char *pattern, int pattern_len, int *lps)
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


int main(void)
{
    const char *my_pattern = "koko";
    int my_lps[strlen(my_pattern)];
    compute_longest_proper_prefix(my_pattern, strlen(my_pattern), my_lps);
    for (size_t i = 0; i < ARRAY_LEN(my_lps); ++i) {
        printf("%d", my_lps[i]);
    }
    printf("\n");
    return 0;
}
