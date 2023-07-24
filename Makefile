# Executable names:
EXE = p
TEST = test

# Add all object files needed for compiling
EXE_OBJ = main.o

# (Hins) The list needs additional files 
OBJS = main.o



# Generated files
CLEAN_RM = *.o *.d tests/*.o tests/*.d cs225/*.d cs225/*.o \
		   cs225/catch/*.o cs225/catch/*.d

# Use the cs225 makefile template:
include cs225/make/cs225.mk

