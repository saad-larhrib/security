#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pgcd(int a, int b){
    if(b == 0) return a;
    return pgcd(b, a % b);
}

int generator(){
    int d;
    do{
        d = rand() % 26;
    }while(pgcd(d, 26) != 1);
    return d;
}

void affine(char str[]){
    int a = generator();
    int b = rand() % 26;

    printf("Clé a=%d, b=%d\n", a, b);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = ((a * (str[i]-'A') + b) % 26) + 'A';
        }
    }

    printf("Message chiffré: %s\n", str);
}

int main(){
    srand(time(NULL));

    char msg[] = "BONJOUR";
    affine(msg);

    return 0;
}
