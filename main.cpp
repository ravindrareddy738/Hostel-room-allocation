#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Test{
   int x; string y ; float z;
};

void Allocateroom( vector<Test> &v, map<int , vector<string>> &mp ){


// Using max heap we arrange students on highest percentage to allocate rooms;



   priority_queue<pair<double,string>>pq;


   for(int i =0; i< v.size(); i++){

    pq.push({v[i].z , v[i].y});

   }




   //Storing students in categorised rooms
   vector<string> ac2share ;
  vector<string> ac3share ;
  vector<string> nonac4share ;
  vector<string>nonac6share ;


//Intializing every room with 1
// Using hold as to count maximum capacity for a specific room

   int c1 = 1;      int hold = 0;
   int c2 = 1;       int hold2 = 0;
   int c4 = 1;      int hold4 =0;
   int c6 = 1;       int hold6 = 0;



  while (!pq.empty()){


double percentage =  pq.top().first;



    if (percentage > 90 && percentage <= 100)

        {


             if(hold == 2){
                c1++;
                hold = hold-2;
                ac2share.clear();


              }
              ac2share.push_back(pq.top().second);
              mp[c1] = ac2share;

            hold ++;

              c2 = c1+1;
              c4 = c1+1;
              c6 = c1+1;
    }


    else if (percentage > 80 && percentage <= 90)
        {


            if(hold2 == 3){
                c2++;
                hold2 =0;
                ac3share.clear();
              }
           ac3share.push_back( pq.top().second);
             mp[c2] = ac3share;


              hold2++;


              c4 = c2+ 1;
              c6 = c6+1;

    }


else if (percentage > 70 && percentage <= 80 )
        {


            if(hold4 == 4){
                c4++;
                hold4 = 0;
                nonac4share.clear();
              }

                nonac4share.push_back( pq.top().second);
             mp[c4] = nonac4share;


              hold4++;


              c6 =c4+1;


    }

     else if (percentage > 60 &&percentage <= 70)
        {


            if(hold6 == 6){
               c6++;
                hold6 = 0;
                nonac6share.clear();
            }
            nonac6share.push_back(pq.top().second);
           mp[c6] = nonac6share;
           hold6++;
       }



    pq.pop();
   }




}






int main(){

cout<<"                     "<<"STUDENT HOSTEL ROOM ALLOCATION BASED ON THEIR PERCENTAGES" << endl;

cout<< "There are 4 different types of rooms available with varying capacity and features"<<endl;
cout<< "Air Conditioned 2 sharing  : students  above 90%"<<endl;
cout<< "Air Conditioned 3 sharing  : students  between  80% and 90%"<<endl;
cout<< "Non-Air Conditioned 2 sharing  : students  between  70% and 80%"<<endl;
cout<< "Non-Air Conditioned 2 sharing  : students between 60% and 70%"<<endl;


int n ;

cout <<"Enter Total number of students:  "<<endl;

cin >>n ;

if(n<1){
cout<< "Enter valid number  :"<<endl;
cin>>n;
}

//Taking input in triplet vector
vector<Test>v ;
int a;
string b;
float s;

cout<< " *****  Roll number must be integer and unique  *****    percentage must be 60 and above  **** "<< endl;

for(int i = 0 ; i<n; i++){



cout<<"Enter student roll number:  "<<endl;
 cin>>s;
 cout<<"Enter student name:  "<<endl;
 cin>>b;
 cout<<"Enter percentage:  "<<endl;
 cin>>s;

 v.push_back({a,b,s});

 }








//storing Room number with students in that room
 map<int , vector<string>> mp ;

cout << "                                            " << endl;

  Allocateroom(v ,mp);

cout << "                                            " << endl;

cout << "Totalrooms allocated :  " << mp.size()<<  endl;

// Printing rooms and respective students in that room

 for(auto it : mp){
    cout<<"Room number " <<it.first<< "  "<<endl;
    for(auto x : it.second){
     cout<<x<<"  "<< endl;
   }
  }

return 0;
}
