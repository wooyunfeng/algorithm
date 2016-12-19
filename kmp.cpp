#include <bits/stdc++.h>
using namespace std;

void getNext(int *next,char *s,int ls)
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<ls)
    {
        if(j==-1||s[i]==s[j])
        {
            i++,j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int kmp(int *next,char *t,char *s,int lt,int ls)
{
    int i=0,j=0;
    while(i<lt&&j<ls)
    {
        if (j==-1||t[i]==s[j])
        {
            i++,j++;
        }
        else
            j=next[j];
    }
    if (j>=ls)
        return i+1-ls;
    else
        return -1;
}
int main(int argc, char const *argv[])
{
    char a[]="BBABBCAC";
    cout<<a<<endl;
    int next[10];
    getNext(next,a,8);
    for (int i = 0; i < 8; ++i)
    {
        cout<<next[i]<<",";
    }
    cout<<endl;
    char b[]="BCAC";
    //cout<<kmp(next,a,b,8,4)<<endl;
    return 0;
}
