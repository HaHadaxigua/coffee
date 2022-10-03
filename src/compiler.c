//
// Created by Miku on 2022/10/1.
//

#include <stdio.h>
#include "../include/common.h"
#include "../include/compiler.h"
#include "../include/scanner.h"

void compile(const char *source) {
    Scanner scanner;
    initScanner(&scanner, source);
    int line = -1;
    for (;;) {
        Token token = scanToken(&scanner);
        if (token.line != line) {
            printf("%4d ", token.line);
            line = token.line;
        } else {
            printf("    | ");
        }
        printf("%2d '%.*s'\n", token.type, token.length, token.start);

        if (token.type == TOKEN_EOF) break;
    }
}