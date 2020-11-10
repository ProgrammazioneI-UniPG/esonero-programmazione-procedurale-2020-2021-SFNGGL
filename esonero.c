#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int lengthm, lengthk, a, b, c, i;
time_t t;
char mtext[128];
char key[128];
char ctext[128];

int xor() {
  for (i = 0; i < lengthm; i++) {
    ctext[i] = mtext[i] ^ key[i];
    mtext[i] = ctext[i] ^ key[i];
  }
  printf("The ciphertext C resulted from the first encryption is:\n");
  printf("%s\n", ctext);
  printf("The ciphertext C' resulted from the second encryption is:\n");
  printf("%s\n", mtext);
  return 0;
}

int keykey() {
  printf("Please enter a string of character longer or as long as the text to encrypt: ");
  fgets(key, 128, stdin);
  lengthk = strlen(key);
  if (lengthk >= lengthm) {
    printf("The key of the encryption is the following string: %s\n", key);
    for (i = 0; i <= lengthk; i++) {
      key[i] = (key[i] % 96) + 31;
      }
    xor();
    }
  else
    printf("The string is too small! Please enter a longer one\n");
  return 0;
}

int rankey() {
  for (i = 0; i < 128; i++){
    srand (time(&t) * i);
    b = (rand() % 96) + 31;
    key[i] = b;
  }
  printf("The randomly generated key of the encryption is the string:\n");
  printf("%s\n", key);
  xor();
  return 0;
}

int main() {
  printf("Please enter a string of character as your text to encrypt: ");
  fgets(mtext, 1000, stdin);
  lengthm = strlen(mtext);
  if (lengthm > 128)
    printf("the string exceeds maximum size! Please enter a smaller one\n");
  else {
    printf("The text to encrypt is the following string: %s\n", mtext);
    printf("Please choose an option to generate the encryption key\nPress either 1 or 2 and hit enter:\n");
    printf("Option 1 - you have to write the key yourself\n");
    printf("Option 2 - the key is generated randomly\n");
    scanf("%d", &a);
    switch (a) {
      case 1: printf("You chose option 1\n");
              getchar();
              keykey();
      break;
      case 2: printf("You chose option 2\n");
              getchar();
              rankey();
      break;
      default: printf("Please enter a valid option\n");
      }
    }
  return 0;
}
