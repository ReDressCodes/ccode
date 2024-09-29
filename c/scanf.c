#include <stdio.h>

int main ()
{
  char sentence []="Rudolph is 12 years old ajkdjalkfdjaljdlfjalkfdjalkfjdlkajfdljfdlk";
  char str [20] = {'C','d','e', 'f', 0};
  int i;

  printf ("%s -> %d\n",str,i);
  sscanf (sentence,"%s %*s %d",str,&i);
  printf ("%s -> %d\n",str,i);
  
  return 0;
}
