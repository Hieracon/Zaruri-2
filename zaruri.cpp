#include "zaruri.h"

Dices::Dices(){
    min[1] = 800;
    min[2]=0;
    for(int iterator_1 = 1; iterator_1 <= 6; iterator_1++){
        for(int iterator_2 = 1; iterator_2 <= 6; iterator_2++){
                apparition[iterator_1][iterator_2] = 0;
        }
    }
}

void Dices::nr_apparition(){
    Dices obj;
    for(int iterator = 1; iterator <= 9000; iterator ++){
        dice_1 = obj.dice_roll();
        dice_2 = obj.dice_roll();

        frecventa[dice_1]++;
        frecventa[dice_2]++;

        if(dice_1 > dice_2){
            temp_1 = dice_1;
            dice_1 = dice_2;
            dice_2 = temp_1;
        }

        apparition[dice_1][dice_2]++;

        temp = dice_1*10 + dice_2;

        if(consecutiv[2] == temp){
            consecutiv[1]++;
        }
        else{
            if(consecutiv[1] >= consecutiv_max[1]){
                consecutiv_max[1] = consecutiv[1];
                consecutiv_max[2] = consecutiv[2];
            }
            consecutiv[1] = 1;
            consecutiv[2] = temp;
        }
    }
}

int Dices::dice_roll(){
    int tmp = rand()%6+1;
    return tmp;
}

void Dices::min_max(){
    for(int iterator_1 = 1; iterator_1 <= 6; iterator_1++){
        for(int iterator_2 = 1; iterator_2 <= 6; iterator_2++){
            if(apparition[iterator_1][iterator_2] >= max[1]){
                max[1] = apparition[iterator_1][iterator_2];
                max[2] = iterator_1 * 10 + iterator_2;
            }
            if(apparition[iterator_1][iterator_2] <= min[1] && apparition[iterator_1][iterator_2] != 0){
                min[1] = apparition[iterator_1][iterator_2];
                min[2] = iterator_1 * 10 + iterator_2;
            }
        }
    }
}

void Dices::display_result(){
    for(int iterator_1 = 1; iterator_1 <= 6; iterator_1++){
        double result = frecventa[iterator_1] / 90;
        cout <<"Frecventa fetei "<<iterator_1<<" este "<<result<<"%"<<endl;
    }

    cout<<"Min este " << min[1]<<" "<<min[2]<<endl;
    cout<<"Max este " << max[1]<<" "<<max[2]<<endl;
    cout<<"Aparitii consecutive "<<consecutiv_max[1]<<" "<<consecutiv_max[2];
}

void Votes::top_2(){
    Dices obj;
    top[1] = obj.frecventa[1];
    top[2] = obj.frecventa[1];
    for(int iterator = 1; iterator <= 6; iterator++){
        if(obj.frecventa[iterator] > top[1]){
            if(top[1] > top[2]){
                top[2] = top[1];
            }
            top[1] = obj.frecventa[iterator];
        }
        else{
            if(obj.frecventa[iterator] > top[2]){
                top[2] = obj.frecventa[iterator];
            }
        }
    }
    if(top[1] < 4501){
        top[0] = 1;
    }
    else{
        top[0] = 0;
    }
}

void Votes::round_2(){
    Dices obj;
    if(obj.frecventa[top[1]] > obj.frecventa[top[2]]){
        cout<<"A castigat "<<top[1]<<endl;
    }
    else{
        cout<<"A castigat "<<top[2]<<endl;
    }
}
