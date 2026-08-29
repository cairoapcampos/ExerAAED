// Converte uma expressão infixa para pós-fixa usando a notação polonesa reversa. Usa string como pilha.
// Complexidade: O(n), onde n é o tamanho da expressão.

#include <iostream>
#include <string>

using namespace std;

// Retorna a prioridade dos operadores
int prioridade(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    }

    if (operador == '*' || operador == '/') {
        return 2;
    }

    return 0;
}


// Converte uma expressão infixa para pós-fixa
string converterParaPosfixa(string expressao) {
    string pilha;
    string posfixa = "";

    for (int i = 0; i < expressao.length(); i++) {
        char caractere = expressao[i];

        // Ignora espaços
        if (caractere == ' ') {
            continue;
        }

        // Se for uma letra, adiciona diretamente à saída
        if (caractere >= 'A' && caractere <= 'Z') {
            posfixa.push_back(caractere);
        }

        // Se encontrar "(", empilha
        else if (caractere == '(') {
            pilha.push_back(caractere);
        }

        // Se encontrar ")", desempilha até encontrar "("
        else if (caractere == ')') {
            while (!pilha.empty() && pilha.back() != '(') {
                posfixa.push_back(pilha.back());
                pilha.pop_back();
            }

            // Remove o "(" da pilha
            if (!pilha.empty()) {
                pilha.pop_back();
            }
        }

        // Se encontrar um operador
        else {
            while (!pilha.empty() &&
                   pilha.back() != '(' &&
                   prioridade(pilha.back()) >= prioridade(caractere)) {

                posfixa.push_back(pilha.back());
                pilha.pop_back();
            }

            pilha.push_back(caractere);
        }
    }

    // Retira os operadores que ainda ficaram na pilha
    while (!pilha.empty()) {
        posfixa.push_back(pilha.back());
        pilha.pop_back();
    }

    return posfixa;
}


int main() {
    string expressao = "(A + B) * (C - D)";

    cout << endl;

    cout << "Expressao infixa: " << expressao << endl;
    cout << "Expressao pos-fixa: "
         << converterParaPosfixa(expressao) << endl;
    
    cout << endl;

    return 0;
}
