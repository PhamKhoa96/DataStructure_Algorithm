#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

class MinHeap{
private:
    int* harr;
    int capacity;
    //int heap_size;
public:
    MinHeap(int*, int);

    int parent(int i){return (i-1)/2; }
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}

    void MinHeapify(int);

    void HeapSort(int);

    void Print(int);
};

MinHeap::MinHeap(int* arr, int capacity){
    harr = arr;
    this->capacity = capacity;
}

void MinHeap::MinHeapify(int i){
    if (left(i) < capacity){
        int smallest = harr[i];
        if (harr[i] > harr[left(i)]){   // khác với binaryHeap, ta không tạo heap từ ban đầu bằng cách insert nên ta phải có bước tìm ta giá trị nhỏ nhất trong 3 node: parent, left, right
            smallest = harr[left(i)];
            if (smallest > harr[right(i)] && right(i) < capacity)   // nhớ phải có điều kiện && right(i) < capacity phòng trường hợp ta vẫn xét node mặc dù capacity của array đã bị giảm và vì thế right(i) không còn nằm trong phạm vi đang xét nữa
                smallest = harr[right(i)];                          
        }

        if(smallest == harr[left(i)]){
            swap(&harr[i], &harr[left(i)]);
            i = left(i);
            MinHeapify(i);
        }
        else if(smallest == harr[right(i)]){
            swap(&harr[i], &harr[right(i)]);
            i = right(i);
            MinHeapify(i);
        } 
        else
            return;
    }
    else
        return;
}

void MinHeap::HeapSort(int initial_capacity){
    int temp = initial_capacity/2 -1;

    for (int i = temp; i >= 0; i--){
        MinHeapify(i);
    }

    int temp2 = capacity;
    for (int j = 0; j < temp2; j++){
        swap(harr[0], harr[capacity-1]);
        capacity--;
        MinHeapify(0);
    }
}

void MinHeap::Print(int initial_capacity){
    for(int i = 0; i < initial_capacity; i++ )
        cout << harr[i] << " ";
}   

int main(){
    int a[] = {8,13,3,6,1,9,55,11,43,22,23};
    int size_arr = sizeof(a)/sizeof(int);

    MinHeap b(a, size_arr);
    b.Print(size_arr);
    cout << endl;

    b.HeapSort(size_arr);
    cout << "sau khi sap xep: "<< endl;
    b.Print(size_arr);

    return 0;
}
