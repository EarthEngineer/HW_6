/*
    � ���� ��������� �� ��������� ������ �� ����� actors.csv � ������ �������� ���� Actor.

    ��������� Actor ������� �� ��������� �����:

        1)  name        - ��� �����
        2)  surname     - ������� �����
        3)  gender      - ���, 0 - �������, 1 - �������
        4)  height      - ������ ����� � �����������
        5)  birth_date  - ���� ��������, ���������, ������� ������� �� ��� ����� ���� int
        6)  birth_address - ����� ��������, ���������, ������� ������� �� ��� ����� - �����.


    � ����� actors.csv ���������� ���������� � 2000 ������. ��� ������ 6 ����� ����� �����:

        2000
        Abel,Garifullin,0,189,16/2/1992,Russia,Rostovskaya Oblast,Rostov-na-Donu
        Viktor,Shchyotkin,0,162,28/6/1992,Russia,Samarskaya Oblast,Samara
        Sophia,Sigayeva,1,148,30/1/1963,Russia,Kurskaya Oblast,Zheleznogorsk
        Vlada,Solodnikova,1,163,16/7/2004,Russia,Sverdlovskaya Oblast,Polevskoy
        Luca,Tyomkin,0,173,16/5/1958,Russia,Sankt-Peterburg,Saint Petersburg


    ���� �������� ��������� �������:

    read_actors_from_file:

        ����� ������� ���� ���� � ������ �������� ���� Actor ���� �������� ������� read_actors_from_file.
        ��� ������� ��������� �� ���� �������� ����� � ��������� �� ������ ������� ������� ��������.
        ��� ���� ���������������, ��� ������ ���������� �������, ����� ��������� ���� ������ �� �����.
        ������� read_actors_from_file ��������� ���� ������ �� ����� � ������ � ���������� ���������� ��������� ������.


    print_actor:

        ��� ������� �������� ���������� �� ����� ������. �� ���� ��� ���������:

        1)  ����� stream. ��� ����� ���� �������� �����, ��������� � ������� fopen, ���� ��� ����� ���� stdout.
            ���� ��� stdout, �� ������� ���������� �� �� � ����, � �� �����.

        2)  ����������� ��������� �� ��������� Actor. ��������� �� ���� �����, �������� ����� ����������.


    print_all_actors_by_birth_year

        �������� �� ����� ���� ������ � ������ ����� ��������.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
    int day, month, year;
};
typedef struct date Date;


struct address
{
    char country[12];
    char region[52];
    char city[32];
};
typedef struct address Address;


struct actor
{
    char name[32];
    char surname[32];
    int gender;
    int height;
    Date birth_date;
    Address birth_address;
};
typedef struct actor Actor;

void print_actor(FILE* stream, const Actor* a);

int read_actors_from_file(const char* filename, Actor* actors)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }
    int number_of_actors;
    fscanf(fin, "%i", &number_of_actors);

    for (int i = 0; i < number_of_actors; ++i)
    {
        fscanf(fin, "%[^,],%[^,],%i,%i,%i/%i/%i,%[^,],%[^,],%[^\n]\n",
            actors[i].name, actors[i].surname, &actors[i].gender, &actors[i].height,
            &actors[i].birth_date.day, &actors[i].birth_date.month, &actors[i].birth_date.year,
            actors[i].birth_address.country, actors[i].birth_address.region, actors[i].birth_address.city);

    }
    fclose(fin);
    return number_of_actors;
}


void print_actor(FILE* stream, const Actor* a)
{
    fprintf(stream, "%12s %15s. Height: %i cm. Birth date: %02i/%02i/%i. Birth Address: %s, %s, %s\n", a->name, a->surname,
           a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year,
           a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

void print_all_actors_by_birth_year(const Actor* actors, int number_of_actors, int year)
{
    for (int i = 0; i < number_of_actors; ++i)
    {
        if (actors[i].birth_date.year == year)
            print_actor(stdout, actors + i);
    }
}


void print_all_actors_by_height(const Actor* actors, int number_of_actors, int height)
{
    for (int i = 0; i < number_of_actors; ++i) {

        if (actors[i].height == height)
            print_actor(stdout, actors + i);
    }
}


void print_all_actors_by_city(const Actor* actors, int number_of_actors, char city[])
{
    for (int i = 0; i < number_of_actors; ++i) {

       if (strcmp(actors[i].birth_address.city, city) == 0)
            print_actor(stdout, actors + i);
    }
}




int main()
{
    Actor actors[2000];

    // ��������� ������ (�������, ����� �� ���� �� ������ 2000)
    int number_of_actors = read_actors_from_file("actors.csv", actors);
    print_all_actors_by_birth_year(actors, number_of_actors, 1981);

    print_all_actors_by_height(actors, number_of_actors, 173);
	print_all_actors_by_city(actors, number_of_actors, "Saratov");



    printf("Size of array = %zu byte\n", sizeof(actors));
}
