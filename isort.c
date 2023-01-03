#include <stdio.h>
#define N 50

int main(){

    void shift_element(int* arr, int i);
    void insertion_sort(int* arr , int len);

    int array[N] = {0};//making non garbage by intilizing array to 0's
    int *arr = array; // arr is a pointer to array's first index

    int i;
    //printf("Please type in %d integers to be inserted in to the array\n",N);
    for(i = 0; i<N;i++){
        scanf("%d",&(*(arr +i)));//scanning input into the array
    }

    insertion_sort(arr, N);//insertion_sort function implemented on the array via refrence of pointer

    //printing sorted array via pointer to n-1 element with ","
    for(i = 0; i<N-1;i++){
        printf("%d,",*(arr + i));
    }
    //printing last element
    printf("%d\n",*(arr+N-1));

    return 0;
}

//shift elements function
void shift_element(int* arr, int i){
    int j;
    for(j = 0; j<i; j++){//for the amount of elements to move right
        *(arr + i - j) = *(arr + i - j - 1);//move each one to the right
    }
}

void insertion_sort(int* arr , int len){

    int *arrhelper = arr; // pointers arr and arrhelper point to the begining of the array
    arrhelper++;//pointer arrhelper points now to one index ahead of pointer arr
    int tempnum, i, j;

    for(i = 0; i<len-1;i++){//loop untill n-1 index's of the array's length

        if(*(arr + i)>*(arrhelper + i)){// if the two elements compared are not in order
            tempnum = *(arrhelper + i); // saving the smaller element as temp

            j = 1;//setting j to 1
            int index = -1;// setting index to -1

            while((arrhelper + i - j)!=(arr)){//indexhelper is not pointing to start of array
                j++;//increase j
                if(*(arrhelper + i - j)<tempnum){//if a number is found that is smaller than temp
                    index = j;
                    break; //break is important as could be many same numbers
                }
            }
            
            if(index!=-1){ // if index is not -1
                index--;// reduce index by one as we have over counted by one
                shift_element((arrhelper + i - index),index); // shift emements to the right
                *(arrhelper + i - index) = tempnum; // insert temp at place where shifted
                index = -1; // return value of index to -1
            }else{ // we got to the beggining of the array 
                shift_element((arrhelper + i - j),j);//shift elements to the right
                *(arrhelper + i - j) = tempnum;//insert temp
            }
            
        }
        
    }



}
