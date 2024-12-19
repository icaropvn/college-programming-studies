/*
		APLICAÇÃO DE GRAFOS
		Exercício da disciplina de Teoria da Computação,
		Engenharia de Software, UNAERP, 2024.
		
		Integrantes:
		- Ícaro Costa Pavan (840790)
		- Jeferon Tomaz Querino (769349)
		- João Lucas Rissi da Silva (840228)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// estrutura dos nós da lista de adjacência
typedef struct NoAdjacencia {
	int vertice;
	struct NoAdjacencia *proximo;
} NoListaAdjacencia;

// estrutura dos nós da lista de arestas auxiliar
typedef struct NoAresta {
	int num_aresta;
	int vertice_origem, vertice_destino;
	struct NoAresta *proximo;
} NoListaArestas;

// estrutura dos grafos
typedef struct {
	int **matriz_adjacencia;
	int **matriz_incidencia;
	NoListaAdjacencia **lista_adjacencia;
	
	int vertices;
	NoListaArestas *lista_arestas;
} Grafo;

// estrutura dos nós da fila para auxiliar no encontro do caminho mínimo
typedef struct NoFila {
	int vertice;
	struct NoFila *proximo;
} NoFila;

// estrutura da fila auxiliar do caminho mínimo
typedef struct Fila {
	NoFila *inicio;
	NoFila *fim;
} Fila;

// função para limpar o terminal
void limparTela();

// funções de manipulação da lista encadeada de arestas auxiliar
NoListaArestas* criarNo(int numero, int origem, int destino);
void inserirNoAresta(NoListaArestas **lista, int numero, int origem, int destino);
void destruirLista(NoListaArestas **lista);
void imprimirListaArestas(NoListaArestas *lista);

// função de leitura dos grafos
void inserirGrafoManual(Grafo *grafo);

// funções de construção das 3 representações
void construirMatrizAdjacencia(Grafo *grafo, int vertices, NoListaArestas *lista);
void construirMatrizIncidencia(Grafo *grafo, int vertices, NoListaArestas *lista);
void construirListaAdjacencia(Grafo *grafo, int vertices, NoListaArestas *lista);

// funções das operações dos grafos
void somarGrafos(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma);
void unirGrafos(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_uniao);
void removerAresta(Grafo *grafo);
void removerVertice(Grafo *grafo);
void contrairAresta(Grafo *grafo);
int* caminhoMinimo(Grafo *grafo, int *tamanho_caminho);

// funções de impressão dos grafos
void imprimirMatrizAdjacencia(Grafo *grafo);
void imprimirMatrizIncidencia(Grafo *grafo);
void imprimirListaAdjacencia(Grafo *grafo);

// funções auxiliares
void opcoesImpressaoMatrizAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void imprimirTodasMatrizesAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void opcoesImpressaoMatrizIncidencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void imprimirTodasMatrizesIncidencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void opcoesImpressaoListaAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void imprimirTodasListasAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void destruirGrafo(Grafo *grafo);
void opcoesRemoverAresta(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void opcoesRemoverVertice(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
void opcoesContrairAresta(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao);
int* opcoesCaminhoMinimo(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao, int *tamanho_caminho);
void criarFila(Fila *fila);
void enfileirar(Fila *fila, int vertice);
int desenfileirar(Fila *fila);
int filaEstaVazia(Fila *fila);

int main() {
	#ifdef _WIN32
        setlocale(LC_ALL, "Portuguese");
    #else
        setlocale(LC_ALL, "pt_BR.UTF-8");
    #endif
	
	Grafo grafo1, grafo2;
	Grafo grafo_soma, grafo_uniao;
	
	grafo_soma.lista_arestas = NULL;
	grafo_uniao.lista_arestas = NULL;
	
	int ch, opcao, opcao_grafo_matriz_adjacencia;
	int *caminho_minimo, tamanho_caminho;
	
	printf("Bem-vindo aoa Simulador de Grafos!\n\n");
	
	printf("Insira os dados do primeiro grafo\n");
	printf("----------------------------------------\n");	
	inserirGrafoManual(&grafo1);
	
	limparTela();
	printf("Insira os dados do segundo grafo\n");
	printf("----------------------------------------\n");	
	inserirGrafoManual(&grafo2);
	
	limparTela();
	printf("Grafos armazenados!\n\n");
	
	while(1) {
		printf("O que deseja fazer?\n\n");
		printf("[1] Somar grafos\n[2] Unir grafos\n[3] Remover aresta\n[4] Remover vértice\n");
		printf("[5] Contrair aresta\n[6] Exibir matriz de adjacência dos grafos\n[7] Exibir matriz de incidência dos grafos\n");
		printf("[8] Exibir lista de adjacência dos grafos\n[9] Exibir caminho mínimo dos grafos\n[10] Sair\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				limparTela();
				
				somarGrafos(&grafo1, &grafo2, &grafo_soma);
				
				printf("Nova soma realizada com sucesso!\n");
				
				printf("\nMatriz de Adjacência do Grafo Soma:\n\n");
				imprimirMatrizAdjacencia(&grafo_soma);
				printf("\n---------------------------------------------\n");
				
				printf("\nMatriz de Incidência do Grafo Soma:\n\n");
				imprimirMatrizIncidencia(&grafo_soma);
				printf("\n---------------------------------------------\n");
				
				printf("\nLista de Adjacência do Grafo Soma:\n\n");
				imprimirListaAdjacencia(&grafo_soma);
				printf("\n---------------------------------------------\n\n");
				break;
			case 2:
				limparTela();
				
				unirGrafos(&grafo1, &grafo2, &grafo_uniao);
				
				printf("Nova união realizada com sucesso!\n");
				
				printf("\nMatriz de Adjacência do Grafo União:\n\n");
				imprimirMatrizAdjacencia(&grafo_uniao);
				printf("\n---------------------------------------------\n");
				
				printf("\nMatriz de Incidência do Grafo União:\n\n");
				imprimirMatrizIncidencia(&grafo_uniao);
				printf("\n---------------------------------------------\n");
				
				printf("\nLista de Adjacência do Grafo União:\n\n");
				imprimirListaAdjacencia(&grafo_uniao);
				printf("\n---------------------------------------------\n\n");
				break;
			case 3:
				limparTela();
				opcoesRemoverAresta(&grafo1, &grafo2, &grafo_soma, &grafo_uniao);
				break;
			case 4:
				limparTela();
				opcoesRemoverVertice(&grafo1, &grafo2, &grafo_soma, &grafo_uniao);
				break;
			case 5:
				limparTela();
				opcoesContrairAresta(&grafo1, &grafo2, &grafo_soma, &grafo_uniao);
				break;
			case 6:
				limparTela();
				opcoesImpressaoMatrizAdjacencia(&grafo1, &grafo2, &grafo_soma, &grafo_uniao);
				break;
			case 7:
				limparTela();
				opcoesImpressaoMatrizIncidencia(&grafo1, &grafo2, &grafo_soma, &grafo_uniao);
				break;
			case 8:
				limparTela();
				opcoesImpressaoListaAdjacencia(&grafo1, &grafo2, &grafo_soma, &grafo_uniao);
				break;
			case 9:
				limparTela();
				caminho_minimo = opcoesCaminhoMinimo(&grafo1, &grafo2, &grafo_soma, &grafo_uniao, &tamanho_caminho);
				
				if(caminho_minimo) {
					int i;
					printf("\n---------------------------------------------\n");
					printf("\nCaminho mínimo econtrado: ");
					
					for(i=0; i<tamanho_caminho; i++) {
						printf("%i", caminho_minimo[i]);
					    if (i < tamanho_caminho - 1)
					        printf(" -> ");
					}
					
					tamanho_caminho--;
					printf("\nQuantidade de arestas do caminho: %i\n\n", tamanho_caminho);
				}
				break;
			case 10:
				printf("\nAté mais!\n\n");
				break;
			default:
				printf("\nOpção inválida.\n\n");
				break;
		}
		
		if(opcao == 10)
			break;
	}
	
	return 0;
}

void limparTela() {
	#ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

NoListaArestas* criarNo(int numero, int origem, int destino) {
	NoListaArestas* nova_aresta = malloc(sizeof(NoListaArestas));
	
	nova_aresta->num_aresta = numero;
	nova_aresta->vertice_origem = origem;
	nova_aresta->vertice_destino = destino;
	nova_aresta->proximo = NULL;
	
	return nova_aresta;
}

void inserirNoAresta(NoListaArestas **lista, int numero, int origem, int destino) {
	NoListaArestas* nova_aresta = criarNo(numero, origem, destino);
	
	if(*lista == NULL) {
		*lista = nova_aresta;
		return;
	}
	
	NoListaArestas *atual = *lista;
	while(atual->proximo != NULL) {
		atual = atual->proximo;
	}
	
	atual->proximo = nova_aresta;
}

void destruirLista(NoListaArestas **lista) {
	NoListaArestas *aux = *lista;
	NoListaArestas *proximo;
	
	while(aux != NULL) {
		proximo = aux->proximo;
		free(aux);
		aux = proximo;
	}
	
	*lista = NULL;
}

void imprimirListaArestas(NoListaArestas *lista) {
	NoListaArestas *aux = lista;
	
    printf("\nArestas adicionadas:\n\n");
    
    while (aux != NULL) {
    	printf("---------------------------\n");
        printf("Aresta %02i\n", aux->num_aresta);
        printf("Vértice 1: %2i\n", aux->vertice_origem);
        printf("Vértice 2: %2i\n\n", aux->vertice_destino);
        
        aux = aux->proximo;
    }
}

void inserirGrafoManual(Grafo *grafo) {
	int contador_arestas = 0, ch;
	int vertice1, vertice2;
	char opcao;
	
	printf("Insira a quantidade de vértices do grafo: ");
	scanf("%i", &grafo->vertices);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	grafo->lista_arestas = NULL;
	
	printf("\n");
	while(1) {
		printf("Seu grafo possui %i vértices e %i arestas.\nGostaria de adicionar alguma aresta? [s/n]\nR: ", grafo->vertices, contador_arestas);
		scanf("%c", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 's':
				contador_arestas++;
				
				while(1) {
					printf("\nInsira o número do PRIMEIRO vértice para compor a aresta %02i: ", contador_arestas);
					scanf("%i", &vertice1);
					while ((ch = getchar()) != '\n' && ch != EOF);
					
					if(vertice1 <= grafo->vertices)
						break;
					else
						printf("\nEsse vértice não existe no grafo.\n");
				}
				
				while(1) {
					printf("\nInsira o número do SEGUNDO vértice para compor a aresta %02i: ", contador_arestas);
					scanf("%i", &vertice2);
					while ((ch = getchar()) != '\n' && ch != EOF);
					
					if(vertice2 <= grafo->vertices) {
						printf("\n");
						break;
					}
					else
						printf("\nEsse vértice não existe no grafo.\n");
				}
				
				inserirNoAresta(&grafo->lista_arestas, contador_arestas, vertice1, vertice2);
				break;
			case 'n':
				break;
			default:
				printf("\nOpção inválida.\n\n");
				break;
		}
		
		if(opcao == 'n')
			break;
	}
	
	construirMatrizAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
	construirMatrizIncidencia(grafo, grafo->vertices, grafo->lista_arestas);
	construirListaAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
}

void construirMatrizAdjacencia(Grafo *grafo, int vertices, NoListaArestas *lista) {
	int i, j;
	
	grafo->matriz_adjacencia = malloc(vertices * sizeof(int*));
	
	for(i=0; i<vertices; i++) {
		grafo->matriz_adjacencia[i] = malloc(vertices * sizeof(int));
		
		for(j=0; j<vertices; j++) {
			grafo->matriz_adjacencia[i][j] = 0;
		}
	}
	
	NoListaArestas *aux = lista;
	
	while(aux != NULL) {
		grafo->matriz_adjacencia[(aux->vertice_origem)-1][(aux->vertice_destino)-1]++;
		aux = aux->proximo;
	}
	
	aux = lista;
	
	while(aux != NULL) {
		grafo->matriz_adjacencia[(aux->vertice_destino)-1][(aux->vertice_origem)-1]++;
		aux = aux->proximo;
	}
}

void construirMatrizIncidencia(Grafo *grafo, int vertices, NoListaArestas *lista) {
	int i, j;
	int arestas = 0;
	
	NoListaArestas *aux = lista;
	
	while(aux != NULL) {
		arestas++;
		aux = aux->proximo;
	}
	
	grafo->matriz_incidencia = malloc(vertices * sizeof(int*));
	
	for(i=0; i<vertices; i++) {
		grafo->matriz_incidencia[i] = malloc(arestas * sizeof(int));
		
		for(j=0; j<arestas; j++) {
			grafo->matriz_incidencia[i][j] = 0;
		}
	}
	
	aux = lista;
	arestas = 0;
	
	while(aux != NULL) {
		arestas++;
		grafo->matriz_incidencia[(aux->vertice_origem)-1][arestas-1] = 1;
		grafo->matriz_incidencia[(aux->vertice_destino)-1][arestas-1] = 1;
		
		aux = aux->proximo;
	}
}

void construirListaAdjacencia(Grafo *grafo, int vertices, NoListaArestas *lista) {
	int i;
	
	grafo->lista_adjacencia = malloc(vertices * sizeof(NoListaAdjacencia*));
	
	for(i=0; i<vertices; i++) {
		grafo->lista_adjacencia[i] = NULL;
	}
	
	NoListaArestas *aux_aresta = lista;
	
	while(aux_aresta != NULL) {
		NoListaAdjacencia *novo_no = malloc(sizeof(NoListaAdjacencia));
		novo_no->vertice = aux_aresta->vertice_destino;
		novo_no->proximo = NULL;
		
		NoListaAdjacencia *aux_adj = grafo->lista_adjacencia[(aux_aresta->vertice_origem)-1];
		
		if(aux_adj == NULL) {
			grafo->lista_adjacencia[(aux_aresta->vertice_origem)-1] = novo_no;
		}
		else {
			while(aux_adj->proximo != NULL) {
				aux_adj = aux_adj->proximo;
			}
			
			aux_adj->proximo = novo_no;
		}
		
		NoListaAdjacencia *novo_no_destino = malloc(sizeof(NoListaAdjacencia));
        novo_no_destino->vertice = aux_aresta->vertice_origem;
        novo_no_destino->proximo = NULL;

        aux_adj = grafo->lista_adjacencia[(aux_aresta->vertice_destino) - 1];
        
        if (aux_adj == NULL) {
            grafo->lista_adjacencia[(aux_aresta->vertice_destino) - 1] = novo_no_destino;
        } else {
            while (aux_adj->proximo != NULL) {
                aux_adj = aux_adj->proximo;
            }
            aux_adj->proximo = novo_no_destino;
        }
		
		aux_aresta = aux_aresta->proximo;
	}
}

void somarGrafos(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma) {
	int contador_arestas = 0;
	
	if(grafo_soma->lista_arestas != NULL) {
		destruirGrafo(grafo_soma);
	}
	
	grafo_soma->vertices = grafo1->vertices + grafo2->vertices;

	NoListaArestas *aux = grafo1->lista_arestas;
	
	while(aux != NULL) {
		contador_arestas++;
		
		inserirNoAresta(&grafo_soma->lista_arestas, contador_arestas, aux->vertice_origem, aux->vertice_destino);
		
		aux = aux->proximo;
	}
	
	aux = grafo2->lista_arestas;
	
	while(aux != NULL) {
		contador_arestas++;
		
		inserirNoAresta(&grafo_soma->lista_arestas, contador_arestas, grafo1->vertices + aux->vertice_origem, grafo1->vertices + aux->vertice_destino);
		
		aux = aux->proximo;
	}
	
	int aresta_grafo1 = 1;
	int aresta_grafo2 = grafo_soma->vertices - grafo2->vertices + 1;
	
	int i, j;
	
	for(i=aresta_grafo1; i<=grafo1->vertices; i++) {
		for(j=aresta_grafo2; j<=grafo_soma->vertices; j++) {
			contador_arestas++;
			
			inserirNoAresta(&grafo_soma->lista_arestas, contador_arestas, i, j);
		}
	}
	
	construirMatrizAdjacencia(grafo_soma, grafo_soma->vertices, grafo_soma->lista_arestas);
	construirMatrizIncidencia(grafo_soma, grafo_soma->vertices, grafo_soma->lista_arestas);
	construirListaAdjacencia(grafo_soma, grafo_soma->vertices, grafo_soma->lista_arestas);
}

void unirGrafos(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_uniao) {
	int contador_arestas = 0;
	
	if(grafo_uniao->lista_arestas != NULL) {
		destruirGrafo(grafo_uniao);
	}
	
	grafo_uniao->vertices = grafo1->vertices + grafo2->vertices;
	
	NoListaArestas *aux = grafo1->lista_arestas;
	
	while(aux != NULL) {
		contador_arestas++;
		
		inserirNoAresta(&grafo_uniao->lista_arestas, contador_arestas, aux->vertice_origem, aux->vertice_destino);
		
		aux = aux->proximo;
	}
	
	aux = grafo2->lista_arestas;
	
	while(aux != NULL) {
		contador_arestas++;
		
		inserirNoAresta(&grafo_uniao->lista_arestas, contador_arestas, grafo1->vertices + aux->vertice_origem, grafo1->vertices + aux->vertice_destino);
		
		aux = aux->proximo;
	}
	
	construirMatrizAdjacencia(grafo_uniao, grafo_uniao->vertices, grafo_uniao->lista_arestas);
	construirMatrizIncidencia(grafo_uniao, grafo_uniao->vertices, grafo_uniao->lista_arestas);
	construirListaAdjacencia(grafo_uniao, grafo_uniao->vertices, grafo_uniao->lista_arestas);
}

void removerAresta(Grafo *grafo) {
	int aresta_remover, ch;
	
	imprimirListaArestas(grafo->lista_arestas);
	
	printf("\nInsira o número da aresta para remover: ");
	scanf("%i", &aresta_remover);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	NoListaArestas *aux = grafo->lista_arestas;
	int qtd_arestas = 0;
	
	while(aux != NULL) {
		qtd_arestas++;
		aux = aux->proximo;
	}
	
	if(aresta_remover <= qtd_arestas) {
		aux = grafo->lista_arestas;
		NoListaArestas *anterior = NULL;
		
		while(aux != NULL) {
			if(aux->num_aresta == aresta_remover) {
				if(anterior == NULL)
					grafo->lista_arestas = aux->proximo;
				else
					anterior->proximo = aux->proximo;
				
				free(aux);
				break;
			}
			
			anterior = aux;
			aux = aux->proximo;
		}
		
		aux = grafo->lista_arestas;
		
		while(aux != NULL) {
			if(aux->num_aresta > aresta_remover)
				aux->num_aresta--;
			
			aux = aux->proximo;
		}
		
		construirMatrizAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
		construirMatrizIncidencia(grafo, grafo->vertices, grafo->lista_arestas);
		construirListaAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
		
		printf("\nRemoção de aresta efetuada com sucesso!\n\n");
	}
	else {
		printf("\nA aresta inserida não existe no grafo em questão.\n");
	}
}

void removerVertice(Grafo *grafo) {
	int vertice_remover, ch;
	
	printf("\nInsira o vértice para remover: ");
	scanf("%i", &vertice_remover);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	if(vertice_remover <= grafo->vertices) {
		NoListaArestas *aux = grafo->lista_arestas;
		NoListaArestas *anterior = NULL;
		
		while(aux != NULL) {
			if(aux->vertice_destino == vertice_remover || aux->vertice_origem == vertice_remover) {
				if(anterior == NULL) {
					grafo->lista_arestas = aux->proximo;
					free(aux);
					aux = grafo->lista_arestas;
				}
				else {
					anterior->proximo = aux->proximo;
					free(aux);
					aux = anterior->proximo;
				}
			}
			else {
				anterior = aux;
				aux = aux->proximo;
			}
		}
		
		aux = grafo->lista_arestas;
		
        while(aux != NULL) {
            if(aux->vertice_origem > vertice_remover)
                aux->vertice_origem--;
                
            if(aux->vertice_destino > vertice_remover)
                aux->vertice_destino--;
                
            aux = aux->proximo;
        }
		
		(grafo->vertices)--;
		
		construirMatrizAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
		construirMatrizIncidencia(grafo, grafo->vertices, grafo->lista_arestas);
		construirListaAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
		
		printf("\nRemoção de vértice efetuada com sucesso!\n\n");
	}
	else {
		printf("\nO vértice inserido não existe no grafo em questão.\n");
		printf("\n---------------------------------------------\n\n");
	}
}

void contrairAresta(Grafo *grafo) {
	int aresta_contrair, ch;
	int maior, menor;
	
	printf("\nInsira a aresta para contrair: ");
	scanf("%i", &aresta_contrair);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	int arestas = 0;
	NoListaArestas *aux = grafo->lista_arestas;
	
	while(aux != NULL) {
		arestas++;
		aux = aux->proximo;
	}
	
	if(aresta_contrair <= arestas) {
		NoListaArestas *anterior = NULL;
		aux = grafo->lista_arestas;
		
		while(aux != NULL) {
			if(aux->num_aresta == aresta_contrair) {
				if(aux->vertice_destino > aux->vertice_origem) {
					maior = aux->vertice_destino;
					menor = aux->vertice_origem;
				}
				else {
					menor = aux->vertice_destino;
					maior = aux->vertice_origem;
				}
				
				if(anterior == NULL)
					grafo->lista_arestas = aux->proximo;
				else
					anterior->proximo = aux->proximo;
				
				free(aux);
				break;
			}
			
			anterior = aux;
			aux = aux->proximo;
		}
		
		aux = grafo->lista_arestas;
		
		while(aux != NULL) {
			if(aux->vertice_origem == maior)
                aux->vertice_origem = menor;
            else if(aux->vertice_origem > maior)
                aux->vertice_origem--;
                
            if(aux->vertice_destino == maior)
                aux->vertice_destino = menor;
            else if(aux->vertice_destino > maior)
                aux->vertice_destino--;
			
			if(aux->num_aresta > aresta_contrair)
				aux->num_aresta--;
			
			aux = aux->proximo;
		}
		
		grafo->vertices--;
		
		construirMatrizAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
		construirMatrizIncidencia(grafo, grafo->vertices, grafo->lista_arestas);
		construirListaAdjacencia(grafo, grafo->vertices, grafo->lista_arestas);
		
		printf("\nContração de aresta efetuada com sucesso!\n\n");
	}
	else {
		printf("\nA aresta inserida não existe no grafo em questão.\n");
		printf("\n---------------------------------------------\n\n");
	}
}

int* caminhoMinimo(Grafo *grafo, int *tamanho_caminho) {	
	int ch, i;
	int inicio, fim;
	Fila fila_vertices;
	
	criarFila(&fila_vertices);
	
	printf("\nIndique o vértice de início: ");
	scanf("%i", &inicio);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	printf("\nIndique o vértice de fim: ");
	scanf("%i", &fim);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	if((inicio > 0 && inicio <= grafo->vertices) && (fim > 0 && fim <= grafo->vertices)) {
		if(inicio == fim) {
            int *caminho = malloc(sizeof(int));
            caminho[0] = inicio;
            *tamanho_caminho = 1;
            return caminho;
        }
		
		enfileirar(&fila_vertices, inicio);
		
		int visitados[grafo->vertices];
		int vertices_anteriores[grafo->vertices];
		
		for(i=0; i<grafo->vertices; i++) {
			visitados[i] = 0;
			vertices_anteriores[i] = -1;
		}
		
		visitados[inicio-1] = 1;
		
		int vertice_removido, proximo, encontrou = 0;
		NoListaAdjacencia *vizinho;
		
		while(filaEstaVazia(&fila_vertices) == 0) {
			vertice_removido = desenfileirar(&fila_vertices);
			vizinho = grafo->lista_adjacencia[vertice_removido-1];
			
			while(vizinho != NULL) {
				proximo = vizinho->vertice;
				
				if(visitados[proximo-1] == 0) {
					enfileirar(&fila_vertices, proximo);
					visitados[proximo-1] = 1;
					vertices_anteriores[proximo-1] = vertice_removido;
					
					if(proximo == fim) {
						encontrou = 1;
						break;
					}
				}
				
				vizinho = vizinho->proximo;
			}
			
			if(encontrou == 1) {
		        break;
		    }
		}
		
		if(!encontrou) {
			printf("\n---------------------------------------------\n");
		    printf("\nNão existe caminho entre os vértices.\n\n");
		    *tamanho_caminho = 0;
		    return NULL;
		}
		
		int *caminho = malloc(grafo->vertices * sizeof(int));
		int tamanho = 0;
		
		for(i=fim; i!=-1; i=vertices_anteriores[i-1]) {
			if(i < 1 || i > grafo->vertices)
		        break;
		        
			caminho[tamanho] = i;
			tamanho++;
		}
		
		for(i=0; i<tamanho/2; i++) {
			int temp = caminho[i];
			caminho[i] = caminho[tamanho-i-1];
			caminho[tamanho-i-1] = temp;
		}
		
		*tamanho_caminho = tamanho;
		return caminho;
	}
	else {
		printf("\n---------------------------------------------\n");
		printf("\nValores dos vértices são inválidos.\n\n");
		*tamanho_caminho = 0;
		return NULL;
	}
}

void imprimirMatrizAdjacencia(Grafo *grafo) {
	int i, j;
	
	printf("     ");
    for(j=0; j<grafo->vertices; j++) {
        printf("v%02i ", j+1);
    }
    printf("\n");

    for(i=0; i<grafo->vertices; i++) {
        printf(" v%02i ", i+1);

        for(j=0; j<grafo->vertices; j++) {
            printf("%3i ", grafo->matriz_adjacencia[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatrizIncidencia(Grafo *grafo) {
	int i, j;
	int arestas = 0;
	
	NoListaArestas *aux = grafo->lista_arestas;
	
	while(aux != NULL) {
		arestas++;
		aux = aux->proximo;
	}
	
	printf("     ");
	for(j=0; j<arestas; j++) {
		printf("e%02i ", j+1);
	}
	printf("\n");
	
	for(i=0; i<grafo->vertices; i++) {
		printf(" v%02i ", i+1);
		
		for(j=0; j<arestas; j++) {
			printf("%3i ", grafo->matriz_incidencia[i][j]);
		}
		printf("\n");
	}
}

void imprimirListaAdjacencia(Grafo *grafo) {
	int i;
	
	for(i=0; i<grafo->vertices; i++) {
		printf("%i -> ", i+1);
		
		NoListaAdjacencia *aux = grafo->lista_adjacencia[i];
		
		while(aux != NULL) {
			printf("%i -> ", aux->vertice);
			aux = aux->proximo;
		}
		
		printf("NULL\n");
	}
}

void opcoesImpressaoMatrizAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	int opcao, ch;
	
	while(1) {
		printf("Qual grafo deseja imprimir a matriz de adjacência?\n");
		printf("[1] Grafo 01\n[2] Grafo 02\n[3] Grafo Soma\n[4] Grafo União\n[5] Todos\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				printf("\nMatriz de Adjacência do Grafo 01:\n\n");
				imprimirMatrizAdjacencia(grafo1);
				printf("\n---------------------------------------------\n");
				break;
			case 2:
				printf("\nMatriz de Adjacência do Grafo 02:\n\n");
				imprimirMatrizAdjacencia(grafo2);
				printf("\n---------------------------------------------\n");
				break;
			case 3:
				printf("\nMatriz de Adjacência do Grafo Soma:\n\n");
				if(grafo_soma->lista_arestas != NULL)	
					imprimirMatrizAdjacencia(grafo_soma);
				else
					printf("Gere o grafo soma antes de verificar suas representações.\n");
				printf("\n---------------------------------------------\n\n");
				break;
			case 4:
				printf("\nMatriz de Adjacência do Grafo União:\n\n");
				if(grafo_uniao->lista_arestas != NULL)
					imprimirMatrizAdjacencia(grafo_uniao);
				else
					printf("Gere o grafo união antes de verificar suas representações.\n");
				printf("\n---------------------------------------------\n\n");
				break;
			case 5:
				imprimirTodasMatrizesAdjacencia(grafo1, grafo2, grafo_soma, grafo_uniao);
				break;
			default:
				printf("\nOpção inválida\n\n");
				break;
		}
		
		if(opcao > 0 && opcao < 6)
			break;
	}
}

void imprimirTodasMatrizesAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	printf("\nMatriz de Adjacência do Grafo 01:\n\n");
	imprimirMatrizAdjacencia(grafo1);
	printf("\n---------------------------------------------\n");
	
	printf("\nMatriz de Adjacência do Grafo 02:\n\n");
	imprimirMatrizAdjacencia(grafo2);
	printf("\n---------------------------------------------\n");
	
	printf("\nMatriz de Adjacência do Grafo Soma:\n\n");
	if(grafo_soma->lista_arestas != NULL)			
		imprimirMatrizAdjacencia(grafo_soma);
	else
		printf("Gere o grafo soma antes de verificar suas representações.\n");
	printf("\n---------------------------------------------\n");
	
	printf("\nMatriz de Adjacência do Grafo União:\n\n");
	if(grafo_uniao->lista_arestas != NULL)				
		imprimirMatrizAdjacencia(grafo_uniao);
	else
		printf("Gere o grafo união antes de verificar suas representações.\n");
	printf("\n---------------------------------------------\n\n");
}

void opcoesImpressaoMatrizIncidencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	int opcao, ch;
	
	while(1) {
		printf("Qual grafo deseja imprimir a matriz de incidência?\n");
		printf("[1] Grafo 01\n[2] Grafo 02\n[3] Grafo Soma\n[4] Grafo União\n[5] Todos\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				printf("\nMatriz de Incidência do Grafo 01:\n\n");
				imprimirMatrizIncidencia(grafo1);
				printf("\n---------------------------------------------\n");
				break;
			case 2:
				printf("\nMatriz de Incidência do Grafo 02:\n\n");
				imprimirMatrizIncidencia(grafo2);
				printf("\n---------------------------------------------\n");
				break;
			case 3:
				printf("\nMatriz de Incidência do Grafo Soma:\n\n");
				if(grafo_soma->lista_arestas != NULL)	
					imprimirMatrizIncidencia(grafo_soma);
				else
					printf("Gere o grafo soma antes de verificar suas representações.\n");
				printf("\n---------------------------------------------\n\n");
				break;
			case 4:
				printf("\nMatriz de Incidência do Grafo União:\n\n");
				if(grafo_uniao->lista_arestas != NULL)
					imprimirMatrizIncidencia(grafo_uniao);
				else
					printf("Gere o grafo união antes de verificar suas representações.\n");
				printf("\n---------------------------------------------\n\n");
				break;
			case 5:
				imprimirTodasMatrizesIncidencia(grafo1, grafo2, grafo_soma, grafo_uniao);
				break;
			default:
				printf("\nOpção inválida\n\n");
				break;
		}
		
		if(opcao > 0 && opcao < 6)
			break;
	}
}

void imprimirTodasMatrizesIncidencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	printf("\nMatriz de Incidência do Grafo 01:\n\n");
	imprimirMatrizIncidencia(grafo1);
	printf("\n---------------------------------------------\n");
	
	printf("\nMatriz de Incidência do Grafo 02:\n\n");
	imprimirMatrizIncidencia(grafo2);
	printf("\n---------------------------------------------\n");
	
	printf("\nMatriz de Incidência do Grafo Soma:\n\n");
	if(grafo_soma->lista_arestas != NULL)	
		imprimirMatrizIncidencia(grafo_soma);
	else
		printf("Gere o grafo soma antes de verificar suas representações.\n");
	printf("\n---------------------------------------------\n");
	
	printf("\nMatriz de Incidência do Grafo União:\n\n");
	if(grafo_uniao->lista_arestas != NULL)
		imprimirMatrizIncidencia(grafo_uniao);
	else
		printf("Gere o grafo união antes de verificar suas representações.\n");
	printf("\n---------------------------------------------\n\n");
}

void opcoesImpressaoListaAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	int opcao, ch;
	
	while(1) {
		printf("Qual grafo deseja imprimir a lista de adjacência?\n");
		printf("[1] Grafo 01\n[2] Grafo 02\n[3] Grafo Soma\n[4] Grafo União\n[5] Todos\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				printf("\nLista de Adjacência do Grafo 01:\n\n");
				imprimirListaAdjacencia(grafo1);
				printf("\n---------------------------------------------\n");
				break;
			case 2:
				printf("\nLista de Adjacência do Grafo 02:\n\n");
				imprimirListaAdjacencia(grafo2);
				printf("\n---------------------------------------------\n");
				break;
			case 3:
				printf("\nLista de Adjacência do Grafo Soma:\n\n");
				if(grafo_soma->lista_arestas != NULL)	
					imprimirListaAdjacencia(grafo_soma);
				else
					printf("Gere o grafo soma antes de verificar suas representações.\n");
				printf("\n---------------------------------------------\n\n");
				break;
			case 4:
				printf("\nLista de Adjacência do Grafo União:\n\n");
				if(grafo_uniao->lista_arestas != NULL)
					imprimirListaAdjacencia(grafo_uniao);
				else
					printf("Gere o grafo união antes de verificar suas representações.\n");
				printf("\n---------------------------------------------\n\n");
				break;
			case 5:
				imprimirTodasListasAdjacencia(grafo1, grafo2, grafo_soma, grafo_uniao);
				break;
			default:
				printf("\nOpção inválida\n\n");
				break;
		}
		
		if(opcao > 0 && opcao < 6)
			break;
	}
}

void imprimirTodasListasAdjacencia(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	printf("\nLista de Adjacência do Grafo 01:\n\n");
	imprimirListaAdjacencia(grafo1);
	printf("\n---------------------------------------------\n");
	
	printf("\nLista de Adjacência do Grafo 02:\n\n");
	imprimirListaAdjacencia(grafo2);
	printf("\n---------------------------------------------\n");
	
	printf("\nLista de Adjacência do Grafo Soma:\n\n");
	if(grafo_soma->lista_arestas != NULL)			
		imprimirListaAdjacencia(grafo_soma);
	else
		printf("Gere o grafo soma antes de verificar suas representações.\n");
	printf("\n---------------------------------------------\n");
	
	printf("\nLista de Adjacência do Grafo União:\n\n");
	if(grafo_uniao->lista_arestas != NULL)				
		imprimirListaAdjacencia(grafo_uniao);
	else
		printf("Gere o grafo união antes de verificar suas representações.\n");
	printf("\n---------------------------------------------\n\n");
}

void destruirGrafo(Grafo *grafo) {
	int vertices = grafo->vertices;
	NoListaAdjacencia *aux, *proximo;
	
	int i, j;
	
	for(i=0; i<vertices; i++) {
		free(grafo->matriz_adjacencia[i]);
	}
	free(grafo->matriz_adjacencia);
	
	for(i=0; i<vertices; i++) {
		free(grafo->matriz_incidencia[i]);
	}
	free(grafo->matriz_incidencia);
	
	for(i=0; i<vertices; i++) {
		aux = grafo->lista_adjacencia[i];
		
		while(aux != NULL) {
			proximo = aux->proximo;
			free(aux);
			aux = proximo;
		}
	}
	free(grafo->lista_adjacencia);
	
	destruirLista(&grafo->lista_arestas);
	grafo->vertices = 0;
}

void opcoesRemoverAresta(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	int opcao, ch;
	
	while(1) {
		printf("De qual grafo você deseja remover uma aresta?\n");
		printf("[1] Grafo 01\n[2] Grafo 02\n[3] Grafo Soma\n[4] Grafo União\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				removerAresta(grafo1);
				break;
			case 2:
				removerAresta(grafo2);
				break;
			case 3:
				if(grafo_soma->lista_arestas != NULL)
					removerAresta(grafo_soma);
				else
					printf("\nGere o grafo soma antes de remover um vértice.\n");
				break;
			case 4:
				if(grafo_uniao->lista_arestas != NULL)
					removerAresta(grafo_uniao);
				else
					printf("\nGere o grafo união antes de remover um vértice.\n");
				break;
			default:
				printf("\nOpção inválida.\n\n");
				break;
		}
		
		if(opcao > 0 && opcao < 5)
			break;
	}
	
	printf("\n---------------------------------------------\n\n");
}

void opcoesRemoverVertice(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	int opcao, ch;
	
	while(1) {
		printf("De qual grafo você deseja remover um vértice?\n");
		printf("[1] Grafo 01\n[2] Grafo 02\n[3] Grafo Soma\n[4] Grafo União\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				removerVertice(grafo1);
				break;
			case 2:
				removerVertice(grafo2);
				break;
			case 3:
				if(grafo_soma->lista_arestas != NULL)
					removerVertice(grafo_soma);
				else
					printf("\nGere o grafo soma antes de remover um vértice.\n");
				break;
			case 4:
				if(grafo_uniao->lista_arestas != NULL)
					removerVertice(grafo_uniao);
				else
					printf("\nGere o grafo união antes de remover um vértice.\n");
				break;
			default:
				printf("\nOpção inválida.\n\n");
				break;
		}
		
		if(opcao > 0 && opcao < 5)
			break;
	}
	
	printf("\n---------------------------------------------\n\n");
}

void opcoesContrairAresta(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao) {
	int opcao, ch;
	
	while(1) {
		printf("De qual grafo você deseja contrair uma aresta?\n");
		printf("[1] Grafo 01\n[2] Grafo 02\n[3] Grafo Soma\n[4] Grafo União\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				contrairAresta(grafo1);
				break;
			case 2:
				contrairAresta(grafo2);
				break;
			case 3:
				if(grafo_soma->lista_arestas != NULL)
					contrairAresta(grafo_soma);
				else
					printf("\nGere o grafo soma antes de contrair uma aresta.\n");
				break;
			case 4:
				if(grafo_uniao->lista_arestas != NULL)
					contrairAresta(grafo_uniao);
				else
					printf("\nGere o grafo união antes de contrair uma aresta.\n");
				break;
			default:
				printf("\nOpção inválida.\n\n");
				break;
		}
		
		if(opcao > 0 && opcao < 5)
			break;
	}
	
	printf("\n---------------------------------------------\n\n");
}

int* opcoesCaminhoMinimo(Grafo *grafo1, Grafo *grafo2, Grafo *grafo_soma, Grafo *grafo_uniao, int *tamanho_caminho) {
	int opcao, ch;
	int *caminho;
	
	while(1) {
		printf("De qual grafo você deseja encontrar o caminho mínimo?\n");
		printf("[1] Grafo 01\n[2] Grafo 02\n[3] Grafo Soma\n[4] Grafo União\nR: ");
		scanf("%i", &opcao);
		while ((ch = getchar()) != '\n' && ch != EOF);
		
		switch(opcao) {
			case 1:
				caminho = caminhoMinimo(grafo1, tamanho_caminho);
				break;
			case 2:
				caminho = caminhoMinimo(grafo2, tamanho_caminho);
				break;
			case 3:
				if(grafo_soma->lista_arestas != NULL)
					caminho = caminhoMinimo(grafo_soma, tamanho_caminho);
				else
					printf("\nGere o grafo soma antes de encontrar o caminho mínimo.\n");
				break;
			case 4:
				if(grafo_uniao->lista_arestas != NULL)
					caminho = caminhoMinimo(grafo1, tamanho_caminho);
				else
					printf("\nGere o grafo união antes de encontrar o caminho mínimo.\n");
				break;
			default:
				printf("\nOpção inválida.\n\n");
				break;
		}
		
		if(opcao > 0 && opcao < 5)
			break;
	}
	
	return caminho;
}

void criarFila(Fila *fila) {
	fila->inicio = NULL;
	fila->fim = NULL;
}

void enfileirar(Fila *fila, int vertice) {
	NoFila *novo_vertice = malloc(sizeof(NoFila));
	
	novo_vertice->vertice = vertice;
	novo_vertice->proximo = NULL;
	
	if(fila->fim == NULL) {
		fila->inicio = novo_vertice;
		fila->fim = novo_vertice;
	}
	else {
		fila->fim->proximo = novo_vertice;
		fila->fim = novo_vertice;
	}
}

int desenfileirar(Fila *fila) {
	if(fila->inicio == NULL)
		return -1;
	
	NoFila *aux = fila->inicio;
	int vertice = aux->vertice;
	
	fila->inicio = fila->inicio->proximo;
	
	if(fila->inicio == NULL)
		fila->fim = NULL;
	
	free(aux);
	return vertice;
}

int filaEstaVazia(Fila *fila) {
	return (fila->inicio == NULL);
}
