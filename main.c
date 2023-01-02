#include "stdio.h"
#include "stdlib.h"


int mini(int first,int second);
int jumpsearch(int array[],int size,int tofind);

int main(){
    int key=1;
    int array[]={1,3,4,5,7,8,10,14,15,18,31,43,54,55,60,79,88,89,90,93,94,95,100};
    int size=sizeof(array)/sizeof(array[0]);
    int tofind;
    while(key==1){
        printf("Which number do you want to find:");
        scanf("%d",&tofind);
        int index=jumpsearch(array,size,tofind);
        if(index!=-1){
            printf("We found %d at index %d\n",array[index],index);
        }else{
            printf("Not found %d\n",tofind);
        }
    }
}

int mini(int first,int second){
    if(first<second){
        return first;
    }else{
        return second;
    }
}

int jumpsearch(int array[],int size,int tofind){
    int previous=0;
    int step=size/3;
    if(array[size-1]<tofind){
        return -1;
    }
    while(array[mini(step,size)-1]<tofind){
        previous=step;
        step+=size/3;
        if(previous>=size){
            return -1;
        }
    }
    if(step<=size){
        if(array[step-1]==tofind){
            return step-1;
        }
    }
    int step2=previous+(size/3/2);
    if(step2>size){
        for (int k = previous; k <size; ++k) {
            if(array[k]==tofind){
                return k;
            }
        }
    }else if(array[step2]==tofind){
        return step2;
    }else if(array[step2]<tofind){
        for (int i = step2; i <step ; ++i) {
            if(array[i]==tofind){
                return i;
            }
        }
    }else if(array[step2]>tofind){
        for (int j = previous; j <step2 ; ++j) {
            if(array[j]==tofind){
                return j;
            }
        }
    }

    return -1;
}