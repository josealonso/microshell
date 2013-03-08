/************************************************/
/* MICROSH.C: módulo principal de la práctica 6 */
/************************************************/

#include "parser.h"

int main (int argc, char* argv[])
{

int i, pid;
char cadena[NUM];
char *pc = NULL;
char *f_entrada, *f_salida;
int segundo_plano;
char **param = NULL;
char camino[NUM];
//char *camino = NULL; No hace falta asignación dinámica de memoria
int statusp, fd;

system ("clear");

while (1)       /* El  programa es un bucle infinito */
  { 
   printf ("\n$>");

   fflush (stdin);
   fflush (stdout);
   pc = (fgets (cadena, NUM, stdin));   
   i = strlen (cadena);
   cadena[i-1] = ('\0');

   if ( strlen (cadena) == 0)        /* Por si no se teclea nada */
     continue;   

param = separaParametros (cadena, &f_entrada, &f_salida,&segundo_plano);                       /* Salta al módulo "parser.c" */

   /*************** Orden interna EXIT ***************/
   if (strcmp (param[0],"exit") == 0)   
     {
     printf ("\n\t FIN DE NUESTRO MICRO-INTÉRPRETE DE COMANDOS\n\n");
     return(-1);  
     }

   /*************** Orden interna PWD ****************/
   else if (strcmp (param[0],"pwd") == 0) 
     {
     getcwd (camino, NUM);
     printf ("%s",camino); 
     }

   /*************** Orden interna CD *****************/
   else if (strcmp (param[0],"cd") == 0)   
     {
     if (param[1] == NULL)
       chdir (getenv ("HOME"));
     else  
       if  (chdir (param [1]) == -1)
         printf ("\n%s",strerror (errno));
     }                           




   /**************** ÓRDENES EXTERNAS ***************/

   else
   {

   switch (pid = fork())
     {
     case -1:    /* se produce un error al crear el proceso */
       printf ("\n%s",strerror (errno));
     break;

/************************ PROCESO HIJO *************************/
     case 0:
     
                /* Redirección de salida*/
        if (f_salida != NULL)
         {
           if  ((fd = creat (f_salida,0666)) == -1)
           {
            printf ("\n%s",strerror (errno));
            exit (-1);
           } 
         close (1);       /* cierro la salida estándar ( descriptor nº1) */
         dup (fd);        /* le asigno un 1 al descriptor del fichero */
         close (fd);
         }                       

                /* Redirección de entrada*/
        if (f_entrada != NULL)
         {
         if  ((fd = open (f_entrada, O_RDONLY)) == -1)
           {
            printf ("\n%s",strerror (errno));
            exit (-1);
           } 

         close (0);      /* cierro la entrada estándar ( descriptor nº0) */
         dup (fd);       /* le asigno un 0 al descriptor del fichero */
         close (fd);
         }                           

       execvp (param[0], param);      /* Ejecución de la orden externa */
       printf ("\nORDEN INEXISTENTE\nVuelva a intentarlo");
       exit (0);    /* Al ejecutar exit, el proceso hijo termina. */ 
       
/************************ PROCESO PADRE *************************/
     default:
                /* Ejecución en segundo plano */
       if ( !segundo_plano )
         wait (&statusp);
  
     }   /* Llave del "switch" */   
   }   /* Llave del "else" */
  }  /* Fin del "while" */
}     


