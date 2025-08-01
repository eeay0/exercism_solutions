#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char* to_rna(const char* dna)
{
    int len = strlen(dna);
    char* rna = malloc(len + 1); // +1 for null terminator
    if (rna == NULL) {
        return NULL;
    }
    for (int i = 0; i < (int) len; i++) {
        switch (dna[i]) {
        case 'G':
            rna[i] = 'C';
            break;
        case 'C':
            rna[i] = 'G';
            break;
        case 'T':
            rna[i] = 'A';
            break;
        case 'A':
            rna[i] = 'U';
            break;
        }
    }

    rna[len] = '\0'; // Null-terminate the string
    return rna;
}
