/*Nível Difícil - Exercício 9*/

#include<stdio.h>
#include<stdlib.h>

void calcular_pontuacao(int jogos[][4], int njogos, int pontuacao[][2], int times);

int main() {
	int times = 4, njogos = 12, pontuacao[4][2];
	int jogos[12][4] = {
	{1,2,2,1}, {1,3,0,0}, {1,4,1,3}, {2,3,2,2}, {2,4,0,1}, {3,4,1,0},
	{2,1,3,1}, {3,1,2,2}, {4,1,0,2}, {3,2,1,0}, {4,2,2,2}, {4,3,1,2}};
	calcular_pontuacao(jogos, njogos, pontuacao, times);
	for (int i=0;i<times;i++) {
		printf("Time %i -> %i pontos\n", pontuacao[i][0], pontuacao[i][1]);
	}
	
	return 0;
}

void calcular_pontuacao(int jogos[][4], int njogos, int pontuacao[][2], int times) {
	for (int i=0;i<times;i++) {
		pontuacao[i][0] = i+1;
		pontuacao[i][1] = 0;
	}
	
	for (int i=0;i<njogos;i++) {
		int mandante = jogos[i][0] - 1, visitante = jogos[i][1] - 1, gols_mandante = jogos[i][2], gols_visitante = jogos[i][3];
		if (gols_mandante > gols_visitante) {
			pontuacao[mandante][1] += 3;
		}
		else if (gols_mandante < gols_visitante) {
			pontuacao[visitante][1] += 3;
		}
		else {
			pontuacao[mandante][1] += 1;
			pontuacao[visitante][1] += 1;
		}
	}
}