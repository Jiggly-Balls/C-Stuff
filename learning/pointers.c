/*
A simple task to create a "Person" struct while creating an 
array of it and define every persons attributes from the user
*/

#include <stdio.h>


struct Person {
    char name[64];
    int age;
};

int main() {
    struct Person persons[5];
    struct Person* p_person = persons;
    struct Person* p_person_begin = p_person;

    int persons_size = sizeof(persons) / sizeof(struct Person);

    for (int i = 0; i < persons_size; ++i) {
        printf("\nEnter the name of the number %d person: ", i);
        scanf("%s", &(p_person->name));
        printf("Enter the age of the number %d person: ", i);
        scanf("%d", &(p_person->age));

        ++p_person;
    }

    p_person = p_person_begin;

    for (int i = 0; i < persons_size; ++i) {
        printf("\n\nName of number %d person is: %s", i, p_person->name);
        printf("\nAge of the number %d person is: %d", i, p_person->age);

        ++p_person;
    }

    return 0;
}