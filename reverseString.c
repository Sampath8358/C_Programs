#include<stdio.h>

void reversestring(char* s)
{
// *s = start of the string
// *e = end of the string 
  char temp;
  char *e = s;
  
  while(*s)
  {
  	s++;
  }
  s--;
   
  while(e<s)
 {
  temp = *e;
  *e = *s;
  *s = temp;
  
  e++;
  s--; 
}
}

int main()
{
  char mystring[] = "Atharva Kadam";
  printf("String before reverse %s \n",mystring);
  
  reversestring(mystring);
  printf("\nthe reverse string is %s ",mystring);
	return 0;
}
