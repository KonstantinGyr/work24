#include <iostream>
#include <map>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>

int dayYear(int day,int mon,int year){  //день сначала года
    int dayY=0;
    for(int i=0;i<mon;i++){
        if(i==1&&year%4==0)dayY+=29;
        else if(i==1&&year%4!=0) dayY+=28;
        else if(i==3||i==5||i==8||i==10) dayY+=30;
        else dayY+=31;
    }
    return (dayY+day)-1;
}
int main() {
    std::string name;
    std::string dt;
    std::time_t t= time(nullptr);
    struct std::tm data=*std::localtime(&t);
    int yearNow=2022;                       //текущий год
    std::map<std::string ,std::tm>birthFriends;
    std::pair<std::string,std::tm>dayFriend;
    while (name!="end"){
        std::cout<<"Enter name your friend: ";
        std::cin>>name;
        if(name=="end")break;
        dayFriend.first=name;
        std::cout<<"Enter birthday your friend (yyyy-mm-dd): ";
        std::cin>>std::get_time(&data,"%Y-%m-%d");
        data.tm_yday= dayYear(data.tm_mday,data.tm_mon,yearNow);
       // std::cout<<std::put_time(&data,"%F")<<" "<<data.tm_yday<<std::endl;//проверял ввод
        dayFriend.second= data;
        birthFriends.insert(dayFriend);
    }
    int min=365;
    t= time(nullptr);
    std::tm local=*std::localtime(&t);
    std::vector<std::string>names;
    for(const auto &elem:birthFriends){

        dayFriend=elem;
        std::tm day=dayFriend.second;
        if(day.tm_yday<local.tm_yday)continue;
        else if(day.tm_yday==local.tm_yday){
            std::cout<<"Today is the birthday of "<<dayFriend.first;
        }
        else if(day.tm_yday-local.tm_yday==min) {
                names.push_back(dayFriend.first);
        }
        else if(day.tm_yday-local.tm_yday<min){
            min = day.tm_yday-local.tm_yday;
            names.clear();
            names.push_back(dayFriend.first);
        }
    }
    for(int i=0;i<names.size();i++){
       // dayFriend=birthFriends.find(names[i]);//почему паре не могу присвоить значение find(names[i])
        auto it=birthFriends.find(names[i]);    //это же тоже пара
        std::cout <<names[i]<<" birthday: "<<it->second.tm_mday<<" / "<<it->second.tm_mon+1<< std::endl;
    }
    return 0;
}
