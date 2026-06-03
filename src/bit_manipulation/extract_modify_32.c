// Extract and Modify Field in a 32-bit Register

// In embedded systems, a 32-bit configuration register often contains several packed fields.

// Your task is to extract a 5-bit field located at bit positions 10 to 14 from
// a 32-bit register value.

// If this field’s value is less than 31, increment it by 1. Then write the updated value back to
// the same bit positions in the register, leaving all other bits unchanged.

// Use only bitwise operations to extract, modify, and update the register.

// Bit layout example (bit 0 is LSB):

// Register: [31 ... 15 | 14 13 12 11 10 | 9 ... 0]
//                         ↑  ↑  ↑  ↑  ↑ (target field)
// Example-1

// Input: 0x00003C00
// Output: 0x00004000

// (Field at bits 10–14 was 0x1E = 30 → incremented to 31)


#include <stdio.h>
#include <stdint.h>

uint32_t update_register(uint32_t reg) {

    return 0;
}

int main() {
    uint32_t reg;
    scanf("%u", &reg);
    uint32_t updated = update_register(reg);
    printf("%u", updated);
    return 0;
}
