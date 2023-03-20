/*
 *
 *
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cmd_parser.h"
#include "job_executor.h"

int main(){
    char* prompt;
    char commands[1000];
    while(true){

        if(prompt[0] == '\0'){
            printf("%%");
        }else{
            printf("%s ",prompt);
        }
        
        fgets(commands,1000,stdin);
        printf("%d",setPrompt(prompt,commands));
        printf("changed prompt %s",prompt);
        //printf("%s",commands);

        //exit(0);
    }
}