#include <iostream>
#include <vector>

using namespace std;

void mergeAlg(vector<int> &numList, int i, int j, int k){
    vector<int> newList={};
    int leftPos = i;
    int rightPos = j+1;

    while (leftPos <= j && rightPos <= k){
        if(numList.at(leftPos) < numList.at(rightPos)){
            newList.push_back(numList.at(leftPos));
            ++leftPos;
        }
        else{
            newList.push_back(numList.at(rightPos));
            ++rightPos;
        }
    }

    while(leftPos <= j){
        newList.push_back(numList.at(leftPos));
        ++leftPos;
    }

    while(rightPos <= k){
        newList.push_back(numList.at(rightPos));
        ++rightPos;
    }

    for ( int y=0; y<newList.size(); ++y){
        numList.at(i+y) = newList.at(y);
    }
}

void sortMergeAlg(vector<int> &numList, int i, int k){
    int j=0;
    if( i < k ){
        j = (i + k)/2;
        sortMergeAlg(numList, i, j);
        sortMergeAlg(numList, j+1, k);
        mergeAlg(numList, i, j, k);
    }
}

void insertList(vector<int> &numList){
    char q = 'y';
    int value = 0;

    do{
        cout << "Enter a whole number: ";
        cin >> value;
        numList.push_back(value);
        cout << "Press y to keep adding number or q to quit: ";
        cin >> q;
    }while(q=='y');
}

void printList(vector<int> &numList){
    for (int i =0; i < numList.size(); ++i){
        cout << numList.at(i) << " ";
    }
    cout << "    ";
}



int main()
{
    vector<int> numList={9, 8, 0, 45, 6, 3, 47, 89, 0, 5};
    cout << "Unsorted: ";
    printList(numList);
    cout << endl;
    sortMergeAlg(numList, 0, numList.size()-1);
    cout << "Sorted: ";
    printList(numList);
    cout << endl;

    return 0;
}

