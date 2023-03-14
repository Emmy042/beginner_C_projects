#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "words.h"

void swaptext(char *string, int a, int b)
{
  /**
   * shuffle string
   */
  char temp = string[a];
  string[a] = string[b];
  string[b] = temp;
}


int main(void)
{
  char tempword_1[50];
  char tempword_2[50];
  char answer[50];
  int result;
  int score = 0;


  /* set timer to be 30 seconds from now */
  time_t timer = time(NULL) + 30;

  /* get a the size of a single string in the words_list header file */
  int num_words = sizeof(words_list) / sizeof(words_list[0]);


  while (time(NULL) < timer)
    {
       srand(time(NULL));

       /* generate a random index from array of words_list and assign it to question */
       int random_index = rand() % num_words;
       char *question = words_list[random_index];

       /* copy the question variable into tempword_1 and into tempword_2*/
       strcpy(tempword_1, question);
       strcpy(tempword_2, tempword_1);


       /* gettting the length of the string */
       int length = strlen(tempword_1);
       int index1 = 1, index2 = length - 1;



       /* swapping the characters of the string */
       swaptext(tempword_1, index1, index2);

       printf("the word is ::::: %s\n", tempword_1);


      /* condition to check the status of the game */

      printf("\narrange the word to win!!, you have %ld seconds now\n", timer - time(NULL));
      scanf("%s", answer);

      /* check if the string from user and computer are equal*/
      result = strcmp(answer, tempword_2);

      if (result == 0)
	{
	  printf("***CONGRATULATIONS!!!***, YOU WON THIS ROUND\n");
	  score = score + 5;
	  timer = timer + 5;
	}
      else if(time(NULL) >= timer)
	{
	  printf("SORRY, YOUR TIME HAS ELASPED!!! and your score is [%d]\n", score);
	  break;
	}
      else
	{
	  printf("SORRY, TRY AGAIN, you have %ld seconds remaining", timer - time(NULL));

	}
    }
}
