#include <iostream>
using namespace std;

int main (){
    long int s,n;
    cin>>n;
    s=0;
    long int a[n],b[n+1];
    for(int i=0;i<=n-1;i++)
    { long int x;
        cin>>x;
        s=s+x;
        a[i]=x;
    }
    b[0]=0;
    b[1]=a[0];
    int k=-1;
    for (int i=0;i<=n-1;i++ )
    {
        b[i+1]=a[i]+b[i];
        if(b[i]==s-b[i+1]) { cout<<i;
            k=1;
            break;
        }}
    if(k==-1) { cout<<k;
    }
    return 0;
}