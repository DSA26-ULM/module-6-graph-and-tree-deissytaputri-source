#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> labels(N);
    map<string, int> index;

    for (int i = 0; i < N; i++) {
        cin >> labels[i];
        index[labels[i]] = i;
    }

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        matrix[index[u]][index[v]] = w;
    }

    int colWidth = 4;

    cout << "Adjacency Matrix:" << endl;

    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << " " << labels[i];
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << labels[i];
        for (int j = 0; j < N; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}