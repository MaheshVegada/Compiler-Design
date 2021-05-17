#include<iostream>
#include<string.h>
using namespace std;

char first[10];
char second[10];

void print(int k,int m)
{
    if(m==1)
    {
    	for(int i=0;i<k;i++)
    	{
        	cout<<first[i];
    	}
	}
	else if(m==2)
	{
		for(int i=0;i<k;i++)
	    {
	        cout<<second[i];
	    }	
	}
}
int main()
{
	int test=1;
	cout<<"For End checking press: #\n";
	while(test)
	{
	    string s;
	    cout<<"Enter the String: ";
	    cin>>s;
	    if(s=="#")
		{
			test=0;
			return 0;
		}
	    int i=-1;
	    int len=s.length();
	    
	    if(s[0]==s[3])
	    {
	        while(s[++i]!='|'){}
	        int p=0,k=0;
	        for(int m=4;m<i;m++)
	        {
	            first[p++]=s[m];
	        }
	        for(int j=i+1;j<=len;j++)
	        {
	            second[k++]=s[j];
	        }
	        cout<<s[0]<<"->";
	        print(k-1,1);
	        cout<<s[0]<<'\''<<endl;
	        cout<<s[0]<<'\''<<"->";
	        print(p,2);
	        cout<<s[0]<<'\''<<"|"<<"^"<<endl<<endl;
	    }
	    else
		{
	        cout<<"There is no Left recursion"<<endl<<endl;
	    }
	}
}

