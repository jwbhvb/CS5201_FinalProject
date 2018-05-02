############################################################
# File       : makefile                                    #
# Author     : John Bagsby, Ryan Leas                      #
# Date       : 4/29/18                                     #
# Course     : CS5201                                      #
############################################################

.PHONY: all clean

CXX = g++
CXXFLAGS = -Wpedantic -Wall -Wextra -Wfloat-conversion -Werror -std=c++17

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

OBJECTS = $(SOURCES:%.cpp=%.o)

default: clean all

all: driver

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

driver: $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

clean:
	-@rm -f core
	-@rm -f driver
	-@rm -f depend
	-@rm -f $(OBJECTS)

depend: $(SOURCES) $(HEADERS)
	@$(CXX) -MM *.cpp > $@
