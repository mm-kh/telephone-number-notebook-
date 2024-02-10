#include <iostream>
#include <string>
#include <iomanip>
//برنامه ذخیره اطلاعات مخاطبین

using namespace std;
string info[100][5];
int counter=0;


void desktap()
{
        cout<<" 1. create a contact."<<endl<<endl;
        cout<<" 2. edit a contact."<<endl<<endl;
        cout<<" 3. delete a contact."<<endl<<endl;
        cout<<" 4. contact list."<<endl<<endl;
        cout<<" 5. search a contact."<<endl<<endl;
        cout<<" 6. sort by name."<<endl<<endl;
        cout<<" 7. exit."<<endl<<endl;
        cout<<" select your choice : ";
}
void create()
{
    system("cls");
    string a,b,c,d;
    cout<<endl<<"enter id: ";
    cin>>a;
    cin.ignore();
    cout<<endl<<"enter contact firstname: ";
    getline(cin,b);
    cout<<endl<<"enter contact lastname: ";
    getline(cin,c);
    cout<<endl<<"enter contact number: ";
    getline(cin,d);
    info[counter][0]=a;
    info[counter][1]=b;
    info[counter][2]=c;
    info[counter][3]=d;
    info[counter][4]="1";
    counter++;

}
void edit()
{
    system("cls");
    int flag=0;
    string a;
    cout<<endl<<"enter contact name: ";
    cin>>a;
    for (int i=0; i<counter; i++)
    {
        if (info[i][1]==a && info[i][4]=="1")
        {
            cout<<endl<<"info contact: "<<endl<<info[i][0]<<" "<<info[i][1]<<" - "<<info[i][2]<<" - "<<info[i][3]<<endl;
            flag=1;
            cin.ignore();
            cout<<endl<<"enter new name :";
            getline(cin,info[i][1]);
            cout<<endl<<"enter new last name: ";
            getline(cin,info[i][2]);
            cout <<endl<<"enter new contact number: ";
            getline(cin,info[i][3]);
            break;

        }
    }
    if (flag==0)
    {
        cout<<"\n not found  ";
    }
}
void Delete()
{
    system("cls");
    int flag=0;
    string a,b;
    cout<<endl<<"enter contact name: ";
    cin>>a;
    for (int i=0; i<counter; i++)
    {
        if(info[i][1]==a && info[i][4]=="1")
        {
            cout<<endl<<"info contact: "<<endl<<info[i][0]<<" "<<info[i][1]<<" - "<<info[i][2]<<" - "<<info[i][3]<<endl;
            flag=1;
            cin.ignore();
            cout<<"are you sure delete contact (Y_N)?";
            getline(cin,b);
            if (b=="y")
            {
                info[i][4]=="0";
                cout<<"delete contact successful."<<endl;
            }
            else
            {
                cout<<endl<<"it was not deleted."<<endl;
            }
            break;
        }
    }
    if (flag==0)
    {
        cout<<"\n not found.";
    }

}
void show()
{
    string a[100][5],temp;
    int flag=0;
    for(int i=0; i<counter; i++)
    {
        if(info[i][4]=="1")
        {
            a[flag][0]=info[i][0];
            a[flag][1]=info[i][1];
            a[flag][2]=info[i][2];
            a[flag][3]=info[i][3];
            a[flag][4]=info[i][4];
            flag++;
        }

    }
    system("cls");
    cout<<endl<<"    -------------------------------------------------------";
    cout<<endl<<"   |"<< " ID " << "|" << " contact name " << "|" << " contact lastname " << "|" << " contact number "<< "|";
    cout<<endl<<"    ----+--------------+------------------+----------------";
    for(int i=0; i<counter; i++)
    {
        cout<<endl<<"   |" << setw(4) << a[i][0] << "|" << setw(14) << a[i][1] << "|" << setw(18) << a[i][2] << "|" << setw(16) << a[i][3] << "|";
        cout<<endl<<"    ----+--------------+------------------+----------------";
    }
    cout<<endl;





}
void Search()
{
    system("cls");
    int flag=0;
    string a,b;
    cout<<endl<<"enter contact name: ";
    cin>>a;
    for(int i=0; i<counter; i++)
    {
        if(info[i][1]==a && info[i][4]=="1")
        {
            cout<<endl<<"info contact: "<<endl<<info[i][0]<<" "<<info[i][1]<<" - "<<info[i][2]<<" - "<<info[i][3]<<endl;
            flag=1;
            cin.ignore();
        }
    }
    if (flag==0)
    {
        cout<<"\n not found.";
    }
}
void Sort()
{
    string a[100][5],temp;
    int flag=0;
    for(int i=0; i<counter; i++)
    {
        if(info[i][4]=="1")
        {
            a[flag][0]=info[i][0];
            a[flag][1]=info[i][1];
            a[flag][2]=info[i][2];
            a[flag][3]=info[i][3];
            a[flag][4]=info[i][4];
            flag++;
        }
    }
    for(int i=0; i<counter; i++)
    {
        for(int j=0; j<flag-1-i; j++)
        {
            if(a[j][1]>a[j+1][1])
            {
                temp=a[j][1];
                a[j][1]=a[j+1][1];
                a[j+1][1]=temp;
                temp=a[j][2];
                a[j][2]=a[j+1][2];
                a[j+1][2]=temp;
                temp=a[j][3];
                a[j][3]=a[j+1][3];
                a[j+1][3]=temp;

            }
        }
    }
    system("cls");
    cout<<endl<<"    -------------------------------------------------------";
    cout<<endl<<"   |"<< " ID " << "|" << " contact name " << "|" << " contact lastname " << "|" << " contact number "<< "|";
    cout<<endl<<"    ----+--------------+------------------+----------------";
    for(int i=0; i<counter; i++)
    {
        cout<<endl<<"   |" << setw(4) << a[i][0] << "|" << setw(14) << a[i][1] << "|" << setw(18) << a[i][2] << "|" << setw(16) << a[i][3] << "|";
        cout<<endl<<"    ----+--------------+------------------+----------------";
    }
    cout<<endl;
}




void choice(int key)
{
    switch(key)
    {
    case 1:
        create();
        break;
    case 2:
        edit();
        break;
    case 3:
        Delete();
        break;
    case 4:
        show();
        break;
    case 5:
        Search();
        break;
    case 6:
        Sort();
        break;
    case 7:
        exit(0);
        break;
    }
}






int main()
{
    int key;
    while(true)
    {
        system("cls");
        key=0;
        desktap();
        cin>>key;
        choice(key);
        system("pause");

    }


    return 0;
}


