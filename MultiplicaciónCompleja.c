#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
INSTRUCCIONES DE USO DEL PROGRAMA
- Ingresa comas en lugar de puntos para n鷐eros con decimales


*/

int main()
{
    setlocale(LC_ALL,"Spanish");
    int x=0,filas1=0,columnas1=0,filas2=0,columnas2=0;
    char ans;

    //lectura de filas y columnas de las matrices
    printf("Este programa realiza la multiplicaci髇 de 2 matrices complejas\n");
    do{
    printf("Introduce el n鷐ero de filas de la primera matriz:\n");
    scanf("%d",&filas1);
    printf("Introduce el n鷐ero de columnas de la primera matriz:\n");
    scanf("%d",&columnas1);
    printf("Introduce el n鷐ero de filas de la segunda matriz:\n");
    scanf("%d",&filas2);
    printf("Introduce el n鷐ero de columnas de la segunda matriz:\n");
    scanf("%d",&columnas2);
    if (columnas1!=filas2)
    {
        x=0;
        printf("Estas matrices no se pueden multiplicar, sus dimensiones no son compatibles\n");
    }
    else if (columnas1==filas2)
    {
        x=1;
    }
    }while(x==0);

    //Declaraci髇 de arreglos
    float reales1[filas1][columnas1];
    float reales2[filas2][columnas2];
    float imaginarios1[filas1][columnas1];
    float imaginarios2[filas2][columnas2];

    //Lectura de matrices
    //Primera matriz
    //Reales
    do
    {
    printf("Ingresa las partes reales de la primer matriz:\n");
    for (int i=0;i<filas1;i++)
    {
        for (int j=0;j<columnas1;j++)
        {
            printf("Ingresa el valor para a[%d][%d]: ",i+1,j+1);
            scanf("%f",&reales1[i][j]);
        }
    }

    //Imaginarios
    printf("Ingresa las partes imaginarias de la primer matriz (sin i):\n");
    for (int i=0;i<filas1;i++)
    {
        for (int j=0;j<columnas1;j++)
        {
            printf("Ingresa el valor para a[%d][%d]: ",i+1,j+1);
            scanf("%f",&imaginarios1[i][j]);
        }
    }

    //Impresi髇 de matriz
    for (int i=0;i<filas1;i++)
    {
        printf("\n");
        for (int j=0;j<columnas1;j++)
        {
            //　　　　　　　　　　FALTA IMPRESI覰 PERFECTA DE N贛EROS COMPLEJOS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

            printf("%.3f %.3f i",reales1[i][j],imaginarios1[i][j]);
            printf("      ");
        }
    }
    printf("\n縀sta es tu matriz? (s/n):\n");
    scanf(" %c", &ans);
    }while(ans!='s');

    //Segunda matriz
    //Reales
    do
    {
    printf("Ingresa las partes reales de la segunda matriz:\n");
    for (int i=0;i<filas2;i++)
    {
        for (int j=0;j<columnas2;j++)
        {
            printf("Ingresa el valor para b[%d][%d]: ",i+1,j+1);
            scanf("%f",&reales2[i][j]);
        }
    }

    //Imaginarios
    printf("Ingresa las partes imaginarias de la segunda matriz (sin i):\n");
    for (int i=0;i<filas2;i++)
    {
        for (int j=0;j<columnas2;j++)
        {
            printf("Ingresa el valor para b[%d][%d]: ",i+1,j+1);
            scanf("%f",&imaginarios2[i][j]);
        }
    }

    //Impresi髇 de matriz
    for (int i=0;i<filas2;i++)
    {
        printf("\n");
        for (int j=0;j<columnas2;j++)
        {
            //　　　　　　　　　　FALTA IMPRESI覰 PERFECTA DE N贛EROS COMPLEJOS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

            printf("%.3f %.3f i",reales2[i][j],imaginarios2[i][j]);
            printf("      ");
        }
    }
    printf("\n縀sta es tu matriz? (s/n):\n");
    scanf(" %c", &ans);
    }while(ans!='s');

    //Declaraci髇 de arreglos resultantes
    float reales_cuadrados[filas1][columnas2];
    float reales1_imaginarios2[filas1][columnas2];
    float reales2_imaginarios1[filas1][columnas2];
    float imaginarios_cuadrados[filas1][columnas2];

    float reales_final[filas1][columnas2];
    float imaginarios_final[filas1][columnas2];

    /*
    Operaciones que van a suceder
    reales_cuadrados + (-1 * imaginarios_cuadrados) = reales_final
    reales1_imaginarios2 + reales2_imaginarios1 = imaginarios_final
    */

    float suma=0;

    //Multiplicaciones
    //reales1 * reales2
    for(int i=0;i<filas1;i++)
    {
        for(int j=0;j<columnas2;j++)
        {
            suma=0;
            for(int k=0;k<columnas1;k++)
            {
                suma+=reales1[i][k]*reales2[k][j];
            }
            reales_cuadrados[i][j]=suma;
        }
    }

    //Reales1 * Imaginarios2
    for(int i=0;i<filas1;i++)
    {
        for(int j=0;j<columnas2;j++)
        {
            suma=0;
            for(int k=0;k<columnas1;k++)
            {
                suma+=reales1[i][k]*imaginarios2[k][j];
            }
            reales1_imaginarios2[i][j]=suma;
        }
    }

    //imaginarios1 * reales2
    for(int i=0;i<filas1;i++)
    {
        for(int j=0;j<columnas2;j++)
        {
            suma=0;
            for(int k=0;k<columnas1;k++)
            {
                suma+=imaginarios1[i][k]*reales2[k][j];
            }
            reales2_imaginarios1[i][j]=suma;
        }
    }

    //imaginarios1 * imaginarios2
    for(int i=0;i<filas1;i++)
    {
        for(int j=0;j<columnas2;j++)
        {
            suma=0;
            for(int k=0;k<columnas1;k++)
            {
                suma+=imaginarios1[i][k]*imaginarios2[k][j];
            }
            imaginarios_cuadrados[i][j]=suma;
        }
    }

    //Sumas
    //reales finales
     for(int i=0;i<filas1;i++)
    {
        for(int j=0;j<columnas2;j++)
        {
            reales_final[i][j]=reales_cuadrados[i][j]+(-1*imaginarios_cuadrados[i][j]);
        }
    }

    //imaginarios finales
    for(int i=0;i<filas1;i++)
    {
        for(int j=0;j<columnas2;j++)
        {
            imaginarios_final[i][j]=reales1_imaginarios2[i][j]+reales2_imaginarios1[i][j];
        }
    }

    printf("La matriz resultante es:\n");
    for(int i=0;i<filas1;i++)
    {
        printf("\n");
        for(int j=0;j<columnas2;j++)
        {
            printf("%.3f %.3f",reales_final[i][j],imaginarios_final[i][j]);
            printf("     ");
        }
    }
    return 0;
}
