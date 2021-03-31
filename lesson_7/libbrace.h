#ifndef LIBBRACE_H_
#define LIBBRACE_H_

#include <stdbool.h>

typedef enum {
	BRACE_OPENLEFT,
	BRACE_MISSINGLEFT,
	BRACE_NONCONFORMITY,
	BRACE_CONFORMITY
} bMessage;

extern bMessage bErrno;

bool checkLeftBrace(char);
bool checkRightBrace(char);
char getBraceLeftPair(char);
bool checkBraces(char *string, int size);
void printBraceMessage();

#endif
