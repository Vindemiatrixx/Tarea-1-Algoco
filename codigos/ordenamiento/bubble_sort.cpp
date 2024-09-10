#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

void bubble_sort(std::vector<int>& vector_numeros){

    int n = vector_numeros.size();
    
    // Outer loop for each pass through the vector
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        // Inner loop to compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (vector_numeros[j] > vector_numeros[j + 1]) {
                std::swap(vector_numeros[j], vector_numeros[j + 1]);
                swapped = true;
            }
        }
        
        // Early termination if no swaps occurred in a pass
        if (!swapped) break;
    }

}


int main(){

    std::vector<int> vector_numeros;

    std::ifstream archivo ("../../dataset/data_semiordenado_5.txt");

    if (!archivo.is_open()){

        std::cerr << "Error al abrir el archivo";
        return 1;
    }

    int cantidad_datos;
    archivo >> cantidad_datos;

    for (int i = 0; i < cantidad_datos; i++){

        int valor;
        archivo >> valor;
        vector_numeros.push_back(valor);
    }

    auto inicio = std::chrono::high_resolution_clock::now();

    bubble_sort(vector_numeros);

    auto fin = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracion = fin - inicio;


    for (size_t i = 0; i < vector_numeros.size(); i ++){

        std::cout << vector_numeros[i] << std::endl;
    }

    std::cout << "Tiempo de bubble sort con " << cantidad_datos << " elementos: \t" << duracion.count() << std::endl;
    return 0;
}