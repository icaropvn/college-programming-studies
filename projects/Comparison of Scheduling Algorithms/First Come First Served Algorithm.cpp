#include <iostream>
using namespace std;

const int MAX_PROCESSOS = 5;

struct Processo {
	int id, tempo_execucao;
};

void FirstComeFirstServed(Processo processos[], int max);

int main()
{
	Processo processos[MAX_PROCESSOS] = {{1, 8}, {2, 4}, {3, 2}, {4, 5}, {5, 2}};
	
	FirstComeFirstServed(processos, MAX_PROCESSOS);
	
	return 0;
}

void FirstComeFirstServed(Processo processos[], int max)
{
	int tempo_total = 0, tempo_por_processo = 0;
	int contador = 0;
	
	while(contador < max)
	{
		tempo_por_processo = 0;
		
		cout << "Executando processo " << processos[contador].id << endl;
		
		for(int i = processos[contador].tempo_execucao; i > 0; i--)
		{
			processos[contador].tempo_execucao--;
			tempo_por_processo++;
			tempo_total++;
		}
		
		if(processos[contador].tempo_execucao == 0)
			cout << "Processo " << processos[contador].id << " executado por " << tempo_por_processo << " unidades de tempo\n" << endl;
		
		contador++;
	}
	
	cout << "Tempo de execução total: " << tempo_total << " unidades de tempo." << endl;
}

