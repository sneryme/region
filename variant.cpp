#include "variant.h"


void enter(Vibor* Vibor1){

    switch(Vibor1->enum_variant){
    case (Enter::Reaed_ffile):
        Vibor1->check = Read_file(Vibor1);
        break;
    case (Enter::Sortt):
        Sort(Vibor1);
        break;
    default:
        break;
    }
}
