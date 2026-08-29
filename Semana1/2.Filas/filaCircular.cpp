// Fila circular usando vetor. Usa índices para frente e re.
//
// Complexidade:
// - inserir: O(1)
// - remover: O(1)
// - mostrarFila: O(n), considerando n como a capacidade da fila.
//
// Como TAMANHO = 5 é constante neste programa,
// o percurso de mostrarFila é limitado a 5 posições.

#include <iostream>

using namespace std;

const int TAMANHO = 5;

int fila[TAMANHO];
int frente = 0;
int re = -1;
int quantidade = 0;


// Insere um elemento no final da fila
void inserir(int elemento) {

    // Verifica se a fila está cheia
    if (quantidade == TAMANHO) {
        cout << "Fila cheia." << endl;
        return;
    }

    // Avança o índice re de forma circular
    re = (re + 1) % TAMANHO;

    fila[re] = elemento;
    quantidade++;
}


// Remove um elemento da frente da fila
void remover() {

    // Verifica se a fila está vazia
    if (quantidade == 0) {
        cout << "Fila vazia." << endl;
        return;
    }

    // Limpa apenas para facilitar a visualização
    fila[frente] = 0;

    // Avança o índice frente de forma circular
    frente = (frente + 1) % TAMANHO;

    quantidade--;
}


// Mostra o vetor e os índices
void mostrarFila() {

    cout << "Vetor: ";

    for (int i = 0; i < TAMANHO; i++) {
        cout << "[" << fila[i] << "] ";
    }

    cout << endl;
    cout << "frente = " << frente << endl;
    cout << "re = " << re << endl;
    cout << "quantidade = " << quantidade << endl;
    cout << endl;
}


int main() {

    cout << endl;

    cout << "Estado inicial:" << endl;
    mostrarFila();

    // 3 inserções
    inserir(10);
    cout << "Apos inserir 10:" << endl;
    mostrarFila();

    inserir(20);
    cout << "Apos inserir 20:" << endl;
    mostrarFila();

    inserir(30);
    cout << "Apos inserir 30:" << endl;
    mostrarFila();


    // 2 remoções
    remover();
    cout << "Apos a primeira remocao:" << endl;
    mostrarFila();

    remover();
    cout << "Apos a segunda remocao:" << endl;
    mostrarFila();


    // Mais 2 inserções
    inserir(40);
    cout << "Apos inserir 40:" << endl;
    mostrarFila();

    inserir(50);
    cout << "Apos inserir 50:" << endl;
    mostrarFila();

    return 0;
}
