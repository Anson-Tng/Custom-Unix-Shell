#ifndef JOB_EXECUTOR_H
#define JOB_EXECUTOR_H

/*  File    :   job_executor.h
 *  Author  :   Lydon   &   Anson
 *  Date    :
 * 
 * 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <glob.h>
#include "cmd_parser.h"
#include <fcntl.h>

//  Prompt
int setPrompt(char* name, char* newName);

//  Pwd
int getPwd();

//  Cd
int getCd(char* command);

//  Wildcard
int runWildcard(char* argv, int* pos);
//  Input and output redirections
int fileInput(char* command, char* redirectIn,char* argv);
int fileOutput(char* command, char* redirectOut,char* argv);

//  Shell pipeline
int runPipeline(char* command, char* argv, int input, int output);
//  Exit
void exitShell();


// 

#endif