//es6.c
/*
//6.1
//Scrivere una funzione mescola che date due stringhe restituisca (allocandola dinamicamente) una terza stringa
//ottenuta mescolando un carattere per volta le due stringhe. Es: cedi & razzo --> creadzizo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shuffle(char *s1_in, char *s2_in);

int main(void) {
	char s1[] = "aaaaaaa";
	char s2[] = "bbbb";
	char* s3 = shuffle(s1, s2);
	printf("%s\n", s3);
}

char* shuffle(char *s1_in, char *s2_in) {
	int s1_length = strlen(s1_in);
	int s2_length = strlen(s2_in);
	char *s_out;
	s_out = malloc((s1_length + s2_length + 1) * sizeof(char));
	if(s1_length <= s2_length) {
		int k = s2_length;
		s2_length = s1_length;
		s1_length = k;
	}
	int i, j = 0;
	for(i = 0; i < s2_length; i++) {
		s_out[j] = s1_in[i];
		s_out[++j] = s2_in[i];
		j++;
	}
	for(i = s2_length; i < s1_length; i++) {
		s_out[j] = s1_in[i];
		j++;
	}
	return s_out;
}
*/
//6.2
//Scrivere un programma in cui:
//a) Si definisce una struttura esame con campi nomecorso, cfu, voto;
//b) Si chiede all'utente quanti esami si vogliono inserire;
//c) Si crea un array dinamico di esami;
//d) Si fanno inserire all'utente i dati di ogni esame;
//e) Si calcola la media pesata; (vote1 * cfu1 + vote2 * cfu2 * ...) / (cfu1 + cfu2 + ...);

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int cfu, vote;
} exam;

float weighted_average(exam *pi, int length);

int main(void) {
	printf("How many exams? ");
	int length;
	scanf("%d", &length);
	exam *pi;
	pi = (exam*) malloc(sizeof(exam) * length);
	if(pi == NULL) {
		printf("Malloc Error");
		return 0;
	}
	int i;
	for(i = 0; i < length; i++) {
		printf("[%d] Name: ", i);
		scanf("%s", &pi[i].name);
		printf("[%d] CFU: ", i);
		scanf("%d", &pi[i].cfu);
		printf("[%d] Vote: ", i);
		scanf("%d", &pi[i].vote);
	}
	printf("Weighted Average: %.2f\n", weighted_average(pi, length));
	return 0;
}

float weighted_average(exam *pi, int length) {
	float out; int i, j = 0;
	for(i = 0; i < length; i++) {
		out += pi[i].cfu * pi[i].vote;
		j += pi[i].cfu;
	}
	return out / j;
}

//es6.c
