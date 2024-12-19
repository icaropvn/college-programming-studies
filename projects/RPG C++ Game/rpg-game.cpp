/*

Grupo do Trabalho:

- �caro Pavan (840790)
- Jeferson Tomaz (769349)
- J�ssica Maganha (769296)
- Samuel Figueiredo (840785)
- Samuel Lima (769214)
- V�tor Pinheiro (840751)

*/

#include <iostream>
#include <string>
#include <initializer_list>
#include <sstream>
#include <random>
#include <thread>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <cstdlib>
#endif

using namespace std;

// estrutura das habilidades dos inimigos
typedef struct {
    string nomeHabilidade;
    int danoHabilidade;
} HabilidadeInimigo;

typedef struct {
    string nomeContraAtaque, descricaoContraAtaque;
    int danoContraAtaque;
} ContraAtaquesInimigo;

// estrutura que define as vari�veis relacionadas aos inimigos
typedef struct {
    string nome;
    int vida, defesa;
    HabilidadeInimigo habilidades[3];
    ContraAtaquesInimigo contraAtaques[2];
} Inimigo;

// estrutura dos n�s da FILA DE COMBATE
typedef struct noFilaCombate {
    string nome;
    struct noFilaCombate *proximo;
} noFilaCombate;

// estrutura principal da FILA DE COMBATE
typedef struct {
    noFilaCombate *frente;
    noFilaCombate *tras;
    int tam;
} FilaCombate;

// estrutura geral dos itens do invent�rio
typedef struct {
    string nome, descricao;
    int codigo, quantidade;
    bool utilizavel;
} Item;

// estrutura dos n�s da LISTA ENCADEADA DO INVENT�RIO
typedef struct noInventario {
    Item item;
    noInventario *proximo;
} noInventario;

// estrutura geral da LISTA ENCADEADA DO INVENT�RIO
typedef struct {
    noInventario *primeiro;
} ListaInventario;

typedef struct {
    int codigoHabilidade;
    string nome;
    string efeito;
    bool possui;
} Habilidade;

typedef struct NoHabilidade {
    Habilidade habilidade;
    NoHabilidade *esquerda;
    NoHabilidade *direita;
} NoHabilidade;

typedef struct {
    NoHabilidade* raiz;
} ArvoreHabilidades;

typedef struct noPilha {
    int vidaPersonagem, vidaInimigo;
    vector<Item> itensInventario;
    noPilha *proximo;
} noPilha;

typedef struct {
    noPilha *topo;
} PilhaRebobinar;

// Estrutura para armazenar as criaturas
typedef struct {
    string nome;
    string descricao;
    string natureza;
} Criatura;

// Estrutura do n� da lista encadeada (bucket)
typedef struct noCriatura {
    Criatura criatura;
    noCriatura* proximo;
} noCriatura;

// Estrutura da tabela hash
typedef struct {
    vector<noCriatura*> buckets;
    int tamanho;
} TabelaHash;

// estrutura que define as vari�veis relacionadas ao personagem do jogador
typedef struct {
    string nome, pronome;
    string arquetipo;
    int vida, ataque, defesa;
    int exp, nivel;
    
    ListaInventario *inventario = new ListaInventario;
    ArvoreHabilidades *arvore = new ArvoreHabilidades;
    TabelaHash *album = new TabelaHash;
} Personagem;

// fun��o que espera uma tecla qualquer do teclado para continuar a execu��o
void esperarTeclaParaContinuar()
{
    #ifdef _WIN32
        cout << "Pressione a tecla enter para continuar...\n";
        _getch();
    #else
        cout << "Pressione a tecla enter para continuar...\n";
        system("read -r -p \"\" key");
    #endif
}

void criarFilaCombate(FilaCombate *filaCombate)
{
    filaCombate->frente = nullptr;
	filaCombate->tras = nullptr;
	filaCombate->tam = 0;
}

void enfileirarCriaturasCombate(FilaCombate *filaCombate, string criatura)
{
    noFilaCombate *novo_no = new noFilaCombate;
    
    if(novo_no)
	{
		novo_no->nome = criatura;
		novo_no->proximo = nullptr;
		
		if(filaCombate->frente == nullptr)
			filaCombate->frente = novo_no;
		else
			filaCombate->tras->proximo = novo_no;

        filaCombate->tras = novo_no;
		
		filaCombate->tam++;
	}
	else
		cout << "\n\nAlgo deu errado ao enfileirar as criaturas para o combate\n\n";
}

void destruirFilaCombate(FilaCombate *filaCombate)
{   
    noFilaCombate *atual = filaCombate->frente, *proximoNo;

    while(atual)
    {
        proximoNo = atual->proximo;
        delete atual;
        atual = proximoNo;
    }

    delete filaCombate;
}

// fun��o que inicializa a LISTA ENCADEADA DO INVENT�RIO
void criarListaInventario(ListaInventario *inventario)
{
    inventario->primeiro = nullptr;
}

// fun��o para adicionar novos itens � LISTA ENCADEADA DO INVENT�RIO
void adicionarItemInventario(ListaInventario *inventario, Item item)
{
    noInventario *novoNo = new noInventario;
    novoNo->item = item;
    novoNo->proximo = nullptr;

    if(inventario->primeiro == nullptr)
        inventario->primeiro = novoNo;
    else
    {
        noInventario *atual = inventario->primeiro;

        while(atual->proximo)
            atual = atual->proximo;
        
        atual->proximo = novoNo;
    }
}

int escolherItem(ListaInventario *inventario)
{
    noInventario *atual = inventario->primeiro;
    int codigo;

    cout << "> Escolha um item pelo c�digo: ";
    cin >> codigo;

    while(atual)
    {
        if(atual->item.codigo == codigo)
            return codigo;

        atual = atual->proximo;
    }

    cout << "Item n�o encontrado." << endl;
    return -1;
}

