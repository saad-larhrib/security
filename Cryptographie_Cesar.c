#include <stdio.h>

// Déchiffrement César
void dechiffrer(int n, char* msg){
	char resultat[100];
 	int i;
 	for(i = 0; msg[i] != '\0'; i++){
 		if(msg[i] >= 'A' && msg[i] <= 'Z'){
 			resultat[i] = ((msg[i] - 'A' - n + 26) % 26) + 'A';
 		} else {
 			resultat[i] = msg[i];
 		}
 	}
 	resultat[i] = '\0';
 	printf("Message déchiffré: %s\n", resultat);
}

// Chiffrement = déchiffrement avec -n
void chiffrer(int n, char* msg){
	dechiffrer(-n, msg);
}

// Force brute
void forcebrut(char* msg){
	for(int i = 0; i < 26; i++){
 		printf("Clé %d : ", i);
 		dechiffrer(i, msg);
 	}
}

// Fréquence
void freq(char* msg, int f[26]){
	for(int i = 0; i < 26; i++)
 		f[i] = 0;
 	
	for(int i = 0; msg[i] != '\0'; i++){
 		if(msg[i] >= 'A' && msg[i] <= 'Z'){
 			f[msg[i] - 'A']++;
 		}
 	}
}


int main(){
	char msg[] = "KMKQ MAB CV RWTQM XZWOZIUUM YCQ KZGXBM/LMKZGXBM CV BMFBM AMTWV TMKPQNNZM KMAIZ";
	
	dechiffrer(3, "KHOOR");

	chiffrer(3, "HELLO");
 
	forcebrut(msg);
 
	int f[26];
 
	freq("SAADLARHRIB", f);
 
	printf("Fréquences:\n");
 
	for(int i = 0; i < 26; i++){
		printf("%d ", f[i]);
	}
 return 0;
}
