#include<iostream>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

class encryption
{
       public:
              long int p,q,n,t,flag,e[1000],d[1000],temp[1000],j,m[1000],en[1000],i;
              string msg;

                void setpq(long pp,long qq)
                {
                    p=pp;
                    q=qq;
                    n=p*q;
                    t=(p-1)*(q-1);
                }
                void setstr(string ss)
                {
                    msg=ss;
                    for(i=0;i<msg.size();i++)
                    {
                           m[i] = msg[i];
                    }
                }
              int prime(long pr)
              {
                     int i;
                     j=sqrt(pr);
                     for (i=2;i<=j;i++) {
                           if(pr%i==0)
                               return 0;
                     }
                     return 1;
              }
              void ce()
              {
                     int k;
                     k=0;
                     for (i=2;i<t;i++)
                     {
                           if(t%i==0)
                               continue;
                           flag=prime(i);
                           if( flag==1 && i!=p && i!=q)
                           {
                                  e[k]=i;
                                  flag=cd(e[k]);
                                  if(flag>0) {
                                         d[k]=flag;
                                         k++;
                                  }
                                  if(k==999)
                                          break;
                           }
                     }
                     for (i=0;i<j-1;i++)
                     {
                           cout<<(i+1)<<"\t("<<e[i]<<","<<d[i]<<")"<<endl;
                     }
                     cout<<endl;
              }
              long int cd(long int x)
              {
                     long int k=1;
                     while(1) {
                           k=k+t;
                           if(k%x==0)
                               return(k/x);
                     }
              }
              void encrypt(int x)
              {
                     long int plaintxt,cyphertxt,key=e[x-1],k,len;
                     char y[20];
                     cout<<"Value of e used is "<<key<<endl;
                     i=0;
                     len = msg.size();
                     while(i!=len)
                     {
                           plaintxt=m[i];
                           plaintxt=plaintxt-96;
                           k=1;
                           for (j=0;j<key;j++)
                           {
                                  k=k*plaintxt;
                                  k=k%n;
                           }
                           temp[i]=k;
                           cyphertxt=k+96;
                           en[i]=cyphertxt;
                           i++;
                     }
                     en[i]=-1;
                     cout<<"\n\t\t\t\t\tThe Encrypted Message : "<<endl;
                     for (i=0;en[i]!=-1;i++)
                     cout<<(char)en[i];
                     cout<<"\n\t\t\t\t\tEnter a file name where you want to save the encrypted data:";
                     cin>>y;
                     ofstream fout;
                     fout.open(y);
                     for (i=0;en[i]!=-1;i++)
                     fout<<(char)en[i];
                     cout<<endl<<"\n\t\t\t\t\tData encrypted successfully and saved in file "<<y<< "!!!"<<endl;
              }
              void decrypt(int x)
              {
                     long int plaintxt,cyphertxt,key=d[x-1],k;
                     cout<<"\n\t\t\t\t\tValue of d used is "<<key<<endl;
                     i=0;
                     while(en[i]!=-1)
                     {
                           cyphertxt=temp[i];
                           k=1;
                           for (j=0;j<key;j++) {
                                  k=k*cyphertxt;
                                  k=k%n;
                           }
                           plaintxt=k+96;
                           m[i]=plaintxt;
                           i++;
                     }
                     m[i]=-1;
                     char y[20];
                     ofstream fout;
                     cout<<"\n\t\t\t\t\tThe Decrypted Message : "<<endl;
                     for (i=0;m[i]!=-1;i++)
                     cout<<(char)m[i];
                     cout<<"\n\n\t\t\t\t\tEnter file name you in which you want to store the data:";
                     cin>>y;
                     fout.open(y);
                     for (i=0;m[i]!=-1;i++)
                     fout<<(char)m[i];
                     cout<<endl<<"\n\t\t\t\t\tData decrypted successfully and stored in file "<<y<<"!!!"<<endl;
                     fout.close();
              }
};


int main()
{
       encryption ob;
       long i,p,q,x,choice;
       system("color 02");
       while(1)
       {
            for(i=0;i<60;i++)
                cout<<"__";
           cout <<"\n\t\t\t\t\t\tMENU\n";
            for(i=0;i<80;i++)
                {if(i%2==0)
                    cout<<"__";
                else
                    cout<<" ";}
           cout<<"\n\t\t\t\t\t1.Enter 2 prime no.s\n\t\t\t\t\t2.Enter data to encrypt\n\t\t\t\t\t3.choose public key\n\t\t\t\t\t4.encrypt data\n\t\t\t\t\t5.decrypt data\n\t\t\t\t\t6.exit"<<endl<<"\n\t\t\t\t\tEnter your choice:";
           cin >> choice;
           switch(choice)
           {
               case 1:
                {
                    cout<<"\n\t\t\t\t\tEnter the Prime Numbers P & Q:";
                    cin>>p>>q;
                    int a,x;
                    int b= sqrt(p);
                    for (a = 2; a <= b; a++)
                    {
                        if (p % a == 0)
                            x = 0;
                        else
                            x=1;
                    }
                    if(x==0)
                    {
                        cout << "\n\t\t\t\t\tFirst entered prime no is Wrong input.";

                    }
                    b = sqrt(q);
                    for (a = 2; a <= b; a++)
                    {
                        if (q % a == 0 || p==q)
                            x = 0;
                        else
                            x = 1;
                    }
                    if(x==0)
                    {
                        cout << "\n\t\t\t\t\tFirst second prime no is Wrong input.";
                        exit(1);
                    }
                    ob.setpq(p,q);
                }
                    break;

       case 2:
        {
            string msg;
            char xx[100];
            cout<<"\n\t\t\t\t\tEnter file name from which you want encrypt the data:";
            cin>>xx;
            ifstream fin(xx);
            if(fin.is_open())
            {
                while(getline(fin,msg))
                {
                    cout<<msg<<'\n';
                }
                fin.close();
            }
            else
                cout<<"\n\t\t\t\t\tFile not open";
            ob.setstr(msg);
        }
            break;

        case 3:
         {
            cout<<"\n\t\t\t\t\tPossible values of (e,d) are"<<endl<<endl;
            ob.ce();
            cout<<"\n\t\t\t\t\tChose which values of (e,d) you want to use?";
            cin>>x;
            cout<<endl;
         }
            break;

        case 4:
            ob.encrypt(x);
            break;

        case 5:
            ob.decrypt(x);
            break;
       case 6:exit(0);
           }
       }
       return 0;
}