void usarItem(Personagem& personagem, int codigo)
{
    noInventario *atual = personagem.inventario->primeiro;
    noInventario *anterior = nullptr;
    string nomeItem;

    while(atual)
    {
        if(atual->item.codigo == codigo)
        {
            nomeItem = atual->item.nome;
            break;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    if(nomeItem == "Frasco de Cicatriza��o")
    {
        cout << "Voc� bebeu uma po��o avermelhada que te fez se sentir melhor." << endl;
        cout << "Curado 5 pontos de vida." << endl;
        personagem.vida += 5;
    }
    else if(nomeItem == "Pote de Cinzas Espirituais")
    {
        cout << "Voc� se sente protegido por algo sobrenatural." << endl;
        cout << "Sua defesa aumentou em 1 ponto." << endl;
        personagem.defesa += 1;
    }

    atual->item.quantidade -= 1;

    if(atual->item.quantidade == 0) {
        if(anterior == nullptr)
            personagem.inventario->primeiro = atual->proximo;
        else
            anterior->proximo = atual->proximo;

        delete atual;
    }

    esperarTeclaParaContinuar();
}

void examinarItensInventario(Personagem& personagem, int codigo)
{
    noInventario *atual = personagem.inventario->primeiro;
    Item item;

    while(atual)
    {
        if(atual->item.codigo == codigo)
        {
            item = atual->item;
            break;
        }

        atual = atual->proximo;
    }

    cout << item.descricao << endl << endl;

    esperarTeclaParaContinuar();
}

void descartarItem(Personagem& personagem, int codigo)
{
    noInventario *atual = personagem.inventario->primeiro;
    noInventario *anterior = nullptr;

    while(atual && atual->item.codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "Item n�o encontrado no invent�rio." << endl;
        return;
    }

    if (anterior == nullptr)
        personagem.inventario->primeiro = atual->proximo;
    else
        anterior->proximo = atual->proximo;

    delete atual;
    cout << "Item descartado com sucesso." << endl << endl;

    esperarTeclaParaContinuar();
}

int manipularInventario(Personagem& personagem)
{
    int escolhaInventario;
    int codigoItem;

    while(true)
    {
        cout << "O que deseja fazer?" << endl;
        cout << "[1] Usar Itens" << endl;
        cout << "[2] Examinar Itens" << endl;
        cout << "[3] Descartar" << endl;
        cout << "[4] Continuar Jornada" << endl;

        cin >> escolhaInventario;

        if(escolhaInventario < 1 || escolhaInventario > 4)
            cout << "Escolha inv�lida." << endl;
        else
            break;
    }

    switch(escolhaInventario)
    {
        case 1:
            codigoItem = escolherItem(personagem.inventario);
            if(codigoItem != -1)
            {
                usarItem(personagem, codigoItem);
            }
            break;
        case 2:
            codigoItem = escolherItem(personagem.inventario);
            if (codigoItem != -1)
            {
                examinarItensInventario(personagem, codigoItem);
            }
            break;
        case 3:
            codigoItem = escolherItem(personagem.inventario);
            if (codigoItem != -1)
            {
                descartarItem(personagem, codigoItem);
            }
            break;
    }

    return escolhaInventario;
}

// fun��o para mostrar a LISTA ENCADEADA DO INVENT�RIO
int mostrarInventario(Personagem& personagem)
{
    noInventario *atual = personagem.inventario->primeiro;

    if(atual == nullptr)
        cout << "Seu invent�rio est� vazio!" << endl;
    else
    {
        while(atual)
        {
            cout << atual->item.codigo << " | " << atual->item.quantidade << " " << atual->item.nome << endl;

            atual = atual->proximo;
        }
    }

    cout << endl;

    return manipularInventario(personagem);
}

void especificarItem(Item& item, int codigo, string nome, int quantidade, bool utilizavel, string descricao)
{
    item.codigo = codigo;
    item.nome = nome;
    item.quantidade = quantidade;
    item.utilizavel = utilizavel;
    item.descricao = descricao;
}

void criarArvore(ArvoreHabilidades *arvore)
{
    arvore->raiz = nullptr;
}

NoHabilidade* criarNoArvore(int codigo, string nome, string efeito, bool possui)
{
    NoHabilidade* novoNo = new NoHabilidade;

    novoNo->habilidade.codigoHabilidade = codigo;
    novoNo->habilidade.nome = nome;
    novoNo->habilidade.efeito = efeito;
    novoNo->habilidade.possui = possui;

    novoNo->esquerda = nullptr;
    novoNo->direita = nullptr;
    return novoNo;
}

NoHabilidade* inserirNoArvore(NoHabilidade *raiz, int codigo, string nome, string efeito, bool possui)
{
    if (raiz == nullptr) {
        return criarNoArvore(codigo, nome, efeito, possui);
    }

    if (nome < raiz->habilidade.nome) {
        raiz->esquerda = inserirNoArvore(raiz->esquerda, codigo, nome, efeito, possui);
    } else if (nome > raiz->habilidade.nome) {
        raiz->direita = inserirNoArvore(raiz->direita, codigo, nome, efeito, possui);
    }

    return raiz;
}

void inserirArvore(ArvoreHabilidades *arvore, int codigo, string nome, string efeito, bool possui)
{
    arvore->raiz = inserirNoArvore(arvore->raiz, codigo, nome, efeito, possui);
}

// Fun��o para percorrer e imprimir a �rvore em ordem
void imprimirEmOrdem(NoHabilidade *raiz)
{
    if(raiz)
    {
        imprimirEmOrdem(raiz->esquerda);

        if(raiz->habilidade.possui)
            cout << "| " << raiz->habilidade.nome << "\n     " << raiz->habilidade.efeito << endl << endl;

        imprimirEmOrdem(raiz->direita);
    }
}

void imprimirArvore(ArvoreHabilidades *arvore)
{
    imprimirEmOrdem(arvore->raiz);
}

void iniciarArvoreHabilidades(ArvoreHabilidades *arvore)
{
    inserirArvore(arvore, 2, "Rebobinar", "Retrocede um turno do combate.", false);
    inserirArvore(arvore, 3, "Pacto", "Diminui a vida do inimigo pela metade, mas voc� d� -3 de dano nesse combate.", false);
    inserirArvore(arvore, 4, "Hiperatividade", "Aumenta sua velocidade de ataque. Voc� pode atacar 2 seguidas durante os pr�ximos 3 turnos.", false);
    inserirArvore(arvore, 5, "Reflexo", "O pr�ximo ataque do inimigo afeta ele mesmo.", false);
    inserirArvore(arvore, 5, "Guarda Divina", "Dobra o valor da sua defesa durante 2 turnos.", false);
    inserirArvore(arvore, 6, "Prolifera��o", "Seu pr�ximo ataque afeta todos os inimigos do combate.", false);
    inserirArvore(arvore, 6, "O Mau da Decad�ncia", "Diminui a vida e ataque de todos os inimigos do combate em 25%.", false);
}

bool aprimorarHabilidade(NoHabilidade *raiz, int codigo)
{
    if (codigo < raiz->habilidade.codigoHabilidade)
        return aprimorarHabilidade(raiz->esquerda, codigo);
    else if (codigo > raiz->habilidade.codigoHabilidade)
        return aprimorarHabilidade(raiz->direita, codigo);
    else
    {
        if (!raiz->habilidade.possui)
        {
            raiz->habilidade.possui = true;
            cout << endl;
            cout << "> Voc� adquiriu a habilidade " << raiz->habilidade.nome << "!" << endl;
            cout << endl;
        }

        return true;
    }
}

bool chamarAprimorarHabilidade(ArvoreHabilidades *arvore, int codigoHabilidade)
{
    return aprimorarHabilidade(arvore->raiz, codigoHabilidade);
}

void criarPilha(PilhaRebobinar *pilha)
{
    pilha->topo = nullptr;
}

void empilhar(PilhaRebobinar *pilha, int vidaPersonagem, int vidaInimigo, vector<Item>& inventario)
{
    noPilha *novoElemento = new noPilha;

    novoElemento->vidaPersonagem = vidaPersonagem;
    novoElemento->vidaInimigo = vidaInimigo;
    novoElemento->itensInventario = inventario;

    novoElemento->proximo = pilha->topo;
    pilha->topo = novoElemento;
}

noPilha* desempilhar(PilhaRebobinar *pilha)
{
    if (pilha->topo == nullptr)
    {
        cout << "N�o h� turnos inseridos na pilha." << endl;
        return nullptr;
    }

    noPilha *elementoRemovido = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    return elementoRemovido;
}

bool estaVazia(PilhaRebobinar *pilha)
{
    return (pilha->topo == nullptr);
}

void destruirPilha(PilhaRebobinar *pilha)
{
    while (!estaVazia(pilha))
    {
        noPilha *elemento = desempilhar(pilha);
        delete elemento;
    }
}

// Fun��o para inicializar a tabela hash
void inicializarTabelaHash(TabelaHash *tabela, int tamanho)
{
    tabela->tamanho = tamanho;
    tabela->buckets.resize(tamanho, nullptr);
}

// Fun��o hash para calcular o �ndice baseado no nome
int calcularHash(string& chave, int tamanho)
{
    int hash = 0;

    for (char c : chave)
        hash = (hash * 31 + c) % tamanho;
    
    return hash;
}

// Fun��o para buscar uma criatura na tabela hash pelo nome
Criatura* buscarCriatura(TabelaHash *tabela, string& nome)
{
    int indice = calcularHash(nome, tabela->tamanho);
    noCriatura* atual = tabela->buckets[indice];

    while (atual != nullptr)
    {
        if (atual->criatura.nome == nome)
            return &atual->criatura;

        atual = atual->proximo;
    }

    return nullptr;
}

// Fun��o para imprimir apenas os nomes das criaturas
void imprimirNomesCriaturas(TabelaHash *tabela)
{
    cout << "Nomes das criaturas:" << endl;

    for (int i = 0; i < tabela->tamanho; ++i)
    {
        noCriatura* atual = tabela->buckets[i];

        while (atual != nullptr)
        {
            cout << atual->criatura.nome << endl;
            atual = atual->proximo;
        }
    }
}

// Fun��o para exibir detalhes de uma criatura
void exibirDetalhesCriatura(TabelaHash *tabela) {
    string nome;
    cout << "Digite o nome da criatura para ver os detalhes: ";
    cin >> nome;

    Criatura* encontrada = buscarCriatura(tabela, nome);
    
    if (encontrada)
    {
        cout << "Nome: " << encontrada->nome << endl;
        cout << "Descri��o: " << encontrada->descricao << endl;
        cout << "Natureza: " << encontrada->natureza << endl;
    }
    else
        cout << "Parece que esta criatura n�o est� o �lbum ainda..." << endl;
}

// Fun��o para inserir uma criatura na tabela hash (�lbum)
void inserirCriatura(TabelaHash *tabela, Criatura& criatura)
{
    int indice = calcularHash(criatura.nome, tabela->tamanho);
    noCriatura* novoNo = new noCriatura;

    novoNo->criatura = criatura;
    novoNo->proximo = tabela->buckets[indice];
    tabela->buckets[indice] = novoNo;
}

void adicionarCriaturaAlbum(TabelaHash *album, string nome, string descricao, string natureza)
{
    Criatura criatura;

    criatura.nome = nome;
    criatura.descricao = descricao;
    criatura.natureza = natureza;

    inserirCriatura(album, criatura);
}

// função que limpa a tela com o comando correto dependendo do seu SO
void limparTela()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// função que pausa a execução do programa com base no SO
void pausar(int milisegundos)
{
    #ifdef _WIN32
        Sleep(milisegundos);
    #else
        usleep(milisegundos * 1000);
    #endif
}

// função de animação dos 3 pontos ao finalizar o jogo
void imprimirAnimacaoPontos()
{
    for(int i=0; i<3; i++)
    {
        cout << "." << flush;
        pausar(500);
        cout << "." << flush;
        pausar(500);
        cout << "." << flush;
        pausar(500);
        
        cout << "\b\b\b   " << flush;
        cout << "\b\b\b" << flush;
        pausar(500);
    }
}

// função que imprime strings letra a letra, dando a impressão de fala
void imprimirNarracao(string narracao)
{
    for(char letra : narracao)
    {
        cout << letra << flush;
        pausar(50);
    }
}

void contraAtaquesInimigo(Inimigo& inimigo, int escolhaDoJogador)
{
    string narracao;
    ostringstream valorConvertido;
    int dano;

    ContraAtaquesInimigo contraAtaque = inimigo.contraAtaques[escolhaDoJogador-2];

    cout << "> ";
    narracao = contraAtaque.descricaoContraAtaque;
    imprimirNarracao(narracao);
    cout << endl;

    dano = contraAtaque.danoContraAtaque - inimigo.defesa;

    if(dano > 0)
    {
        inimigo.vida -= dano;

        valorConvertido << dano;

        cout << "> ";
        narracao = "Voc� causou ";
        imprimirNarracao(narracao);
        narracao = valorConvertido.str();
        imprimirNarracao(narracao);
        narracao = " de dano ao ";
        imprimirNarracao(narracao);
        narracao = inimigo.nome;
        imprimirNarracao(narracao);
        narracao = ".";
        imprimirNarracao(narracao);
        cout << endl;
    }
    else
    {
        cout << "> ";
        narracao = "Apesar das suas habilidades, n�o foi suficiente para abalar a criatura.";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "Todo o dano foi absorvido pela defesa da criatura.";
        imprimirNarracao(narracao);
        cout << endl;
    }
    
    valorConvertido.str("");
    valorConvertido.clear();

    cout << endl;

    esperarTeclaParaContinuar();
}

void imprimirAcoesUnicas(Inimigo inimigo, int& contadorDeAcoes)
{
    string narracao;
    ostringstream contadorDeAcoesConvertido;

    for(int i=0; i<2; i++)
    {
        contadorDeAcoesConvertido << contadorDeAcoes;

        cout << "> ";
        narracao = "[";
        imprimirNarracao(narracao);
        narracao = contadorDeAcoesConvertido.str();
        imprimirNarracao(narracao);
        narracao = "] ";
        imprimirNarracao(narracao);
        narracao = inimigo.contraAtaques[i].nomeContraAtaque;
        imprimirNarracao(narracao);
        cout << endl;

        contadorDeAcoesConvertido.str("");
        contadorDeAcoesConvertido.clear();
        contadorDeAcoes++;
    }
}

void imprimirHabilidadesDisponiveis(Personagem& personagem)
{
    imprimirArvore(personagem.arvore);
}

int escolherHabilidade()
{
    int habilidade;

    while(true)
    {
        cin >> habilidade;

        if(habilidade >= 1 && habilidade <= 7)
            break;
    }

    return habilidade;
}

void limparInventario(ListaInventario *inventario)
{
    noInventario *atual = inventario->primeiro;
    
    while(atual)
    {
        noInventario *temp = atual;
        atual = atual->proximo;
        delete temp;
    }

    inventario->primeiro = nullptr;
}

void substituirInventario(ListaInventario *inventarioAtual, vector<Item>& inventarioAnterior)
{
    limparInventario(inventarioAtual);

    for(auto& item : inventarioAnterior)
    {
        adicionarItemInventario(inventarioAtual, item);
    }
}

void executarHabilidade(Personagem& personagem, Inimigo& inimigo, PilhaRebobinar *pilhaHabilidade, int habilidadeEscolhida)
{   
    noPilha *turnoAnterior = pilhaHabilidade->topo;
    turnoAnterior = pilhaHabilidade->topo;
    turnoAnterior = turnoAnterior->proximo;

    if(habilidadeEscolhida == 1)
    {
        personagem.vida = turnoAnterior->vidaPersonagem;
        inimigo.vida = turnoAnterior->vidaInimigo;

        substituirInventario(personagem.inventario, turnoAnterior->itensInventario);
    }
}

int executarAcaoJogadorCombate(int escolhaDoJogador, Personagem& personagem, Inimigo& inimigo, PilhaRebobinar *pilhaHabilidade)
{
    string narracao;
    ostringstream valorConvertido;
    int dano, inventarioManipulado, continuarFluxo;

    switch(escolhaDoJogador)
    {
        case 1:
            dano = personagem.ataque - inimigo.defesa;
            inimigo.vida -= dano;

            valorConvertido << dano;

            cout << "> ";
            narracao = "Voc� causou ";
            imprimirNarracao(narracao);
            narracao = valorConvertido.str();
            imprimirNarracao(narracao);
            narracao = " de dano ao ";
            imprimirNarracao(narracao);
            narracao = inimigo.nome;
            imprimirNarracao(narracao);
            narracao = ".";
            imprimirNarracao(narracao);
            cout << endl;
            cout << endl;

            valorConvertido.str("");
            valorConvertido.clear();

            continuarFluxo = 1;

            esperarTeclaParaContinuar();
            break;
        case 2:
        case 3:
            contraAtaquesInimigo(inimigo, escolhaDoJogador);
            continuarFluxo = 1;
            break;
        case 4:
            limparTela();
            inventarioManipulado = mostrarInventario(personagem);

            if(inventarioManipulado == 4)
                continuarFluxo = 0;
            break;
        case 5:
            imprimirHabilidadesDisponiveis(personagem);
            executarHabilidade(personagem, inimigo, pilhaHabilidade, escolherHabilidade());
            break;
    }

    return continuarFluxo;
}

void fazerBackupItensInventario(Personagem& personagem, vector<Item>& inventario)
{
    noInventario *atual = personagem.inventario->primeiro;
    atual = personagem.inventario->primeiro;

    while (atual)
    {
        inventario.push_back(atual->item);
        atual = atual->proximo;
    }
}

int combate(Personagem& personagem, initializer_list<Inimigo*> inimigos)
{
    FilaCombate *filaCombate = new FilaCombate;
    PilhaRebobinar *pilha = new PilhaRebobinar;

    string narracao;
    Inimigo* inimigoMarcado = nullptr;
    int contadorDeAcoes = 1, escolhaDoJogador, contadorDeInimigos = 0, marcador, habilidadeInimigoEscolhida, dano, continuarFluxo = 1;
    ostringstream contadorDeAcoesConvertido;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);
    vector<Item> backupInventario;
    
    criarFilaCombate(filaCombate);
    enfileirarCriaturasCombate(filaCombate, personagem.nome);

    criarPilha(pilha);
    
    for(auto inimigo : inimigos)
    {
        enfileirarCriaturasCombate(filaCombate, inimigo->nome);
        contadorDeInimigos++;
    }
    
    contadorDeInimigos--;
    noFilaCombate *aux = filaCombate->frente;
    
    while(true)
    {
        limparTela();

        cout << "> ";
        narracao = "Sua vida: " + to_string(personagem.vida);
        imprimirNarracao(narracao);
        cout << endl;

        for(auto inimigo : inimigos)
        {
            cout << "> ";
            narracao = "Vida do " + inimigo->nome + ": " + to_string(inimigo->vida);
            imprimirNarracao(narracao);
            cout << endl;
        }

        cout << endl;

        if(aux->nome == personagem.nome || continuarFluxo == 0)
        {
            if(contadorDeInimigos > 0)
            {
                cout << "> ";
                narracao = "� a sua vez! Escolha qual inimigo atacar:";
                imprimirNarracao(narracao);
                cout << endl;
                cout << endl;
                
                for(auto inimigo : inimigos)
                {
                    if(!inimigo->nome.empty())
                    {
                        contadorDeAcoesConvertido << contadorDeAcoes;
                        
                        cout << "> ";
                        narracao = "[";
                        imprimirNarracao(narracao);
                        narracao = contadorDeAcoesConvertido.str();
                        imprimirNarracao(narracao);
                        narracao = "] ";
                        imprimirNarracao(narracao);
                        narracao = inimigo->nome;
                        imprimirNarracao(narracao);
                        cout << endl;
                        
                        contadorDeAcoesConvertido.str("");
                        contadorDeAcoesConvertido.clear();
                        contadorDeAcoes++;
                    }
                }
                
                cin >> marcador;
                marcador--;
                inimigoMarcado = inimigos.begin()[marcador];
                
                contadorDeAcoes = 1;
            }
            else
            {
                cout << "> ";
                narracao = "� a sua vez! Como voc� ir� agir?";
                imprimirNarracao(narracao);
                cout << endl;

                inimigoMarcado = inimigos.begin()[0];
            }

            cout << endl;
            cout << "> ";
            narracao = "[1] Golpear";
            imprimirNarracao(narracao);
            cout << endl;
            contadorDeAcoes++;
            
            imprimirAcoesUnicas(*inimigoMarcado, contadorDeAcoes);
            
            contadorDeAcoesConvertido << contadorDeAcoes;
            
            cout << "> ";
            narracao = "[";
            imprimirNarracao(narracao);
            narracao = contadorDeAcoesConvertido.str();
            imprimirNarracao(narracao);
            narracao = "] Checar Invent�rio";
            imprimirNarracao(narracao);
            cout << endl;

            if(personagem.nivel >= 2)
            {
                contadorDeAcoesConvertido.str("");
                contadorDeAcoesConvertido.clear();

                contadorDeAcoes++;
                contadorDeAcoesConvertido << contadorDeAcoes;

                cout << "> ";
                narracao = "[" + contadorDeAcoesConvertido.str() + "] Usar Habilidades";
                imprimirNarracao(narracao);
                cout << endl;
            }
            
            cin >> escolhaDoJogador;

            cout << endl;
            continuarFluxo = executarAcaoJogadorCombate(escolhaDoJogador, personagem, *inimigoMarcado, pilha);
        }
        else
        {
            habilidadeInimigoEscolhida = dis(gen);
            
            for(auto inimigo : inimigos)
            {
                if(aux->nome == inimigo->nome)
                    inimigoMarcado = inimigo;
            }
            
            dano = inimigoMarcado->habilidades[habilidadeInimigoEscolhida].danoHabilidade - personagem.defesa;

            if(dano > 0)
            {
                personagem.vida -= dano;

                cout << "> ";
                narracao = inimigoMarcado->nome + " usou a habilidade " + inimigoMarcado->habilidades[habilidadeInimigoEscolhida].nomeHabilidade + " e causou " + to_string(dano) + " de dano a voc�.";
                imprimirNarracao(narracao);
                cout << endl;
            }
            else
            {
                cout << "> ";
                narracao = "A criatura tenta te atacar de diversas formas, mas voc� tem experi�ncia com isso; e sua armadura � bastante resistente.";
                imprimirNarracao(narracao);
                cout << endl;

                cout << "> ";
                narracao = "Todo o dano foi absorvido pela sua defesa.";
                imprimirNarracao(narracao);
                cout << endl;
                cout << endl;
            }
            
            cout << endl;
            esperarTeclaParaContinuar();
            cout << endl;
        }
        
        if(continuarFluxo == 1)
        {
            aux = aux->proximo;
            
            if(aux == nullptr)
                aux = filaCombate->frente;
        }
        
        contadorDeAcoesConvertido.str("");
        contadorDeAcoesConvertido.clear();
        contadorDeAcoes = 1;
        
        bool todosInimigosDerrotados = true;

        fazerBackupItensInventario(personagem, backupInventario);
        empilhar(pilha, personagem.vida, inimigoMarcado->vida, backupInventario);

        for(auto inimigo : inimigos)
        {
            if(inimigo->vida > 0)
                todosInimigosDerrotados = false;
        }

        if(todosInimigosDerrotados == true || personagem.vida <= 0)
            break;
    }

    destruirFilaCombate(filaCombate);
    destruirPilha(pilha);

    if(personagem.vida <= 0)
        return 0;
    else
        return 1;
}

// fun��o que imprime o menu e guarda a sele��o do usu�rio
int imprimirMenuPrincipal()
{
    int escolhaMenu;
    
    while(true)
    {
        limparTela();
    
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "              Ecos de L�te               " << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << endl;
        cout << "[1] Iniciar Jogo" << endl;
        cout << "[2] Sair" << endl;
        
        cin >> escolhaMenu;
        
        if(escolhaMenu != 1 && escolhaMenu != 2)
        {
            cout << "Desculpe! N�o temos a op��o inserida, ainda..." << flush;
            pausar(4000);
        }
        else
            break;
    }
    
    return escolhaMenu;
}

// fun��o que direciona as frases de cria��o de personagem para o feminino
void criarPersonagemPronomeFeminino(Personagem& personagem)
{
    string narracao;
    int escolhaArquetipo;
    
    cout << "> ";
    narracao = "Dentre eles, uma se destacou. O nome dela era: ";
    imprimirNarracao(narracao);
    
    cin >> personagem.nome;
    cout << endl;
    
    cout << "> ";
    narracao = personagem.nome;
    imprimirNarracao(narracao);
    narracao = ", inquieta, se equipava e se preparava para sair em busca de algo maior.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    while(true)
    {
        cout << "> ";
        narracao = "Ela foi criada sua vida inteira nesta vila, sempre treinando para se tornar a melhor:";
        imprimirNarracao(narracao);
        cout << endl;
        
        narracao = "[1] Guerreira";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] Bruxa";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[3] Assassina";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[4] Cavaleira";
        imprimirNarracao(narracao);
        cout << endl;
        cin >> escolhaArquetipo;
        
        switch(escolhaArquetipo)
        {
            case 1:
                personagem.arquetipo = "Guerreira";
                break;
            case 2:
                personagem.arquetipo = "Bruxa";
                break;
            case 3:
                personagem.arquetipo = "Assassina";
                break;
            case 4:
                personagem.arquetipo = "Cavaleira";
                break;
            default:
                cout << "> ";
                narracao = "Ela ainda n�o aprendeu as habilidades necess�rias para se tornar isso. Vamos tentar de novo!";
                imprimirNarracao(narracao);
                cout << endl;
                break;
        }
        
        if(escolhaArquetipo < 5 && escolhaArquetipo > 0)
            break;
    }
}

