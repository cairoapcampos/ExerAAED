// Verifica se uma expressão contendo parênteses, colchetes e chaves é válida. Usa uma string como pilha do C++.
// Complexidade: O(n), onde n é o tamanho da expressão.

#include <iostream>
#include <string>

using namespace std;

bool parValido(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']') || (abertura == '{' && fechamento == '}');
}

bool expressaoValida(string expressao) {
    string pilha;

    for (int i = 0; i < expressao.length(); i++) {
        char caractere = expressao[i];

        // Se for um símbolo de abertura, empilha
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            pilha.push_back(caractere);
        }

        // Se for um símbolo de fechamento
        else if (caractere == ')' || caractere == ']' || caractere == '}') {

            // Se a pilha estiver vazia, não existe abertura correspondente
            if (pilha.empty()) {
                return false;
            }

            // Verifica se o último símbolo da pilha forma um par válido
            else if (!parValido(pilha.back(), caractere)) {
                return false;
            }

            // Encontrou um par válido, então desempilha
            else {
                pilha.pop_back();
            }
        }
    }

    return pilha.empty();
}

int main() {
    string entradas[5] = { "()", "()[]{}", "(]", "([{}])", "{(})"
    };

    for (int i = 0; i < 5; i++) {
        cout << "Entrada: " << entradas[i] << endl;

        if (expressaoValida(entradas[i])) {
            cout << "Resultado: valida" << endl;
        }
        else {
            cout << "Resultado: invalida" << endl;
        }

        cout << endl;
    }

    return 0;
}

