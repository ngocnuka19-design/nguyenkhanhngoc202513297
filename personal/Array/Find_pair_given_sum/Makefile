CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGETS = brute_force two_pointer hashing

.PHONY: all clean

all: $(TARGETS)

brute_force: brute_force.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

two_pointer: two_pointer.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

hashing: hashing.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS) *.exe
