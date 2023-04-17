# Pipes-In-C
Program displaying interprocess communication through pipes.

Q1.
From USP, compile and execute following:
  i) Program 3.1
  ii) Program 3.2
  iii) Exercise 3.1
  iv) Exercise 3.8 and 3.9
  Ensure you understand the above programs/exercises. You don’t have to submit any
  answers for this question.

Q2.
  A. Write a program that sleeps for a random duration between 0 and 5 seconds and then displays, on a single line, its process id and parent process’s id. [Hint: getpid(), getppid()]
  B. Write a (parent) program that makes three child processes. Each child should run the program of part A. [Hint: fork(), exec()]
  C. Update the (parent) program in part B such that it waits for all child processes to complete execution. When a child process stops, the parent displays that child’s process id. Note that the parent should only begin waiting after all three child processes have been forked. [Hint: wait() or waitpid()]

Q3.
  A. Convert the following code snippet into a program. Execute the program and ensure you understand the output.
  fork();
  fork(); printf(“A\n”);
  fork(); printf(“B\n”);
  B. Now, remove \n from both printf() above and execute the program. Are the letters A and B displayed in the same quantity (and/or sequence) as in part A? If the output is different, find out the reason. [Hints: buffer, standard output, standard error, google.com, stackoverflow.com]
  C. Repeat part A and B after replacing printf(...) with fprintf(stderr,...) in the snippet above. Comment on the output displayed by above program now.

Q4.

  A Dataset partitioning is a process where a dataset is partitioned into smaller datasets, usually of same or similar sizes. A large file is therefore broken down into multiple smaller datasets for easier processing. You are to perform dataset partitioning in the following manner:
  
  a. Parent process:
  i. Opens a large file (preferably 500MB or more) given to it as command line argument.
  ii. Spawns N number of children via fork/exec. The number of children to be spawned will also be given as a command line argument to the Parent process.
  iii. Creates two pipes for each child.
  iv. The first pipe will be used to send data from the Parent to the child. The Parent will read a set number of characters from the file and send it via the pipe to the child. Number of characters to be read in one go will also be given as a command line argument.
  v. The second pipe will be used by the child, at the completion of data transfer, to return how many characters were written in the file.
  vi. The parent, on completion of the whole process, will display Child PID and number of characters written by each child.
  vii. Any open pipes should be closed down before exiting.
  
  b. Child Process:
  i. Self-contained code, hence no code sharing with Parent.
  ii. Uses Standard Input to read text for file writing.
  iii. Receives the original filename from the Parent as a command line argument. The file created by the child should be in the format filename-ChildPID.
  iv. Receives the file descriptor information from the Parent as a command line argument for the second pipe.
  v. Writes data as it is received from the parent to the new file.
  vi. Once the file writing process is over, the child process will close the file, send the number of characters written back to the Parent process via the second pipe and closes any open pipes.
