#include <stdint.h>

struct gpio {
    volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFR[2];
};

#define GPIOA ((struct gpio *) 0x40020000)

#define GPIO(bank)  ((struct gpio *) (0x40020000 + 0x400 * (bank)))

#define PIN (bank, num)  ((((bank)- 'A') << 8) | (num))
#define PINN0(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)


enum {
    GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG};

static inline void gpio_set_mode(struct gpio *gpio, uint8_t pin, uint8_t mode) {
    gpio -> MODER &= ~(3U << (pin * 2));
    gpio -> MODER |= (mode & 3) << (pin * 2);

}


int main(){

    /* * (volatile uint32_t *) (0x40020000 + 0) = 0; // Setting A0-A15 to input (00) mode.
    * (volatile uint32_t *) (0x40020000 + 0) &= ~(3 << 6); // Clear bit range 6-7
    * (volatile uint32_t *) (0x40020000 + 0) |= 1 << 6;   // Set bit range 6-7 to 1 -> MODER[3] = 01 (OUTPUT)*/

    // Making the code cleaner and improving readability.

    gpio_set_mode(GPIOA, 3 /*pin*/, GPIO_MODE_OUTPUT); //Setting A3 to output mode


    return 0;
}