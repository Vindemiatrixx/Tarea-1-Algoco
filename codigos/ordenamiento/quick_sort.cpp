
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>


int partition(std::vector<int>& vector_datos, int izquierda, int derecha) {
    
    int pivote = vector_datos[derecha];
    int i = izquierda - 1;

    for (int j = izquierda; j <= derecha - 1; j++) {

        if (vector_datos[j] <= pivote) {
            
            i++;
            std::swap(vector_datos[i], vector_datos[j]);
        }
        
    }

    std::swap(vector_datos[i + 1], vector_datos[derecha]);
    
    return i + 1;
}

void quickSort(std::vector<int>& vector_datos, int izquierda, int derecha) {
    
    if (izquierda < derecha) {
    
        int indice_pivote = partition(vector_datos, izquierda, derecha);
        quickSort(vector_datos, izquierda, indice_pivote - 1);
        quickSort(vector_datos, indice_pivote + 1, derecha);
    
    }

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

        quickSort(vector_numeros, 0, vector_numeros.size()-1);

        auto fin = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duracion = fin - inicio;



        std::cout << "Tiempo de bubble sort con " << cantidad_datos << " elementos: \t" << duracion.count() << std::endl;
        archivo.close();
    }
    
    return 0;
}