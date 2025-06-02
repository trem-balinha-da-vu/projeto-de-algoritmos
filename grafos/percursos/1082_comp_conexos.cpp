/*
 *
 *Entrada
A primeira linha do arquivo de entrada contém um valor inteiro N que representa a quantidade de casos de teste que vem a seguir. Cada caso de teste contém dois valores V e E que são, respectivamente, a quantidade de Vértices e arestas (Edges) do grafo. Seguem E linhas na sequência, cada uma delas representando uma das arestas que ligam tais vértices. Cada vértice é representado por uma letra minúscula do alfabeto ('a'-'z'), ou seja, cada grafo pode ter no máximo 26 vértices. Cada grafo tem no mínimo 1 componente conexo.

Obs: Os vértices de cada caso de teste sempre iniciam no 'a'. Isso significa que um caso de teste que tem 3 vértices, tem obrigatoriamente os vértices 'a', 'b' e 'c'.

Saída
Para cada caso de teste da entrada, deve ser apresentada uma mensagem Case #n:, onde n indica o número do caso de teste (conforme exemplo abaixo). Segue a listagem dos vértices de cada segmento, um segmento por linha, separados por vírgula (inclusive com uma virgula no final da linha). Finalizando o caso de teste, deve ser apresentada uma mensagem indicando a quantidade de componentes conexos do grafo (em inglês). Todo caso de teste deve ter uma linha em branco no final, inclusive o último caso de teste.
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int v, vector<vector<int>> &vizinhos, vector<bool> &visitado, vector<int> &componente_conexo)
{
    queue<int> q;

    visitado[v] = true;

    q.push(v);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        componente_conexo.push_back(u);

        for(auto p = vizinhos[u].begin(); p != vizinhos[u].end(); p++)
        {
            int v = *p;              // 'v' é um vizinho de 'u'
            if(!visitado[v])
            {
                visitado[v] = true;
                q.push(v);
            }
        }
    }

}

int main()
{
    int count = 1, V, E, n;
    char v1, v2;

    cin >> n;


    while(count <= n)
    {

        cin >> V >> E;

        //Lista de adjacência
        vector<vector<int>> vizinhos(V);
        for (int i = 0; i < E; i++)
        {
            cin >> v1 >> v2;
            vizinhos[v1 - 'a'].push_back(v2 - 'a');
            vizinhos[v2 - 'a'].push_back(v1 - 'a');
        }

        vector<bool> visitado(V, false);

        cout << "Case #" << count << ":\n";

        int num_componentes = 0;

        //Começa a busca em largura em cada vértice para descobrir os componentes
        for(int v = 0; v < V; v++)
        {
            if(!visitado[v])
            {
                //novo componente
                num_componentes++;

                vector<int> componente_conexo;

                //busca em largura
                bfs(v, vizinhos, visitado, componente_conexo);

                //ordenar componentes
                sort(componente_conexo.begin(), componente_conexo.end());

                //imprimir
                for(auto p = componente_conexo.begin(); p != componente_conexo.end(); p++)
                {
                    cout << char(*p + 'a') << ",";
                }
                cout << endl;
            }
        }

        cout << num_componentes << " connected components" << "\n\n";

        count++;
    }

    return 0;

}
