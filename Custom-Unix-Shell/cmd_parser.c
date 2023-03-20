#include "cmd_parser.h"

/*******************************************************************************
*   File: CMD_PARSER_H
*   Author: Anson & Lyndon
*   Date:
*
*******************************************************************************/

CMD_Struct ****getSingleLineCMD(char * givenCMD)
{
    /* the function should have the structures for pointers */

    //array of pointers to strings
    char * charPtr[256];            //stores sequential commands in strings
    int a;
    CMD_Struct *cmdPtr; //pointer to a struct
    CMD_Struct ****cmdArrayPtr;
    const char sequentialDelim[2] = ';';
    const char backgroundDelim[2] = '&'; //could add delim as '/n'

    char **strArrayPtr;




    int sequentialCMDCount;


    sequentialCMDCount = 0;

    sequentialCMDCount =  get_number_of_occurrences(givenCMD, sequentialDelim[0]);
    sequentialCMDCount++;
    cmdArrayPtr = (struct CMD_Struct****)calloc((sequentialCMDCount+1), sizeof(struct CMD_Struct***)); //pointer to an array of cmd_struct pointers
    cmdArrayPtr[sequentialCMDCount] = NULL; //end of array of pointers
    strArrayPtr = (char **)calloc(sequentialCMDCount, sizeof(char*))
    //cmdMatrixTally = (int***)calloc((sequentialCMDCount + 1), sizeof(int**))
    //cmdMatrixTally[sequentialCMDCount] = NULL;

    char *sequentialToken;
    char *backgroundToken;


    int sequentialTokenCount = 0;
    int outerCount = 0;



    int strCount = 0;

    do{
        if(strCount == 0)
        {
            sequentialToken = strtok(givenCMD, sequentialDelim);
        }
        else
        {
            sequentialToken = strtok(NULL, sequentialDelim);
        }
        strArrayPtr[strCount] = strdup(sequentialToken);
        strCount++

    }while(strCount < sequentialToken);


    for(int i = 0; i < sequentialCMDCount; i++)
    {

        //sequentialToken = strtok(NULL, sequentialDelim[0]);

        tempOuterString = strdup(strArrayPtr[i]); //free this at end.


        int innerTokenCount = 0;
        int innerCount = 0;
        int backgroundCMDCount;
        int specificTokenCount;

        innerCount = 0;

        backgroundCMDCount = 0;
         //searchChar = '&';

        backgroundCMDCount =  getNumOccurrences(tempOuterString, backgroundDelim[0]);
        backgroundCMDCount++; //if n is number of '&'. then n+1 is number of background commands

        cmdArrayPtr[i] = (struct CMD_Struct***)calloc((backgroundCMDCount + 1), sizeof(struct CMD_Strict**));
        cmdArrayPtr[backgroundCMDCount] = NULL; //end of array of pointer for background cmd pointers


        innerCount = 0;

        while(innerCount < backgroundCMDCount)
        {

            if(innerCount == 0)
            {
                backgroundToken = strtok(tempOuterString, backgroundDelim[0]);
            }
            else
            {
                backgroundToken = strtok(NULL, backgroundDelim[0]);
            }


            char *tempInnerString;
            tempInnerString = strdup(backgroundToken); //free up later


            specificTokenCount = 0;

            specificTokenCount = specificTokenCount + getNumOccurrences(tempInnerString, '>');
            specificTokenCount = specificTokenCount + getNumOccurrences(tempInnerString, '<');
            specificTokenCount = specificTokenCount + getNumOccurrences(tempInnerString, '|');
            specificTokenCount = specificTokenCount + 1;



            cmdArrayPtr[i][innerCount] = (struct CMD_Struct**)calloc((specificTokenCount+1), sizeof(struct CMD_Struct*));
            cmdArrayPtr[i][innerCount][specificTokenCount] = NULL;
            populateStructArray(cmdArrayPtr[i][innerCount],tempInnerString, 0);




             innerCount++;

             free(tempInnerString);

          } //might produce +1 command structs; careful
        }
    return cmdArrayPtr;
}


//recieves string containing no '&' and no ';' characters.
void populateStructArray(CMD_Struct **cmdArray, char * cmdStr, int arraySize, int iteration) //recursive function to go through <,> and |
{
    char * singleToken;

    char * tempString;

    char * token;
    char * secToken;

    char * redirIn = NULL;
    char * redirOut = NULL;

    int pipe = 0;

    static int cmdCount;

    if(iteration == 0)
    {
        cmdCount = 0;
        //token = strtok_r(cmdStr, singleToken, cmdStr); //gets first token

    }


    if((singleToken = getSingleToken(cmdStr)) != NULL)
    {
        char * tempToken;


        iteration++;

        populateStructArray(cmdArray, cmdStr, arraySize, iteration);

        switch(singleToken)
        {
            case">":
                tempToken = strtok(cmdStr, input);
                tempToken = strtok(NULL, input); //this should only include the first one
                redirIn = NULL;
                redirOut = strdup(token);


                break;
            case"<":
                tempToken = strtok(cmdStr, input);
                tempToken = strtok(NULL, input);

                redirIn = NULL;
                redirOut = strdup(token);
                break;
            case"|":
                tempToken = strtok(cmdStr, input);
                tempToken = strtok(NULL, input);
                pipe = 1;
                redirIn = NULL;
                redirOut = strdup(tempToken);
                break;
        }
        cmdElement[iteration] = makeSimpleCMD(cmdElement[iteration], cmdStr, redirIn, redirOut, pipe);
    }
    else
    {
        cmdElement[iteration] = makeSimpleCMD(cmdArray[cmdCount], cmdStr, NULL, NULL, 0);
    }

}


