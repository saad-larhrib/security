#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Chiffrement Vigenère
void vigenere_encrypt(char str[], char key[], char result[]) {
    int j = 0;
    int keyLen = strlen(key);

    for(int i = 0; str[i] != '\0'; i++) {

        if(isalpha(str[i])) {
            char c = toupper(str[i]);
            char k = toupper(key[j]);

            result[i] = ((c - 'A' + k - 'A') % 26) + 'A';

            j = (j + 1) % keyLen;
        } else {
            result[i] = str[i]; // garder espaces/symboles
        }
    }

    result[strlen(str)] = '\0';
}

// Déchiffrement Vigenère
void vigenere_decrypt(char str[], char key[], char result[]) {
    int j = 0;
    int keyLen = strlen(key);

    for(int i = 0; str[i] != '\0'; i++) {

        if(isalpha(str[i])) {
            char c = toupper(str[i]);
            char k = toupper(key[j]);

            result[i] = ((c - k + 26) % 26) + 'A';

            j = (j + 1) % keyLen;
        } else {
            result[i] = str[i];
        }
    }

    result[strlen(str)] = '\0';
}

int main() {
    char message[100];
    char key[100];
    char encrypted[100];
    char decrypted[100];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    vigenere_encrypt(message, key, encrypted);
    printf("Encrypted: %s\n", encrypted);

    vigenere_decrypt(encrypted, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
