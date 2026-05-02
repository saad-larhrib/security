#include <stdio.h>

float ic(char* ch){
    int i = 0;
    int a, N = 0;
    int Val[26] = {0};
    float s = 0;

    while(ch[i] != '\0'){
        a = ch[i] - 'A';  // plus lisible que 65
        if(a >= 0 && a < 26){ // sécurité
            Val[a]++;
            N++;
        }
        i++;
    }

    for(int i = 0; i < 26; i++){
        s += Val[i] * (Val[i] - 1);
    }

    if(N <= 1) return 0;

    float x = s / (N * (N - 1));
    return x;
}

int main(){
    char str[] = "UNENFANTNAPASDAVER";
    float idc = ic(str);
    printf("Indice de Coincidence : %.3f\n", idc);

    return 0;
}
