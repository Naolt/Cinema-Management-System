#include <iostream>
#include <string.h>
#include <cctype>
#include "listofmovies.h"

using namespace std;

 struct rating{
 int age;
 float scale;

 }rate;
 struct date
 {
 int day;
 int month;
 int year;
 };
 struct movie
 {
 string name;
 string genre;
 rating rate;
 float price;
 date release;
 date outc;
 };

int main()

{
int n=1;
int add=1;
movie *lists{new movie[n]};
movie *addedlist{new movie[add]};
cout<<"MOVIE REGISTRATION"<<endl;

    for(int i{};i<n;++i)
    {

        cout<<"\nMovie Name: ";
        cin>>lists[i].name;
        cout<<"\nGenre: ";
        cin>>lists[i].genre;
        cout<<"Rating: ";
        cout<<"\nEnter the age rating (max age allowed):";
        cin>>lists[i].rate.age;
        cout<<"Enter the rating out of 10: ";
        cin>>lists[i].rate.scale;
        cout<<"Price: ";
        cin>>lists[i].price;
        cout<<"Release Date: ";
            cout<<"\nDay: ";
            cin>>lists[i].release.day;
            cout<<"Month: ";
            cin>>lists[i].release.month;
            cout<<"Year: ";
            cin>>lists[i].release.year;
        cout<<"Out of Cinema Date: ";
            cout<<"\nDay: ";
            cin>>lists[i].outc.day;
            cout<<"Month: ";
            cin>>lists[i].outc.month;
            cout<<"Year: ";
            cin>>lists[i].outc.year;
            system("cls");
            char choice;

    trial:
            cout<<"\nDo you want to register another Movie(Y/N): ";
                cin.ignore();
                cin>>choice;
                switch(tolower(choice))
                {
                    case 'y':

                        addedlist=lists;//check this area
                        delete[] lists;
                        lists=NULL;
                        lists={new movie[++n]};

                        for(int j{};j<add;++j)
                            {
                                lists[j]=addedlist[j];
                            }

                        delete[] addedlist;
                        addedlist=NULL;
                        break;

                    case 'n':  break;

                    default:
                        cout<<"!!Invalid input\n";goto trial;
                        break;

                }
    }
    movie store[n];

        for(int i{};i<n;++i)
        {
        store[i]=lists[i];


        }
        for(int i{};i<n;++i)
            {
            cout<<store[i].name<<endl;

            }


    char choice2;
    cout<<"\nDo you want to display the list of movies(Y/N): ";
    cin>>choice2;

        switch(tolower(choice2))
        {

        case 'y':movieList(lists,n);
        default: return 0;

        }


}
