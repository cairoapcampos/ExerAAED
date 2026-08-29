// Simplifica um caminho absoluto em um sistema de arquivos Unix. Usa vetor como pilha.
// Complexidade: O(n), onde n é o tamanho do caminho.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simplificarCaminho(string caminho)
{
    vector<string> pilha;
    string diretorio;
    string resultado = "";

    for (int i = 0; i < caminho.length(); i++)
    {

        // Ignora barras
        if (caminho[i] == '/')
        {
            continue;
        }

        // Lê o nome do diretório
        diretorio = "";

        while (i < caminho.length() && caminho[i] != '/')
        {
            diretorio.push_back(caminho[i]);
            i++;
        }

        // "." representa o diretório atual e é ignorado
        if (diretorio == ".")
        {
            continue;
        }

        // ".." retorna um diretório
        else if (diretorio == "..")
        {
            if (!pilha.empty())
            {
                pilha.pop_back();
            }
        }

        // Nome normal de diretório
        else
        {
            pilha.push_back(diretorio);
        }
    }

    // Monta o caminho simplificado
    for (int i = 0; i < pilha.size(); i++)
    {
        resultado.push_back('/');
		resultado += pilha[i];
    }

    // Se não houver diretórios, o resultado é a raiz
    if (resultado == "")
    {
        return "/";
    }

    return resultado;
}

int main()
{
    string entradas[5] = {
        "/home/user/./downloads/../documents//fotos/",
        "/home/aluno/./projetos/../trabalhos/",
        "/var//log///sistema/",
        "/home/usuario/documentos/../../imagens/",
        "/usr/local/../share/documentacao/"
    };

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Entrada: " << entradas[i] << endl;
        cout << "Resultado: " << simplificarCaminho(entradas[i]) << endl;
        cout << endl;
    }

    return 0;
}
