#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


int get_grade(string text);

int main(void)
{
  string text = get_string("Enter text: ");
  int grade = get_grade(text);
  if(grade < 1)
    printf("Before Grade 1");
  else if(grade > 16)
    printf("Grade 16+");
  else
    printf("Grade: %d\n", grade);
  return 0;
}

int get_grade(string text)
{
  int letters,words,sentences;
  letters = words = sentences = 0;

  for(int i = 0; i < strlen(text); i++)
  {
    char curr = text[i];

    if(isalpha(curr))
      letters++;
    
    if(isalpha(curr) && (i == 0 || (i > 0 && text[i-1] == ' ')))
      words++;
    
    if(curr == '.' || curr == '!' || curr == '?')
      sentences++;
  }

  printf("words : %i\n", words);
  printf("letters : %i\n", letters);
  printf("sentences : %i\n", sentences);

  float L = (float)letters / (float)words * 100;
  float S = (float)sentences / (float)words * 100;

  float grade = (0.0588 * L) - (0.296 * S) - 15.8;

  int rounded = round(grade);
  return rounded;
}
