import random

def crear_archivo_semiordenado():

    nombre_str_archivo = "data_semiordenado_"
    extension_txt = ".txt"
    
    datos_list = [100, 1000, 2500, 5000, 10000, 50000, 100000, 150000, 250000]
    
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
    
    datos_list = [100, 1000, 2500, 5000, 10000, 50000, 100000, 150000, 250000]
    
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

def generar_matriz(n, min = 0, max = 500):
    return [[random.randint(min, max) for _ in range(n)] for _ in range(n)]

def crear_matrix_cuadrada():
    
    nombre_str_archivo = "matrix_misma_dimension_"
    extension_txt = ".txt"
    
    tamannos_matrix = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]
    
    numero = 500
    
    for i, tamanno in enumerate(tamannos_matrix):
        
        valor_i = str(i)
        nombre_archivo = "../dataset/" + nombre_str_archivo + valor_i + extension_txt
        
        matriz1 = generar_matriz(tamanno, 0, numero)
        matriz2 = generar_matriz(tamanno, 0, numero)
        
        with open(nombre_archivo, "w") as archivo:
            archivo.write(str(tamanno)+"\n")
            
            for fila in matriz1:
                archivo.write(" ".join(map(str, fila)) + "\n")
            
            archivo.write("-\n")
            
            for fila in matriz2:
                archivo.write(" ".join(map(str, fila)) + "\n")

def crear_matrix_NO_cuadrada():
    
    nombre_str_archivo = "matrix_no_misma_dimension_"
    extension_txt = ".txt"
    
    posibles_tamanos = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]
    numero = 500  # Límite superior para los números aleatorios

    for i in range(10):
        valor_i = str(i)
        nombre_archivo = "../dataset/" + nombre_str_archivo + valor_i + extension_txt
        
        # Seleccionar dos tamaños aleatorios para las matrices
        tamanno1 = random.choice(posibles_tamanos)
        tamanno2 = random.choice(posibles_tamanos)
        
        # Generar las dos matrices de tamaños diferentes
        matriz1 = generar_matriz(tamanno1, 0, numero)
        matriz2 = generar_matriz(tamanno2, 0, numero)
        
        with open(nombre_archivo, "w") as archivo:
            archivo.write(f"{tamanno1}x{tamanno1}\n")
            for fila in matriz1:
                archivo.write(" ".join(map(str, fila)) + "\n")
            
            archivo.write("-\n")
            
            archivo.write(f"{tamanno2}x{tamanno2}\n")
            for fila in matriz2:
                archivo.write(" ".join(map(str, fila)) + "\n")

crear_archivo_desordenado()
crear_archivo_semiordenado()