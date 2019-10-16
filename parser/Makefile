parser: sam_scanner.l parser.y
	flex sam_scanner.l
	bison -d parser.y
	gcc -o parser lex.yy.c parser.tab.c -lfl

clean:
	rm lex.yy.c parser.tab.c parser.tab.h
