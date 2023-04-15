#!/bin/bash

# Remove the build folder if it exists
if [ -d "build" ]; then
  rm -r build
fi

# Create the build folder and navigate to it
mkdir build
cd build

# Generate the build files using CMake
cmake ..

# Build the code
make

echo "Let's build some code and see what happens!"
echo
echo -e "      (\\__/)      (\\__/)"
echo -e "      (=^ .^=)    (=^. ^=)"
echo -e "     c(\")(\")      c(\")(\")"
echo "++++++++++++++++++++++++++++++++++"
# Run the executable
./my_executable

