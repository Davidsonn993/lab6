#include <stdio.h>
#include <stdlib.h>
int factorial(int n){
int i = 1;                  //inicializamos la variable
while (n > 1) {                //hacemos un bucle while
 i = i * n;            //multiplica el resultado actual por un numero
 n = n - 1;            //reducimos en 1 el valor de n
}
return i ;       //retornamos i
 }

int main (int argc, char *argv[]) {    //funcion principal
    int num1 = atoi(argv[1]);          //convierte estos argumentos a enteros usando la función atoi()
    int num2 = atoi(argv[2]);

                                   // Calcula los factoriales de los dos números
    int fac1 = factorial(num1);
    int fac2 = factorial(num2); 


printf("%d! = %d, %d! = %d\n", num1, fac1, num2, fac2) ; //imprime los datos requeridos
 return 0 ;

}
