#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


void readGraph(const string& filename, vector<vector<int>>& weightMatrix, int& n, int& m) {
    ifstream file(filename);
    if (!file) {
        cout << "Не вдалося відкрити файл " << filename << endl;
        return;
    }

    file >> n >> m; 
    weightMatrix.assign(n, vector<int>(n, 0)); 

    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        file >> v1 >> v2 >> w;
        weightMatrix[v1 - 1][v2 - 1] = w; 
    }

    file.close();
}


void outputMatrix(const string& outFilename, const vector<vector<int>>& weightMatrix) {
    ofstream outFile(outFilename);
    if (!outFile) {
        cout << "Не вдалося відкрити файл для запису " << outFilename << endl;
        return;
    }

    cout << "Матриця ваг: " << endl;
    for (const auto& row : weightMatrix) {
        for (int val : row) {
            cout << setw(4) << val;
            outFile << setw(4) << val;
        }
        cout << endl;
        outFile << endl;
    }

    outFile.close();
}

int main() {
    string inputFilename, outputFilename;
    int n, m; 
    vector<vector<int>> weightMatrix;

   
    cout << "--------------------------" << endl;
    cout << "Завдання 1: Зчитування графу з файлу" << endl;
    cout << "--------------------------" << endl;

  
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFilename;

   
    readGraph(inputFilename, weightMatrix, n, m);

    cout << "Граф успішно зчитано. Кількість вершин: " << n << ", кількість ребер: " << m << endl;

   
    cout << "--------------------------" << endl;
    cout << "Завдання 2: Виведення матриці ваг" << endl;
    cout << "--------------------------" << endl;

    
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFilename;

    
    outputMatrix(outputFilename, weightMatrix);

    cout << "Матриця ваг успішно виведена у файл " << outputFilename << endl;

    return 0;
}
