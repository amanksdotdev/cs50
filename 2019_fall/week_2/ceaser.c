#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define UPPER_CASE_START 97
#define LOWER_CASE_START 65
#define TOTAL_ALPHABETS 26

void print_encode(string text, int key);
int is_valid_num(string str);

int main(int argc, string argv[])
{
  string arg;
  int key;
  if(argc == 2)
  {
    arg = argv[1];
    if(is_valid_num(arg))
    {
      key = atoi(arg);
    }
    else
    {
      printf("Key should be a number!\n");
      return 1;
    }
  }
  else if (argc > 2)
  {
    printf("Usage: ./ceaser key\n");
    return 1;
  }
  else if(argc == 1)
  {
    printf("No key found!\n");
    return 1;
  }

  string text = get_string("Plain text: ");
  print_encode(text, key);
  return 0;
}

void print_encode(string text, int key)
{ 
  printf("Cipher text: ");
  for(int i = 0; i < strlen(text); i++)
  {
    char ch = text[i];
    //uppercase letter
    if(isalpha(ch) && isupper(ch))
    {
      ch = (ch + key) % (LOWER_CASE_START + TOTAL_ALPHABETS);
      if(ch < LOWER_CASE_START)
        ch += LOWER_CASE_START;
      printf("%c", ch);
    }
    //lowercase letter
    else if(isalpha(ch) && islower(ch))
    {
      ch = (ch + key) % (UPPER_CASE_START + TOTAL_ALPHABETS); 
      if(ch < UPPER_CASE_START) 
        ch += UPPER_CASE_START;
      printf("%c", ch);
    }
    else 
    {
      printf("%c", ch);
    }
  }
  printf("\n");
}

int is_valid_num(string str)
{
  for(int i = 0; i < strlen(str); i++)
  {
    if(!isdigit(str[i])) return 0;
  }
  return 1;
}