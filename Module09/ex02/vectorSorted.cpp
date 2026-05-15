
#include "PmergeMe.hpp"



void insertElement(std::vector<int> &v, int element){

    std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), element);
    v.insert(it, element);
}



void insertNelement(std::vector<int> &winner, std::vector<int>losers, int &insered , int indexJacob ){
   int tmp = 0; 
    while(indexJacob >= insered){
        insertElement(winner, losers[indexJacob]);
        tmp++;
        indexJacob--;
    }
    insered += tmp;
}
void inserLoserIntoWinner(std::vector<int> &winner, std::vector<int> &losers){
     const std::vector<int> &Jacob = JacobsthalSequenec(losers.size());
    
    int inserted = 0;
    int indexJacob  = 0;
    while(inserted < (int)losers.size()){
        if ((size_t) Jacob[indexJacob] < losers.size() ){
            insertNelement(winner, losers, inserted, Jacob[indexJacob]);

        }
        else if (inserted < (int)losers.size()){
            insertNelement(winner, losers, inserted, (losers.size() -1) );
            break;
        }
        indexJacob++;
    }

}

void mergeInsertionVector(PmergeMe &obj, std::vector<int> &v){

    if (v.size() <= 2){
        if (v.size() == 2)
        {
            if(v[0] > v[1]){
                 std::swap(v[0], v[1]);
            }
        }
        return  ;
    }
    std::vector<int> losers;
    std::vector<int> winner;
    int flag = 0;
    int unpaired ;
    int size = v.size() -1;
    if (v.size() % 2 != 0){
        unpaired = v[size];
        flag = 1;
        size--;
    }

    int i = 0;
    while (i < size)
    {
        if (v[i] < v[i + 1] ){
            winner.push_back(v[ i + 1]);
            losers.push_back(v[i]);
        }
        else{
           losers.push_back(v[ i + 1]);
            winner.push_back(v[i]);
        }
        i+=2;
    }
    mergeInsertionVector(obj, winner);
 
    inserLoserIntoWinner(winner, losers);
    if (flag == 1){
            insertElement(winner, unpaired);
        }
    v = winner;
}