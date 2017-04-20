#include <string.h>
// because we need to use the built-in function strcmp(), which is in string.h header file
#include "../y.tab.h" //
// '..' indicates that y.tab.h is in the parent directory. 
//We need to include y.tab.h  because we want to include "number" from the y.tab.h

extern int strcmp(const char*,const char*); 

extern char Data_Type[50];
// 'extern' means that 'Data_Type[50]' is actually declared in another file (langFunctions.h)


/*
  This function checks if the data type "givenDatatype", which is passed in as the parameter, is the data type of the identifier (from the yacc file). 
  if valid, return 1, 
  if invalid, return 0
*/
int isValidAssignment(char* givenDatatype){
    int i=0;

    if(strcmp(givenDatatype,Data_Type) != 0){
        return 0;
    }
    return 1;
}

/*
  This function converts INTEGER to ASCII
  The equivalent ascii value of "number" is stored in the character array "buffer" and is returned .
  snprintf() accomplishes this task
*/
char* itoa(int number){
   static char buffer[33];
  snprintf(buffer, sizeof(buffer), "%d", number);
  return buffer;
}



/*
  This function converts FLOATING POINT NUMBER to ASCII
  The equivalent ascii value of "number" is stored in the character array "buffer" and is returned .
  snprintf() accomplishes this task
*/
char* ftoa(float number){
   static char buffer[33];
  snprintf(buffer, sizeof(buffer), "%f", number);
  return buffer;
}


/*
  This function converts CHARACTER to ASCII
  The equivalent ascii value of "number" is stored in the character array "buffer" and is returned .
  snprintf() accomplishes this task
*/
char* ctoa(char number){
  static char buffer[33];
  snprintf(buffer, sizeof(buffer), "%c", number);
  return buffer;
}

