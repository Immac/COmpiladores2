mkdir bin
mkdir gen
mkdir build
bison --defines=tokens.h -o gen/expr_parser.cpp src/expr.y
mv tokens.h gen/tokens.h
cp src/*.h gen/
flex -o gen/expr_lexer.cpp src/expr.l 
g++ -std=c++11 -c -o build/expr_lexer.o gen/expr_lexer.cpp
g++ -std=c++11 -c -o build/expr_parser.o gen/expr_parser.cpp
g++ -std=c++11 -o bin/expr build/expr_lexer.o build/expr_parser.o