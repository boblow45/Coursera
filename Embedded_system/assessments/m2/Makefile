FOO = $PATH

APP     = Hello

SRCDIR  = src
OBJDIR  = Objects

# Source folder
SRCS    := $(shell find $(SRCDIR) -name '*.c')
# SRCDIRS = $(shell find . -name '*.c' | dirname {} | sort | uniq | sed 's/\/$(SRCDIR)//g' )
SRCDIRS = $(shell find . -name '*.c' | dirname {} )

#SRCDIRS = $(shell find . -name '*.c' | dirname {} | sort | uniq | sed 's/\/$(SRCDIR)//g' )

# Include folders
INCDIR = include/*
INCS := $(shell find $(ALLDIR) -name '*.h')  

# folder to place complited code 
OBJS    := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CFLAGS  = -Wall -pedantic -ansi


# .PHONY: all
# all: $(TARGET).out

# $(TARGET).out: $(OBJS)
# 	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

all:
	@echo $(SRCDIRS)
# @echo $(OBJS)
# @echo $(INCS)



# buildrepo:
# 	@$(call make-repo)

# # Create obj directory structure
# define make-repo
# 	mkdir -p $(OBJDIR)
# 	for dir in $(SRCDIRS); \
# 	do \
# 		mkdir -p $(OBJDIR)/$$dir; \
# 	done
# endef