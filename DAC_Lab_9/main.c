#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

// DAC I2C Address
#define DAC_ADDRESS 0x60  // MCP4725 address (adjust if needed)

// Constants for triangular waveform
#define MAX_VALUE 4095     // Max value for a 12-bit DAC
#define MIN_VALUE 0        // Min value
#define STEP 50            // Step size for waveform

void I2C0_Init(void) {
    // Enable I2C0
    SYSCTL_RCGCI2C_R |= (1U << 0); // Enable I2C0
    SYSCTL_RCGCGPIO_R |= (1U << 1); // Enable Port B

    // Set PB0 and PB1 as I2C pins
    GPIO_PORTB_AFSEL_R |= (1U << 0) | (1U << 1); // PB0 and PB1 as I2C
    GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0xFFFFFF00) | 0x00000033; // Set PB0 and PB1 to I2C
    GPIO_PORTB_DEN_R |= (1U << 0) | (1U << 1); // Enable digital function
    I2C0_MCR_R = I2C_MCR_MFE; // Enable I2C0 master
}
