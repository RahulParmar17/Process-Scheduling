#include<iostream>
using namespace std;

class PRIO
{
public:
    int i,j;
    int n;
    int bt[20],p[20],wt[20],tat[20],pr[20];
    float total;//It is not a static variable
    int pos,temp;
    float avwt,avtat;

  public void disAvgT(float x,float y)
    {
        cout<<"\n\nAverage Waiting Time:"<<x;
        cout<<"\nAverage Turnaround Time:"<<y;
    };
   public void getdata()
    {
        cout<<"Enter Total Number of Process:";
        cin>>n;
        cout<<"\nEnter Burst Time and Priority\n";
        for(i=0; i<n; i++)
        {
            cout<<"\nP["<<i+1<<"]\n";
            cout<<"Burst Time:";
            cin>>bt[i];
            cout<<"Priority:";
            cin>>pr[i];
            p[i]=i+1;           //contains process number
        }

        //sorting burst time, priority and process number in ascending order using selection sort
        for(i=0; i<n; i++)
        {
            pos=i;
            for(j=i+1; j<n; j++)
            {
                if(pr[j]<pr[pos])
                    pos=j;
            }

            temp=pr[i];
            pr[i]=pr[pos];
            pr[pos]=temp;

            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;

            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }

//void display(){
        wt[0]=0;            //waiting time for first process is zero

        //calculate waiting time
        for(i=1; i<n; i++)
        {
            wt[i]=0;
            for(j=0; j<i; j++)
                wt[i]+=bt[j];

            total+=wt[i];
        }
    };
   public void display()
    {
        avwt=total/n;      //average waiting time
        total=0;

        cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
        for(i=0; i<n; i++)
        {
            tat[i]=bt[i]+wt[i];     //calculate turnaround time
            total+=tat[i];
            cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
        }

        avtat=total/n;
        disAvgT(avwt,avtat);  //average turnaround time
    };
} 



int main()
{
    PRIO pr;
    pr.getdata();
    pr.display();

    return 0;
}
