#ifndef CMD_PARSER_H
#define CMD_PARSER_H

/*******************************************************************************
*   File: CMD_PARSER_H
*   Author: Anson & Lyndon
*   Date:
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include <string.h>

#include "cmd_struct.h"

static const char white_space[3] = {(char) 0x20, (char) 0x09, (char) 0x00};

CMD_Struct ****getSingleLineCMD(char * givenCMD);

CMD_Struct **populateStructArray(CMD_Struct **cmdArray, char *cmdStr);

CMD_Struct * makeSimpleCMD(CMD_Struct * cmdElement, char * givenStringCMD, char *redirIN, char *redirOut, int pipe);



void getArgCV(char * strCMD, CMD_Struct *givenCMD);



//search given string and give amount of occurrences
int getNumOccurrences(char *givenString, char token);

char * getSeparator(char * tempStr);

void freeArrayCMD(CMD_Struct ****cmdStruct);

CMD_Struct * freeCMD(CMD_Struct * tempCMD);

void printCommands(CMD_Struct * tempCMD);


//******************************************************************************












#endif
