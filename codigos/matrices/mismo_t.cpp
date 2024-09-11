#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

void multiplicacion_cubica(const std::vector<std::vector<int>>& matriz_A, const std::vector<std::vector<int>>& matriz_B, std::vector<std::vector<int>>& result, int tamanno) {
    
    for (int i = 0; i < tamanno; i++) {
    
        for (int j = 0; j < tamanno; j++) {
    
            result[i][j] = 0;
    
            for (int k = 0; k < tamanno; k++) {
    
                result[i][j] += matriz_A[i][k] * matriz_B[k][j];
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

        auto inicio = std::chrono::high_resolution_clock::now();

        multiplicacion_cubica(matriz_A, matriz_B, matriz_resultante, tamanno_matriz);

        auto fin = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double> duracion = fin - inicio;

        std::cout << "Tiempo de matriz de tamaño " << tamanno_matriz << ": " << duracion.count() << " segundos" << std::endl;

        inputFile.close();
    }

    return 0;
}
