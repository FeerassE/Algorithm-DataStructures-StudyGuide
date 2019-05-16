
#include<stdio.h>



int BinarySearch(int array[], int low, int high, int target);


int main(void){


}

int BinarySearch(int array[], int low, int high, int target){
    if(high >= 1){
        int mid = (low + high)/2;
        if(array[mid] == target){
            return mid;
        }
        else if(array[mid] > target){
            return BinarySearch(array, low, mid - 1, target);
        }
        else if(array[mid] < target){
            return BinarySearch(array, mid + 1, high, target);
        }
    }
    else{
        return -1;
    }
}