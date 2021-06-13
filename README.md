# jsonflatten
A JSON flattening utility in C++. 

How does it work? The utility uses json parser from https://github.com/nlohmann/json and implements a recursive function to go through the json document and flatten the file. 

Assumptions made - The utility makes some assumptions
  1. Assuming the whole input file will fit into memory
  2. Input file will be valid
  3. Output can be written to any ostream object; however the utility prints the output to stdout.
  4. Solving using recursion assuming the call stack doesn't overflow due to json nesting that is too deep. 

How to compile? - cd to the project directory and run the command - **g++ -g json_flatten.cpp jsonflatten_tests.cpp -o ./json_flatten**

How to run? - **cat ./tests/tc1.json | ./json_flatten**

Test cases - Test cases can be run by the command **json_flatten -t**. This will run test cases under tests/ folder and validate the output against the precomputed output
