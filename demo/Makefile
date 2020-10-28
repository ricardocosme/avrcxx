MCU_TARGET=attiny85
STD_CXX=c++17
OPTIMIZE=-Os

CXX=avr-g++
CC=avr-gcc
OBJCOPY=avr-objcopy
OBJDUMP=avr-objdump
INCLUDE=-I../include
CXXFLAGS=-std=$(STD_CXX) -g -mmcu=$(MCU_TARGET) -Wall $(OPTIMIZE) -DF_CPU=1000000 $(INCLUDE) -fexceptions

demos = power_down_sleep_1s power_down_sleep_3s power_down_sleep_30s power_down_sleep_45min power_down_sleep_1h

all: $(demos:%=%.elf) $(demos:%=%.lst) $(demos:%=%.s)

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(demos:%=%.d)

%.s: %.cpp
	$(CXX) $(CXXFLAGS) -S $^

power_down_sleep_1h.elf: power_down_sleep_1h.o
	$(CXX) $(CXXFLAGS) -o $@ $^ ../src/avrcxx/watchdog/counter.cpp

power_down_sleep_45min.elf: power_down_sleep_45min.o
	$(CXX) $(CXXFLAGS) -o $@ $^ ../src/avrcxx/watchdog/counter.cpp

power_down_sleep_30s.elf: power_down_sleep_30s.o
	$(CXX) $(CXXFLAGS) -o $@ $^ ../src/avrcxx/watchdog/counter.cpp

power_down_sleep_3s.elf: power_down_sleep_3s.o
	$(CXX) $(CXXFLAGS) -o $@ $^ ../src/avrcxx/watchdog/counter.cpp

power_down_sleep_1s.elf: power_down_sleep_1s.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

.PHONY: flash_%
flash-%: %.hex
	avrdude -p t85 -c usbasp -P usb  -U flash:w:$<

size:
	avr-size $(demos:%=%.elf)

.PHONY: clean
clean:
	rm -f *.hex *.lst *.elf *.o *.d *.s

