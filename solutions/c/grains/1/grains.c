#include "grains.h"
uint64_t square(uint8_t index){
    if (index == 0){
        return 0;
    } else if (index == 1) {
        return 1;
    } else {
    uint64_t sq = 1;
    for(int i = 2; i <= index ; i++){
        sq *= 2;
    }
    
    return sq;
    }
}
uint64_t total(void){
    uint64_t sum = 0;
    for (int i = 1; i<= 64; i++){
        sum += square(i);
    }
    return sum;
}