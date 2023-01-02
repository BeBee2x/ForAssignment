#include "stdio.h"
#include "stdlib.h"

int minium(int first,int second);
int jumpsearch(int array[],int size,int tofind);

int main(){
    int array[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int tofind=17;
    int size = sizeof (array) / sizeof (array[0]);
    printf("size is %d\n",size);
    int index=jumpsearch(array,size,tofind);
    if(index!=-1){
        printf("We found %d at index %d\n",array[index],index);
        printf("%d\n", array[18]);
    } else{
        printf("Not found");
    }
    return 0;
}

int minium(int first,int second){
    if(first<second){
        return first;
    }else{
        return second;
    }
}

int jumpsearch(int array[],int size,int tofind){
    int step = size/3;
    int previous=0;
    while(array[minium(step,size)-1]<tofind){
        previous=step;
        step+=size/3;
        if(previous>=size){
            return 0;
        }
    }
        for (int i = previous; i <=step; ++i) {
            if(array[previous]==tofind){
                return i;
            }
        }
    return -1;
}