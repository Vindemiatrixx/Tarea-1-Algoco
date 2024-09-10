#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>

void merge(std::vector<int>& vector_datos, int izquierda, int medio, int derecha) {

    std::vector<int> lado_izquierdo(vector_datos.begin() + izquierda, vector_datos.begin() + medio + 1);
    
    std::vector<int> lado_derecho(vector_datos.begin() + medio + 1, vector_datos.begin() + derecha + 1);

    size_t i = 0, j = 0, k = izquierda;

    while (i < lado_izquierdo.size() && j < lado_derecho.size()) {
        
        if (lado_izquierdo[i] <= lado_derecho[j]) {
        
            vector_datos[k++] = lado_izquierdo[i++];
        
        } else {
        
            vector_datos[k++] = lado_derecho[j++];
        
        }
    }

    while (i < lado_izquierdo.size()) {
        
        vector_datos[k++] = lado_izquierdo[i++];
    }

    while (j < lado_derecho.size()) {
        
        vector_datos[k++] = lado_derecho[j++];
    }
}

void mergeSort(std::vector<int>& vector_datos, int izquierda, int derecha) {
    
    if (izquierda >= derecha) return;

    int medio = (izquierda + derecha) / 2;

    mergeSort(vector_datos, izquierda, medio);
    mergeSort(vector_datos, medio + 1, derecha);

    merge(vector_datos, izquierda, medio, derecha);
}




int main(){


    for (int i = 0; i < 9; i++){

        std::string ruta = "../../dataset/data_semiordenado_";
        std::string valor_archivo = std::to_string(i);
        std::string txt = ".txt";

        ruta += valor_archivo;
        ruta += txt;
        

        std::vector<int> vector_numeros;

        std::ifstream archivo (ruta);

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

        mergeSort(vector_numeros, 0, vector_numeros.size()-1);

        auto fin = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duracion = fin - inicio;



        std::cout << "Tiempo de bubble sort con " << cantidad_datos << " elementos: \t" << duracion.count() << std::endl;
        archivo.close();
    }
    return 0;
}