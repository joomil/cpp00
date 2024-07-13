# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -Wall -g

# Define the name of your final executable
TARGET = my_program

# Define the source files
SRCS = Account.cpp tests.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# The first rule is the default. It will be executed when you run 'make' without arguments
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove the object files and the executable
clean:
	$(RM) $(OBJS) $(TARGET)

# Additional dependencies
-include $(OBJS:.o=.d)
