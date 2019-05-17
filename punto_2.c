#include<stdio.h>

void punto_2_elecciones() ;
int esMujer(int segso) ;
int esPar(int mesa) ;
int getVoto( char* cand1 , char* cand2 , char* cand3 ) ;
void getDatosEstadistica(char genero, int edad) ;
int puedeVotar(char genero, int mesa, int edad) ;
void mostrarResultados() ;

static int cantidadMujeres = 0 ;
static int cantidadHombres = 0 ;
static int edadHombres = 0 ;
static int edadMujeres = 0 ;
static char cand1[20], cand2[20], cand3[20] ;
static int votoCand1, votoCand2, votoCand3 ;

const int TRUE = 1 ;
const int FALSE = 0 ;

int main()
{
    punto_2_elecciones();
    return 0 ;
}

/*2) Se vienen las elecciones...
Hay tres candidatos posibles. Ingrese los nombres de los tres candidatos por teclado.
Entonces, para cada votante, ingresar su opcion (número de 1 a 3, el cero también es
válido). VALIDAR que el valor del voto sea correcto. La carga se interrumpe al ingresar
un cero en el valor del voto. Dicho ingresado obviamente no cuenta.
Luego, ingrese su edad, género (M/F) y el n° de mesa en el que vota. VALIDE que el
votante sea mayor de edad, y que el género corresponde con el n° de mesa: Las mesas
PARES son para mujeres, y las IMPARES son para hombres.

Finalmente, mostrar una estadística de:
- Cuántos votantes asistieron al comicio,
- distribución por género (cuántos hombres y mujeres, porcentaje del total),
- promedio de edades por género (ej. 36 años para hombres, 43 años para mujeres).

Y, por supuesto... quién fue el candidato ganador, y con cuántos votos ganó...*/

void punto_2_elecciones()
{
    /*2) Se vienen las elecciones...
    Hay tres candidatos posibles. Ingrese los nombres de los tres candidatos por teclado.*/

    printf("Ingrese nombre del candidato 1:\n") ;
    scanf("%s", cand1) ;
    printf("Ingrese nombre del candidato 2:\n") ;
    scanf("%s", cand2) ;
    printf("Ingrese nombre del candidato 3:\n") ;
    scanf("%s", cand3) ;
    printf("Candidato1: %s\n", cand1) ;
    printf("Candidato1: %s\n", cand2) ;
    printf("Candidato1: %s\n", cand3) ;

    char genero ;

    int opcion, mesa, edad ;
    votoCand1 = votoCand2 = votoCand3 = 0 ;

    do
    {
        /*ingrese su edad, género (M/F) y el n° de mesa en el que vota. VALIDE que el
         * votante sea mayor de edad, y que el género corresponde con el n° de mesa:
         * Las mesas PARES son para mujeres, y las IMPARES son para hombres. */

        /*para cada votante (válido), ingresar su opcion (número de 1 a 3, el cero
         * también es válido). VALIDAR que el valor del voto sea correcto. La carga
         * se interrumpe al ingresar un cero en el valor del voto. Dicho ingresado
         * obviamente no cuenta.*/

        printf("ingrese su edad:\n") ;
        scanf("%d", &edad) ;

        printf("Ingrese su género:\n") ;
        scanf(" %c", &genero) ;

        printf("ingrese el número de su mesa:\n") ;
        scanf("%d", &mesa) ;

        if (puedeVotar(genero, mesa, edad))
        {
            opcion = getVoto(cand1, cand2, cand3) ;
            getDatosEstadistica(genero, edad) ;
        }
        else
        {
            continue ;
        }
        

        switch (opcion)
        {
            case 1:
                votoCand1++ ;
                break;
            
            case 2:
                votoCand2++ ;
                break;

            case 3:
                votoCand3++ ;
                break;

            case 0:
                printf("Gracias por utilizar la aplicación \"elecciones\"\n");
                break;

            default:
                printf("Opción incorrecta... el voto será impugnado, pero el voto será "
                		"contabilizado en las estadísticas\n") ;
                break ;
        }
    } while ( opcion != 0) ;

    mostrarResultados() ;

    /*Finalmente, mostrar una estadística de:
    - Cuántos votantes asistieron al comicio,
    - distribución por género (cuántos hombres y mujeres, porcentaje del total),
    - promedio de edades por género (ej. 36 años para hombres, 43 años para mujeres).

    Y, por supuesto... quién fue el candidato ganador, y con cuántos votos ganó...*/
}

void mostrarResultados()
{
    printf("Mostrar resultados...\n") ;
}

void getDatosEstadistica(char genero, int edad)
{
	//estado = invalido
	char estado = 'i' ;
	while ( estado == 'i')
	{
		if (esMujer(genero))
		{
			cantidadMujeres ++ ;
			edadMujeres += edad ;
			//estado = valido
			estado = 'v' ;
		}
		else if ( (genero == 'm') || (genero == 'M') )
		{
			cantidadHombres++ ;
			edadHombres += edad ;
			//estado = valido
			esado = 'v' ;
		}
		else
		{
			printf("por favor introduzca el género de manera correcta (m = masc; f = fem)\n");
		}
	}
}

int puedeVotar(char genero, int mesa, int edad)
{

    if (edad < 16)
    {
        printf("Ud. no está habilitado para votar por ser menor\n") ;
        return FALSE ;
    }

    if ((esMujer(genero) && esPar(mesa)) || (!esMujer(genero) && !esPar(mesa)))
    {
        printf("mesa correcta... usted puede votar, por favor introduzca su "
        		"voto:\n") ;
		return TRUE ;
    }
    else
    {
        printf("mesa incorrecta... diríjase a la mesa que le corresponde\n") ;
        return FALSE ;
    }

}

int esMujer( int segso)
{
    return (segso == 'F') || (segso == 'f');
}

int esPar( int mesa )
{
    return mesa % 2 == 0 ;
}

int getVoto(char* cand1, char* cand2, char* cand3)
{
    /*para cada votante, ingresar su opcion (número de 1 a 3, el cero también es
     * válido). VALIDAR que el valor del voto sea correcto. La carga se interrumpe
     * al ingresar un cero en el valor del voto. Dicho ingresado obviamente no cuenta.*/
    int opcion ;
    printf("Esto es getVOTO()") ;
    printf("introduzca el candidato a votar:\n 1_ %s \n 2_ %s \n 3_ %s \n", cand1,
    		cand2, cand3) ;
    scanf("%d", &opcion) ;
    return opcion ; 
}
