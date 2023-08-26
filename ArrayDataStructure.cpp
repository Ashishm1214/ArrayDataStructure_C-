#include<iostream>
using namespace std;
class Array
{
    int capacity;
    int lastindex;
    int *ptr;

    public:
        Array(int);
        bool empty();
        void Append(int);
        void insert(int,int);
        void edit(int,int);
        void DeleteData(int);
        bool ArrayFull();
        int GetElement(int);
        int count();
        ~Array();
        int FindData(int);

};

//FindData function to check whether given data by user is present in the array or not
int Array::FindData(int data)
{
    int i;
    for(i=0;i<=lastindex;i++)
        if(ptr[i]==data)
        {
           cout<<"Given data is at index ";
           return i;
        }
    return -1;
}

//destructor to deallocate the memory
Array::~Array()
{
    delete[]ptr;
}

//count function to find total elements present in the array
int Array::count()
{
    int i,c=0;
    for(i=0;i<=lastindex;i++)
        c++;
    cout<<"Total Element in the array is/are: ";
    return c;
}

//GetElement function to get data of given index
int Array::GetElement(int index)
{
    if(index<0||index>lastindex)
        cout<<"Invalid index";
    else
    {
        cout<<"Element at index "<<index<<" is ";
        return ptr[index];
    }
    return -1;
}

//ArrayFull Function to check whether array is full or not
bool Array::ArrayFull()
{
    if(lastindex==capacity-1)
    {
        cout<<"Array is full"<<endl;
        return true;
    }
    else
    {
        cout<<"Array is not full"<<endl;
        return false;
    }
}

//DeleteData function to delete data from the array of given index
void Array::DeleteData(int index)
{
    if(lastindex==-1)
      cout<<"Array is Empty";
    else if(index<0||index>lastindex)
      cout<<"Invalid index";
    else
    {
        int i;
        for(i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
    }
}

//edit function to edit data from array
void Array::edit(int index,int data)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=data;
    else
        cout<<"Error"<<endl;
}

//insert function to insert data at a given specific index
void Array::insert(int index,int data)
{
     if(lastindex==capacity-1)
        cout<<"Array is already full"<<endl;
     else if(index<0 || index>capacity)
        cout<<"Given index is wrong"<<endl;
     else
     {
         int i;
         for(i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
         ptr[index]=data;
         lastindex++;
     }
}

//Append function to add data after last index filled block
void Array::Append(int data)
{
    if(lastindex==capacity-1)
        cout<<"Array is already full"<<endl;
    else
    {
        lastindex++;
        ptr[lastindex]=data;
    }
}

//Empty function to check array is empty or not
bool Array::empty()
{
    if(lastindex==-1)
    {
        cout<<"Array is Empty"<<endl;
        return true;
    }
    else
    {
        cout<<"Array is not Empty"<<endl;
        return false;
    }
}

//construction it will be called when an object will be created of Array class
Array::Array(int cap)
{
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];
}


//Main section
int main()
{
    Array obj(3);
    obj.Append(14);
    obj.Append(12);
    obj.Append(28);
    cout<<obj.GetElement(2)<<endl;
    cout<<obj.count()<<endl;
    cout<<obj.FindData(12);

    return 0;
}
