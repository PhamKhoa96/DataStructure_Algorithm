#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int a = *x;
    *x = *y;
    *y = a;
}

class MinHeap{
private:
    int* harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int);

    void MinHeapify(int);

    int parent (int i){return (i-1)/2;}
    int left (int i){return 2*i+1;}
    int right (int i){return 2*i+2;}

    int getMin(){return harr[0];}

    int extractMin();

    void decreaseKey(int i, int new_val);

    void insertKey(int);

    void Delete (int );

    void PrintHeap();

};

MinHeap::MinHeap(int capacity){
    this->heap_size = 0;
    this->capacity = capacity;
    this->harr = new int[capacity];
}

void MinHeap::insertKey (int k){
    if (heap_size < capacity){
        if (heap_size == 0){
            harr[0] = k;
            heap_size++;
            return;
        }
        else{
            int i = heap_size;
            harr[i] = k;
            heap_size++;
            while (parent(i) >= 0){
                if (harr[i] < harr[parent(i)]){
                    swap(harr[i], harr[parent(i)]); 
                    i = parent(i);
                }
                else
                    return;
            }
        }
    }
    else{
        cout << "full of space" << endl;
        return;
    }
}

void MinHeap::decreaseKey(int i, int new_val){
    harr[i] = new_val;
    while (parent(i) >= 0){
        if (harr[parent(i)] > harr[i]){
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
        else
            return;       
    }
}



void MinHeap::MinHeapify(int i){
    if (left(i) < heap_size){
        if (harr[left(i)] < harr[i]){
            swap(harr[left(i)], harr[i]);
            i = left(i);
            MinHeapify(i);
        }
        else{ 
            swap(harr[right(i)], harr[i]);
            i = right(i);
            MinHeapify(i);
        }
    }
    else
        return;
}

int MinHeap::extractMin(){
    int temp = harr[0];
    swap(harr[0], harr[heap_size-1]);
    heap_size--;
    MinHeapify(0);

    return temp;
}

void MinHeap::Delete(int i){
    if (i < heap_size){
        swap(harr[heap_size-1], harr[i]);
        heap_size--;
        MinHeapify(i);
    }
    else
        return;
}

void MinHeap::PrintHeap(){
    for (int i = 0; i < heap_size; i++)
        cout << harr[i] << " ";
}

int main(){
    MinHeap a(11);

    a.insertKey(6);
    a.insertKey(63);
    a.insertKey(4);
    a.insertKey(8);
    a.insertKey(10);
    a.insertKey(12);
    a.insertKey(5);
    a.insertKey(44);
    a.insertKey(1);
    a.insertKey(3);
    a.insertKey(9);
    a.PrintHeap();
    cout << endl;

    a.decreaseKey(8, 2);
    a.PrintHeap();
    cout << endl;

    int k = a.extractMin();
    cout << "loai harr[0] = "<< k << " ra khoi heap" << endl;
    a.PrintHeap();

    a.Delete(2);
    cout << endl;
    a.PrintHeap();

    return 0;
}

