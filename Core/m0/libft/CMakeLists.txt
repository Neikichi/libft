cmake_minimum_required(VERSION 3.10)
project(MyProject C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Enable compilation database

include_directories(include) # Add include directory

# Use file(GLOB ...) to include all .c files in src/
file(GLOB SOURCES "src/*.c")  # This will find all .c files in the src directory

#add_executable(my_executable ${SOURCES}) # Create executable from all .c files

# Create a static or shared library from all .c files
# Change STATIC to SHARED if you want a shared library (.so or .dll)
add_library(my_library STATIC ${SOURCES})
