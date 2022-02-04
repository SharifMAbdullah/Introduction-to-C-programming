#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void countMax(FILE *f,int freq[])
{
  int c;
  while( (c = fgetc(f)) != EOF)
    {
      if(isalpha(c))
	{
	  c = tolower(c);
	  c = c - 'a';
	  freq[c]++;
	}
    }
}

int getFreqOfLetters(int freq[])
{
  int max = freq[0];
  int serialOf = 0;

  for(int i=0; i<26; i++)
    {
      if(freq[i] > max)
	{
	  max = freq[i];
	  serialOf = i;
	}
    }
  return serialOf;
}

int main(int argc, char **argv)
{
  if(argc!=2)
    {
      perror("Usage: Wrong number of arguments!");
      return EXIT_FAILURE;
    }
  FILE *f = fopen(argv[1],"r");
  if(!f)
    {
      perror("Could not open file!");
      return EXIT_FAILURE;
    }

  int freq[30] = {0};
  countMax(f,freq);
  int serialOfMax = getFreqOfLetters(freq);
  int key = (serialOfMax + 'a' - 'e' + 26)%26;
  printf("%d\n",key);

  return 0;
}
