#include "marks.h"

marks::marks()
{
    int i;

}
float marks::getMid1(){
    return mid1;
}
float marks::getMid2(){
    return mid2;
}
float marks::getSessionals(){
    return sessionals;
}
float marks::getFinal(){
    return final;
}
float marks::getTM(){
    return (mid1+mid2+sessionals+final);
}

void marks::setMid1(float mid1){
    this->mid1 = mid1;
}
void marks::setMid2(float mid2){
    this->mid2 = mid2;
}
void marks::setSessionls(float sess){
    sessionals = sess;

}
void marks::setFinal(float final){
    this->final = final;
}


