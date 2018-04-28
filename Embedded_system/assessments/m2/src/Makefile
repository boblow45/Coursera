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

# Platform Overrides
PLATFORM = MSP432
# PLATFORM = HOST

CUSTOMDEFINES = -D$(PLATFORM)

# Check if the user wants to compile the code for the host machine or for the 
# embedded system. This if statement will change to the correct compliler for
# the given platform
ifeq ($(PLATFORM), HOST)
	CC = gcc

else
	# Compiler to use for the ARM based device
	CC = arm-none-eabi-gcc
	
	SRCS += interrupts_msp432p401r_gcc.c system_msp432p401r.c startup_msp432p401r_gcc.c
	# Architectures Specific Flags
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) 
	LINKER_FILE = -T ../msp432p401r.lds

endif

CFLAGS += -Wall -Werror -g -O0 -std=c99 $(CUSTOMDEFINES)
CFLAGS += $(INCS) 
LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)

# Define all object files.
OBJS = $(SRCS:.c=.o)


# Compile: create object files from C source files.
%.o : %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)  

# Create preprocessed source for use in sending a bug report.
%.i : %.c
	$(CC) -E $< -o $@ $(CFLAGS) 

# Compile: create assembler files from C source files.
%.asm : %.c
	$(CC) -S $(CFLAGS) $< -o $@

# Build and link the project
.PHONY: build
build: all

# Build and link the project
.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

# Create all the object files for this make file
.PHONY: compile-all 

compile-all: $(OBJS)

# print out details of what this makefile can do 
.PHONY: help

help:
	-@echo $(LDFLAGS)
	-@echo $(DEPS)


# Following rule will remove all files created by this makefile.
.PHONY: clean

clean:
	rm -f $(OBJS) $(SRCS:.c=.i) $(SRCS:.c=.asm) $(TARGET).out $(TARGET).map
