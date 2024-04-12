#!/bin/bash

# Directorio a monitorear
directorio="/home"

# Archivo de registro
archivo_log="/var/log/cambios_home.log"

# Monitorear el directorio continuamente
inotifywait -m -r -e create,modify,delete "$directorio" |
while read -r directory evento archivo
do
    fecha_hora=$(date +"%Y-%m-%d %H:%M:%S")
    echo "[$fecha_hora] Evento detectado: $evento en $archivo" >> "$archivo_log"
done





