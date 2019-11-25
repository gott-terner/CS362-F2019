#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	char nextChar;

	nextChar = (rand() % 94 + 32);

	// TODO: rewrite this function
    return nextChar;
}

char *inputString()
{
	char letters[15] = "rsseettrypoiu";
	char* ptr = malloc(10);


	int len = 5;
	
	int i;
	for (i = 0; i < len; i++)
	{
		ptr[i] = letters[(rand() % 15)];
	}
	
	
	// TODO: rewrite this function
    return ptr;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  int loop = 1;
  while (loop)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error \n");
	  loop = 0;
      //exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
