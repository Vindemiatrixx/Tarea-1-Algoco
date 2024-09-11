#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>


void transponerMatriz(const std::vector<std::vector<int>>& matrizOriginal, std::vector<std::vector<int>>& matrizTranspuesta, int tamano) {
    
    matrizTranspuesta.assign(tamano, std::vector<int>(tamano));
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            matrizTranspuesta[j][i] = matrizOriginal[i][j];
        }
    }
}
void multiplicarMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB, std::vector<std::vector<int>>& resultado, int tamano) {
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < tamano; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}


int main() {
    
    for (int i = 0; i < 5; i++) {
    
        std::string ruta = "../../dataset/matrix/matrix_misma_dimension";
        std::string valor_archivo = std::to_string(i);
        std::string txt = ".txt";

        ruta = ruta + valor_archivo + txt;

        std::ifstream inputFile(ruta);

        if (!inputFile.is_open()) {
            std::cerr << "Error al abrir el archivo " << ruta << std::endl;
            return 1;
        }

        std::string line;
        std::getline(inputFile, line);

        int tamanno_matriz = std::stoi(line);

        std::vector<std::vector<int>> matriz_A(tamanno_matriz, std::vector<int>(tamanno_matriz));
        std::vector<std::vector<int>> matriz_B(tamanno_matriz, std::vector<int>(tamanno_matriz));
        std::vector<std::vector<int>> matriz_A_transpuesta(tamanno_matriz, std::vector<int>(tamanno_matriz));
        std::vector<std::vector<int>> matriz_resultante(tamanno_matriz, std::vector<int>(tamanno_matriz));


        for (int i = 0; i < tamanno_matriz; ++i) {
    
            std::getline(inputFile, line);
            std::istringstream iss(line);
    
            int valor;
    
            for (int j = 0; j < tamanno_matriz; ++j) {
    
                iss >> valor;
                matriz_A[i][j] = valor;
                matriz_B[i][j] = valor;  
            }
        }

        transponerMatriz(matriz_A, matriz_A_transpuesta, tamanno_matriz);

        auto inicio = std::chrono::high_resolution_clock::now();

        multiplicarMatrices(matriz_A_transpuesta, matriz_B, matriz_resultante, tamanno_matriz);

        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracion = fin - inicio;

        std::cout << "Tiempo de matriz de tamaño " << tamanno_matriz << ": " << duracion.count() << " segundos" << std::endl;

        inputFile.close();
    }

    return 0;
}
