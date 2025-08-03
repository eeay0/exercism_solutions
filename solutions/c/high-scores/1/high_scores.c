#include "high_scores.h"
#include <stddef.h>
#include <stdint.h>
/// Return the latest score.
int32_t latest(const int32_t* scores, size_t scores_len)
{
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t* scores, size_t scores_len)
{
    int32_t max = scores[0];
    for (size_t i = 1; i < scores_len; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t* scores, size_t scores_len, int32_t* output)
{
    size_t output_len = 0;
    int32_t first = 0;
    int32_t second = 0;
    int32_t third = 0;
    for (size_t i = 0; i < scores_len; i++) {
        if (scores[i] > first) {
            third = second;
            second = first;
            first = scores[i];
        } else if (scores[i] > second && scores_len > 1) {
            third = second;
            second = scores[i];
        } else if (scores[i] > third && scores_len > 2) {
            third = scores[i];
        }
    }
    if (scores_len == 1) {
        output[0] = first;
        output_len = 1;
    } else if (scores_len > 1 && scores_len < 3) {
        output[0] = first;
        output[1] = second;
        output_len = 2;
    } else if (scores_len > 2) {
        output[0] = first;
        output[1] = second;
        output[2] = third;
        output_len = 3;
    }
    return output_len;
}
