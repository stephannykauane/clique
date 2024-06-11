#include <bits/stdc++.h>

using namespace std;

void solver(int n, vector<vector<int>> &G, int *tamClique, vector<bool> &clique);
bool isClique(int n, vector<vector<int>> &G, vector<bool> V);
void leituraGrafo(vector<vector<int>> &, int);
void escritaGrafo(vector<vector<int>> &);

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> clique;
    int tamClique;
    vector<vector<int>> Grafo;
    Grafo.assign(n, vector<int>(n, 0));
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    solver(n, Grafo, &tamClique, clique);
    cout << "Clique: ";
    
    for(int i = 0; i < n; i++){
        if(clique[i]){
            cout << i << " ";
        }
    }
    cout << "\nQuantidade de vértices: " << tamClique << "\n";

    return 0;
}

void solver(int n, vector<vector<int>> &G, int *tamClique, vector<bool> &clique){
    vector<bool> v(n);
    for(int r = 1; r <= n; r++){
        fill(v.end() - r, v.end(), true);
        do{
            if(isClique(n, G, v)){
                (*tamClique) = r;
                clique = v;
            }
        }while(next_permutation(v.begin(), v.end()));
    }
}

bool isClique(int n, vector<vector<int>> &G, vector<bool> V){
    for(int i = 0; i < n; i++){
        if(V[i]){
            for(int j = 0; j < n; j++){
                if(i != j && V[j]){
                    if(!G[i][j]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
}

void escritaGrafo(vector<vector<int>> &G)
{
    int n = G.size();
    cout << "Matriz de Adjacência:" << endl;
    cout << "   ";
    for (int u = 0; u < n; u++)
    {
        cout << u << " ";
    }
    cout << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (int v = 0; v < n; v++)
        {
            cout << G[u][v] << " ";
        }
        cout << endl;
    }
}