/* code developed by Naveen Auvusali
In this code u can observe arrays ,pointers ,strings, array of pointers ,walking pointers.
and char to int conversion using atoi,char to float conversion using atof .
string type of input is converting into ints ,floats , strings .*/
/* any one can use this code and make chenges ,if possible optimise it..*/
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

# define MAX 1000
int getlin(char line[],int lim);
main()
{
	int i = 0, j = 0 ,k = 0,c,x=0,y=0,z=0,count=0;
	int n_words = 0,l = 0,c1 = 0;
	char line[MAX];
	char *p,*q,*temp,*temp1;
	char *arr[MAX];
	char *ptr_ints[MAX];
	char *ptr_chars[MAX];
	char *ptr_floats[MAX];
	int *int_arr;
	double *flt_arr;		
	/* reading line from file */
	while (getlin( line, MAX))
         /* each line is converting in to words based on spaces */
 		for( p = line; *p != EOF ; p++, j++)
		{
			if (*p == ' '  || *p == '\n')
			{ 
				*p = '\0';
				 
				arr[n_words] = p-j;     /* words are copying to array of pointers*/
				j = 0;
				p++;
				n_words++;
			}
		}
			/* this is our input after converting nto words*/
		printf(" your input is from array of pointers ...\n"); 
		for( i = 0; i< n_words;i++){
		temp1 = arr[i];
		if ((isalpha(*temp1)) || (isdigit(*temp1))) 
		printf(" %s",arr[i]);
		}
			/* seperation of ints , floats ,strings */
	 	for (i = 0;i < n_words; i++)
		{
			temp = arr[i];
			if(isalpha(*temp))
			{
			ptr_chars[x] = arr[i];  /* strings are moved to  one array of pointers*/
			x++;
			}
			else
			{
				for( ;*temp != '\0';temp++)
				{
					if(*temp == '.')
					count++;			
				}
								
				if (count == 1 ){
				ptr_floats[y] = arr[i];  /* floats are moved to one array of pointers*/
				y++;
				count = 0;
				}	
				else if (count > 1){
					ptr_chars[x] = arr[i];  
					x++;
					count = 0;
				}
				else if(count == 0 && !isalpha(*temp)){
					ptr_ints[z] = arr[i];  /*ints are moved to one array of pointers*/
					z++;
				}
			}
		}
			/*converting string type of inputs into ints , floats using atoi,atof*/ 
		printf("\n");	
		printf("\n");	
		printf("---------------- -----------------\n");
		int_arr = (int *)malloc(z*sizeof(int));
		for ( i = 0 ;i < z; i++){
		int_arr[i] = atoi(ptr_ints[i]);  /*converted ints are moved to dynamic array of int type*/
		if(int_arr[i] > 0){
		c1++;
		}
		}
		printf("printing ints of array are :%d\n",c1);
		for ( i = 0 ;i < z; i++){
		if(int_arr[i] > 0) 
		printf(" %d",int_arr[i]);	
		}
		printf("\n");
		printf("\n");
		printf("---------------- -----------------\n");
		flt_arr = (double *)malloc(y*sizeof(double));
		printf("printings floats of array are :%d\n",y);
		for ( i = 0 ;i < y; i++){
		flt_arr[i] = atof(ptr_floats[i]); /*converted floats are moved to dynamic array of double type*/
		if(flt_arr[i])
		printf(" %lf",flt_arr[i]);	
		}
		printf("\n");
		printf("\n");
		printf("---------------- -----------------\n");
		printf("printing strings of array of ptr to char are:%d\n",x);
		for ( i = 0 ;i < x ;i++){
		printf(" %s",ptr_chars[i]); /*printing strings from array of pointers to char type*/
		}	
		printf("\n");
		printf("\n");
	}
int getlin( char line[],int lim)  /* getline function*/
{
	int c, i = 0;
	while(--lim>0&&(c = getchar())!= EOF && c != '\0')
	line[i++] = c;
	if ( c== '\n')
	line[i++] = c;
	return i;
}
