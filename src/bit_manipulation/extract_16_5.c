// Extract Bit Field from 16-bit Register

// Your task is to:

//     Read a uint16_t register value
//     Extract the 5-bit field from bits 4 to 8 (LSB = bit 0)
//     Return the value of that field as an unsigned integer


// Example-1

// Input: 0x01F0
// Output: 31

// (Binary = 0000 0001 1111 0000 → bits 4–8 are all 1)

#include <stdio.h>
#include <stdint.h>

uint8_t extract_field(uint16_t reg) {
    unsigned int extract = 0;
    extract = (reg >> 4) & 0b11111;
    return extract;
}

int main() {
    uint16_t reg;
    scanf("%hx", &reg);
    printf("%u", extract_field(reg));
    return 0;
}