// fun��o que direciona as frases de cria��o de personagem para o masculino
void criarPersonagemPronomeMasculino(Personagem& personagem)
{
    string narracao;
    int escolhaArquetipo;
    
    cout << "> ";
    narracao = "Dentre eles, um se destacou. O nome dele era: ";
    imprimirNarracao(narracao);
    
    cin >> personagem.nome;
    cout << endl;
    
    cout << "> ";
    narracao = personagem.nome;
    imprimirNarracao(narracao);
    narracao = ", inquieto, se equipava e se preparava para sair em busca de algo maior.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    while(true)
    {
        cout << "> ";
        narracao = "Ele foi criado sua vida inteira nesta vila, sempre treinando para se tornar o melhor:";
        imprimirNarracao(narracao);
        cout << endl;
        
        narracao = "[1] Guerreiro";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] Bruxo";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[3] Assassino";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[4] Cavaleiro";
        imprimirNarracao(narracao);
        cout << endl;
        cin >> escolhaArquetipo;
        
        switch(escolhaArquetipo)
        {
            case 1:
                personagem.arquetipo = "Guerreiro";
                break;
            case 2:
                personagem.arquetipo = "Bruxo";
                break;
            case 3:
                personagem.arquetipo = "Assassino";
                break;
            case 4:
                personagem.arquetipo = "Cavaleiro";
                break;
            default:
                cout << "> ";
                narracao = "Ele ainda n�o aprendeu as habilidades necess�rias para se tornar isso. Vamos tentar de novo!";
                imprimirNarracao(narracao);
                cout << endl;
                break;
        }
        
        if(escolhaArquetipo < 5 && escolhaArquetipo > 0)
            break;
    }
}

