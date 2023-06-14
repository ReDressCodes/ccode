#include <stdio.h>
#include <string.h>

char *mystrstr(const char *const haystack, const char *needle)
{
      while(*haystack)
      {
             const char *q = haystack;
             const char *p = needle;

             while(*p && *q)
             {
                     if (*p != *q)
                             break;
                     p++;
                     q++;
             }

             if (*p == '\0') return (char *)haystack;

             haystack++;
      }

      return NULL;
}

int main(int argc, char *argv[])
{
        const char *haystack = "This is xxx string\n";
        char *needle = "x";

        char *found = mystrstr(haystack, needle);

        if (found)
                printf(" %s \n", found);
        else
                printf(" Not found \n");

        return 0;
}
