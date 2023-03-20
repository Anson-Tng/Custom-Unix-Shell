/*  File    :   job_executor.c
 *  Author  :   Lydon   &   Anson
 *  Date    :
 * 
 * 
*/

#include "job_executor.h"

int setPrompt(char* name, char* newName){
    // name     = current name
    // newName  = name to change
    name = (char*)malloc(strlen(newName));
    //printf("%ld",strlen(name));
    //printf("%ld",strlen(newName));
    printf("%s",name);
    printf("%s",newName);
    strcpy(name, newName);
    return 1;
}

int getPwd(){
    char pwd[1024];
    getcwd(pwd,sizeof(pwd));
    printf("%s\n",pwd);
    //free(pwd);
    return 1;
}

int getCd(char* command){
    int valid = chdir(command);
    if(valid){
        perror(command);
        return 0;
    }
    return 1;
}

int runWildcard(char* argv, int* pos){
/*
pos 1 = (cl[lc]->argv[1] != NULL) && (strstr(cl[lc]->argv[1], "*") != NULL)
pos 2 = (cl[lc]->argv[2] != NULL) && (strstr(cl[lc]->argv[2], "*") != NULL)

*/
    glob_t globs;
    int boolean;

    globs.gl_offs = 0;
    globs.gl_pathc = 0;
    globs.gl_pathv = NULL;

    if(*pos == 1){
        boolean = glob(argv,GLOB_NOCHECK, NULL, &globs);
    }else if(*pos == 2){
        boolean = glob(argv,GLOB_NOCHECK, NULL, &globs);
    }else{
        boolean = 1;
    }

    if(boolean){
        for(int i=0;i<globs.gl_pathc;i++){
            printf("%s\n",globs.gl_pathv[i]);
        }
    }

    return 1;
}

int fileInput(char* command, char* redirectIn,char* argv){
    int input;

    if(dup2(input, STDIN_FILENO)){
        close(input);
    }

    if((input = open(redirectIn, O_RDONLY,0)) < 0){
        printf("\nSomething wrong: %s\n", redirectIn);
    }

    execvp(command, &argv);

    return 1;
}

int fileOutput(char* command, char* redirectOut,char* argv){
    int output;

    if(dup2(output, STDOUT_FILENO)){
        close(output);
    }

    if((output = creat(redirectOut, 0777))< 0){
        printf("\nSomething wrong: %s\n", redirectOut);
    }

    execvp(command, &argv);

    return 1;
}


int runPipeline(char* command, char* argv, int input, int output){
    pid_t pid, npid;
    
    if((pid = fork()) < 0){
        printf("\nno fork\n");
    }else if( pid == 0){
        if(input != 0){
            dup2(input, 0);
            close(input);
        }

        if(output != 1){
            dup2(output,1);
            close(output);
        }

        execvp(command, &argv);
    }

    return 1;
}


void exitShell(){
    printf("\nThanks for using it.\n");
    exit(0);
}