parser: scanner.l parser.y ast.h ast.c
	flex scanner.l
	bison -d parser.y
	gcc -o parser lex.yy.c parser.tab.c ast.c -lfl

clean:
	rm lex.yy.c parser.tab.c parser.tab.h