CMD_Struct * makeSimpleCMD(CMD_Struct * cmdElement, char * givenStringCMD, char *redirIn, char *redirOut, int givenPipe)
{
    cmdElement->redirInput = strdup(redirIn);
    cmdElement->redirOutput = strdup(redirOut);

    getArgCV(givenStringCMD, cmdElement);
    cmdElement->path_name = cmdElement->arg[0];
    cmdElement->pipe = givenPipe;

    return cmdElement;
}


void getArgCV(char * strCMD, CMD_Struct *givenCMD)
{
    char *token;
    int count = 1;
    token = strtok(strCMD, white_space);

    givenCMD->path_name = strdup(token);
    givenCMD->argv = realloc((void *) givenCMD->argv, sizeof(char *));
    givenCMD[0] = strdup(token);

    while(token != NULL)
    {
        givenCMD->argv = realloc((void*)givenCMD->argv, (count + 1) * sizeof(char *))
        givenCMD->argv[count] = strdup(token);
        count++
    }

    givenCMD->argc = count;
}

int getNumOccurrences(char *givenString, char token)
{
    int count = 0;
    int i = 0;
    while(givenString[i] != '\0')
    {

        if(givenString[i] == char) //might need to change from constant to a char variable e.g char search = ';';
        {
            count++;
        }
        i++;
    }

    return count;
}

char * getSingleToken(char * tempStr)
{
    char * token = NULL;

    if((token = strchr(tempStr, '>')) != NULL)
    {
        token = '>';
    }
    else if((token = strchr(tempStr, '<')) != NULL)
    {
        token = '<';
    }
    else if((token = strchr(tempStr, '|')) != NULL)
    {
        token = '|';
    }

    return token;
}

void freeArrayCMD(CMD_Struct ****cmdStruct)
{
    int j = 0;
    int k = 0;
    int i = 0;

    while(cmdStruct[i] != NULL)
    {
        j = 0;
        while(cmdStruct[i][j] != NULL)
        {
            k = 0;
            while(cmdStruct[i][j][k] != NULL)
            {
                freeCMD(cmdStruct[i][j][k]);
                free(cmdStruct[i][j][k])
                cmdStruct[i][j][k] = NULL;
                k++;
            }
            free(cmdStruct[i][j]);
            cmdStruct[i][j] = NULL;
            j++;


        }
        i++
        free(cmdStruct[i])
        cmdStruct[i] = NULL;
    }

}


CMD_Struct * freeCMD(CMD_Struct * tempCMD)
{
    int argIndex = 0;
    while(tempCMD->argv[argIndex] != NULL)
    {
        tempCMD->argv[argIndex] = NULL;
        argIndex++;
    }
    free(tempCMD->path_name);
    free(tempCMD->redirInput);
    free(tempCMD->redirOutput);
}


void printCommands(CMD_Struct * tempCMD)
{
    int j = 0;
    int k = 0;
    int i = 0;

    while(cmdStruct[i] != NULL)
    {
        j = 0;
        while(cmdStruct[i][j] != NULL)
        {
            k = 0;
            while(cmdStruct[i][j][k] != NULL)
            {
                fprintf(stderr,"com_pathname=%s\n", cmdStruct[i][j][k]->path_name);
                fprintf(stderr,"argc=%d\n", cmdStruct[i][j][k]->argc);
                for(i=0;  com->argv[i]!=NULL; i++)
                {
                    fprintf(stderr,"argv[%d]=%s\n", i, cmdStruct[i][j][k]->argv[i]);
                    fprintf(stderr,"#######\n");
                }

                if (cmdStruct[i][j][k]->redirInput == NULL)
                    fprintf(stderr,"redirect_in=NULL\n");
                else
                    fprintf(stderr,"redirect_in=%s\n", cmdStruct[i][j][k]->redirOutput);
                if (com->redirOutput == NULL)
                    fprintf(stderr,"redirect_out=NULL\n");
                else
                    fprintf(stderr,"redirect_out=%s\n", cmdStruct[i][j][k]->redirOutput);

                k++;
            }

            j++;


        }
        i++

    }
}
