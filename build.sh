# mkdir bin -p
# mkdir gen -p
# mkdir build -p
# bison --defines=tokens.h -o gen/expr_parser.cpp src/expr.y
# mv tokens.h gen/tokens.h
# cp src/*.h gen/
# cp src/*.h include/
# flex -o gen/expr_lexer.cpp src/expr.l 
cmake .
make