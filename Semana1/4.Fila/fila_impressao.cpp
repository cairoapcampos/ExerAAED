// Fila circular de impressão de documentos. Usa vetor estático e índices
// frente e re.
//
// Complexidade, considerando n como a capacidade da fila:
// - adicionar_documento: O(n), devido à verificação de ID único
// - imprimir_proximo: O(1)
// - visualizar_fila: O(n)
// - cancelar_impressao: O(n)
//
// Como TAMANHO = 5 é constante neste programa,
// os percursos são limitados a 5 posições.

#include <iostream>
#include <string>

using namespace std;

const int TAMANHO = 5;


// Estrutura que representa um documento
struct Documento {
    int id;
    string nome;
    int paginas;
};


// Fila circular de documentos
Documento fila[TAMANHO];

int frente = 0;
int re = -1;
int quantidade = 0;


// Verifica se um ID já existe na fila
bool id_existe(int id) {

    for (int i = 0; i < quantidade; i++) {

        // Calcula a posição real no vetor circular
        int posicao = (frente + i) % TAMANHO;

        if (fila[posicao].id == id) {
            return true;
        }
    }

    return false;
}


// Adiciona um documento ao final da fila
void adicionar_documento(int id, string nome, int paginas) {

    // Verifica se a fila está cheia
    if (quantidade == TAMANHO) {
        cout << "Erro: Fila de impressão cheia! Documento "
             << nome << " rejeitado." << endl;

        return;
    }

    // Verifica se o ID já está sendo utilizado
    if (id_existe(id)) {
    cout << "Erro: ID " << id
         << " já está sendo utilizado." << endl;

    return;
}

    // Avança o índice re de forma circular
    re = (re + 1) % TAMANHO;

    // Armazena os dados do documento
    fila[re].id = id;
    fila[re].nome = nome;
    fila[re].paginas = paginas;

    quantidade++;

    cout << "Documento " << nome
         << " adicionado à fila." << endl;
}


// Imprime e remove o próximo documento da fila
void imprimir_proximo() {

    // Verifica se a fila está vazia
    if (quantidade == 0) {
        cout << "Nenhum documento na fila para imprimir." << endl;
        return;
    }

    cout << "Imprimindo "
         << fila[frente].nome
         << " (" << fila[frente].paginas
         << " pág)... Concluído!" << endl;

    // Limpa os dados apenas para facilitar a visualização
    fila[frente].id = 0;
    fila[frente].nome = "";
    fila[frente].paginas = 0;

    // Avança o índice frente de forma circular
    frente = (frente + 1) % TAMANHO;

    quantidade--;
}


// Mostra os documentos na ordem em que serão impressos
void visualizar_fila() {

    if (quantidade == 0) {
        cout << "Fila de impressão vazia." << endl;
        return;
    }

    cout << endl;
    cout << "Fila de impressão:" << endl;

    for (int i = 0; i < quantidade; i++) {

        // Calcula a posição real dentro do vetor circular
        int posicao = (frente + i) % TAMANHO;

        if (i == 0) {
            cout << "Próximo -> ";
        }
        else {
            cout << "           ";
        }

        cout << "ID: " << fila[posicao].id
             << " | Arquivo: " << fila[posicao].nome
             << " | Páginas: " << fila[posicao].paginas
             << endl;
    }

    cout << endl;
}


// Cancela todos os documentos pendentes
void cancelar_impressao() {

    for (int i = 0; i < TAMANHO; i++) {
        fila[i].id = 0;
        fila[i].nome = "";
        fila[i].paginas = 0;
    }

    frente = 0;
    re = -1;
    quantidade = 0;

    cout << "Todos os documentos pendentes foram cancelados." << endl;
}


int main() {

    // Adiciona documentos
    adicionar_documento(1, "relatorio.pdf", 10);
    adicionar_documento(2, "artigo.pdf", 6);
    adicionar_documento(3, "atividade.pdf", 4);

    visualizar_fila();


    // Testa um ID repetido
    adicionar_documento(2, "documento_repetido.pdf", 8);


    // Imprime o primeiro documento
    imprimir_proximo();

    visualizar_fila();


    // Adiciona mais documentos
    adicionar_documento(4, "projeto.pdf", 15);
    adicionar_documento(5, "apostila.pdf", 20);
    adicionar_documento(6, "exercicios_marluce.pdf", 3);

    visualizar_fila();


    // Tenta adicionar com a fila cheia
    adicionar_documento(7, "livro.pdf", 100);


    // Imprime o próximo documento
    imprimir_proximo();

    visualizar_fila();


    // Cancela todos os documentos restantes
    cancelar_impressao();

    visualizar_fila();

    return 0;
}
