#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int lengthm, lengthk, a, b, c, i, y;
time_t t;
char mtext[128];
char key[128];
char ctext[128];

int xor() {     //funzione per la cifratura XOR di testo e chiave, e poi testo cifrato e chiave
  for (i = 0; i < lengthm - 1; i++) {
    ctext[i] = mtext[i] ^ key[i];
    mtext[i] = ctext[i] ^ key[i];
    ctext[i] = (ctext[i] % 96) + 31;
  }
  printf("The ciphertext C resulted from the first encryption is (displayed in hexadecimal):\n");
  for (i = 0; i < strlen(ctext); i++)  //rappresentazione del testo cifrato in caratteri esadecimali, qualora la chiave risulti esteticamente poco comprensibile
    printf("%X", ctext[i]);
  printf("\nThe ciphertext C resulted from the first encryption is (displayed in characters):\n");
  printf("%s\n", ctext);
  printf("The ciphertext C' resulted from the second encryption is:\n");
  printf("%s\n", mtext);
  return 0;
}

int keykey() {  //funzione per la chiave generata da tastiera
  printf("Please enter a string of character longer or as long as the text to encrypt: ");
  fgets(key, 128, stdin);
  lengthk = strlen(key);
  if (lengthk >= lengthm) {  //controllo della lunghezza rispetto al testo in chiaro
    printf("The key of the encryption is the following string: %s\n", key);
    for (i = 0; i < lengthk; i++)
    key[i] = (key[i] % 96) + 31;
    xor(); //la cifratura avviene qui, in quanto non volevo avvenisse cifratura di una chiave non valida
    }
  else
    printf("The string is too small! Please enter a longer one\n"); //caso di chiave troppo corta
  return 0;
}

int rankey() {  //funzione per la generazione casuale della chiave
  for (i = 0; i < 128; i++){
    srand (time(&t) * i);
    b = (rand() % 96) + 31;
    key[i] = b;
    }
  printf("The randomly generated key is (displayed in hexadecimal): \n");
  for (i = 0; i < 128; i++)
  printf("%X", key[i]); //rappresentazione della chiave in esadecimali, qualora la chiave sia esteticamente poco comprensibile
  printf("\n(displayed in characters):\n %s\n", key);
  xor(); //la cifratura avviene qui
  return 0;
}

int main() {
  printf("Please enter a string of character as your text to encrypt: "); //Parte #1: chiedo il testo in chiaro
  fgets(mtext, 1000, stdin); //metto 1000 qui come numero grande, per presentare casi di testi piu grandi di 128 posizioni
  lengthm = strlen(mtext);   //l'alternativa era di troncare stringhe che eccedevano il limite, soluzione che io non preferivo
  if (lengthm > 128)         //controllo la lunghezza del testo
    printf("the string exceeds maximum size! Please enter a smaller one\n");
  else {
    printf("The text to encrypt is the following string: %s\n", mtext);
    printf("Please choose an option to generate the encryption key\nPress either 1 or 2 and hit enter:\n");
    printf("Option 1 - you have to write the key yourself\n");
    printf("Option 2 - the key is generated randomly\n");
    scanf("%d", &a); //Parte #2: chiedo all'utente il modo di generare la chiave
    switch (a) {
      case 1: printf("You chose option 1\n");
      getchar();
      keykey(); //chiamo funzione per chiave inserita dall'utente. Parte #3-4: La cifratura, che avviene internamente alla funzione
      break;
      case 2: printf("You chose option 2\n");
      getchar();
      rankey(); //chiamo la funzione per chiave casuale. Parte #3-4: La cifratura, che avviene internamente alla funzione
      break;
      default: printf("Please enter a valid option\n");
      }
  }
  return 0;
}
