# Custom-Unix-Shell
The aim of this project was to create and implement a custom shell for the Unix system using
the programming language c. The custom Unix shell must be able to perform functional
requirements as specified by the unit documents of the project.

# Features fully functional

o Calling “make” in terminal is working and main will be created.

o “ls”, “ls -l”, “ps”, ”exit”, simple commands are working same as the Unix shell.

o Reconfiguring the prompt shell to the second token given, works functionally as
expected. The “prompt” changes to the 2nd given token.

o “pwd” key word is functional and prints the current directory of the shell process.

o “cd” directory walks fully implemented and tested.

o Wild card functionality is functional. Works for both * and ? wildcards.

o Key word and resulting action for “exit” is functional. Program exits when key word is
entered.

o Program not terminating from the signals “CTRL-C”, “CTRL-\” and “CTRL-Z”

# functionality implemented.
o Concurrent execution “&” is implemented and working.
Features not Fully Functional

o “show” command partially works.

o Shell pipeline and long pipeline implemented but not working.

o Standard input and output are implemented but partially working.

o Claims of zombies implemented but don’t seem working.

o Combination of multiple command partially works.

# Features not implemented
o Sequential execution “;”

o Slow system calls

# Discussion of your solution
We initially had planned to implement the parser as a 3-dimensional array of pointers.
Whereby the first dimension being the indexes for the sequential commands. Then the second
dimension for the background commands and then the last pointers to the command struct.
Unfortunately, on my part (ID: 32901246), I had not properly read the implementation file and
had not seen the example on time, which was the reason for the extension request.
Unfortunately, we were not able to implement the custom design for the cmd_parser though it
is included in the file called scrappedPrototypes. The problem mostly arising due to time
constraints. The major problem for our custom cmd_parser was the need for recursively
looping through the command struct, which unfortunately could not be implemented in time.
The major idea for the implementation was to break the whole project into 2 parts. The
cmd_parser and the job_executor. The cmd_parser was responsible for receiving a string and
constructing the cmd 3-d array. While the Job_executor would perform functions upon the
array to implement the functionality of the required program. The task of creating the
cmd_parser was tasked to Lyndon (32901246) and the job for the job_executor was tasked to
Anson Ting(3421278). Unfortunately, I (32901246) as stated above had glossed over the link for
the cmd_parser so, I was starting from the vantage point of creating the cmd_parser from
scratch.
Given the time constraints and the cmd_parser not being finished on time; it was decided that
we would use the given cmd_parser from the notes and modify it such that it would satisfy our
requirements and include all the features from job_executor into main. The design for the main
function was multiple if-else statements to handle simple requests and then the final else
statement to handle more complex commands. These were all nested inside a while loop that
would iterate through until we had reached the exit clause. Most of the simple commands were
passed to outbound functions and executed there. 
