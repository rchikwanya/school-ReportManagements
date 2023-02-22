#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
int main()
{
    FILE *fp, *ft;
    char another, choice;

    struct ruva
    {
        char duct[50], type[50];
        int number;
        long ount;
    };

    struct ruva e;
    char duct[50], type[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }



    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout << "\t\t  Ruva hair's product";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. ENTER REQUIRED HAIR PRODUCT ";
        cout << "\n \t\t\t 2. READ INFORMATION ADDED";
        cout << "\n \t\t\t 3. UPDATE INFORMATION";
        cout << "\n \t\t\t 4. DELETE INFORMATION";
        cout << "\n \t\t\t 5. Exit";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice : ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the product : ";
                cin >> e.duct;
                cout << "Enter type of product : ";
                cin >> e.type;
                cout << "Enter number of products     : ";
                cin >> e.number;
                cout << "Enter amount   : ";
                cin >> e.ount;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "=== View the list in the Database ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n" << e.duct << setw(10)  << e.type;
                cout << "\n";
                cout <<"\n" <<e.number <<  setw(8)  << e.ount;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter  product : ";
                cin >> type;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.duct,type) == 0)
                    {
                        cout << "Enter new new product : ";
                        cin >> e.duct;
                        cout << "Enter new type of product : ";
                        cin >> e.type;
                        cout << "Enter new number of products    : ";
                        cin >> e.number;
                        cout << "Enter new amount  : ";
                        cin >> e.ount;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter product  to be deleted : ";
                cin >> type;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.type,type) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another product (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '5':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t     THANK YOU!";
            cout << "\n\n";
            exit(0);
        }
    }


    system("pause");
    return 0;
}
