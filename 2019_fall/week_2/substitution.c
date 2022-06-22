//SUBSTITUTION CIPHER
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

void print_encoded(char* str, char* key);

int main(int argc, char* argv[])
{
  char* key;
  if(argc == 2)
  {
    if(strlen(argv[1]) < 26)
    {
      printf("Key must contain 26 characters\n");
      return 1;
    }
    key = argv[1];
  }
  else if(argc < 2 || argc > 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  char* str = get_string("Plain text: ");
  print_encoded(str, key);

  return 0;
}

void print_encoded(char* str, char* key)
{
  for(int i = 0; i < strlen(str); i++)
  {
    char ch = str[i];
    if(isalpha(ch) && islower(ch)){
      printf("%c", tolower(key[ch - 'a']));
    }
    else if(isalpha(ch) && isupper(ch))
      printf("%c", key[ch - 'A']);
    else
      printf("%c", ch);
  }
  printf("\n");
}