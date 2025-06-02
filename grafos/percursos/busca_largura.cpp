//Dado um vértice, quero saber a distância dele para todos os outros vértices do grafo.
//O algoritmo faz busca em largura em um grafo representado por sua lista de adjacência.
#include <iostream>
#include <queue>
#include <vector>
#include <climits>   // para INT_MAX

using namespace std;

struct Vertice {
    bool visitado;
    int pai;
    int distancia;

    //inicializa visitado=false, pai=-1, distancia=∞
    Vertice() {
        visitado  = false;
        int pai = -1;
        distancia = INT_MAX; // ou um valor que represente “infinito”
    }
};

void bfs(vector<vector<int>> &adj, int s, vector<Vertice> &vertice)
{
    // Marca a raiz s
    vertice[s].visitado  = true;
    vertice[s].distancia = 0;
    vertice[s].pai       = -1;

    queue<int> q;
    q.push(s);

    int u;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(auto p = adj[u].begin(); p != adj[u].end(); p++)
        {
            int v = *p;
            if(!vertice[v].visitado)
            {
                vertice[v].visitado = true;
                vertice[v].pai = u;
                vertice[v].distancia = vertice[u].distancia + 1;

                q.push(v);

            }
        }
    }

}

int constroi_grafo(vector<vector<int>> &adj, int v, int e)
{
    int  v1, v2;
    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2;

        if(!(v1 < v && v2 < v))
        {
            cout << "os vertices devem ir de 0 a " << v-1 << "\n";
            return 0;
        }

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    return 1;
}


int main()
{


    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    if(!constroi_grafo(adj, v, e))return 0;

    vector<Vertice> vertice(v);

    for(int u = 0; u < v; u++)
    {
        if(!vertice[u].visitado)
        {
            bfs(adj, u, vertice);
        }
    }

    cout << "Resultado do BFS a partir da raíz:\n";
    cout << "Vertice | Distancia | Pai | Visitado\n";
    for (int i = 0; i < v; i++) {
        cout << "   " << i
             << "    |     "
             << (vertice[i].distancia == INT_MAX ? -1 : vertice[i].distancia)
             << "     |   "
             << vertice[i].pai
             << "  |     "
             << (vertice[i].visitado ? "sim" : "não")
             << "\n";
    }

    return 0;

}
