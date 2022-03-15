#include <iostream>
#include <ctime>
#include <map>
#include <string>

std::string convert(double t){//конвертируем время работы в string
    std::string time;
    int hours=(int)t/3600;
    int min=(int)t%3600/60;
    int sek=(int)t%60;
    time+=std::to_string(hours);
    time+=" hours ";
    time+=std::to_string(min);
    time+=" min. ";
    time+=std::to_string(sek);
    time+=" sek.";
    return time;
}
void saveTask(std::map<std::string,std::string>&taskMap, std::string &task, double d){
    std::pair<std::string,std::string>taskPair;
    taskPair.first=task;
    taskPair.second=convert(d);
    taskMap.insert(taskPair);
}

int main() {
    std::time_t startT=0;
    std::time_t finishT=0;
    std::string command;
    std::string task;
    std::map<std::string,std::string>taskMap;
    while (command!="exit"){
        std::cout << "Enter command: ";
        std::cin>>command;
        if(command=="begin"){
            std::cout << "Enter a task: ";
            if(startT!=0){
               finishT=std::time(nullptr);
                saveTask(taskMap, task, difftime(finishT, startT));
            }
            std::cin>>task;
            startT= std::time(nullptr);
        }
        else if(command=="end"){
            if(startT==0)continue;
            finishT=std::time(nullptr);
            saveTask(taskMap, task, difftime(finishT, startT));
            startT=0;
        }
        else if(command=="status"){
            for(const auto& elem:taskMap){
                std::cout<<"Task: "<<elem.first<<" Time: "<<elem.second<<std::endl;
            }
            if(startT!=0){
                std::cout<<"Task: "<<task<<" in progress."<<std::endl;
            }
        }
    }
    return 0;
}
