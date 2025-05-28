#include <stdint.h>
/* Creating a struct to concpetualise the GPIO peripheral into its components registers as is defined
in the datasheet*/
struct gpio {
    volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFR[2];
};

//Macros to refrence any pin and bank(port) on the GPIO peripheral in a consistent way
#define GPIO(bank)  ((struct gpio *) (0x40020000 + 0x400 * (bank)))

#define PIN(bank, num) ((((bank)- 'A') << 8) | (num))
#define PINNO(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)




enum {
    GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG};  // Reminds me of PinMode in Arduino
/* Function that turns pin value to actual hardware configuration - manipulating the bits*/
static inline void gpio_set_mode(uint16_t pin, uint8_t mode) {
    struct gpio *gpio = GPIO(PINBANK(pin)); //GPIO BANK
    uint8_t n = PINNO(pin); //PIN NUMBER
    gpio -> MODER &= ~(3U << (n * 2));   // clears existing setting (bits)
    gpio -> MODER |= (mode & 3) << (n * 2); // Set new mode

}



int main(){

    // Making the code cleaner and improving readability by calling aforemade functions
    uint16_t pin = PIN('A', 3);
    //uint16_t pin2 = PIN('G', 11); 
    gpio_set_mode(pin, GPIO_MODE_OUTPUT); //Setting A3 to output mode


    return 0;
}