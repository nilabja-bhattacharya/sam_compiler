
#ifndef _COMMON_H_ 
#define _COMMON_H_ 
 
 
#include <stdlib.h> 
#include <stdio.h> 
#include <assert.h> 
#include <string.h> 
#include <ctype.h>
 
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif
 
#define  MAX_INTEGER INT_MAX

#define  MAX_IDENTIFIER 32 

#define  MAX_TEXT 256

extern FILE * inputFile;
extern FILE * outputFile;
extern FILE * errorFile;
extern FILE * dumpFile;
extern FILE * traceFile;
extern FILE * runInputFile;

extern int errorOccurred;
extern int suppressExecution;

extern int traceScanner;
extern int traceParser;
extern int traceExecution;

extern int dumpSource;
extern int dumpAST;
extern int dumpSymbols;
extern int dumpInstructions;

#endif
