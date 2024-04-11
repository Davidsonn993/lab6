#!/bin/bash

# Verificar que se haya proporcionado un argumento (ejecutable)
if [ $# -ne 1 ]; then               #Esto es para verificar que se introduce un argumento  
                                        #de no ser asi muestra el mensaje
    echo "Uso: $0 <ejecutable>"
    exit 1
fi

ejecutable="$1"                           #guardamos el nombre de la variable 
log_file="registro_memoria.txt"          #creamos una carpeta txt para guardar los datos


obtener_consumo() {                                           #funcion para obtener el consumo   
    local timestamp=$(date "+%Y-%m-%d %H:%M:%S")               #y la informacion
    local cpu_usage=$(ps -p "$pid" -o %cpu --no-headers)
    local mem_usage=$(ps -p "$pid" -o %mem --no-headers)
    echo "$timestamp $cpu_usage $mem_usage" >> "$log_file"    #redireccionamosla salida  a log_file o el registro
}

echo "Ejecutando el proceso: $ejecutable"    # correr el ejecutable en segundo plano
"$ejecutable" &
pid=$!                                          #


echo "Timestamp CPU% Memoria%" > "$log_file"   #crear el archivo log_file


while ps -p "$pid" > /dev/null; do     #este wile es para registrar el consumo de cpu y memoria cada segundo
    obtener_consumo                     #/dev/null   esto es para que no muestre en pantalla
    sleep 1
done

# Procesar los datos registrados usando gnuplot al finalizar el proceso
echo "Proceso finalizado. Generando gráfica..."  #muestra una advertencia que finalizo el proceso y que se
                                                      #genero la grafica
#comandos y caracteristicas de la grafica como nombre de eje x o eje y, el titulo  

gnuplot << EOF                                 
set terminal png size 800,600
set output 'grafico_cpu_memoria.png'                                        
set xlabel 'Tiempo'
set ylabel 'Consumo (%)'
set title 'Consumo de CPU y Memoria a lo largo del tiempo'
set xdata time
set timefmt '%Y-%m-%d %H:%M:%S'
set format x '%H:%M:%S'
plot '$log_file' using 1:2 with lines title 'CPU%', '$log_file' using 1:3 with lines title 'Memoria%'
EOF

echo "Gráfico generado: grafico_cpu_memoria.png"   # Muestro el nombre donde del archivo donde se genero la grafica
