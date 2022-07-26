#include "str.h"
enum {Male, Female};

struct HUMAN{
    char name[20];
    int age;
    int gender;
};

struct HUMAN create_human(char *name, int age, int gender){
    struct HUMAN human;

    human.age = age;
    human.gender = gender;
    copy_str(human.name, name);

    return human;
}

int print_human(struct HUMAN *human){
    printf("name : %s\n", human->name);
    printf("age : %d / gender : ", human->age);
    if (human->gender == Male) printf("Male\n");
    else if (human->gender == Female) printf("Female\n");

    return 0;
}