#ifndef PALAVRAS_H_INCLUDED
#define PALAVRAS_H_INCLUDED

#include <windows.h> // Para acessar arquivos no Windows
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>   // Para manipula��o de arquivos em C++
#include <cstring>
using namespace std;

const int  MAX_CHARS  = 30; // Quantidade m�xima de caracteres
const char PASTA[]    = "categorias"; // Pasta que deve estar dentro do projeto
const char TIPO_ARQ[] = "*.txt";

// Retorna a quantidade de arquivos do tipo especificado em TIPO_ARQ na pasta PASTA.
// Retorna 0 caso a pasta n�o exista ou n�o existam arquivos na pasta especificada.
int quantCategorias()
{
    HANDLE hFind;
    WIN32_FIND_DATA FindData;
    int quant=0;
    char pastaTipoArq[50];

    pastaTipoArq[0] = '\0';
    strcat(pastaTipoArq, PASTA);
    strcat(pastaTipoArq, "\\");
    strcat(pastaTipoArq, TIPO_ARQ);
    //cout << "Pasta tipo arq: " << pastaTipoArq << endl;

    // Encontra o primeiro arquivo
    hFind = FindFirstFile(pastaTipoArq, &FindData);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        quant++;
        while (FindNextFile(hFind, &FindData))
        {
            quant++;
        }
    }

    FindClose(hFind);
    return quant;
}

// L� pelo menos uma categoria no vetor de ponteiros para caracteres.
void leCategorias(char *categorias[], int quant)
{
    HANDLE hFind;
    WIN32_FIND_DATA FindData;
    int i = 0;
    char pastaTipoArq[50];

    pastaTipoArq[0] = '\0';
    strcat(pastaTipoArq, PASTA);
    strcat(pastaTipoArq, "\\");
    strcat(pastaTipoArq, TIPO_ARQ);

    hFind = FindFirstFile(pastaTipoArq, &FindData);

    categorias[i] = new char[strlen(FindData.cFileName)+1];

    strcpy(categorias[i++], FindData.cFileName);

    while (FindNextFile(hFind, &FindData))
    {
        categorias[i] = new char[strlen(FindData.cFileName)+1];
        strcpy(categorias[i++], FindData.cFileName);
    }

    // Close the file handle
    FindClose(hFind);
}

// Libera a mem�ria alocada para cada categoria
void liberaCategoriasMemoria(char *categorias[], int quant)
{
    for(int i=0; i<quant; i++)
    {
        delete [] categorias[i];
    }
}

// Retorna true caso haja pelo menos uma categoria, sorteando uma.
// Retorna false, caso contr�rio (a pasta �categoria� n�o existe ou n�o existem arquivos com
// extens�o txt nessa pasta)
bool sorteiaCategoria(char *categoria)
{
    int quant = quantCategorias();

    if (quant != 0)
    {
        char *categorias[quant];

        leCategorias(categorias, quant);
/*        for(int i=0; i<quant; i++)
            cout << categorias[i] << endl;
*/
        srand(time(NULL));
        strcpy(categoria, categorias[rand()%quant]);

        liberaCategoriasMemoria(categorias, quant);

        return true;
    }
    else return false;
}

// Retorna -1 caso n�o tenha conseguido abrir o arquivo da categoria.
// Retorna 0 caso n�o haja palavras no arquivo.
// Retorna a quantidade de palavras no arquivo e l� as palavras da categoria.
int lePalavras(char ***palavras, char categoria[MAX_CHARS])
{
    ifstream ifs;
    int quantPalavras, cont;
    char arquivo[MAX_CHARS], aux[MAX_CHARS];

    arquivo[0] = '\0';
    strcpy(arquivo, PASTA);
    strcat(arquivo, "\\");

    ifs.open(strcat(arquivo,categoria));

    if (ifs.is_open())
    {
        ifs >> quantPalavras;

        ifs.getline(aux, 30); // Para n�o pegar palavra em branco

        *palavras = new char *[quantPalavras];

        for(cont=0; cont<quantPalavras && !ifs.eof(); cont++)
        {
            ifs.getline(aux, MAX_CHARS);
            (*palavras)[cont] = new char [strlen(aux)+1];
            strcpy((*palavras)[cont], aux);
        }
        if(cont != quantPalavras)
            quantPalavras = cont;

        ifs.close();
        return quantPalavras;
    }
    else
        return -1;
}

// Libera a mem�ria alocada para cada palavra
void liberaPalavrasMemoria(char ***palavras, int quant)
{
    for(int i=0; i<quant; i++)
        delete [] (*palavras)[i];
    delete [] (*palavras);
}

// Retorna 0 caso n�o haja palavras no arquivo da categoria selecionada.
// Retorna -1 caso n�o tenha conseguido abrir o arquivo da categoria.
// Retorna a quantidade de palavras e sorteia uma delas na string palavra.
int sorteiaPalavra(char categoria[MAX_CHARS], char palavra[MAX_CHARS])
{
    char **palavras;
    int quantPalavras;

    quantPalavras = lePalavras(&palavras, categoria);
    if(quantPalavras > 0)
    {
/*        cout << "\nPALAVRAS:\n";
        for(int i=0; i<quantPalavras; i++)
            cout << palavras[i] << endl;
*/
        srand(time(NULL));
        strcpy(palavra, palavras[rand()%quantPalavras]);
        liberaPalavrasMemoria(&palavras, quantPalavras);
    }
    return quantPalavras;
}


#endif // PALAVRAS_H_INCLUDED
