#include "shell.h"



void command_free(char **commandArr)
{
   int index;

   index = 0;
   while (commandArr)
   {
      free(commandArr[index]);
      index++;
   }
   free(commandArr);
}