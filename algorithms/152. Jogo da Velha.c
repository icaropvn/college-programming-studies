// Algoritmo de Jogo da Velha (Tic Tac Toe)

// 1. Implementar tabela de pontos de jogos seguidos

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fillMatrix(char matrix[3][3]);
void runGame(char matrix[3][3]);
int mainLoop(char matrix[3][3]);
int checkAnswer();
int verifyVictory(char matrix[3][3], int round);
int verifyLines(char matrix[3][3]);
int verifyColumns(char matrix[3][3]);
int verifyDiagonals(char matrix[3][3]);
void printMatrix(char matrix[3][3]);
void playerStroke(char matrix[3][3], int player_id);
void distributePoints(int score_up, int *player1_score, int *player2_score);
void scoreView(int player1_score, int player2_score, int match_counter);
int verifyStroke(char matrix[3][3], int player_stroke, int player_id);
void finalScore();

// função main: começa o jogo pela função 'runGame'
int main()
{
	char matrix[3][3];
	
	setlocale(LC_ALL, "Portuguese");
	
	runGame(matrix);
	
	return 0;
}

// função principal do jogo que possui um loop geral e invoca todas as outras funções
void runGame(char matrix[3][3])
{
	int stop = 0, score_up = 0, match_counter = 0;
	int player1_score, player2_score;
	
	while(1)
	{
		fillMatrix(matrix);
		score_up = mainLoop(matrix);
		match_counter++;
		
		distributePoints(score_up, &player1_score, &player2_score);
		scoreView(player1_score, player2_score, match_counter);
		
		stop = checkAnswer();
		
		if(stop == 1)
			break;
	}
	
	finalScore(player1_score, player2_score);
}

// função que preenche a matriz de números de 1 a 9 para facilitar a escolha do jogador
void fillMatrix(char matrix[3][3])
{
	int i, j;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			matrix[i][j] = '-';
	}
}

// loop principal do jogo; chama as funções de escolha de jogada
// e verificação de vitória/limite de rodadas
int mainLoop(char matrix[3][3])
{
	int round = 1, player_id = 1, winner = 0;
	
	while(1)
	{
		if(round == 1)
			printMatrix(matrix);
		
		if(round % 2 == 0)
			player_id = 2;
		else
			player_id = 1;
		
		playerStroke(matrix, player_id);
		
		round++;
		
		printMatrix(matrix);
		
		winner = verifyVictory(matrix, round);
		
		if(winner || round == 10)
			break;
	}
	
	if(round == 10)
	{
		printf("\n\nEMPATE!\n");
		return 0;
	}
	else
		return winner;
}

// função que verifica, a partir da 5ª rodada, se algum jogador venceu
int verifyVictory(char matrix[3][3], int round)
{
	if(round < 5)
		return 0;
	else 
	{
		if(verifyLines(matrix) == 1 || verifyColumns(matrix) == 1 || verifyDiagonals(matrix) == 1)
			return 1;
		else if(verifyLines(matrix) == 2 || verifyColumns(matrix) == 2 || verifyDiagonals(matrix) == 2)
			return 2;
	}
}

// função que verifica se algum dos jogadores venceu nas LINHAS da matriz
int verifyLines(char matrix[3][3])
{
	int i;
	
	for(i=0; i<3; i++)
	{
		if(matrix[i][0] == 'X' && matrix[i][1] == 'X' && matrix[i][2] == 'X')
		{
			printf("\n\nJogador 01 venceu na linha %i!\n", i+1);
			return 1;
		}
		
		if(matrix[i][0] == 'O' && matrix[i][1] == 'O' && matrix[i][2] == 'O')
		{
			printf("\n\nJogador 02 venceu na linha %i!\n", i+1);
			return 2;
		}
	}
	
	return 0;
}

// função que verifica se algum dos jogadores venceu nas COLUNAS da matriz
int verifyColumns(char matrix[3][3])
{
	int j;
	
	for(j=0; j<3; j++)
	{
		if(matrix[0][j] == 'X' && matrix[1][j] == 'X' && matrix[2][j] == 'X')
		{
			printf("\n\nJogador 01 venceu na coluna %i!\n", j+1);
			return 1;
		}
		
		if(matrix[0][j] == 'O' && matrix[1][j] == 'O' && matrix[2][j] == 'O')
		{
			printf("\n\nJogador 02 venceu na coluna %i!\n", j+1);
			return 2;
		}
	}
	
	return 0;
}