// fun��o que conta a hist�ria inicial e cria o personagem
void criarPersonagem(Personagem& personagem)
{
    string narracao;
    int pronomePersonagem;
    
    while(true)
    {
        limparTela();
    
        cout << "> Antes de tudo, escolha o pronome do seu personagem:" << endl;
        cout << "[1] Ela" << endl;
        cout << "[2] Ele" << endl;
        cin >> pronomePersonagem;
        
        if(pronomePersonagem == 1 || pronomePersonagem == 2)
            break;
        else
        {
            cout << endl;
            cout << "Infelizmente n�o temos esse pronome dispon�vel no momento..." << flush;
            pausar(4000);
        }
    }
    
    limparTela();
    
    cout << "> ";
    narracao = "Em um reino distante, guerreiros se erguiam em uma pequena vila denominada [nome da vila].";
    imprimirNarracao(narracao);
    cout << endl;
    
    if(pronomePersonagem == 1)
    {
        personagem.pronome = "Ela";
        criarPersonagemPronomeFeminino(personagem);
    }
    else
    {
        personagem.pronome = "Ele";
        criarPersonagemPronomeMasculino(personagem);
    }
    
    if(personagem.arquetipo == "Guerreira" || personagem.arquetipo == "Guerreiro")
    {
        personagem.vida = 18;
        personagem.ataque = 6;
        personagem.defesa = 6;
    }
    else if(personagem.arquetipo == "Bruxa" || personagem.arquetipo == "Bruxo")
    {
        personagem.vida = 17;
        personagem.ataque = 7;
        personagem.defesa = 5;
    }
    else if(personagem.arquetipo == "Assassina" || personagem.arquetipo == "Assassino")
    {
        personagem.vida = 16;
        personagem.ataque = 8;
        personagem.defesa = 4;
    }
    else
    {
        personagem.vida = 19;
        personagem.ataque = 5;
        personagem.defesa = 7;
    }
    
    personagem.exp = 0;
    personagem.nivel = 1;
    inicializarTabelaHash(personagem.album, 30);
}

