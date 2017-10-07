#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <iostream>

/*
    This class implements a vector for the purpose of storing data
    in a size-adjusting data structure and accessing it efficiently
*/


template <class T>
class DSVector
{

private:
    int capacity;                   //number of spaces allocated
    int size;                       //number of spaces used
    T * array;                      //underlying array
    void resize();                  //increases capacity to make more space

public:
    DSVector();
    DSVector(T*, int);
    DSVector(int);
    DSVector(const DSVector<T>&);
    ~DSVector();
    int getCapacity() const;
    int getSize() const;
    T * getArray() const;
    DSVector<T> operator=(const DSVector<T>&);
    bool operator==(const DSVector<T>&) const;
    bool operator!=(const DSVector<T>&) const;
    DSVector<T> operator+(T) const;
    DSVector<T> operator+(const DSVector<T>&) const;
    DSVector<T>& operator+=(T);
    DSVector<T>& operator+=(const DSVector<T>&);
    template <class U>
    friend std::ostream& operator<<(std::ostream&, const DSVector<U>&);
    bool operator>(const DSVector<T>&) const;
    bool operator<(const DSVector<T>&) const;
    T& operator[](int) const;        //subscript
    void push_back(T);
    void pop_back();
    void insert(T, int);
    void remove(int);
    bool isEmpty();
    void clear();
    void swap(int, int);
    void sort(int begin, int end);
    void quicksort(int, int);
    int partition(int, int);
    int medianOfThree(int, int);
    void dualPivotQuicksort(int, int);
    int *dualPivotPartition(int, int);
};



//============
//CONSTRUCTORS
//============

//default constructor; sets capacity to 5, size to 0
template <class T>
DSVector<T>::DSVector() {
    capacity = 5;           //capacity 5
    size = 0;               //size 0
    array = new T[capacity] {};    //dyn. alloc array
}


//constructor for array takes T* and size
template <class T>
DSVector<T>::DSVector(T * contents, int length) {
    size = length;                  //set size
    capacity = size+5;              //set capacity at 5+size
    array = new T[capacity] {};     //dyn alloc array

    //copy array over element-wise
    for(int i=0; i<size; i++) {
        array[i] = contents[i];
    }
}


//constructor for int size
template <class T>
DSVector<T>::DSVector(int length){
    size = 0;                   //set size
    capacity = length;          //set capacity at 5+size
    array = new T[capacity] {}; //dyn alloc array
}


//copy constructor
template<class T>
DSVector<T>::DSVector(const DSVector<T> & rhs) {
    size = rhs.getSize();               //copy size and cap
    capacity = rhs.getCapacity();

    array = new T[capacity] {};         //dyn alloc array

    //copy over array
    for(int i=0; i<size; i++) {
        array[i] = rhs.getArray()[i];
    }
}


//destructor
template <class T>
DSVector<T>::~DSVector(){
    delete[] array;
}


//===============
//GETTERS/SETTERS
//===============

template <class T>
int DSVector<T>::getCapacity() const {
    return capacity;
}


template <class T>
int DSVector<T>::getSize() const {
    return size;
}


template <class T>
T * DSVector<T>::getArray() const {
    return array;
}


//=========
//OPERATORS
//=========

//Assignment
template <class T>
DSVector<T> DSVector<T>::operator =(const DSVector<T>& rhs) {
    //check if same object
    if(this != &rhs) {
        //if not, delete[] array
        delete[] array;

        //copy over size and cap
        size = rhs.size;
        capacity = rhs.getCapacity();

        //alloc new array, copy over data
        array = new T[capacity] {};
        for(int i=0; i<size; i++) {
            array[i] = rhs[i];
        }
    }
    return *this;
}


//Equality
template <class T>
bool DSVector<T>::operator ==(const DSVector<T>& rhs) const {
    //check size is same; cap doesn't matter
    if(size != rhs.getSize()) {
        return false;
    } else {
        //check each element of array
        for(int i=0; i<size; i++) {
            if(array[i] != rhs[i]) {
                return false;
            }
        }
    }
    return true;
}


//Inequality
template <class T>
bool DSVector<T>::operator !=(const DSVector<T>& rhs) const {
    return !(*this == rhs); //not equals
}


//Addition (for T)
template <class T>
DSVector<T> DSVector<T>::operator +(T added) const {
    //return an vector with new element pushed back
    DSVector<T> temp = *this;
    return (temp += added);
}


//Addition (for vector)
template <class T>
DSVector<T> DSVector<T>::operator+(const DSVector<T>& rhs) const {
    DSVector<T> temp = *this;        //make new vector as copy of first
    return (temp += rhs);            //return left += right
}


//Plus-Assign (for T)
template <class T>
DSVector<T>& DSVector<T>::operator +=(const T pushed) {
    this->push_back(pushed);   //wraps push_back
    return *this;
}


