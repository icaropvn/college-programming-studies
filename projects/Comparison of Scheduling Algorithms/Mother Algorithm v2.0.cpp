#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

struct Processo {
	int id;
	int tempo_execucao;
};

void FirstComeFirstServed(Processo processos[], int max);
void ShortestJobFirst(Processo processos[], int max);
void RoundRobin(Processo processos[], int max);
int escolhaProcessos();
void gerarProcessos(Processo *processos1, Processo *processos2, Processo *processos3, int tipoProcessos, int quantidadeProcessos);
void executarTestes(int quantidadeProcessos, Processo *processos1, Processo *processos2, Processo *processos3);

int main()
{	
	srand(time(NULL));
	
	int quantidadeProcessos, tipoProcessos = 0;
	
	tipoProcessos = escolhaProcessos();
	
	cout << "\nInsira a quantidade de processos a serem executados: ";
	cin >> quantidadeProcessos;
	cout << endl;
	
	Processo processos1[quantidadeProcessos], processos2[quantidadeProcessos], processos3[quantidadeProcessos];
	
	gerarProcessos(processos1, processos2, processos3, tipoProcessos, quantidadeProcessos);
	
	executarTestes(quantidadeProcessos, processos1, processos2, processos3);
	
	return 0;
}

void FirstComeFirstServed(Processo processos[], int max)
{
	int tempo_total = 0, tempo_por_processo = 0;
	int contador = 0;
	
	// loop que simula a execução dos processos em geral
	while(contador < max)
	{
		tempo_por_processo = 0;
		
		cout << "Executando processo " << processos[contador].id << "..." << endl;
		
		// loop interno que simula a execução de cada processo individualmente
		for(int i = processos[contador].tempo_execucao; i > 0; i--)
		{
			processos[contador].tempo_execucao--;
			tempo_por_processo++;
			tempo_total++;
		}
		
		// condição usada quando um processo é terminado
		if(processos[contador].tempo_execucao == 0)
			cout << "Processo " << processos[contador].id << " executado por " << tempo_por_processo << " unidades de tempo\n" << endl;
		
		contador++;
	}
	
	cout << "Tempo de execução total: " << tempo_total << " unidades de tempo." << endl;
}

void ShortestJobFirst(Processo processos[], int max)
{
	Processo temp;
	int i, j;
	
	int tempo_total = 0, tempo_por_processo = 0;
	int contador = 0;
	
	// implementa  o do algoritmo insertion sort para ordenar os processos
	for(i=1; i<max; i++)
	{
		temp = processos[i];
		
		for(j=i-1; j>=0 && processos[j].tempo_execucao > temp.tempo_execucao; j--)
		{
			processos[j+1].id = processos[j].id;
			processos[j+1].tempo_execucao = processos[j].tempo_execucao;
		}
		
		processos[j+1].id = temp.id;
		processos[j+1].tempo_execucao = temp.tempo_execucao;
	}
	
	// loop que simula a execu  o dos processos em geral
	while(contador < max)
	{
		tempo_por_processo = 0;
		
		cout << "Executando processo " << processos[contador].id << "..." << endl;
		
		// loop interno que simula a execu  o de cada processo individualmente
		for(int i = processos[contador].tempo_execucao; i > 0; i--)
		{
			processos[contador].tempo_execucao--;
			tempo_por_processo++;
			tempo_total++;
		}
		
		// condi  o usada quando um processo   terminado
		if(processos[contador].tempo_execucao == 0)
			cout << "Processo " << processos[contador].id << " executado por " << tempo_por_processo << " unidades de tempo\n" << endl;
		
		contador++;
	}
	
	cout << "Tempo de execucao total: " << tempo_total << " unidades de tempo." << endl;
}

