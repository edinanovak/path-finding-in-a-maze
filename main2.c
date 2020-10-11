#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ni=0,nj=0,is=0,ie=0,js=0,je=0;
char m[301][301];

void ReadFile(char *path)
{
  FILE* f=fopen(path,"r");
  char line[300];

  if(f==NULL)
    {
      printf("File is empty!\n");
      exit(0);
    }

  fgets(line,301,f);
  printf("%s\n",line);
  strcpy(m[ni],line);
  nj=strlen(line);
  ni++;

  while(!feof(f))
    {
      fgets(line,301,f);
      printf("%s\n",line);
      strcpy(m[ni],line);
      ni++;
    }

  fclose(f);
  printf("%d %d\n",ni,nj);
}

void print_maze()
{
  int i,j;
  FILE * g=fopen("mazes.dat","w");
  for(i=0;i<ni;i++)
    {
      for(j=0;j<nj;j++)
	{
	  fprintf(g,"%c",m[i][j]);
	  printf("%c",m[i][j]);
	}
    }
}

void searchSE()
{
  while(m[is][js]!='S')
    {
      if(is<ni)
	{
	  if(js<nj)
	    {
	      js++;
	    }
	  if(js==nj)
	    {
	      js=0;
	      is++;
	    }
	}
    }
  printf("is=%d js=%d\n",is,js);

  m[is][js]=' ';

  while(m[ie][je]!='E')
    {
      if(ie<ni)
	{
	  if(je<nj)
	    {
	      je++;
	    }
	  if(je==nj)
	    {
	      je=0;
	      ie++;
	    }
	}
    }
  printf("ie=%d je=%d\n",ie,je);
  m[ie][je]=' ';
}

int maze(int x,int y)
{
  if(!(x>=0 && x<=ni) && !(y>=0 && y<nj))
    return 0;
  
  if(x==ie && y==je)
    {
      m[is][js]='S';
      m[x][y]='E';
      return 1;
    }
  
  if(m[x][y]!=' ')
    return 0;

  m[x][y]='.';
  
  if(maze(x-1,y))
    return 1;

  if(maze(x,y+1))
    return 1;

  if(maze(x+1,y))
    return 1;

  if(maze(x,y-1))
    return 1;

  m[x][y]='X';
  return 0;
}


int main(int argv,char **argc)
{
  if(argv<2)
    {
      printf("Incorrect input!!\n");
      exit(0);
    }

  ReadFile(argc[1]);
  
  searchSE();
  
  printf("is=%d js=%d\n",is,js);
 
  if(maze(is,js)==1)
    print_maze();
  else
    {
      printf("There is no path!\n");
    }
  
  return 0;
}
