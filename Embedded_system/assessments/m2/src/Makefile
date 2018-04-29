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
OBJDUMP_FILE = output.dump
PLATFORM = MSP432

DEFINES = -D$(PLATFORM)

# Check if the user wants to compile the code for the host machine or for the 
# embedded system. This if statement will change to the correct compliler for
# the given platform
ifeq ($(PLATFORM), HOST)
	CC = gcc

else
	# Compiler to use for the ARM based device
	CC = arm-none-eabi-gcc
	
	# Add the files which can only be compiled using arm core
	SRCS += interrupts_msp432p401r_gcc.c system_msp432p401r.c startup_msp432p401r_gcc.c
	# Architectures Specific Flags
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	
	ARCH_FLAGS = -m$(ARCH) -march=armv7e-m
	CFLAGS = -mcpu=$(CPU) $(ARCH_FLAGS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 
	LINKER_FILE = -T ../msp432p401r.lds
	
	# Linker Settings
	LFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE) --specs=$(SPECS) 
endif

CFLAGS += $(INCS) $(DEFINES)

# --------------------------------------- Source Files ----------------------------------
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

$(TARGET).elf: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	arm-none-eabi-objcopy -O binary $< $@

$(OBJDUMP_FILE): $(TARGET).bin
	arm-none-eabi-objdump -D $(TARGET).elf > $(OBJDUMP_FILE)

# Build and link the project
.PHONY: build
build: all

# Build and link the project
.PHONY: all
all: $(TARGET).elf

# Create all the object files for this make file
.PHONY: compile-all 

compile-all: $(OBJS)

# print out details of what this makefile can do 
.PHONY: help

help:
	-@echo $(LFLAGS)
	-@echo $(DEPS)


# Following rule will remove all files created by this makefile.
.PHONY: clean

clean:
	rm -f $(OBJS) $(SRCS:.c=.i) $(SRCS:.c=.asm) $(TARGET).elf $(TARGET).bin $(OBJDUMP_FILE) $(TARGET).map