//Plus-Assign (for vector)
template <class T>
DSVector<T>& DSVector<T>::operator +=(const DSVector<T>& added) {
    //push_back all elements of vector arg
    for(int i=0; i<added.getSize(); i++) {
        this->push_back(added[i]);
    }
    return *this;
}


//Stream Insertion
template <class T>
std::ostream& operator<<(std::ostream& stream, const DSVector<T>& vect) {
    //print each element separated by commas and spaces
    stream << vect[0];
    for(int i=1; i<vect.getSize(); i++) {
        stream << '\n';
        stream << vect[i];
    }
    stream << std::endl;
    return stream;
}


//Comparison > (assumes that data type has >)
template <class T>
bool DSVector<T>::operator >(const DSVector<T>& rhs) const {
    //go through and compare each element until one is > or <
    if(rhs.getSize() == 0)
        return true;
    else if(getSize() == 0)
        return false;

    int minSize = (rhs.getSize() < this->getSize()) ? (rhs.getSize()) : (this->getSize());
    for(int i=0; i<minSize; i++) {
        if(array[i] < rhs[i])
            return false;
        else if(array[i] > rhs[i])
            return true;
        else if(array[i] == rhs[i])
            continue;
    }
    return false;
}


//Comparison < (assumes that data type has <)
template <class T>
bool DSVector<T>::operator <(const DSVector<T>& rhs) const {
    //go through and compare each element until one is > or <
    if(rhs.getSize() == 0)
        return false;
    else if(getSize() == 0)
        return true;

    int minSize = (rhs.getSize() < this->getSize()) ? (rhs.getSize()) : (this->getSize());
    for(int i=0; i<minSize; i++) {
        if(array[i] > rhs[i])
            return false;
        else if(array[i] < rhs[i])
            return true;
        else if(array[i] == rhs[i])
            continue;
    }
    return false;
}
    //go through and compare each element until one is > or <


//Subscript
template<class T>
T& DSVector<T>::operator[](int index) const{
    //if >= size, throw error
    if(index >= size || index < 0){
        throw(std::out_of_range("Requested index is out of bounds."));
    } else {
        //return reference to ith element
        return array[index];
    }
}


//=======
//UTILITY
//=======


//push_back
template <class T>
void DSVector<T>::push_back(T item) {
    size++;                 //increment siz
    array[size - 1] = item; //make last element the arg
    this->resize();         //resize
}


//pop_back
template <class T>
void DSVector<T>::pop_back() {
    if(!(this->isEmpty())){     //check if array is empty
        //array[size-1] = '\0';     //set last element to null
        size--;                 //decrement size
    }
}


//insert
template <class T>
void DSVector<T>::insert(T contents, int location) {
    if(location > size || location < 0) {           //make sure you don't insert past bounds
        throw(std::out_of_range("The requested location to insert is out of bounds."));
    } else if(location == size) {                   //if location is same as size, push back
        this->push_back(contents);
    } else {                                        //adjust size and capacity

        for(int i=size-1; i>=location; i--) {       //iterate from arg to size-1
            array[i+1] = array[i];                  //move i to i+1
        }
        array[location] = contents;                 //array[arg] = element
        size++;
        resize();
    }
}


//remove
template <class T>
void DSVector<T>::remove(int location) {
    //make sure location exists
    if(location > size-1 || location < 0) {     //make sure you don't insert past bounds
        throw(std::out_of_range("The requested location to insert is out of bounds."));
    } else if(location == size-1) {
        this->pop_back();
    } else {
        for(int i=location; i<size-1; i++) {    //iterate from arg to size
            array[i] = array[i+1];              //move i+1 to i
        }
        size--;                                 //size--
    }
}


//isEmpty
template <class T>
bool DSVector<T>::isEmpty() {
    return(size == 0);  //is size == 0?
}


//resize (private); try calling everytime there's a push_back
template <class T>
void DSVector<T>::resize() {
    //if cap - size < 2
    if(capacity - size <= 2) {
        capacity += 5;                  //increase cap by 5
        T * temp = new T[capacity] {};  //allocate new array

        for(int i=0; i<size; i++) {     //copy over contents
            temp[i] = array[i];
        }

        delete[] array;                 //delete old array
        array = temp;
    }
}


//clear
template <class T>
void DSVector<T>::clear() {
    while(!isEmpty()) {
        pop_back();
    }
}


//swaps first element of array with second
template <class T>
void DSVector<T>::swap(int first, int second) {
    T temp = (*this)[first];
    (*this)[first] = (*this)[second];
    (*this)[second] = temp;
}


//=======
//SORTING
//=======

//sort
template <class T>
void DSVector<T>::sort(int begin, int end) {

    //stop if empty
    if(isEmpty())
        return;

    //selectionsort
    T select = array[0];
    for(int i=begin+1; i<=end; i++){
        select = array[i];
        int bound = i-1;
        while(bound >= 0 && array[bound] >= select){
            array[bound+1] = array[bound];
            bound--;
        }
        array[bound+1] = select;
    }
}


