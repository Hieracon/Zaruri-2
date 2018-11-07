#include "zaruri.h"

int main()
{
    int choice;

    srand(time(0));

    cout<<"Press 1 for Dices./nPress 2 for Votes.";
    cin>>choice;

    Dices obj;
    Votes obj_2;

    if(choice == 1){
        obj.nr_apparition();
        obj.min_max();
        obj.display_result();
    }
    else{
        obj.nr_apparition();
        obj_2.top_2();
        if(obj_2.top[0] == 1){
            obj.nr_apparition();
            obj_2.round_2();
        }
        else{
            cout<<"A castigat "<<obj_2.top[1]<<endl;
        }
    }

    return 0;
}
