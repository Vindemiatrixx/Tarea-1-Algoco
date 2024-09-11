#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

void sumar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void restar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int n = A.size();
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    std::vector<std::vector<int>> A11(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A12(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A21(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> A22(newSize, std::vector<int>(newSize));

    std::vector<std::vector<int>> B11(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B12(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B21(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> B22(newSize, std::vector<int>(newSize));

    // Dividir las matrices A y B
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Crear matrices auxiliares para productos
    std::vector<std::vector<int>> M1(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> M2(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> M3(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> M4(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> M5(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> M6(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> M7(newSize, std::vector<int>(newSize));

    // Calcular los productos de Strassen
    std::vector<std::vector<int>> temp1(newSize, std::vector<int>(newSize));
    std::vector<std::vector<int>> temp2(newSize, std::vector<int>(newSize));

    sumar(A11, A22, temp1);
    sumar(B11, B22, temp2);
    strassen(temp1, temp2, M1);

    sumar(A21, A22, temp1);
    strassen(temp1, B11, M2);

    restar(B12, B22, temp2);
    strassen(A11, temp2, M3);

    restar(B21, B11, temp2);
    strassen(A22, temp2, M4);

    sumar(A11, A12, temp1);
    strassen(temp1, B22, M5);

    restar(A21, A11, temp1);
    sumar(B11, B12, temp2);
    strassen(temp1, temp2, M6);

    restar(A12, A22, temp1);
    sumar(B21, B22, temp2);
    strassen(temp1, temp2, M7);

    // Calcular las submatrices del resultado
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}


int main() {
    
    for (int i = 0; i < 10; i++) {
    
        std::string ruta = "../../dataset/matrix/matrix_Strassen";
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
        std::vector<std::vector<int>> resultado(tamanno_matriz, std::vector<int>(tamanno_matriz));


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

        strassen(matriz_A, matriz_B, resultado);
        
        auto fin = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double> duracion = fin - inicio;

        std::cout << "Tiempo de matriz de tamaño " << tamanno_matriz << ": " << duracion.count() << " segundos" << std::endl;

        inputFile.close();
    }

    return 0;
}
