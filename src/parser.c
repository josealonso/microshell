/*************************************************
**       PARSER.C: breaks the line into tokens
*************************************************/

#include "parser.h"

char **separaParametros (char *linea, char **ficheroEntrada, char **ficheroSalida, int  *ejecucionSumergida)
{

static char *param[255];
//char *tok;
int ntok=0;

*ficheroEntrada      = NULL;
*ficheroSalida       = NULL;
*ejecucionSumergida = 0;

if ((param[ntok] = strtok (linea, DELIMITADOR)) != NULL) {
   ntok++;
   while ((param[ntok]=strtok ((char *)NULL, DELIMITADOR)) != NULL) {
      if (strcmp (param[ntok], "&") == 0) 
         *ejecucionSumergida = 1;
      else
         if (strcmp (param[ntok], "<") == 0)
            *ficheroEntrada = strtok ((char *)NULL, DELIMITADOR);
         else
            if (strcmp (param[ntok], ">") == 0)
               *ficheroSalida = strtok ((char *)NULL, DELIMITADOR);
            else
               ntok++;
     } /* while */
  } /* if */ 

  return (param);

} /* End of separaParametros */

