#include <bits/stdc++.h>
using namespace std;
int NT,nb;//NT=number of Terms in Sum of Prodacut nb=number of bits
vector<string>odd;
vector<string>nameodd;
vector<string>decsop;
vector<string>binsop;


int intersection(string x, string y)
{
    int r=0,j=0;
    for(int i=0;i<x.size();i++)
    {
        if(y[j]==x[i]&&(i==0||x[i-1]==','))
        {
            r=0;
           while(x[i]!=','&&i!=x.size())
           {
                if(x[i]!=y[j])
                {
                    r=0;
                    j=0;
                    break;
                }
                r++;
                i++;            
                j++;

           } 
           i--;  
        }
    }
    if(r==y.size())return 1;
    return 0;
}
int ones(string s)
{
    int x=0;
    for (int i = 0; i < nb; i++)
    {
        if(s[i]=='1')x++;
    }
    return x;
}
string compare(string x,string y)
{
    int b=0,s=0,r=0;
    for (int i = 0; i < nb; i++)
    {
       if(x[i]!=y[i]){
        s++;
        b=i;
       }
       if(x[i]=='0'&&y[i]=='1')r++;
       if(s==2)break;
    }
    if(s==1&&r==1){
        x[b]='-';
        return x;
    }
    else return "";
    
}
bool compression(vector<string>z,vector<string>x)
{
    if(x.size()==0)return false;
    vector<int>oo;
    string tt;
    int ff,u=x.size();
     vector<bool>test(u,false);
    for (int i = 0; i < u; i++)
    { 
        ff =ones(x[i]);
        oo.push_back(ff);
    }
    for (int i = 0; i < u; i++)
    {
        for(int j=i+1;j<u;j++)
        {
            int rt=oo[i]+1,tr=oo[j];
            if(rt==tr){
                tt=compare(x[i],x[j]);
                if(tt!="")
                {
                    cout<<z[i]<<','<<z[j]<<"  "<<tt<<'\n';
                    binsop.push_back(tt);
                    decsop.push_back(z[i]+','+z[j]);
                    test[i]=test[j]=true;

                }
            }
            if(oo[i]+2==oo[j])break;
        }
        if(!test[i]){
            bool uio=true;
            for(int cs=0;cs<odd.size();cs++){
                if(odd[cs]==x[i]){
                    uio=false;
                    break;
                }
            }
            if(uio){
                odd.push_back(x[i]);
            nameodd.push_back(z[i]);
            }
            
        }
    }
    cout<<"-----------\n";
    return true;

}
int BinaryToDec(string s)
{
    int y=0;
    for(int i=0;i<nb;i++)
    {
        y=y+(s[i]-'0')*pow(2,nb-1-i);
    }
    return y;
}
string DecToBinary(string y)
{
    int x=stoi(y);
    string s="";
    for (int i = 0; i < nb; i++)
    {
        s=to_string(x%2)+s;
        x=(x-x%2)/2;
    }
    return s;

}


int main()
{
    int rrr=0;
    cout<<"besme allah elrhman elrhem\n";
    cout<<"this done by Hossam Abohadima to help you not to cheat\n";
    cout<<"for any problem , help or suggestion tell me Hossamabohadima@gmail.com\n";
    cout<<"Number of bits\n";
    //nb=4;
    cin>>nb;
    cout<<"is there don't care?(y,n)\n";
    char v;
    cin>>v;
    cout<<"Number of Terms in Sum of Prodacut with out don't care\n";
    cin>>NT;
    //NT=11;
    vector<string>sop(NT);
    vector<string>colom(NT);
    vector<string>Sop(NT);
    vector<int>oo(NT);
    string tt;
    int ff;
    for (int i = 0; i < NT; i++)
    {
        cin>>sop[i];
        colom[i]=sop[i];
        Sop[i]=DecToBinary(sop[i]);
        oo[i] =ones(Sop[i]);
    }
    if(v=='y'){
        cout<<"Number of Terms don't care\n";
        
        string qw;
        cin>>rrr;
        for (int i = 0; i < rrr; i++)
    {
        cin>>qw;
        sop.push_back(qw);
        Sop.push_back(DecToBinary(qw));
        oo.push_back(ones(Sop[Sop.size()-1]));
    }
    NT+=rrr;
    }
    for(int i=0;i<NT;i++){
        for (int j = 0; j < NT-1; j++)
        {
            if(oo[j]>oo[j+1]){
                ff=oo[j+1];
                oo[j+1]=oo[j];
                oo[j]=ff;
                tt=Sop[j+1];
                Sop[j+1]=Sop[j];
                Sop[j]=tt;
                tt=sop[j+1];
                sop[j+1]=sop[j];
                sop[j]=tt;
            }
        }
        
    }

    for (int i = 0; i <NT ; i++)
    {  
        cout<<sop[i]<<"  "<<Sop[i]<<"\n";
    }
    cout<<"-----------\n";

    while(compression(sop,Sop))
    { 
        
        sop.clear();
        Sop.clear();
        for(int i=0;i<decsop.size();i++)
        {
            sop.push_back(decsop[i]);
            Sop.push_back(binsop[i]);
        }
        decsop.clear();
        binsop.clear();

    }
   /*
    for(int i=0;i<odd.size();i++){
        cout<<nameodd[i]<<"    "<<odd[i]<<"\n";
    }
*/
    NT-=rrr;
    vector<vector<int>> mat( odd.size() , vector<int> (NT, 0));
    cout<<"this is the intersection\n";
    for (int i = 0; i < colom.size(); i++)
    {
        cout<<colom[i]<<" ";
    }
    cout<<"\n";
    for (int i = 0; i < odd.size(); i++)
    {
        
        for (int j = 0; j < NT; j++)
        {
            mat[i][j]=intersection(nameodd[i],colom[j]);
            cout<<mat[i][j]<<" ";
        }   
        cout<<"    "<<nameodd[i]<<"\n";
    }
    while(true)
    {
        int q,w,f=99999;
        long long g=0;
            for(int i=0;i<NT;i++)
            {
                int sum=0;
                for (int j = 0; j < odd.size(); j++)
                {
                    if(mat[j][i]==0)continue;
                    sum+=mat[j][i];
                }
                if(sum==0){
                    continue;
                }
                if(f>=sum){
                    f=sum;
                    q=i;
                }
            }
            if(f==99999){
                    break;;
                }
            for (int j = 0; j < odd.size(); j++)
                {
                    if(mat[j][q]==1){
                        w=j;
                        break;
                    }
                }
                Sop.push_back(nameodd[w]);
                sop.push_back(odd[w]);
            for (int j = 0; j < NT; j++)
                {
                    if(mat[w][j]==1)
                    {
                        for (int i = 0; i < odd.size(); i++)
                        {
                            mat[i][j]=0;
                        }
                    }
                }
    }
    cout<<"this is the function\n"<<"f()=";
    for (int i = 0; i < sop.size(); i++)
    {
        tt="";
        string c=sop[i];
        for(int j=0;j<nb;j++){
            if(c[j]=='-')continue;
            else if(c[j]=='1')tt=tt+char(65+j);
            else tt=tt+char(65+j)+'\'';
        }
        if(sop.size()-1==i)cout<<tt;
        else
            cout<<tt<<"+";
    }
    cin>>tt; 
}