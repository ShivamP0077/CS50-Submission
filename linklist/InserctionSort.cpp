#include<iostream>
using namespace std;
#define Max 5
int arr[Max] = {3,2,4,5,1};

void print()
{
    for(int i = 0; i<Max; i++ ){
        cout<<arr[i]<<" ";
    }

}
int main(void){
   for (int i = 0; i<Max; i++){

  for (int i = 0; i <= Max - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

   }
   print();
}