// fun��o que executa os comandos caso o jogador decida se juntar � T�mis
void respostaCasoAceitarProposta(Personagem& personagem)
{
    string narracao;
    Item item;
    
    limparTela();
    
    cout << "> [T�mis] - ";
    narracao = "Fez a escolha certa, crian�a.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [T�mis] - ";
    narracao = "O que eu sei at� ent�o � que muitas criaturas esquisitas t�m aparecido pelos lados de {nome de algum lugar}. Talvez seja interessante come�ar por l�.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [T�mis] - ";
    narracao = "Infelizmente n�o posso te acompanhar no momento, mas acredito que isto te servir� para alguma coisa. Boa sorte.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = "Voc� recebeu um saco com 3 pequenos frascos vermelhos borbulhantes.";
    imprimirNarracao(narracao);
    cout << endl;
    
    especificarItem(item, 1, "Frasco de Cicatriza��o", 3, true, "Frasco de vidro com um l�quido carmesim cintilante dentro. Cura 5 de sua vida.");
    adicionarItemInventario(personagem.inventario, item);

    cout << "> ";
    narracao = "3 Frascos de Cicatriza��o adicionados ao INVENT�RIO.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
}

// fun��o que executa os comandos caso o jogador decida n�o se juntar � T�mis
void respostaCasoRecusarProposta(Personagem& personagem)
{
    string narracao;
    Item item;
    
    limparTela();
    
    cout << "> [T�mis] - ";
    narracao = "Como quiser. Boa sorte na sua jornada.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << ">  ";
    narracao = "A pessoa misteriosa se desvanece em meio a uma fuma�a na sua frente, deixando um s�mbolo marcado no ch�o.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << ">  ";
    narracao = "Voc� percebe um ac�mulo de um p� cinza no local. Sua curiosidade fala mais alto. Voc� guarda o p� em um frasco para mais tarde.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    especificarItem(item, 1, "Pote de Cinzas Espirituais", 1, false, "Um pote com cinzas recolhidas de um ritual. Atordoa os inimigos durante 1 turno.");
    adicionarItemInventario(personagem.inventario, item);

    cout << ">  ";
    narracao = "1 Pote de Cinzas Espirituais adicionado ao INVENT�RIO.";
    imprimirNarracao(narracao);
    cout << endl;
    
    esperarTeclaParaContinuar();
}

// fun��o que direciona a conversa do pr�logo para o fluxo 1.1
void respostaCaso1o1(Personagem& personagem)
{
    string narracao;
    int resposta;
    
    limparTela();
    
    cout << "> [T�mis] - ";
    narracao = "Receio que temos um interesse em comum. Parti de minha vila h� um tempo para descobrir o que s�o os acontecimentos recentes.";
    imprimirNarracao(narracao);
    cout << endl;
    
    while(true)
    {
        cout << "> [T�mis] - ";
        narracao = "Imagino que queira se juntar a mim para descobrir o que est� havendo, o que acha? Podemos decifrar juntos o que as pessoas t�m chamado de \"Apocalipse\".";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        
        narracao = "[1] (Se juntar)";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] (Continuar de forma independente)";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indispon�vel... Vamos tentar de novo!" << flush;
            pausar(5000);
            limparTela();
        }
        else
            break;
    }
    
    switch(resposta)
    {
        case 1:
            respostaCasoAceitarProposta(personagem);
            break;
        case 2:
            respostaCasoRecusarProposta(personagem);
            break;
    }
    
}

