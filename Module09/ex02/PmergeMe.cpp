

#include "PmergeMe.hpp"

int convertString(std::string str){
    

    std::stringstream ss(str);
    std::string s;
    int value;
    ss >> value;
    ss >> s;

    if (!ss.eof()|| !s.empty() )
        throw std::runtime_error("< Error Incorrect Arguments..!  < " + str + " > > ");
    else 
        return value;
}
void printDebug(single v){
    single::iterator it  = v.begin();
    while(it != v.end()){
        printf("-> %d\n",*it);
        it++;
    }
    printf("\n-----------------\n");
}
void printDouble(doubleV v){
    doubleV::iterator it = v.begin();
    while(it != v.end()){
        printf("this is first -> %d -- seconde %d\n", it->first, it->second);
        it++;
    }
}
void pushValue(int node1, int node2, PmergeMe &obj){

    if (node1 < node2)
        obj.V2.push_back(std::make_pair(node1, node2));
    else
        obj.V2.push_back(std::make_pair(node2, node1));
    
    
}

void CreateDoubleVector(PmergeMe &obj){
    if (obj.V1.size() % 2 == 1){
        obj.upairedValue = obj.V1.back();
        obj.V1.erase(obj.V1.end() - 1 , obj.V1.end());
         printDebug(obj.V1);
    }
    for(size_t i = 0;  (i + 1) < obj.V1.size(); i+=2){
        pushValue(obj.V1[i], obj.V1[i + 1], obj);
    }
}

void parsing(int ac, char *av[], PmergeMe &obj){
    
    obj.upairedValue = -1;
    int local;
    if (ac < 2)
        throw std::runtime_error("< Error incorrect arguments...! >");
    else{
        for(int i = 1; i < ac; i++){
          local =  convertString(av[i]);
          if (local < 0)
            throw std::runtime_error("< Error incorrect arguments negative...! >");
            else    
                obj.V1.push_back(local);
        }
        printDebug(obj.V1);
       CreateDoubleVector(obj);
       printDouble(obj.V2);
    }
}