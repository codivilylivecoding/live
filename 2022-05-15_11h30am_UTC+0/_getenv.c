#include "main.h"
#include <stddef.h>

extern char **environ;

char *_getenv(const char *name)
{
   size_t i = 0, k = 0;
   char *env_var = NULL;

   while (environ[i] != NULL)
   {
        env_var = environ[i];
        k = 0;
        while (env_var[k] == name[k] &&  env_var[k] != '=' && env_var[k] && name[k])
            k++;
        if (name[k] == '\0')
            return (_strdup(env_var));
        i++;
   }

   return (NULL);
}
