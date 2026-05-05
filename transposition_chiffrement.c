#include <stdio.h>
#include <string.h>

//////////////////////////////////////
// 🔹 TRANSPOSITION
//////////////////////////////////////

void chiffrerTransposition(char message[], int colonnes, char code[]){
    int len = strlen(message);
    int lignes = (len + colonnes - 1) / colonnes;

    char mat[100][100];
    int k = 0;

    // remplir matrice
    for(int i = 0; i < lignes; i++){
        for(int j = 0; j < colonnes; j++){
            if(k < len)
                mat[i][j] = message[k++];
            else
                mat[i][j] = 'X';
        }
    }

    // lecture colonne
    k = 0;
    for(int j = 0; j < colonnes; j++){
        for(int i = 0; i < lignes; i++){
            code[k++] = mat[i][j];
        }
    }
    code[k] = '\0';
}

void dechiffrerTransposition(char code[], int colonnes, char message[]){
    int len = strlen(code);
    int lignes = len / colonnes;

    char mat[100][100];
    int k = 0;

    // remplir colonne
    for(int j = 0; j < colonnes; j++){
        for(int i = 0; i < lignes; i++){
            mat[i][j] = code[k++];
        }
    }

    // lecture ligne
    k = 0;
    for(int i = 0; i < lignes; i++){
        for(int j = 0; j < colonnes; j++){
            message[k++] = mat[i][j];
        }
    }
    message[k] = '\0';
}

//////////////////////////////////////
// 🔹 XOR (CHIFFREMENT PAR FLOT)
//////////////////////////////////////

void repeterCle(char message[], char cle[], char cleRep[]){
    int lenM = strlen(message);
    int lenC = strlen(cle);

    for(int i = 0; i < lenM; i++){
        cleRep[i] = cle[i % lenC];
    }
    cleRep[lenM] = '\0';
}

void chiffrerFlot(char message[], char cleRep[], char code[], int len){
    for(int i = 0; i < len; i++){
        code[i] = message[i] ^ cleRep[i];
    }
}

void dechiffrerFlot(char code[], char cleRep[], char message[], int len){
    for(int i = 0; i < len; i++){
        message[i] = code[i] ^ cleRep[i];
    }
    message[len] = '\0';
}

void afficherHex(char code[], int n){
    for(int i = 0; i < n; i++){
        printf("%02X ", (unsigned char)code[i]);
    }
    printf("\n");
}

//////////////////////////////////////
// 🔹 MAIN
//////////////////////////////////////

int main(){

    char message[100] = "BONJOURSAAD";
    char code[100];
    char decrypted[100];

    printf("=== TRANSPOSITION ===\n");

    chiffrerTransposition(message, 4, code);
    printf("Chiffré: %s\n", code);

    dechiffrerTransposition(code, 4, decrypted);
    printf("Déchiffré: %s\n\n", decrypted);


    //////////////////////////////////////
    printf("=== XOR ===\n");

    char cle[] = "KEY";
    char cleRep[100];
    char xorCode[100];
    char xorDecrypted[100];

    int len = strlen(message);

    repeterCle(message, cle, cleRep);

    chiffrerFlot(message, cleRep, xorCode, len);

    printf("Chiffré (HEX): ");
    afficherHex(xorCode, len);

    dechiffrerFlot(xorCode, cleRep, xorDecrypted, len);
    printf("Déchiffré: %s\n", xorDecrypted);

    return 0;
}
