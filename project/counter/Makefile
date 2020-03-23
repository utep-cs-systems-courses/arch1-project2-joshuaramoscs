# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: counter.elf 

#additional rules for files
counter.elf: ${COMMON_OBJECTS} led.o buzzer.o switches.o counterMain.o led_toggle.o stateMachines.o wdInterruptHandler.o p2_interrupt_handler.c ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: counter.elf
	msp430loader.sh counter.elf

clean:
	rm -f *.o *.elf

led.o: led.h

buzzzer.o: buzzer.h

switches.o: switches.h stateMachines.h

counterMain.o: led.h buzzer.h switches.o

stateMachines.o: led.h buzzer.h led_toggle.h stateMachines.h

wdInterruptHandler.o: switches.h wdInterruptHandler.c

p2_interrupt_handler.o: switches.h
