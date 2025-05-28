#include <stdint.h>

int main(){

    * (volatile uint32_t *) (0x40020000 + 0) = 0; // Setting A0-A15 to input (00) mode.

    * (volatile uint32_t *) (0x40020000 + 0) &= ~(3 << 6); // Clear bit range 6-7
    * (volatile uint32_t *) (0x40020000 + 0) |= 1 << 6;   // Set bit range 6-7 to 1 -> MODER[3] = 01 (OUTPUT)




    return 0;
}