// Parte 0: Inclus�o de bibliotecas

#include <iostream> // input e output
#include <cstdlib>
#include <ctime> // tempo

using namespace std;

// Parte 1: Cria��o de fun��es -------------------------------------------------------

// Iniciar o gerador de n�mero aleat�rio
void initGerador() {
    srand(static_cast<unsigned int>(time(NULL))); //Inicalizado o gerador
}

// Gerador de n�mero aleat�rio
int geradorAleatorio(int min, int max) {
    int valorAle = min + (rand() % (max - min + 1));
    return valorAle;
}

// Cria��o da struct
typedef struct {
    int id, timeExec, timeArrival, timeRemain;
} Process;

// Gerador de processos (tempo aleat�rio dentro dos limites)
Process* geradorProcessos(int numProcess, int tempMin = 0, int tempMax = 0) {
    Process* nowProcess = new Process[numProcess];

    for(int i = 0; i < numProcess; i++){
        nowProcess[i].id = i + 1;
        nowProcess[i].timeExec = geradorAleatorio(tempMin, tempMax);
        nowProcess[i].timeRemain = nowProcess[i].timeExec;
    }

    return nowProcess;
}

// Ordenador de processos

void ordena() {

}

// Round Robin
int roundRobin(Process* processos, int n, int quantum) {

    cout << "Gerenciador Round Robin Ativo\n\n" << endl;

    bool done = true; // Inicializar done como true no in�cio de cada itera��o do loop
    int contadorDeCiclo = 0;

    do {

        done = true;

        cout << "Ciclo " << contadorDeCiclo << " ---------------------------------" << endl;
        
            for (int i = 0; i < n; i++) {

                if (processos[i].timeRemain > 0) {
                    done = false;
                    processos[i].timeRemain -= quantum;
                    cout << "Processo " << i << ":\n";
                    cout << "Tempo Restante: " << processos[i].timeRemain << " quantum\n\n";
                }
            }

        contadorDeCiclo++;

    } while (!done);

    return 0;
}


// Parte 2: main -------------------------------------------------------

int main() {
    initGerador();
    
    int numeroProcessos, tempoMinimo = 0, tempoMaximo = 0, quantum = 0;

    cout << "Quantos processos ser�o feitos?" << endl;
    cin >> numeroProcessos;

    cout << "Quantos quantum cada processo deve utilizar (por ciclo)?" << endl;
    cin >> quantum;

    cout << "Qual o tempo m�ximo de cada processo?" << endl;
    cin >> tempoMaximo;

    Process* vetorProcessos = geradorProcessos(numeroProcessos, tempoMinimo, tempoMaximo);

    roundRobin(vetorProcessos, numeroProcessos, quantum);

/*
    for(int i = 0; i < numProcess; i ++){
        cout << "Processo " << workProcess[i].id << ":" << endl;
        cout << "Tempo de Execuss�o: " << workProcess[i].timeExec << " quantum" << endl;
        cout << endl;
    }
*/
    delete[] vetorProcessos;

	return 0;
}
