import threading
import random

def crear_archivo_semiordenado():

    nombre_str_archivo = "data_ordenado_"
    extension_txt = ".txt"
    
    datos_list = [100, 1000, 2500, 5000, 10000, 50000, 100000, 150000, 250000, 500000]
    
    for i in range(len(datos_list)):

        valor_i = str(i)
    
        lista_datos = list(range(datos_list[i]))
        numero_permutaciones = len(lista_datos) // 2
        
        for _ in range (numero_permutaciones):
            
            valor_1, valor_2 = random.sample(range(len(lista_datos)), 2)
            
            lista_datos[valor_1], lista_datos[valor_2] = lista_datos[valor_2], lista_datos[valor_1]        
        
        nombre_archivo = "../dataset/"+nombre_str_archivo+valor_i+extension_txt
        with open(nombre_archivo, "w") as archivo:
            
            archivo.write(str(datos_list[i])+"\n")
            
            for valores in lista_datos:
                
                archivo.write(str(valores)+"\n")
    
def crear_archivo_desordenado():
    
    nombre_str_archivo = "data_desordenado_"
    extension_txt = ".txt"
    
    datos_list = [100, 1000, 2500, 5000, 10000, 50000, 100000, 150000, 250000, 500000]
    
    for i in range(len(datos_list)):

        valor_i = str(i)
        
        nombre_archivo = "../dataset/"+nombre_str_archivo+valor_i+extension_txt
        with open(nombre_archivo, "w") as archivo:
            
            archivo.write(str(datos_list[i])+"\n")    
            
            datos_ordenados = list(range(datos_list[i]))
            random.shuffle(datos_ordenados)
            for valores in datos_ordenados:
                
                archivo.write(str(valores)+"\n")
    
def crear_archivo_semidesordenado():
    
    nombre_str_archivo = "data_mixto_"
    extension_txt = ".txt"
    
    datos_list = [100, 1000, 2500, 5000, 10000, 50000, 100000, 150000, 250000, 500000]
    
    for i in range(len(datos_list)):

        valor_i = str(i)
    
        lista_datos = list(range(datos_list[i]))
        numero_permutaciones = len(lista_datos) // 4
        
        for _ in range (numero_permutaciones):
            
            valor_1, valor_2 = random.sample(range(len(lista_datos)), 2)
            
            lista_datos[valor_1], lista_datos[valor_2] = lista_datos[valor_2], lista_datos[valor_1]        
        
        nombre_archivo = "../dataset/"+nombre_str_archivo+valor_i+extension_txt
        with open(nombre_archivo, "w") as archivo:
            
            archivo.write(str(datos_list[i])+"\n")
            
            for valores in lista_datos:
                
                archivo.write(str(valores)+"\n")
    
def crear_matrix_cuadrada():
    
    nombre_str_archivo = "matrix_misma_dimension_"
    extension_txt = ".txt"
    
    tamannos_matrix = [10, 100, 500, 1000, 5000, 10000, 15000, 20000]
    
    #TERMINAR DE CREAR MATRICES DE N*N
    
    for i in range(10):

        valor_i = str(i)
        
        nombre_archivo = "../dataset/"+nombre_str_archivo+valor_i+extension_txt
        with open(nombre_archivo, "w") as archivo:
            
            print("a")

def crear_matrix_NO_cuadrada():
    
    nombre_str_archivo = "matrix_no_misma_dimension_"
    extension_txt = ".txt"
    
    for i in range(10):

        valor_i = str(i)
        
        nombre_archivo = "../dataset/"+nombre_str_archivo+valor_i+extension_txt
        with open(nombre_archivo, "w") as archivo:
            
            print("a")
    
crear_archivo_desordenado()
crear_archivo_semidesordenado()
crear_archivo_semiordenado()
