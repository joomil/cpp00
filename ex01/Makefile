# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
OBJDIR = obj
BINDIR = bin
EXEC = PhoneBook

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Default target
all: $(BINDIR)/$(EXEC)

# Linking
$(BINDIR)/$(EXEC): $(OBJECTS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compiling
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Directories
$(BINDIR) $(OBJDIR):
	mkdir -p $@

# Cleaning
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(EXEC)

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean all

.PHONY: all re clean fclean