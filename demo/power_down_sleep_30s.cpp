#include "avrcxx/sleep/power_down.hpp"

using namespace avrcxx;

#define LED_PIN PB0

/** 
    This demo illustrates the usage of sleep::power_down::sleep<Duration>()
    
    The MCU sleeps for 30s using the power down mode and a watchdog
    timer to wake up.
 */
int main() {
    //Defines LED_PIN as an output pin
    DDRB = 1 << LED_PIN;
    
    while(true) {
        //Toggle the LED when the MCU wakes up
        PORTB = PORTB ^ (1 << LED_PIN);
        sleep::power_down::sleep<30s>();
    }
}
