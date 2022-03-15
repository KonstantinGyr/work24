#include <iostream>
#include <ctime>
#include <iomanip>

void display(std::tm timer){
    int count=timer.tm_sec;
    for(int i=0;i<=timer.tm_min;i++){
        if(i!=0){
            count=59;
        }
        for(int j=0;j<=count;j++){
            std::time_t startT= std::time(nullptr);
            std::time_t nowT = std::time(nullptr);
            while (nowT==startT) {
                nowT = std::time(nullptr);
            }
            std::cout<<timer.tm_min-i<<" : "<<count-j<<std::endl;
        }
    }
}

int main() {
    std::time_t t=std::time(nullptr);
    std::tm timer=*std::localtime(&t);;
    std::cout << "Enter delay time: ";
    std::cin>>std::get_time(&timer,"%M:%S");
    //std::cout<<std::put_time(&timer,"%M:%S")<<std::endl;//проверка
    display(timer);
    std::cout<<"DING! DING! DING!";
    return 0;
}