void RoundRobin(Processo processos[], int max)
{
    int contadorDeCiclo = 1, quantum = 10, contador = 0, tempo_total = 0;

    while(contador <= max+1)
    {
        cout << "Ciclo " << contadorDeCiclo << " ---------------------------------" << endl;
        
        for (int i = 0; i < max; i++)
        {
            if(processos[i].tempo_execucao > 0)
            {
                cout << "Executando processo " << processos[i].id << "..." << endl;
                cout << "Tempo Restante: " << processos[i].tempo_execucao << " quantum\n\n";
            }
            else
            {
            	cout << "Processo " << processos[i].id << " executado\n\n";
                processos[i].tempo_execucao = 0;
                contador++;
            }
            
            processos[i].tempo_execucao -= quantum;
            tempo_total += quantum;
        }
        
        contadorDeCiclo++;
    }
    
    cout << "Tempo de execucao total: " << tempo_total << " unidades de tempo." << endl;
}

int escolhaProcessos()
{
	int tipoProcessos = 0;
	
	while(tipoProcessos < 1 || tipoProcessos > 3)
	{
		cout << "Qual teste deseja fazer?" << endl;
		cout << "[1] Processos Curtos\n[2] Processos Medios\n[3] Processos Longos\nR: ";
		cin >> tipoProcessos;
	}
	
	return tipoProcessos;
}

void gerarProcessos(Processo *processos1, Processo *processos2, Processo *processos3, int tipoProcessos, int quantidadeProcessos)
{
	int min_rand, max_rand;
	
	switch(tipoProcessos)
	{
		case 1: {
			min_rand = 1;
			max_rand = 20;
			break;
		}
		case 2: {
			min_rand = 40;
			max_rand = 70;
			break;
		}
		case 3: {
			min_rand = 80;
			max_rand = 120;
			break;
		}
	}
	
	for(int i=0; i<quantidadeProcessos; i++)
	{
		processos1[i].id = i+1;
		processos2[i].id = i+1;
		processos3[i].id = i+1;
		
		processos1[i].tempo_execucao = min_rand + (rand() % (max_rand - min_rand + 1));
		processos2[i].tempo_execucao = processos1[i].tempo_execucao;
		processos3[i].tempo_execucao = processos1[i].tempo_execucao;
	}
}

void executarTestes(int quantidadeProcessos, Processo *processos1, Processo *processos2, Processo *processos3)
{
    cout << "------------------------------------------------------" << endl;
    cout << "\nExecutando FIRST COME FIRST SERVED...\n" << endl;
    
	auto inicio = chrono::high_resolution_clock::now();
	
	FirstComeFirstServed(processos1, quantidadeProcessos);
    
    auto fim = chrono::high_resolution_clock::now();
    auto fcfs = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    
    cout << "Tempo de duracao do First Come First Served: " << fcfs.count() << " microssegundos\n" << endl;
    
    cout << "------------------------------------------------------" << endl;
    cout << "\nExecutando SHORTEST JOB FIRST...\n" << endl;
    
    inicio = chrono::high_resolution_clock::now();
    
	ShortestJobFirst(processos2, quantidadeProcessos);

    fim = chrono::high_resolution_clock::now();
    auto sjf = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    
    cout << "Tempo de duracao do Shortest Job First: " << sjf.count() << " microssegundos\n" << endl;
    
    cout << "------------------------------------------------------" << endl;
    cout << "\nExecutando ROUND ROBIN...\n" << endl;
    
    inicio = chrono::high_resolution_clock::now();
    
	RoundRobin(processos3, quantidadeProcessos);
	
	fim = chrono::high_resolution_clock::now();
    auto rr = chrono::duration_cast<chrono::microseconds>(fim - inicio);
	
	cout << "Tempo de duracao do Round-Robin: " << rr.count() << " microssegundos\n" << endl;
	
	cout << "------------------------------------------------------" << endl;
	cout << "Resultados:\n" << endl;
	cout << "First Come First Served: " << fcfs.count() << " microssegundos" << endl;
	cout << "Shortest Job First: " << sjf.count() << " microssegundos" << endl;
	cout << "Round Robin: " << rr.count() << " microssegundos" << endl;
}
