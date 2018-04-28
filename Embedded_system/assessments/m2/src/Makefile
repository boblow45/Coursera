#----------------------------------------------------------------------------
# Simple makefile for the cortex-M0+ build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      	<FILE>.o - Builds <FILE>.o object file
#      	<FILE>.i - Create a preprocessed source file for use in submitting
#                 bug reports to the GCC project.
#      	<FILE>.asm - Just compile <FILE>.c into the assembler code only.
#      	build - Builds and links all source files
#      	clean - removes all generated files
# 		help- gives the user details about what this makefile does
#
# Overrides:
#      	PLATFORM - Defines the platform to build the code for
#      	CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      	ARCH - ARM Architecture (arm, thumb)
#
# To rebuild project do "make clean" then "make build".
#----------------------------------------------------------------------------
# 
# see https://www.avrfreaks.net/forum/makefile-winavr-asm-code for example of 
# example of an extensive make file
#----------------------------------------------------------------------------

include sources.mk

TARGET = c1m2

# Define all object files.
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
	
	# Architectures Specific Flags
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) 
	LINKER_FILE = -T../msp432p401r.lds

endif

CFLAGS += -Wall -Werror -g -O0 -std=c99 $(CUSTOMDEFINES)
CFLAGS += $(INCS) 
LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)


# Compile: create object files from C source files.
%.o : %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)  

# Create preprocessed source for use in sending a bug report.
%.i : %.c
	$(CC) -E $< -o $@ $(CFLAGS) 

# Compile: create assembler files from C source files.
%.asm : %.c
	$(CC) -S $(CFLAGS) $< -o $@

.PHONY: build

build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: help

help:
	-@echo $(LDFLAGS)
	-@echo $(DEPS)
#-@echo $(SRCS)
#-@echo $(OBJS)
#-@echo $(INCS)


.PHONY: clean

clean:
	rm -f $(OBJS) $(SRCS:.c=.i) $(SRCS:.c=.asm) $(TARGET).out $(TARGET).map