// função que verifica se algum dos jogadores venceu nas DIAGONAIS da matriz
int verifyDiagonals(char matrix[3][3])
{
	int i, j = 2;
	
	if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
	{
		printf("\n\nJogador 01 venceu na diagonal principal!\n");
		return 1;
	}
	
	if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
	{
		printf("\n\nJogador 02 venceu na diagonal principal!\n");
		return 2;
	}
	
	if(matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
	{
		printf("\n\nJogador 01 venceu na diagonal secundária!\n");
		return 1;
	}
	
	if(matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
	{
		printf("\n\nJogador 02 venceu na diagonal secundária!\n");
		return 2;
	}
	
	return 0;
}

// função que imprime a matriz tabulada como um jogo da velha
void printMatrix(char matrix[3][3])
{
	int i, j;
	int counter = 1;
	
	printf("\n");
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(j == 2)
			{
				if(matrix[i][j] == '-')
					printf(" %i ", counter);
				else
					printf(" %c ", matrix[i][j]);
			}
			else
			{
				if(matrix[i][j] == '-')
					printf(" %i |", counter);
				else
					printf(" %c |", matrix[i][j]);
			}
			
			counter++;
		}
		
		if(counter < 9)
		    printf("\n---|---|---\n");
	}
}

void playerStroke(char matrix[3][3], int player_id)
{
	int player_stroke;
	
	while(1)
	{
		printf("\n\nJogador %02i: qual bloco deseja jogar?\nR: ", player_id);
		scanf("%i", &player_stroke);
		
		if(verifyStroke(matrix, player_stroke, player_id) == 1)
			break;
		else if(verifyStroke(matrix, player_stroke, player_id) == 0)
			printf("\nEste bloco já foi usado em outra jogada. Escolha um bloco válido.");
		else
			printf("\nEste bloco não existe.");
	}
}

int verifyStroke(char matrix[3][3], int player_stroke, int player_id)
{
	int i, j;
	int counter = 1;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(counter == player_stroke)
			{
				if(matrix[i][j] == '-')
				{
					if(player_id == 1)
						matrix[i][j] = 'X';
					else
						matrix[i][j] = 'O';
						
					return 1;
				}
				else
					return 0;
			}
			
			counter++;
		}
	}
	
	return -1;
}

void distributePoints(int score_up, int *player1_score, int *player2_score)
{
	if(score_up == 1)
		*player1_score += 2;
	else if(score_up == 2)
		*player2_score += 2;
	else
	{
		(*player1_score)++;
		(*player2_score)++;
	}	
	
}

// função que imprime o placar atual do jogo e o número da rodada jogada
void scoreView(int player1_score, int player2_score, int match_counter)
{	
	printf("\n======== Placar Rodada %02i ========\n", match_counter);
	printf("     Jogador 01  x  Jogador 02\n");
	printf("        %02i             %02i   \n", player1_score, player2_score);
	printf("==================================\n");
}

// função que verifica se o usuário quer jogar mais vezes ou não
int checkAnswer()
{
	char answer;
	
	while(1)
	{
		printf("\nDeseja jogar novamente? [S/N]\nR: ");
		scanf(" %c", &answer);
			
		if(answer == 'n' || answer == 'N')
			return 1;
		else if(answer == 's' || answer == 'S')
			return 0;
		else
			printf("\nResposta Inválida. Tente Novamente.");
	}
}

void finalScore()
{
	printf("\n======== Placar Final ========\n");
	printf("     Jogador 01  x  Jogador 02\n");
	printf("        %02i             %02i   \n", player1_score, player2_score);
	printf("===============================\n");
	
	if(player1_score > player2_score)
		printf("\nJogador 01 venceu o jogo!\n");
	else if(player1_score < player2_score)
		printf("\nJogador 02 venceu o jogo!\n");
	else
		printf("\nO jogo terminou em EMPATE! Que acirrado!\n");
}
