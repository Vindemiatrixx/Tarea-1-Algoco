#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>



int main(){

    std::vector<int> vector_numeros;

    std::ifstream archivo ("../../dataset/data_semiordenado_8.txt");

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

    std::sort(vector_numeros.begin(), vector_numeros.end());

    auto fin = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracion = fin - inicio;



    std::cout << "Tiempo de bubble sort con " << cantidad_datos << " elementos: \t" << duracion.count() << std::endl;
    return 0;
}