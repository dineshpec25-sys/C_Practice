#include <stdio.h>
#include <stdint.h>

uint16_t pack_register(uint8_t mode, uint8_t speed, uint8_t status) {
    uint16_t result = 0;

    result = (mode & 0x07) | ((speed & 0x1F) << 3) | ((status & 0x3F) << 10);

    return result;
}

int main() {
    uint8_t mode, speed, status;
    scanf("%hhu %hhu %hhu", &mode, &speed, &status);

    uint16_t reg = pack_register(mode, speed, status);
    printf("%u", reg);

    return 0;
}