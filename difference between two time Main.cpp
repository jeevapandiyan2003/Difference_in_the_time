#include <iostream>
#include<string>
using namespace std;
void process(string wrr)
{
  int arr[10];
  int art[10];
  int b=0;
  string sr="";
  string zone="";
  for (int i=0;i<wrr.length();i++)
  {
    if(wrr[i]==':')
    {
      
      if((i-2)>=0 && wrr[i-2]!=' ')
      {
        sr+=wrr[i-2];
      }
      sr+=wrr[i-1];
      int ref=stoi(sr);
      cout<<zone;
      zone+=wrr[i+4];
      
      zone+=wrr[i+5];
      if(zone=="pm" && ref<12)
      {
        ref+=12;
      }
      arr[b]=ref;
      zone="";
      sr="";
      sr+=wrr[i+1];
      if(wrr[i+2]!=' ')
      {
        sr+=wrr[i+2];
      }
      
      
      art[b]=stoi(sr);
      
      b+=1;
      sr="";
    }
  }
  int deff=abs(arr[0]-arr[1]);
  int rdd=abs(art[0]-art[1]);
  int hour=(((deff*60)-rdd)/60);
  int minutes=(((deff*60)-rdd)%60);
  
    cout<<"Diffrence  " <<hour<<':';
    cout<<minutes;
}
int main() 
{
  string word;
  getline(cin,word);
  process(word);
}