#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#define INFINITY 999
    struct student
    {
        char first_name[50], last_name[50];
        char course[100];
        int section;
       
    };

    struct student e;
    struct node
    {int cost;
    int value;
    int from;
	}a[7];
using namespace std;
int main()
{ void Quicksort(int *marks,int start,int end);
void min_heapify(int *b, int i, int n);
void build_minheap(int *b, int n);
void addEdge(int am[][7], int src, int dest, int cost);
void bell(int am[][7]);

    FILE *fp, *ft;
    char another, choice;


    char xfirst_name[50], xlast_name[50];
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

        cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add    Records";
        cout << "\n \t\t\t 2. List   Records";
        cout << "\n \t\t\t 3. Modify Records";
        cout << "\n \t\t\t 4. Delete Records";
        cout << "\n \t\t\t 5. Exit   Program";
        cout << "\n \t\t\t 6.Sorting Marks";
        cout << "\n \t\t\t 7.Priority Services";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice :=> ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :
        	{
			
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the First Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        }
        case '2':
        	{
			
            system("cls");
            rewind(fp);
            cout << "=== View the Records in the Database ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n" << e.first_name << setw(10)  << e.last_name;
                cout << "\n";
                cout <<"\n" <<e.course <<  setw(8)  << e.section;
            }
            cout << "\n\n";
            system("pause");
            break;
           }
        case '3' :
        {
		
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "Enter new the First Name : ";
                        cin >> e.first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter new the Course    : ";
                        cin >> e.course;
                        cout << "Enter new the Section   : ";
                        cin >> e.section;
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
       }

        case '4':
        	{
			
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;
   			}
        case '5':
        	{
			
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
            cout << "\n\n";
            exit(0);
        	}
        case '6':
        	{
			
        	system("cls");
        	 int a;
        	cout<<"Enter number of students: ";
        	cin>>a;
        	int marks[a];
        	cout<<"Enter the marks of student:\n";
        	for(int i=0;i<a;i++)
       		{
    	 	cin>>marks[i];
       		}
			Quicksort(marks,0,a-1);
			{
				cout<<("After quick sorting the array is\n");
				for(int i=0;i<a;i++)
				{
					cout<<marks[i]<<" ";
				}
			}
			break;
			}
		case '7':
			{
			
			system("cls");
			int n,am[7][7],c=0,i,j,cost;
			for(int j;j<7;j++)
			{
				am[i][j]=INFINITY;
				
			}
        	while (c<12)
        	{
        	cout<<"Enter the source,destination and cost of edge\n";
        	cin>>i>>j>>cost;
        	addEdge(am,i,j,cost);
        	c++;
		
			bell(am);
			}
			break;
      		}
    	}


    system("pause");
    return 0;
	}
}
int partition(int *marks,int start,int end)
{
int pivot=marks[end];
int P_index=start;
int i,t;
for(i=start;i<end;i++)
{
if(marks[i]<=pivot)
	{
	t=marks[i];
	marks[i]=marks[P_index];
	marks[P_index]=t;
	 P_index++;
	 }
}
t=marks[end];
marks[end]=marks[P_index];
marks[P_index]=t;
return P_index;
}
void Quicksort(int *marks,int start,int end)
{
if(start<end)
{
	int P_index=partition(marks,start,end);
	Quicksort(marks,start,P_index-1);
	Quicksort(marks,P_index+1,end);
}
}
void min_heapify(int *b, int i, int n)
{
    int j, temp;
    temp = b[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && b[j + 1] < b[j])
        {
            j = j + 1;
        }
        if (temp < b[j])
        {
            break;
        }
        else if (temp >= b[j])
        {
            b[j / 2] = b[j];
            j = 2 * j;
        }}
    b[j / 2] = temp;
    return;
}
void build_minheap(int *b, int n)
{
    int i;
    for(i = n / 2; i >= 1; i--)
    {
        min_heapify(b, i, n);
    }
}
void addEdge(int am[][7], int src, int dest, int cost)
{
     am[src][dest] = cost;
     return;
}
void bell(int am[][7])
{
    int i, j, k, c = 0, temp;
    a[0].cost = 0;
    a[0].from = 0;
    a[0].value = 0;
    for (i = 1; i < 7; i++)
    {
        a[i].from = 0;
        a[i].cost = INFINITY;
        a[i].value = 0;
    }
    while (c < 7)
    {
        int min = 999;
        for (i = 0; i < 7; i++)
        {
            if (min > a[i].cost && a[i].value == 0)
            {
                min = a[i].cost;
            }
            else
            {
                continue;
            }
        }
        for (i = 0; i < 7; i++)
        {
            if (min == a[i].cost && a[i].value == 0)
            {
                break;
            }
            else
            {
                continue;}}
        temp = i;
        for (k = 0; k < 7; k++)
        {
            if (am[temp][k] + a[temp].cost < a[k].cost)
            {
                a[k].cost = am[temp][k] + a[temp].cost;
                a[k].from = temp;
            }
            else
{
                continue;
            }}
        a[temp].value = 1;
        c++;
    }
    cout<<"Cost"<<"\t"<<"Source Node"<<endl;
    for (j = 0; j < 7; j++)
    {
        cout<<a[j].cost<<"\t"<<a[j].from<<endl;
    }}
