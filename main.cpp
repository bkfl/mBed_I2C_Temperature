#include "mbed.h"

I2C tmp102(p9, p10);
Serial serial(USBTX, USBRX);
const int tmp102_addr = 0x48 << 1;
char buffer[2];
float temperature;

int main() {  
    // Set pointer register to temperature register
    buffer[0] = 0x00;
    tmp102.write(tmp102_addr, buffer, 1);
    while(1) {
        // Read 2 byte temperature register to buffer
        tmp102.read(tmp102_addr, buffer, 2);
        // Convert and store temperature
        temperature =  ((buffer[0] << 8) + (buffer[1] >> 4)) * 0.0625;
        // Display temperature to usb serial port
        serial.printf("Temperature = %.2f", temperature);
        wait(1);
    }
}
