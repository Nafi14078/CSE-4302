
#include<iostream>
using namespace std;

void bubblesort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {

        for(int j=0;j<size-i-1;j++)
        {

            if(arr[j]>arr[j+1])
            {

                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int binarysearch(int arr[],int size,int key)
{

    int left=0;
    int right=size-1;

    while(left<=right)
    {
        int mid=(left+right)/2;

        if(arr[mid]==key)
        {

            return mid;
        }
        else if(arr[mid]>key)
        {

            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}
int main()
{

    int size;

    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {


       cin>>arr[i];
    }
    cout<<"The sorted array:"<<endl;

    bubblesort(arr,size);
    for(int i=0;i<size;i++)
    {

       cout<<arr[i]<<endl;

    }
    int key;
    cout<<"Enter key:"<<endl;
    cin>>key;

    cout<<binarysearch(arr,size,key)<<endl;


    return 0;
}
