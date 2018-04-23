#------------------------------------------------------------------------------
# Simple makefile for the cortex-M0+ build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      PLATFORM - Defines the platform to build the code for
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#
#
#------------------------------------------------------------------------------

# include sources.mk
SRCS = main.c \
	memory.c \
	interrupts_msp432p401r_gcc.c \
	startup_msp432p401r_gcc.c \
	system_msp432p401r.c

# Sources can also be done with one of the following
# SRCS = $(wildcard *.c)
TARGET = demo

# Add your include paths to this variable
INCS = -I ../include/CMSIS -I ../include/common -I ../include/msp432

OBJS = $(SRCS:.c=.o)

# Platform Overrides
PLATFORM = MSP432

CUSTOMDEFINES = -D$(PLATFORM)

# Check if the user wants to compile the code for the host machine or for the 
# embedded system. This if statement will change to the correct compliler for
# the given platform
ifeq ($(PLATFORM), HOST)
	CC = gcc

else
	# Compiler to use for the ARM based device
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	
	# Architectures Specific Flags
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) 
	LINKER_FILE = -T ../msp432p401r.lds

endif

CFLAGS += -Wall -Werror -g -O0 -std=c99 $(CUSTOMDEFINES)
LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)


%.o : %.c
	$(CC) -c $^ $(INCS) $(CFLAGS) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: help

help:
	-@echo $(LDFLAGS)
	-@echo $(CFLAGS)
	-@echo $(OBJS)
#-@echo $(SRCS)
#-@echo $(OBJS)
#-@echo $(INCS)


.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map
