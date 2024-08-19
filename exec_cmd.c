#include "shell.h"

/**
 * 
 */

int exec_command(char *argv[], char **environ)
{
   pid_t id;
   int status;

   id = fork();
   if (id < 0)
   {
      perror("Error in creating new Process");
      exit(EXIT_FAILURE);
   } else if (id == 0)
      execve(argv[0], argv, environ);
   else
   {
      waitpid(id, &status, 0);
   }
   return (0);
}