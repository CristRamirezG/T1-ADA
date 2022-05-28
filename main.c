#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <windows.h>
//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

void CrearArchivo(int n) {                                          //https://www.aprenderaprogramar.com/index.php?option=com_content&view=article&id=936:escribir-guardar-datos-en-ficheros-o-archivos-en-lenguaje-c-fputc-putc-fputs-fprintf-ejemplos-cu00537f&catid=82&Itemid=210

    int number = 0;
    char num[] = "12345678901234567890123456789012345678901234567890";
    FILE* fichero;
    fichero = fopen("NumbersFile.txt", "wt");
   
    while(n > 0){
        number = rand() % 20;
        n--;
        fputc(num[number], fichero);
        fputs(" ", fichero);
        
    }
    
    fclose(fichero);
    printf(" Proceso completado ");
}

int * leerArchivo ()
{
  FILE* file = fopen ("NumbersFile.txt", "r");
  int i = 0, n = 0;
  static int arr[10000000];

  fscanf (file, "%d", &i);    
  while (!feof (file))
    {  
        //printf ("%d ", i);
        arr[n]=i;
        n++;
        fscanf (file, "%d", &i);      
    }
  fclose (file);
  return arr;
}
void leerArray(int array[], int n){
    while(n>0){
        n--;
        printf("%d",array[n]);
    }
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
int * MetodoBurbuja(int arr[], int num){                            //https://www.simplilearn.com/tutorials/c-tutorial/c-program-for-bubble-sort

    int x, y, temp;    

    for(x = 0; x < num - 1; x++){       

        for(y = 0; y < num - x - 1; y++){          

            if(arr[y] > arr[y + 1]){               

                temp = arr[y];

                arr[y] = arr[y + 1];

                arr[y + 1] = temp;

            }

        }
    }
    return arr;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
void intercambiar(int *a, int *b) {                                 //https://parzibyte.me/blog/2020/05/16/ordenamiento-seleccion-c/
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

int * seleccion(int arreglo[], int longitud) {  
  for (int i = 0; i < longitud - 1; i++) {
    for (int j = i + 1; j < longitud; j++) {
     
      if (arreglo[i] > arreglo[j]) {
        intercambiar(&arreglo[i], &arreglo[j]);
      }
    }
  }
  return arreglo;
}
//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

int * InsercionDirecta(int lista[],int TAM){

    int temp,j;
    for (int i=1; i<TAM; i++){
    temp = lista[i];
    j = i - 1;
        while ( (lista[j] > temp) && (j >= 0) ){
            lista[j+1] = lista[j];
            j--;
        }
    lista[j+1] = temp;
    }
    return lista;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
int * shellsort(int arr[], int num)                                  //https://www.sanfoundry.com/c-program-implement-shell-sort/
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
    return arr;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

void swap(int* a, int* b)                                          //https://www.geeksforgeeks.org/iterative-quick-sort/
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
int * quickSortIterative(int arr[], int l, int h)
{
    
    int op = h - l + 1;
    int *stack;
    stack = (int*) malloc(op * sizeof(int));
    
    int top = -1;
 
    stack[++top] = l;
    stack[++top] = h;
    
    while (top >= 0) {
        
        h = stack[top--];
        l = stack[top--];
        
        int p = partition(arr, l, h);
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
     free(stack);
    return arr;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

int main()
{
    int nSwitch = 0;
    int *arr,num;
tag1:
    printf("\n-.-.-.-Seleccione un Metodo-.-.-.-.-\n1)Metodo Burbuja\n2)Metodo Seleccion\n3)Insercion Directa\n4)Metodo Shell\n5)Metodo Quicksort\n6)Crear Archivo de n numeros\n7)Salir\nSeleccion: ");
    scanf("%i",&nSwitch);
    switch(nSwitch){
        case 1:
        {

            //ClockFunction https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/#:~:text=To%20calculate%20time%20taken%20by,h.
            arr = leerArchivo();
            printf("Ingrese la cantidad de valores a ordenar:");
            scanf("%d",&num);
            clock_t t;
            t = clock();

            arr = MetodoBurbuja(arr,num);
            printf ("Primer numero: %d \n", arr[0]);
            printf ("Numero intermedio: %d \n", arr[num/2]);
            printf ("Ultimo numero: %d \n", arr[num-1]);

            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC; 
        
            printf("MetodoBurbuja() tomo %f segundos en ejecutarce \n", time_taken);
            system("PAUSE");
            printf("\n-.-.-Ultimos 1000 valores-.-.-.-\n");
            leerArray(arr,1000);
            printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
            goto tag1;
        }
        break;
        case 2:
        {
            arr = leerArchivo();
            printf("Ingrese la cantidad de valores a ordenar:");
            scanf("%d",&num);
            clock_t t;
            t = clock();
            arr = seleccion(arr,num);
            printf ("Primer numero: %d \n", arr[0]);
            printf ("Numero intermedio: %d \n", arr[num/2]);
            printf ("Ultimo numero: %d \n", arr[num-1]);

            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC; 
        
            printf("Metodo Seleccion() tomo %f segundos en ejecutarce \n", time_taken);
            system("PAUSE");
            printf("\n-.-.-Ultimos 1000 valores-.-.-.-\n");
            leerArray(arr,1000);
            printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
            
            goto tag1;
        }
        break;
        case 3:
        {
           arr = leerArchivo();
            printf("Ingrese la cantidad de valores a ordenar:");
            scanf("%d",&num);
            clock_t t;
            t = clock();
            arr = InsercionDirecta(arr,num);
            printf ("Primer numero: %d \n", arr[0]);
            printf ("Numero intermedio: %d \n", arr[num/2]);
            printf ("Ultimo numero: %d \n", arr[num-1]);

            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC; 
        
            printf("Metodo InsercionDirecta() tomo %f segundos en ejecutarce \n", time_taken);
            system("PAUSE");
            printf("\n-.-.-Ultimos 1000 valores-.-.-.-\n");
            leerArray(arr,1000);
            printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
            goto tag1;
        }
        break;
        case 4:
        {
            //Shell
            arr = leerArchivo();
            printf("Ingrese la cantidad de valores a ordenar:");
            scanf("%d",&num);
            clock_t t;
            t = clock();
            arr = shellsort(arr,num);
            printf ("Primer numero: %d \n", arr[0]);
            printf ("Numero intermedio: %d \n", arr[num/2]);
            printf ("Ultimo numero: %d \n", arr[num-1]);

            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC; 
        
            printf("Metodo shellsort() tomo %f segundos en ejecutarce \n", time_taken);
            system("PAUSE");
            printf("\n-.-.-Ultimos 1000 valores-.-.-.-\n");
            leerArray(arr,1000);
            printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
            goto tag1;
        }
        break;
        case 5:
        {
            //Quicksort
            arr = leerArchivo();
            printf("Ingrese la cantidad de valores a ordenar:");
            scanf("%d",&num);
            clock_t t;
            t = clock();
            arr = quickSortIterative(arr,0,num-1);

            printf ("Primer numero: %d \n", arr[0]);
            printf ("Numero intermedio: %d \n", arr[num/2]);
            printf ("Ultimo numero: %d \n", arr[num-1]);

            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC; 
        
            printf("Metodo quickSortIterative() tomo %f segundos en ejecutarce \n", time_taken);
            system("PAUSE");
            printf("\n-.-.-Ultimos 1000 valores-.-.-.-\n");
            leerArray(arr,1000);
            printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
            goto tag1;
        }
        break;
        
        case 6:
        {
            printf("Ingrese la cantidad de elementos dentro del archivo");
            scanf("%i",&nSwitch);
            CrearArchivo(nSwitch);
            printf("El archivo se creó correctamente con el nombre de NumbersFile.txt, es recomendable visualizarlo a través de un editor de texto...");
            goto tag1;
        }
        break;
        case 7:
        {
            
        }
        break;
        default:
        {
            printf("Seleccione un caso valido");
            goto tag1;
        }
        break;
    }
    return 0;
}


