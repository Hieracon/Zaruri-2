#ifndef ZARURI_H_INCLUDED
#define ZARURI_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Dices{
    public:
        int consecutiv[3] = {0};
        int consecutiv_max[3] = {0};
        int frecventa[7] = {0};
        int apparition[7][7];
        int dice_1;
        int dice_2;
        int temp;
        int temp_1;
        int max[3] = {0};
        int min[3];

        Dices();

        int dice_roll();
        void nr_apparition();
        void min_max();
        void display_result();
};

class Votes{
    public:
        int top[3];

        void top_2();
        void round_2();
};

#endif // ZARURI_H_INCLUDED
