

#include "PmergeMe.hpp"
//  pair and return winners be shore that winner can insert abel 
//  recursion untill size equel tow check if value upaired put value number unpaired var 
//  when recursion reach base case return back with reucrsion  
//
//
//
//

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


std::vector<int> JacobsthalSequenec(int n){
    
    std::vector<int> v;
    if (n <= 0)
        return v;
    v.push_back(0);
    if (n == 1){
        
        return v;
    }   
    v.push_back(1);
    int i  = 2;
    while (i < n)
    {
        size_t val = v[i - 1]  + 2 * v[i - 2];
        v.push_back(val);
        i++;
    }
    return v;
}


void mergeInsertion(PmergeMe &obj, single v){

    if (obj.V1.size() <= 2)
        return;
    std::deque<int> losers;
    std::deque<int> winner;
    int unpaired ;
    int size = obj.V1.size() -1;
    if (obj.V1.size() % 2 != 0){
        unpaired = obj.V1[size];
        size--;
    }

    int i = 0;
    while (i < size)
    {
        if (obj.V1[i] > obj.V1[i + 1] ){
            winner.push_back(obj.V1[ i + 1]);
            losers.push_back(obj.V1[i]);
        }
        else{
           losers.push_back(obj.V1[ i + 1]);
            winner.push_back(obj.V1[i]);
        }
        i+=2;
    }
    mergeInsertion(obj, obj.V1);
    printf("unpaired Value %d \n", unpaired);
    printf("winner\n");
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
        //printDebug(obj.V1);
        mergeInsertion(obj, obj.V1);
        //CreateDoubleVector(obj);
    
    }
}