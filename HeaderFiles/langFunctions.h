#include <stdlib.h>
#include <string.h>

char Data_Type[50];

int noOfIdentifiers = 0;

struct IdentifierStructure
{
    char*   value;
    char*   data_type;
}identifiers[20];

char* IdentifierArray[20]; //Not using this anywhere. :/
extern int yylineno;
extern char* yytext; //Not using this anywhere. :/

//For development only
void showIdentifiers(){
    int i;
    for(i=0;i<noOfIdentifiers;i++){
        printf("%s\n",identifiers[i].value);
    }
}

void clearBuffers(){
    int i=0;
    while(Data_Type[i] != '\0'){
        Data_Type[i] = '\0';
        i++;
    }
}

void storeDataType(char* data_type){
    int i=0;
    while(data_type[i] != '\0'){
        Data_Type[i] = data_type[i];
        i++;
    }
}

char* retrieveDataType(){
    return Data_Type;
}

int isDuplicate(char* identifier,char* identifier_data_type){
    int i;
    for(i=0;i<noOfIdentifiers;i++){
        if(strcmp(identifier,identifiers[i].value) == 0){
            return 1;
        }
    }
    return 0;
}

/*
Function to extract the identifier name from the array.
e.g. This function extracts "a" from "a[50][69]"
*/

char* extractIdentifier(char* arrayIdentifier){
    char extractedIdentifier[50];
    static char copied[50];

    int i=0;

    while(arrayIdentifier[i] != '['){
        extractedIdentifier[i] = arrayIdentifier[i];
        i++;
    }
    extractedIdentifier[i] = '\0';

    i=0;
    while(extractedIdentifier[i] != '\0'){
        copied[i] = extractedIdentifier[i];
        i++;
    }
    copied[i] = '\0';
    return copied;
    
}

// to store all identifiers and check for duplicates
void storeIdentifier(char* identifier, char* identifier_data_type){
    identifiers[noOfIdentifiers].value = identifier;
    identifiers[noOfIdentifiers].data_type = identifier_data_type;
    noOfIdentifiers++;
}

void AssignmentError(char* data_type){
    printf("\nERROR ON LINE %d : \nInvalid assignment! Expected '%s', but found %s \n",yylineno,Data_Type, data_type);
    exit(0);
}

void DuplicateIdentifierError(char* identifier){
    printf("\nERROR ON LINE %d : \nDuplicate identifier '%s' found.\n",yylineno,identifier);
    exit(0);
}

