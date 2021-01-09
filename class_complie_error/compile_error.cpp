//
// Created by Lee Jung Ki on 2021/01/09.
//

#include <iostream>
#include <string>
#include <utility>

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

//typedef struct Animal {
//    char name[30];  // 이름
//    int age;        // 나이
//
//    int health;  // 체력
//    int food;    // 배부른 정도
//    int clean;   // 깨끗한 정도
//} Animal;

class animal {
public:
    std::string name;  // 이름
    int age;        // 나이

    int health;  // 체력
    int food;    // 배부른 정도
    int clean;   // 깨끗한 정도


    animal();

    animal(std::string input_name, int input_age, int input_health, int input_food, int input_clean) {
        name=std::move(input_name);
        age=input_age;
        health=input_health;
        food=input_food;
        clean=input_clean;
    }
};

animal * create_animal() {
    std::string _name;
    std::cout << "동물의 이름? ";
    std::cin >> _name;

    std::cout << "동물의 나이? ";
    int _age;
    std::cin >> _age;

    return new animal(_name, _age, 100, 100, 100);
}

void play(animal *animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}
void one_day_pass(animal *animal) {
    // 하루가 지나면
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}
void show_stat(animal *animal) {
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력    : " << animal->health << std::endl;
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결    : " << animal->clean << std::endl;
}
int main() {
    int animal_num = 0;
    animal *local_animal[10];

    for (;;) {
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기 " << std::endl;
        std::cout << "3. 상태 보기 " << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;
            case 1:
                local_animal[animal_num] = create_animal();
//                create_animal(list[animal_num], local_animal[animal_num]);

                animal_num++;
                break;
            case 2:
                std::cout << "누구랑 놀게? : ";
                std::cin >> play_with;

                if (play_with < animal_num) play(local_animal[play_with]);

                break;

            case 3:
                std::cout << "누구껄 보게? : ";
                std::cin >> play_with;
                if (play_with < animal_num) show_stat(local_animal[play_with]);
                break;
        }

        for (int i = 0; i != animal_num; i++) {
            one_day_pass(local_animal[i]);
        }
    }
    for (int i = 0; i != animal_num; i++) {
        delete local_animal[i];
    }
}