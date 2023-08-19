#include<iostream>
using namespace std;
#define Max 5
int arr[Max] = {3,2,4,5,1};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print()
{
    for(int i = 0; i<Max; i++ ){
        cout<<arr[i]<<" ";
    }

}

int main(void){

    for(int i = 0; i < Max; i++ )
    {
        for (int j = 0; j< Max-1; j++)
        {
            if(arr[j]> arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    print();

}