// fun��o que direciona a conversa do pr�logo para o fluxo 1.2
void respostaCaso1o2(Personagem& personagem)
{
    string narracao;
    int resposta;

    while(true)
    {
        limparTela();

        cout << "> [T�mis] - ";
        narracao = "Me encontro em um momento de muita descoberta dos mist�rios recentes. Talvez essas armas que carrega podem ser �teis. O que acha de me acompanhar?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
                
        narracao = "[1] (Se juntar)";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] (Continuar de forma independente)";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indispon�vel... Vamos tentar de novo!" << flush;
            pausar(5000);
            limparTela();
        }
        else
            break;
    }

    switch(resposta)
    {
        case 1:
            respostaCasoAceitarProposta(personagem);
            break;
        case 2:
            respostaCasoRecusarProposta(personagem);
            break;
    }
}

// fun��o que direciona a conversa do pr�logo para o fluxo 1
void respostaCaso1(Personagem& personagem)
{
    string narracao;
    int resposta;
    
    limparTela();
    
    cout << "> [???] - ";
    narracao = "A aurora cativa essas plan�cies. Acredito que queira voltar sempre que puder.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [???] - ";
    narracao = "Eu, a prop�sito, estou aqui em busca de algo. Prazer, me chamo T�mis.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = "O ser misterioso retira o capuz de cor marrom, revelando um rosto de uma mulher cansada, como quem j� viu coisas demais.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    
    while(true)
    {
        limparTela();
    
        cout << "> [T�mis] - ";
        narracao = "Acredito que tenha percebido os estranhos acontecimentos recentes. Vejo que carrega armas, para que s�o?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        
        narracao = "[1] Estou as levando em minha jornada. Quero desvendar o que tem acontecido ao redor destes vilarejos.";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] S�o apenas por garantia. N�o pretendo us�-las para fins que n�o seja defesa pessoal.";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indispon�vel... Vamos tentar de novo!" << flush;
            pausar(5000);
        }
        else
            break;
    }
    
    switch(resposta)
    {
        case 1:
            respostaCaso1o1(personagem);
            break;
        case 2:
            respostaCaso1o2(personagem);
            break;
    }
}

// fun��o que direciona a conversa do pr�logo para o fluxo 2
void respostaCaso2(Personagem& personagem)
{
    string narracao;
    int resposta;

    limparTela();

    cout << "> [???] - ";
    narracao = "Por sorte encontrou algu�m com o mesmo objetivo que voc�. Esses acontecimentos t�m me intrigado por semanas.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> [???] - ";
    narracao = "Meu nome � T�mis, por sinal. Moro em uma vila a n�o muito tempo daqui. As pessoas l� n�o sabem mais o que fazer em rela��o �s coisas estranhas que t�m acontecido.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = "O ser misterioso retira o capuz de cor marrom, revelando um rosto de uma mulher cansada, como quem j� viu coisas demais.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    esperarTeclaParaContinuar();
    limparTela();

    cout << "> [T�mis] - ";
    narracao = "Por isso, decidi eu mesma ir atr�s desse mist�rio. J� fiz muito progresso.";
    imprimirNarracao(narracao);
    cout << endl;

    while(true)
    {
        cout << "> [T�mis] - ";
        narracao = u8"Uma ajuda extra seria muito bem-vinda. O que acha de ouvir um pouco sobre o que tenho a dizer sobre essa situa��o?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        narracao = "[1] (Se juntar)";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] (Continuar de forma independente)";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indispon�vel... Vamos tentar de novo!" << flush;
            pausar(5000);
            limparTela();
        }
        else
            break;
    }

    switch(resposta)
    {
        case 1:
            respostaCasoAceitarProposta(personagem);
            break;
        case 2:
            respostaCasoRecusarProposta(personagem);
            break;
    }
}

// fun��o que direciona a conversa do pr�logo para o fluxo 3
void respostaCaso3(Personagem& personagem)
{
    string narracao;
    Item item;

    limparTela();

    cout << "> [???] - ";
    narracao = "Nesse caso, meu nome tamb�m n�o lhe diz respeito. Trilhe seu caminho sem inc�modos, mas se atente aos perigos dessa estrada. Nem tudo s�o rosas se visto muito de perto.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = "A pessoa misteriosa se desvanece em meio a uma fuma�a na sua frente, deixando um s�mbolo marcado no ch�o.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = "Voc� percebe um ac�mulo de um p� cinza no local. Sua curiosidade fala mais alto. Voc� guarda o p� em um frasco para mais tarde.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "1 Pote de Cinzas Espirituais adicionado ao INVENT�RIO.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    especificarItem(item, 1, "Pote de Cinzas Espirituais", 1, false, "Um pote com cinzas recolhidas de um ritual. Atordoa os inimigos durante 1 turno.");

    adicionarItemInventario(personagem.inventario, item);
    
    esperarTeclaParaContinuar();
}

// fun��o que executa o pr�logo do jogo
void prologo(Personagem& personagem)
{
    string narracao;
    int resposta;
    
    limparTela();
    
    cout << "> ";
    narracao = "Voc� se encontra saindo da vila onde viveu sua vida toda, em busca de algo que tem perturbado a paz dos moradores locais.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = "Planta��es mortas, desastres naturais, animais doentes por causas desconhecidas, e nada de respostas.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    limparTela();
    
    cout << "> ";
    narracao = "Durante seu caminhar atrav�s de uma estreita estrada de calc�rio, algo chama sua aten��o: um ser encapuzado.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = "Voc� se aproxima, apesar da afli��o.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    
    while(true)
    {
        limparTela();
        
        cout << "> [???] - ";
        narracao = "O que anda fazendo por essas bandas, crian�a?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        
        narracao = "[1] Apenas dando uma passeada, e o senhor?";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] Estou procurando algo que est� causando desordem em minha vila.";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[3] N�o lhe diz respeito. Quem seria voc� por sinal?";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 3)
        {
            cout << "Resposta indispon�vel... Vamos tentar de novo!" << flush;
            pausar(5000);
        }
        else
            break;
    }
    
    switch(resposta)
    {
        case 1:
            respostaCaso1(personagem);
            break;
        case 2:
            respostaCaso2(personagem);
            break;
        case 3:
            respostaCaso3(personagem);
            break;
    }
}

void verificarNivel(Personagem& personagem)
{
    string narracao;
    bool progrediu = false;

    progrediu = false;

    if(personagem.exp >= 20)
    {
        personagem.nivel = 2;
        progrediu = true;
    }
    else if(personagem.exp >= 40)
    {
        personagem.nivel = 3;
        progrediu = true;
    }
    else if(personagem.exp >= 60)
    {
        personagem.nivel = 4;
        progrediu = true;
    }
    else if(personagem.exp >= 80)
    {
        personagem.nivel = 5;
        progrediu = true;
    }
    else if(personagem.exp >= 100)
    {
        personagem.nivel = 6;
        progrediu = true;
    }

    if(progrediu)
    {
        cout << "> ";
        narracao = "Parab�ns! Voc� progrediu para o n�vel " + to_string(personagem.nivel) + " de personagem!";
        imprimirNarracao(narracao);
        cout << endl;

        chamarAprimorarHabilidade(personagem.arvore, personagem.nivel);
    }
}

void recompensarJogador(Personagem& personagem, int exp)
{
    string narracao;

    personagem.exp += exp;

    cout << "> ";
    narracao = "Voc� ganhou " + to_string(exp) + " pontos de experi�cia!";
    imprimirNarracao(narracao);
    cout << endl << endl;

    verificarNivel(personagem);
}

