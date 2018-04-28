#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

# Add your Source files to this variable
SRCS = main.c \
	memory.c \
	interrupts_msp432p401r_gcc.c \
	startup_msp432p401r_gcc.c \
	system_msp432p401r.c

# Add your include Drectorys here. 
INCDIRS =  ./../include/CMSIS ./../include/common ./../include/msp432

# Add -I infront of each include directory so they can be pass to GCC
INCS = $(INCDIRS:%=-I%)

# Find all .h files in the directories defined above
DEPS = $(foreach I, $(INCDIRS), $(shell find $(I) -name '*.h'))
