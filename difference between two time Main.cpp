#include <iostream> //jeeva=2003
#include<string>
using namespace std;
void process(string wrr)
{
  int arr[10]; // creating empty array to have hours sepereated from sentence
  int art[10]; // creating empty array to have minutes seperated from the sentence we are getting as input
  int b=0;
  string sr=""; // empty string to append the number
  string zone="";
  for (int i=0;i<wrr.length();i++) // loop continuous based on the length of string
  {
    if(wrr[i]==':') // as we clearly see the hours and minutes are written before and after (:)
    {
      
      if((i-2)>=0 && wrr[i-2]!=' ')  // the might be two digit or one digit so if it's two digit we already know the index of : so by decrementing the i value can acces the number as individual character
      {
        sr+=wrr[i-2]; // adding the first number of hour in the sr string holding variable
      }
      sr+=wrr[i-1];// adding the second number of the hour 
      int ref=stoi(sr); // if we have a number as a string we can convert it again to number by usin stoi string to int keyword
      zone+=wrr[i+4];
      
      zone+=wrr[i+5]; // zone is used to determine whether it is am or pm
      if(zone=="pm" && ref<12)
      {
        ref+=12; //once we found it's a pm and the hour is less than 12 then we add 12 with the number to convert it into 24 hours format
      }
      arr[b]=ref;
      zone="";// emptying the zone 
      sr=""; // emptying the number holding string
      sr+=wrr[i+1];
      if(wrr[i+2]!=' ')// this condition is to determine the minutes even minutes have two digit and single digit
      {
        sr+=wrr[i+2];
      }
      
      // here we don't have to check the am or pm because it's processing the minutes
      art[b]=stoi(sr);
      
      b+=1;
      sr="";
    }
  }
  int deff=abs(arr[0]-arr[1]); // to determine the difference in hour abs is used to return only the positive value
  int rdd=abs(art[0]-art[1]); //to determine the difference in minutes
  int hour=(((deff*60)-rdd)/60); // we are converting the differece in hour to minutes and sub with the diffenece in minutes then dividing it with 60 gives the exact hour
  int minutes=(((deff*60)-rdd)%60);  // so when we find the percentage of it we get to know the minutes remaining
  
    cout<<"Diffrence  " <<hour<<':'; //printing hours and minutes
    cout<<minutes;
}
int main() 
{
  string word;
  getline(cin,word);// To get a time in sentence
  process(word); // function call with the parameter
}
