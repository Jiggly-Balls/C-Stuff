/*
A simple task to create a "Person" struct while creating an 
array of it and define every persons attributes from the user
*/


/*
Notes-

type* ptr_var = &var;
    This creates a "ptr_var" pointer to a variable called "var".
    When using structs, "type" should be the same as the struct
    used in the variable we're referencing.

    We ues "&" to obtain the memory location of the var, if we
    don't use it, it will reference the actual value of the 
    variable which defeats the purpose of the pointer.

*ptr_var
    When we use this specific syntax, (without any types) it's
    called dereferencing the pointer which gets us the actual
    value on that memory which the pointer is pointing to.

*/

#include <stdio.h>


struct Person {
    char name[64];
    int age;
};

void simple_pointer();
void person_handler();

int main() {
    simple_pointer();

    return 0;
}

void simple_pointer() {
    int x = 3;
    int* ptr_x = &x;  // Creating a pointer reference to x

    printf("%d", *ptr_x);  // Dereferencing "ptr_x" to get it's actual value

}

void person_handler(){
    struct Person persons[5];
    struct Person* p_person = persons;
    struct Person* p_person_begin = p_person; // Store the starting value of the pointer

    int persons_size = sizeof(persons) / sizeof(struct Person);

    for (int i = 0; i < persons_size; ++i) {
        printf("\nEnter the name of the number %d person: ", i);
        scanf("%s", &(p_person->name));  // Accessing and assigning name attribute of each struct in the array
        printf("Enter the age of the number %d person: ", i);
        scanf("%d", &(p_person->age));

        ++p_person;  // Going to the next element of the array pointer
    }

    p_person = p_person_begin;  // Resetting the array pointer

    for (int i = 0; i < persons_size; ++i) {
        printf("\n\nName of number %d person is: %s", i, p_person->name);
        printf("\nAge of the number %d person is: %d", i, p_person->age);

        ++p_person;
    }
}