void mostrarMensagemRessurreicao()
{
    string narracao;

    limparTela();

    cout << "... ";
    narracao = "Voc� se encontra perdido no tempo ...";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "... ";
    narracao = "Todo o conhecimento primordial se encontra nas suas m�os ...";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "... ";
    narracao = "Agora voc� sabe de tudo, mas n�o deveria saber ...";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "... ";
    narracao = "Est� na hora de voltar por onde voc� veio ...";
    imprimirNarracao(narracao);
    cout << endl << endl;

    esperarTeclaParaContinuar();
}

int sucessoCombate(Personagem& personagem, int combateBemSucedido, int backupVidaPersonagem, int expGanho)
{
    string narracao;

    if(!combateBemSucedido)
    {
        mostrarMensagemRessurreicao();
        personagem.vida = backupVidaPersonagem;
        return 0;
    }
    else
    {
        limparTela();

        cout << "> ";
        narracao = "Voc� sobreviveu ao combate e matou a criatura!";
        imprimirNarracao(narracao);
        cout << endl;

        recompensarJogador(personagem, expGanho);
        esperarTeclaParaContinuar();
        return 1;
    }
}

void addInimigo(Inimigo& inimigo, string nome, int vida, int defesa, HabilidadeInimigo habilidades[3], ContraAtaquesInimigo contraAtaques[2])
{
    inimigo.nome = nome;

    inimigo.vida = vida;
    inimigo.defesa = defesa;
    
    for(int i=0; i<3; i++)
    {
        inimigo.habilidades[i] = habilidades[i];
        
        if(i<2)
            inimigo.contraAtaques[i] = contraAtaques[i];
    }
}

void introducaoInimigoUm(Personagem& personagem)
{
    Inimigo druidaAssombrado;
    int combateBemSucedido;
    int backupVidaPersonagem = personagem.vida;
    
    limparTela();
    
    HabilidadeInimigo habilidades[] = {
        {"Agarrar", 5},
        {"Envolver em Trevas", 6},
        {"A Maldi��o da Floresta", 8}
    };

    ContraAtaquesInimigo contraAtaques[] = {
        {"Purificar", "Voc� usa as hist�rias que ouvia quando era crian�a para proferir ora��es que livram esta alma maldita de seu estado decadente.", 9},
        {"Usar a for�a da natureza", "Voc� n�o est� apto a controlar a natureza. A criatura sente seus movimentos e absorve quase todos.", 5}
    };

    while(true)
    {
        addInimigo(druidaAssombrado, "Druida Assombrado", 7, 4, habilidades, contraAtaques);

        combateBemSucedido = combate(personagem, {&druidaAssombrado});

        if(sucessoCombate(personagem, combateBemSucedido, backupVidaPersonagem, 5))
            break;
    }
    
    adicionarCriaturaAlbum(personagem.album, "Druida Assombrado", "Um esp�rito da floresta em sofrimento.", "Agressivo");
}

void introducaoInimigoDois(Personagem& personagem)
{
    Inimigo insetoNecrofago;
    int combateBemSucedido;
    int backupVidaPersonagem = personagem.vida;
    
    limparTela();
    
    HabilidadeInimigo habilidades[] = {
        {"Cortar", 6},
        {"Absorver", 8},
        {"Corroer", 9}
    };

    ContraAtaquesInimigo contraAtaques[] = {
        {"Purificar", "Voc� usa as hist�rias que ouvia quando era crian�a para proferir ora��es que livram esta alma maldita de seu estado decadente.", 9},
        {"Usar a for�a da natureza", "Voc� n�o est� apto a controlar a natureza. A criatura sente seus movimentos e absorve quase todos.", 5}
    };

    while(true)
    {
        addInimigo(insetoNecrofago, "Inseto Necr�fago", 9, 4, habilidades, contraAtaques);

        combateBemSucedido = combate(personagem, {&insetoNecrofago});

        if(sucessoCombate(personagem, combateBemSucedido, backupVidaPersonagem, 5))
            break;
    }

    adicionarCriaturaAlbum(personagem.album, "Inseto Necr�fago", "Um gigante inseto.", "Agressivo");
}

void introducaoInimigoTres(Personagem& personagem)
{
    Inimigo gargulaDecadente;
    int combateBemSucedido;
    int backupVidaPersonagem = personagem.vida;
    
    limparTela();
    
    HabilidadeInimigo habilidades[] = {
        {"Morder", 8},
        {"Grito Infernal", 8},
        {"Destreza Mortal", 9}
    };

    ContraAtaquesInimigo contraAtaques[] = {
        {"Purificar", "Voc� usa as hist�rias que ouvia quando era crian�a para proferir ora��es que livram esta alma maldita de seu estado decadente.", 9},
        {"Usar a for�a da natureza", "Voc� n�o est� apto a controlar a natureza. A criatura sente seus movimentos e absorve quase todos.", 5}
    };

    while(true)
    {
        addInimigo(gargulaDecadente, "G�rgula Decadente", 12, 4, habilidades, contraAtaques);

        combateBemSucedido = combate(personagem, {&gargulaDecadente});

        if(sucessoCombate(personagem, combateBemSucedido, backupVidaPersonagem, 10))
            break;
    }
    
    adicionarCriaturaAlbum(personagem.album, "G�rgula Decadente", "Uma gigante g�rgula viva.", "Agressivo");
}

void introducaoEntrarNaFloresta(Personagem personagem)
{
    string narracao;
    
    limparTela();
    
    cout << "> ";
    narracao = "Com apreens�o e entusiasmo, voc� se dirige � trilha banhada de dor, � inevit�vel se assustar com a apar�ncia dessa floresta.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = "As �rvores se assemelham a tent�culos de um enorme polvo emergindo do solo, se contorcendo e entrela�ando nelas mesmas.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = "Um ar pesado toma seu corpo. Seu caminhar se torna mais cuidadoso. H� algo por perto.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    limparTela();

    cout << "> ";
    narracao = "De forma bestial, um vulto negro se lan�a em sua dire��o a partir de folhagens escuras.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = "UM INIMIGO APARECEU!";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    
    introducaoInimigoUm(personagem);
    limparTela();

    cout << "> ";
    narracao = "Sua jornada continua, apesar do susto. Esse lugar � muito perigoso.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "Voc� escuta movimentos nas folhagens, e j� se prepara para atacar.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "Um grande inseto tenta te atacar, mas voc� se defende com sucesso.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = "UM INSETO GIGANTE APARECEU!";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    esperarTeclaParaContinuar();

    introducaoInimigoDois(personagem);
    limparTela();

    cout << "> ";
    narracao = "Apesar do seu treinamento, ningu�m disse que seria f�cil. � assustador enfrentar tais criaturas.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "A presen�a da morte te comove, como esperado, tem algo aguardando voc� nesta trilha.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "Se aproximando atrav�s de uma n�voa densa, voc� v�. Existe uma figura demon�aca no seu caminho.";
    imprimirNarracao(narracao);
    cout << endl << endl;

    cout << "> ";
    narracao = "MATE A G�RGULA!";
    imprimirNarracao(narracao);
    cout << endl << endl;

    esperarTeclaParaContinuar();

    introducaoInimigoTres(personagem);
}

