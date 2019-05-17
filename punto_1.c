#include<stdio.h>

/*1) Para realizar un cómputo de los días de licencia correspondientes a un empleado
 * en un período determinado, se considera lo siguiente:
- La cantidad de días depende de la antigüedad del empleado. 1 año: 20 días. 2 años:
	25 días. 3 años o más: 30 días.
- Si son mujeres con hijos a cargo, les corresponden 10 días adicionales (fijos).
- Si son hombres mayores a 55 años, les corresponden 2 días adicionales por cada año
	de antigüedad.

Realice un programa en el que se ingrese el nombre, género (M/F), edad, antigüedad,
y si tiene hijos a cargo. Con dichos datos, calcule y muestre el total de días de
licencia que le corresponde a dicho empleado.*/

void punto_1_vacaciones();

int main()
{
    punto_1_vacaciones();
    return 0 ;
}

void punto_1_vacaciones()
{
    int antiguedad, hijos, genero, edad ;
    char nombre[] ;

    printf("ingrese la antigüedad del empleado:\n") ;
    scanf("%d", &antiguedad) ;

    printf("ingrese género:\n") ;
    scanf("%d", &genero) ;

    printf("ingrese edad:\n") ;
    scanf("%d", &edad) ;

    printf("tiene hijos a cargo?:\n") ;
    scanf("%d", &hijos) ;
}


