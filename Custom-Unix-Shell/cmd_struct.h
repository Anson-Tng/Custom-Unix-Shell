/*
 *
 *
 *
*/

#ifndef CMD_STRUCT.H
#define CMD_STRUCT.H

#define MAX_ARGS 1000

typedef struct{
    char* P_name;
    char* argv[MAX_ARGS];
    int argc;
    char* redirInput;
    char* redirOutput;

} CMD_Struct;

#endif