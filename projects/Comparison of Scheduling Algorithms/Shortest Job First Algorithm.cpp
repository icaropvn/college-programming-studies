#include <iostream>
using namespace std;

const int MAX_PROCESSOS = 5;

struct Processo {
	int id;
	int tempo_execucao;
	bool executado;
};

void ShortestJobFirst(Processo processos[], int max);

int main()
{
	Processo processos[MAX_PROCESSOS] = {{1, 8, false}, {2, 4, false}, {3, 2, false}, {4, 5, false}, {5, 2, false}};
	
	ShortestJobFirst(processos, MAX_PROCESSOS);
	
	return 0;
}

void ShortestJobFirst(Processo processos[], int max)
{
	int tempo_total = 0, tempo_por_processo = 0;
	int contador = 0, id_menor_tempo = 0;
	int menor_tempo_execucao = processos[0].tempo_execucao;
	
	while(contador < max)
	{
		tempo_por_processo = 0;
		
		for(int i=0; i<max; i++)
		{
			if(processos[i].tempo_execucao < menor_tempo_execucao && processos[i].executado == false)
			{
				menor_tempo_execucao = processos[i].tempo_execucao;
				id_menor_tempo = i;
			}
		}
		
		cout << "Executando processo " << id_menor_tempo + 1 << endl;
		
		for(int i = processos[id_menor_tempo].tempo_execucao; i > 0; i--)
		{
			processos[id_menor_tempo].tempo_execucao--;
			tempo_por_processo++;
			tempo_total++;
		}
		
		if(processos[id_menor_tempo].tempo_execucao == 0)
			cout << "Processo " << id_menor_tempo + 1 << " executado por " << tempo_por_processo << " unidades de tempo\n" << endl;
		
		processos[id_menor_tempo].executado = true;
		
		for(int i=0; i<max; i++)
		{
			if(processos[i].executado == false)
			{
				menor_tempo_execucao = processos[i].tempo_execucao;
				id_menor_tempo = i;
			}
		}
		
		contador++;
	}
	
	cout << "Tempo de execução total: " << tempo_total << " unidades de tempo." << endl;
}
