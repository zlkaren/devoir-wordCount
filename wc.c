#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wc_c(FILE * fichier )
{
		int c=0;
		
		while ( fgetc (fichier) != EOF)
		{
				c++;
		}
		rewind(fichier);
		return(c);
}

int wc_w(FILE * fichier)
{
	int w = 0;
	char a [100000];
	while(fscanf(fichier, "%s", a ) == 1)
	{
		w++;
	}
	rewind(fichier);
	return (w);
}

int wc_l(FILE * fichier)
{
	int l=0;
	char a [100000];

		while(fgets (a , sizeof(a) ,  fichier) != NULL)
		{
			l++;
		}
	rewind(fichier);	
	return (l);
}
int wc_a(FILE * fichier)
{
		int a=0;
		int b;
		int max = 0;
		while ( (b = fgetc (fichier)) != EOF)
		{
			 if ( b == '\n')
			 {
				 if ( a > max)
					{
							max = a;
					}
					a = 0;
			}
			else
			{
					a++;
			}
		}		
		return (max);
}
void options (char * nomFichier , char * a)
{
	FILE * fichier = fopen (nomFichier, "r");
		if ( fichier  == NULL)
		{
				printf ("eroor!!!");
				exit (1);
		}
		else
		{
				if(strcmp (a , "-c")  == 0 || strcmp (a, "--bytes") == 0 || strcmp (a, "-m") == 0 || strcmp (a, "--chars") == 0)
				{
						printf("%d %s\n", wc_c(fichier ), nomFichier);
				}
				else if(strcmp (a , "-w") == 0|| strcmp (a, "--words") == 0 )
				{
					printf("%d %s\n", wc_w(fichier ), nomFichier);
					
				}
				else if (strcmp (a , "-l") == 0 || strcmp (a, "--lines") == 0)
				{
					printf("%d %s\n", wc_l(fichier ), nomFichier);
				}
				else if (strcmp(a, "-L") == 0  || strcmp (a , "--max-line-length") == 0 )
				{
					printf("%d %s\n", wc_a(fichier), nomFichier);
				}
		}
		fclose(fichier);

}
void wc(char * nomFichier )
{
		FILE * fichier = NULL;
		fichier = fopen (nomFichier , "r");
		if (fichier == NULL)
		{
				 printf ("error!!!");
				 exit(1);
		}
		else 
		{
				printf("%d ", wc_l(fichier ));
				printf("%d ", wc_w(fichier ));
				printf("%d  ", wc_c(fichier ));
				printf("%s\n", nomFichier);
				
		}
}
