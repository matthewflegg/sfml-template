# Navigate into the build directory
# Build commands will be run from this folder
cd bin/

root=".." # Root directory of the project  
src="src" # Source files directory
inc="inc" # Header files directory

# Contains the SFML files to link main.o to
# This shouldn't really be changed
lib="\
     -lsfml-audio \
     -lsfml-graphics \
     -lsfml-network \
     -lsfml-system \
     -lsfml-window"

# Contains all of the user-defined source
# files we need to compile & execute the game
#
# Put your source files here, follwing the same
# pattern seen below.
cpp="\
     $root/$src/game.cc"

# Compile the game to an object file main.o
# Link main.o with the libraries and compile
g++ -c $root/$src/main.cc
g++ main.o -o game $lib $cpp