void introducao(Personagem& personagem)
{
    string narracao;
    int escolha;

    limparTela();
    
    cout << "> ";
    narracao = "Voc� observa tra�os decadentes a partir de uma parte da trilha.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    while(true)
    {
        cout << "> ";
        narracao = "Fa�a sua escolha:";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "[1] Checar invent�rio";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "[2] Seguir o caminho da decad�ncia";
        imprimirNarracao(narracao);
        cout << endl;

        cin >> escolha;

        if(escolha < 1 || escolha > 2)
        {
            cout << endl;
            cout << "Fa�a uma das escolhas propostas. N�o fuja disso.";
            pausar(4000);
            limparTela();
        }
        else
        {
            switch(escolha)
            {
                case 1:
                    limparTela();
                    cout << "> ";
                    narracao = "Esta � a sua bolsa. Aqui voc� pode guardar tudo o que achar em sua jornada.";
                    imprimirNarracao(narracao);
                    cout << endl << endl;
                    
                    mostrarInventario(personagem);
                    
                    limparTela();

                    break;
                case 2:
                    introducaoEntrarNaFloresta(personagem);
                    break;
            }
        }
        
        if(escolha == 2)
            break;
    } 
}

void ermosInimigoUm(Personagem& personagem)
{
    Inimigo escaravehoDeCristal;
    int combateBemSucedido;
    int backupVidaPersonagem = personagem.vida;
    
    limparTela();
    
    HabilidadeInimigo habilidades[] = {
        {"Perfurar", 8},
        {"Levantar Voo", 9},
        {"Tempestade de Areia", 11}
    };

    ContraAtaquesInimigo contraAtaques[] = {
        {"Desintegrar", "O uso das areias escaldantes te apoiam. Parte do inimigo � levado pelo calor.", 9},
        {"Furac�o Arenoso", "A criatura est� acostumada com este clima. Seu ataque n�o tem muito efeito", 5}
    };

    while(true)
    {
        addInimigo(escaravehoDeCristal, "Escaravelho de Cristal", 14, 5, habilidades, contraAtaques);

        combateBemSucedido = combate(personagem, {&escaravehoDeCristal});

        if(sucessoCombate(personagem, combateBemSucedido, backupVidaPersonagem, 10))
            break;
    }
    
    adicionarCriaturaAlbum(personagem.album, "Escaravelho de Cristal", "Um enorme escaravelho com asas p�rpura feitas de cristal.", "Agressivo");
}

void ermosCristalinos(Personagem& personagem)
{
    string narracao;

    limparTela();

    cout << "> ";
    narracao = "Campos �ridos e joias emergindo do solo te esperam neste lugar...";
    imprimirNarracao(narracao);
    cout << endl;

    ermosInimigoUm(personagem);
}

void ruinasDialogoCacador(Personagem& personagem, bool& primeiraVez, bool portaoAberto)
{
    string narracao;

    limparTela();

    if(primeiraVez)
    {
        cout << "> ";
        narracao = "Ol�, tamb�m est� aqui atr�s de L�te?";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "� esta coisa que est� causando todo o mau que tem visto.";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "Ele se encontra atr�s daquele port�o, mas ningu�m tem coragem de abrir?";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "Acredito que isso possa servir como um incentivo para conseguir finalizar a sua jornada.";
        imprimirNarracao(narracao);
        cout << endl << endl;

        cout << "> ";
        narracao = "Voc� recebeu o �lbum do Ca�ador";
        imprimirNarracao(narracao);
        cout << endl << endl;

        primeiraVez = false;
    }
    else
    {
        if(!portaoAberto)
        {
            cout << "> ";
            narracao = "Ainda n�o conseguiu abrir o port�o, n�... Se precisar de algo, estou por aqui.";
            imprimirNarracao(narracao);
            cout << endl;
        }
        else
        {
            cout << "> ";
            narracao = "Voc� conseguiu... Agora s� falta uma �ltima etapa. Boa sorte.";
            imprimirNarracao(narracao);
            cout << endl;
        }
    }
}

void escolhaRuinasMananciais(Personagem& personagem)
{
    int escolha;
    string narracao;
    bool primeiraVezCacador = true;
    bool primeiraVezAgnes = true;
    bool primeiraVezRuinas = true;
    bool portaoAberto = false;

    while(true)
    {   
        limparTela();

        if(!primeiraVezRuinas)
        {
            narracao = "As ru�nas te d�o as boas-vindas. Mesmo que em seu pior estado desde sua queda.";
            imprimirNarracao(narracao);
            cout << endl << endl;
        }

        narracao = "[1] Checar Port�o";
        imprimirNarracao(narracao);
        cout << endl;

        narracao = "[2] Falar com O Ca�ador";
        imprimirNarracao(narracao);
        cout << endl;

        narracao = "[3] Falar com Agnes, a Avariciosa";
        imprimirNarracao(narracao);
        cout << endl;

        narracao = "[4] Partir";
        imprimirNarracao(narracao);
        cout << endl;

        narracao = "[5] Checar Invent�rio";
        imprimirNarracao(narracao);
        cout << endl;

        narracao = "[6] Visualizar �rvore de Habilidades";
        imprimirNarracao(narracao);
        cout << endl;

        if(!primeiraVezCacador)
        {
            narracao = "[7] Ver �lbum do Ca�ador";
            imprimirNarracao(narracao);
            cout << endl;
        }

        cin >> escolha;

        switch(escolha)
        {
            case 1:
                // indisponivel
                break;
            case 2:
                ruinasDialogoCacador(personagem, primeiraVezCacador, portaoAberto);
                break;
            case 3:
                // indisponivel
                break;
            case 4:
                ermosCristalinos(personagem);
                break;
            case 5:
                // indisponivel
                break;
            case 6:
                // indisponivel
                break;
            case 7:
                imprimirNomesCriaturas(personagem.album);
                exibirDetalhesCriatura(personagem.album);
                break;
            default:
                cout << "Escolha inv�lida" << endl;
                esperarTeclaParaContinuar();
                limparTela();
                break;
        }
    }
}

void ruinasMananciais(Personagem& personagem)
{
    string narracao;

    limparTela();

    cout << "> ";
    narracao = "Voc� finalmente chega a uma aparente cidade destru�da.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "Ru�nas se erguem lutando contra a fonte da Decad�ncia.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "Algumas pessoas se encontram espalhadas pelo local hexagonal, ao que parece est�o esperando por algo.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "No centro, uma grande fonte quebrada se mostra imponente e, mesmo que ferida, resistente �s for�as do tempo.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "Um grande port�o com uma aura mortal se mostra grandioso e rouba a aten��o do que tem ao seu redor.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "Voc� sente que ali se encontra a Nascente da Decad�ncia.";
    imprimirNarracao(narracao);
    cout << endl;

    escolhaRuinasMananciais(personagem);
}

// fun��o que inicia o jogo e executa todos os comandos para o funcionamento dele
void iniciarJogo()
{
    Personagem personagem;

    criarListaInventario(personagem.inventario);
    criarArvore(personagem.arvore);
    iniciarArvoreHabilidades(personagem.arvore);
    
    criarPersonagem(personagem);
    
    prologo(personagem);

    introducao(personagem);

    ruinasMananciais(personagem);
}

// fun��o que finaliza o jogo mostrando uma pequena anima��o
void finalizarJogo()
{
    char confirmarSaida;
    
    limparTela();
    
    cout << "Tem certeza que deseja sair? [s/n]" << endl;
    cin >> confirmarSaida;
    
    switch(confirmarSaida)
    {
        case 's':
            cout << "\nFinalizando o jogo" << flush;
            
            imprimirAnimacaoPontos();
            
            limparTela();
            cout << "Jogo finalizado. Continue explorando por a�. At� mais.";
            
            exit(0);
            break;
        case 'n':
            break;
    }
}

// fun��o principal que executa todos os comandos necess�rios para iniciar e finalizar o jogo
int main()
{
    system("chcp 1252 > nul");

    int escolhaMenu;
       
    while(true)
    {
        escolhaMenu = imprimirMenuPrincipal();
        
        switch(escolhaMenu)
        {
            case 1:
                iniciarJogo();
                break;
            case 2:
                finalizarJogo();
                break;
        }
    }

    return 0;
}