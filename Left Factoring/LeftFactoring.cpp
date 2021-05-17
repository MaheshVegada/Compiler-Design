#include <bits/stdc++.h>
using namespace std;
int main()
{
	string terms,temp;
	cout<<"Enter the Terms:";
	cin>>terms;
	vector<string> productions;
	for(int i=3;i<terms.length();i++)
	{
		if(terms[i]=='|')
		{
			productions.push_back(temp);
			temp="";
		}
		else
		{
			temp+=terms[i];
		}
	}
	if(temp!="")
	{
		productions.push_back(temp);
	}
	vector<string> proLeft(productions.size()),proRight(productions.size());
	for(int i=0;i<productions.size();++i) {
		proLeft[i]=terms[0];
		proRight[i]=productions[i];
	}
	int p=productions.size();
	int e=1;
	for(int i=0;i<p;++i)
	{
		for(int j=i+1;j<p;++j)
		{
			if(proLeft[j]==proLeft[i])
			{
				int k=0;
				string str="";
				while(k<proRight[i].length()&&k<proRight[j].length()&&proRight[i][k]==proRight[j][k])
				{
					str+=proRight[i][k];
					++k;
				}
				if(k==0)	continue;
				string leftstr=proLeft[i];
				if(k==proRight[i].length())
				{
					proLeft[i]+=string(to_string(e));
					proLeft[j]+=string(to_string(e));
					proRight[i]="^";
					proRight[j]=proRight[j].substr(k,proRight[j].length()-k);
				}
				else if(k==proRight[j].length())
				{
					proLeft[i]+=string(to_string(e));
					proLeft[j]+=string(to_string(e));
					proRight[j]="^";
					proRight[i]=proRight[i].substr(k,proRight[i].length()-k);
				}
				else
				{
					proLeft[i]+=string(to_string(e));
					proLeft[j]+=string(to_string(e));
					proRight[j]=proRight[j].substr(k,proRight[j].length()-k);
					proRight[i]=proRight[i].substr(k,proRight[i].length()-k);
				}
				int l;
				for(l=j+1;l<p;++l)
				{
					if(leftstr==proLeft[l]&&str==proRight[l].substr(0,fmin(k,proRight[l].length()))) 
					{
						proLeft[l]+=string(to_string(e));
						proRight[l]=proRight[l].substr(k,proRight[l].length()-k);
					}
				}
				proLeft.push_back(leftstr);
				proRight.push_back(str+proLeft[i]);
				++p;
				++e;
			}
		}
	}
	map<string,vector<string>>store;
	vector<string> order;
	map<string,bool> check;
	for(int i=p-1;i>=0;i--)
	{
		store[proLeft[i]].push_back(proRight[i]);
		if(check[proLeft[i]]==false)
		{
			check[proLeft[i]]=true;
			order.push_back(proLeft[i]);
		}
	}
	cout<<"Final Terms after eliminating Left Factor"<<endl;
	for(auto i:order)
	{
		cout<<i<<"->";
		string result;
		for(auto l:store[i])
		{
			result+=l;
			result+='|';
		}
		result.pop_back();
		cout<<result<<endl;
	}
}
