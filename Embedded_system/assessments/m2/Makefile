FOO = $PATH

APP     = Hello

SRCDIR  = src
CMSISDIR  = include/CMSIS
OBJDIR  = Objects

SRCS    := $(shell find $(SRCDIR) -name '*.c')
CMSISINCS    := $(shell find $(CMSISDIR) -name '*.h')  
OBJS    := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CFLAGS  = -Wall -pedantic -ansi

all:
	@echo $(SRCS)
	@echo $(CMSISINCS)


