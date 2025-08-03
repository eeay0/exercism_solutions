#include "pangram.h"
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
bool is_pangram(const char* sentence)
{

    if (sentence == NULL) {
        return false;
    } else if (strlen(sentence) < 26) {
        return false;
    }
    char check_pangram[27];
    memset(check_pangram, '0', 26);
    check_pangram[26] = '\0';
    char tmp_char;

    for (int i = 0; i < (int) strlen(sentence); i++) {
        tmp_char = tolower((unsigned char) sentence[i]);
        switch (tmp_char) {
        case 'a':
            check_pangram[0] = '1';
            break;
        case 'b':
            check_pangram[1] = '1';
            break;
        case 'c':
            check_pangram[2] = '1';
            break;
        case 'd':
            check_pangram[3] = '1';
            break;
        case 'e':
            check_pangram[4] = '1';
            break;
        case 'f':
            check_pangram[5] = '1';
            break;
        case 'g':
            check_pangram[6] = '1';
            break;
        case 'h':
            check_pangram[7] = '1';
            break;
        case 'i':
            check_pangram[8] = '1';
            break;
        case 'j':
            check_pangram[9] = '1';
            break;
        case 'k':
            check_pangram[10] = '1';
            break;
        case 'l':
            check_pangram[11] = '1';
            break;
        case 'm':
            check_pangram[12] = '1';
            break;
        case 'n':
            check_pangram[13] = '1';
            break;
        case 'o':
            check_pangram[14] = '1';
            break;
        case 'p':
            check_pangram[15] = '1';
            break;
        case 'q':
            check_pangram[16] = '1';
            break;
        case 'r':
            check_pangram[17] = '1';
            break;
        case 's':
            check_pangram[18] = '1';
            break;
        case 't':
            check_pangram[19] = '1';
            break;
        case 'u':
            check_pangram[20] = '1';
            break;
        case 'v':
            check_pangram[21] = '1';
            break;
        case 'w':
            check_pangram[22] = '1';
            break;
        case 'x':
            check_pangram[23] = '1';
            break;
        case 'y':
            check_pangram[24] = '1';
            break;
        case 'z':
            check_pangram[25] = '1';
            break;
        }
    }

    // Check if all characters were seen
    for (int i = 0; i < 26; i++) {
        if (check_pangram[i] == '0')
            return false;
    }
    return true;
}
