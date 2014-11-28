#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
typedef unsigned int ui;

using namespace std;


class Array
{
private:

    ui siz;
    ui *arr;


public:
 /////////////////////////////////////////
Array()
    {
    siz = 2;
	arr = (ui*)malloc(siz*sizeof(ui));
	for (int i = 0; i < siz; ++i)
		arr[i] = 0;
    }
 //////////////////////////////////////
Array(int s)
    {
        siz = s;
        arr = (ui*)malloc(s*sizeof(ui));
        if(arr!=NULL)
            {
                for(int i = 0; i<siz; i++)
                {
                    arr[i] = i+1;
                }
            }
            else
                {
                cout<<"Memory is not given";
                free(arr);

                }
             }
///////////////////////////////////////////////////////////////
Array(const Array &a)
    {
        siz = 0;
        arr = (ui*)malloc(siz*sizeof(ui));
        this->operator=(a);
    }

////////////////////////////////////////////////////////////////
//Оператор + перегружаю как сложение элементов 2х массивов
Array  operator+(const Array &source){

    if(siz<source.siz){
         Array Temp(source.siz);
         ui j = 0;

        for(int i = 0; i<source.siz; i++){
           while(j<siz)
           {
               Temp.arr[j]=arr[j]+source.arr[j];
                 ++j;
                 ++i;
           }
           Temp.arr[i] = source.arr[i];
        }
        return Temp;
        }

        else{
         Array Temp(siz);
         ui j = 0;

        for(int i = 0; i<siz; i++){
           while(j<source.siz)
           {
               Temp.arr[j]=arr[j]+source.arr[j];
                 ++j;
                 ++i;
           }
           Temp.arr[i] = arr[i];
        }
        return Temp;
        }
    }
///////////////////////////////////////////////////////
//Оператор - перегружаю как вычитание элементов 2х массивов
Array  operator-(const Array &source){

    if(siz<source.siz){
         Array Temp(source.siz);
         int j = 0;

        for(int i = 0; i<source.siz; i++){
           while(j<siz)
           {
               Temp.arr[j]=arr[j]-source.arr[j];
                 ++j;
                 ++i;
           }
           Temp.arr[i] = source.arr[i];
        }
        return Temp;
        }

        else{
         Array Temp(siz);
         int j = 0;

        for(int i = 0; i<siz; i++){
           while(j<source.siz)
           {
               Temp.arr[j]=arr[j]-source.arr[j];
                 ++j;
                 ++i;
           }
           Temp.arr[i] = arr[i];
        }
        return Temp;
        }
    }
////////////////////////////////////////////////////////

Array& operator=(const Array &temp){

    if(siz<temp.siz){
        siz = temp.siz;
       arr = (ui*)realloc(arr, temp.siz * sizeof(ui));
         }

        for(int i = 0; i<temp.siz; i++)

            arr[i] = temp.arr[i];
        return *this;

}
/////////////////////////////////////////////////////////////
Array &operator++(){

    siz+= 1;
    arr = (ui*)realloc(arr, siz * sizeof(ui));
    arr[siz-1] = arr[siz-2]+1;
    return *this;
}
//////////////////////////////////////////////////////////
Array &operator--(){

    siz-= 1;
    arr = (ui*)realloc(arr, siz * sizeof(ui));
    return *this;
}
/////////////////////////////////////////////////////////////
void Show(){
        for(int i = 0; i<siz; i++)
            {
                printf("%4d", arr[i]);
            }
        cout<<endl;
    }
///////////////////////////////////////////////////////////
//Проверка на выход за пределы массива
ui &operator[](ui index)
{
    if(index>=0&&index<siz)
    {
        cout<<"Element with index "<<index<<" is ";
        return arr[index];
    }
    else{
       cout<<"Array index out of bounds! Max index is "<<siz-1<<" you entered - ";
        return index;
        }
}
////////////////////////////////////////////////////////////
    ~Array()
    {
        free(arr);
    }

};



int main()
{
    ui len1, len2, choise, index;
    cout<<"Enter the length of the array - ";
    cin>>len1;
    Array a(len1);

do{
    system("cls");
    a.Show();

    cout<<"\n\n1 - '+'";
    cout<<"\n\n2 - '-'";
    cout<<"\n\n3 - '++'";
    cout<<"\n\n4 - '--'";
    cout<<"\n\n5 - '[]'\n";
    cout<<"\n\n6 - exit.\n\n";
    cin>>choise;
    cout<<"\n\n";

    switch(choise){

case 1:
    {
    system("cls");
    cout<<"Enter the length of the second array - ";
    cin>>len2;
    cout<<"\n";
    Array b(len2);
    a.Show();
    cout<<"\n\t+\n";
    b.Show();
    cout<<"\n\t=\n";
    Array c;
    c=a+b;
    c.Show();
    getch();
    break;
    }

case 2:
    {
    system("cls");
    cout<<"Enter the length of the second array - ";
    cin>>len2;
    cout<<"\n";
    Array b(len2);
    a.Show();
    cout<<"\n\t-\n";
    b.Show();
    cout<<"\n\t=\n";
    Array c;
    c=a-b;
    c.Show();
    getch();
    break;
    }
case 3:
    system("cls");
    a.Show();
    ++a;
    cout<<"\n\n";
    a.Show();
    getch();
    break;

case 4:
    system("cls");
    a.Show();
    --a;
    cout<<"\n\n";
    a.Show();
    getch();
    break;

case 5:
    cout<<"Vvedite index massiva - ";
    cin>>index;
    system("cls");
    a.Show();
    cout<<"\n\n";
    cout<<a[index]<<"\n\n";
    getch();
    break;
 }
 }
 while(choise!=6);
}