//implementation of quicksort for sorting more efficiently
template <class T>
void DSVector<T>::quicksort(int begin, int end) {
    int pivotLoc = this->partition(begin, end);

    //if pivot location-begin > 1, quicksort first partition
    if((pivotLoc-1) - begin > 0) {
        if((pivotLoc-1) - begin > 17) {
            quicksort(begin,pivotLoc-1);
        } else {
            sort(begin, pivotLoc-1);
        }
    }
    //if end-pivot location > 1, quicksort second partition
    if(end - (pivotLoc+1) > 0) {
        if(end - (pivotLoc+1) > 17) {
            quicksort(pivotLoc+1, end);
        } else {
            sort(pivotLoc+1, end);
        }
    }
}


//function for partitioning array in single-pivot quicksort
template <class T>
int DSVector<T>::partition(int begin, int end) {

    //find pivot value
    int pivotLoc = medianOfThree(begin, end);
    T pivot = (*this)[pivotLoc];

    //place pivot at end
    if(pivotLoc != end) {
        swap(pivotLoc,end);
    }

    //initialize i to start, j to end-1
    int i = begin;
    int j = end-1;

    //while i<j
    while(i <= j) {
        //increment i until ith item is greater than pivot
        while(array[i] < pivot) {
            i++;
        }
        //increment j until jth item is less than pivot
        while(array[j] > pivot) {
            j--;
        }
        //if i<j
        if(i <= j) {
            //swap i and j
            swap(i,j);
            i++;
            j--;
        }
    }

    //swap pivot value with value at i
    swap(end, i);

    //return location of pivot (which is i)
    return i;
}


//find approximation of median through "median of three" method
template <class T>
int DSVector<T>::medianOfThree(int begin, int end) {
    //get values
    int midIndex = (begin + end)/2;
    T first = array[begin];
    T last = array[end];
    T middle = array[midIndex];

    //find median value of first, middle, last
    if (first <= middle) {
        if (last <= first) {
            return begin;
        } else if (middle <= last){
            return midIndex;
        } else {
            return end;
        }
    } else {
        if(last <= middle) {
            return midIndex;
        } else if(first <= last) {
            return begin;
        } else {
            return end;
        }
    }
}


//calls recursive dual-pivot quicksort algorithm
template <class T>
void DSVector<T>::dualPivotQuicksort(int begin, int end) {
    //dualPivotPartition from begin to end
    int * pivotLocs = nullptr;

    pivotLocs = dualPivotPartition(begin, end);

    //recursively call dpquick on each partition
    if((pivotLocs[0]-1) - begin > 0) {
        if((pivotLocs[0]-1) - begin > 27) {
            dualPivotQuicksort(begin, pivotLocs[0] - 1);
        } else {
            sort(begin, pivotLocs[0]-1);
        }
    }
    if((pivotLocs[1]-1) - (pivotLocs[0]+1) > 0) {
        if((pivotLocs[1]-1) - (pivotLocs[0]+1) > 27) {
            dualPivotQuicksort((pivotLocs[0]+1), (pivotLocs[1]-1));
        } else {
            sort((pivotLocs[0]+1), (pivotLocs[1]-1));
        }
    }
    if(end - (pivotLocs[1]+1) > 0) {
        if(end - (pivotLocs[1]+1) > 27) {
            dualPivotQuicksort(pivotLocs[1]+1, end);
        } else {
            sort(pivotLocs[1]+1, end);
        }
    }
    delete[] pivotLocs;

}


//partitions vector for dual-pivot quicksorting
template <class T>
int * DSVector<T>::dualPivotPartition(int begin, int end) {
    //if not already, put median1 at front and median2 at back
    if(array[begin] > array[end]) {
        swap(begin, end);
    }

    //determine median1 and median2
    T median1 = array[begin];
    T median2 = array[end];

    //initialize lower and k to begin and upper to end
    int lower = begin+1;
    int upper = end-1;
    int k = begin+1;

    //iterate k starting from lower until it hits great
    while(k <= upper) {
        T kthElement = array[k];
        //if array[k] < median1 put it ahead of lower and increment lower
        if(kthElement < median1) {
            swap(k, lower++);

            //else if array[k] > median2 put it behind upper and decrement upper
        } else if(kthElement > median2) {
            while(array[upper] > median2 && k < upper)
                upper--;

            swap(k, upper--);

            if(array[k] < median1) {
                swap(k, lower++);
            }
        }
        k++;
    }

    //swap median1 with lower and median2 with upper
    swap(begin, lower-1);
    swap(upper+1, end);

    int * pivotLocs = new int[2] {lower-1, upper+1};

    //return lower and upper
    return pivotLocs;
}

#endif // DSVECTOR_H
