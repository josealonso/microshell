/************************************************/
/*              MSH.C: main module              */
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

while (1)       /* The program is an infinite loop */
  { 
   printf ("\n$>");

   fflush (stdin);
   fflush (stdout);
   pc = (fgets (cadena, NUM, stdin));   
   i = strlen (cadena);
   cadena[i-1] = ('\0');

   if ( strlen (cadena) == 0)        /* in case there is no input from the keyboard */
     continue;   

param = separaParametros (cadena, &f_entrada, &f_salida, &segundo_plano);     /* Jump to the module "parser.c" */

   /*************** Built-in EXIT command ***************/
   if (strcmp (param[0],"exit") == 0)   
     {
     printf ("\n\t END OF THE MICRO-SHELL\n\n");
     return(-1);  
     }

   /*************** Built-in PWD command ****************/
   else if (strcmp (param[0],"pwd") == 0) 
     {
     getcwd (camino, NUM);
     printf ("%s",camino); 
              // printf ("\nPrueba2, despues de free\n");
     }

   /*************** Built-in CD command *****************/
   else if (strcmp (param[0],"cd") == 0)   
     {
     if (param[1] == NULL)
       chdir (getenv ("HOME"));
     else  
       if  (chdir (param [1]) == -1)
           {
            printf ("\n%s",strerror (errno));
            //exit (-1);
           } 
       else   
       chdir (param[1]); 
     }                           




   /****************  EXTERNAL COMMANDS ***************/

   else
   {

   switch (pid = fork())
     {
     case -1:    /* se produce un error al crear el proceso */
       printf ("\n%s",strerror (errno));
     break;

/************************ CHILD PROCESS *************************/
     case 0:
     
                /* Output Redirection*/
        if (f_salida != NULL)
         {
           if  ((fd = creat (f_salida, 666)) == -1)
           {
            printf ("\n%s",strerror (errno));
            exit (-1);
           } 
         close (1);       /* the standard output is closed */
         dup (fd);        /* le asigno un 1 al descriptor del fichero */
         close (fd);
         }                       

                /* Input Redirection*/
        if (f_entrada != NULL)
         {
         if  ((fd = open (f_entrada, O_RDONLY)) == -1)
           {
            printf ("\n%s",strerror (errno));
            exit (-1);
           } 

         close (0);      /* the standard input is closed */
         dup (fd);       /* le asigno un 0 al descriptor del fichero */
         close (fd);
         }                           

       execvp (param[0], param);      /* The external command is executed */
       printf ("\nUNKNOWN COMMAND \nPlease, enter a valid command");
       exit (0);    /* Al ejecutar exit, el proceso hijo termina. */ 
       
/************************ PARENT PROCESS *************************/
     default:
                /* Execution in the background */
       if ( !segundo_plano )
         wait (&statusp);
  
     }   /* End of "switch" */   
   }   /* End of "else" */
  }  /* End of "while" */
}     


