#!/bin/bash
# Verifica que se pasen dos argumentos al script
if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <nombre_proceso> <comando_ejecutable>"
    exit 1
fi

nombre_proceso="$1"
comando_ejecutable="$2"


is_process_running() {   #funcion para comprobar si el proceso esta en ejecucion.
    pgrep "$nombre_proceso" >/dev/null 2>&1  # para verificar si el proceso esta en ejecucion devuelve un falso o verd
}                                              #/dev/null para que no muestre la salida en pantalla

# Función para iniciar el proceso
start_process() {   #funcion para iniciar el proceso en caso de que no este siendo ejecutado.          

    echo "Iniciando el proceso: $comando_ejecutable"  # muetra en pantalla que va a iniciar el proceso
    # Ejecutar el comando para iniciar el proceso en segundo plano
    $comando_ejecutable &
}

# Iniciar el proceso al ejecutar el script por primera vez
start_process

while true; do                                #hacemos un while para monitorear,reiniciar  y hacer un bucle
    # Verificar si el proceso está en ejecución
    if ! is_process_running; then
        echo "El proceso '$nombre_proceso' no está en ejecución. Reiniciando..."
        start_process  # Reiniciar el proceso
    fi
    sleep 5  # Esperar 5 segundos antes de volver a verificar
done
