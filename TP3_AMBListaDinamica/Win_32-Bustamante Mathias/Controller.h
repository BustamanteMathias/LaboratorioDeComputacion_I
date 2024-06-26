#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputsGeneric.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int menuPrincipal(LinkedList*);
int subMenu();
int subMenuDoss();
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);
void controller_setAutoId(Employee* thisEmployee, LinkedList* listaEmpleados);


