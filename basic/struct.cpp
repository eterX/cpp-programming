// Copyright[2016] <Vex Woo>

#include <iostream>
#include <string>

struct people {
    std::string name;
    int age;
} bob, jack;


void print_info(people *p) {
    std::cout << "name " << p->name << "\n";
    std::cout << "age " << p->age << "\n";
}

int main(int argc, const char *argv[]) {
    people smith;
    people *smith_copy;

    bob.name = "bob";
    bob.age = 21;

    jack.name = "jack";
    jack.age = 22;

    smith.name = "smith";
    smith.age = 23;

    smith_copy = &smith;

    print_info(&bob);
    print_info(&jack);
    print_info(&smith);
    print_info(smith_copy);

    return 0;
}
