class DynamicArray {
    int *arr;
    int arr_size, total_capacity;
public:

    DynamicArray(int capacity) {
        arr = new int[capacity];
        arr_size = 0;
        total_capacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(arr_size == total_capacity){
            resize();
        }
        arr[arr_size] = n;
        arr_size++;
    }

    int popback() {
        int ele = arr[arr_size-1];
        arr_size--;
        return ele;
    }

    void resize() {
        int *newArr = new int[total_capacity*2];
        for(int i=0;i<total_capacity;i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        total_capacity *= 2;
    }

    int getSize() {
        return arr_size;
    }

    int getCapacity() {
        return total_capacity;
    }
};
