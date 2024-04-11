#!/bin/bash
if [ $# -ne 1 ];then               #para comprobar si se proporciona un argumento
echo "uso: $0 <ID_del_proceso>"           #mostramos un mensaje en caso de que no se introdusca el arumento
exit 1                                #numero de argumentos pasados al script ($#)
fi

pid="$1"  #obtener el ID del proceso      $1 es el primer argumento pasado al script 

if ! [[ "$pid" =~ ^[0-9]+$ ]];then   #mostramos un mensaje si el numero no es entero
echo "error: el id debe de ser un numero entero"
exit 1
fi


info=$(ps -p "$pid" -o comm=,pid=,ppid=,user=,pcpu=,pmem=,state=) #con el comando ps extraemos la informacion
                                                                      #del proceso
nombre=$(echo "$info" | awk '{print $1}')

pid=$(echo "$info" | awk '{print $2}')

ppid=$(echo "$info" | awk '{print $3}')

usuario=$(echo "$info" | awk '{print $4}')

porcentaje_cpu=$(echo "$info" | awk '{print $5}')


consumo_memoria=$(echo "$info" | awk '{print $6}')

estado=$(echo "$info" | awk '{print $7}')

path=$(readlink -f "/proc/$pid/exe")     #con readlink obtenemos el path del ejecutable


echo "Infirmación del proceso:(ID:$pid):"
echo "Nombre del proceso:$nombre"
echo "PID del proceso:$pid"
echo "Parent process ID:$ppid"
echo "Usuario propietario:$usuario"
echo "Porcentaje de CPU:$porcentaje_cpu"
echo "Consumo de memoria:$consumo_memoria"

echo "Estado:$estado"
echo "Path del ejecutable:$path"




