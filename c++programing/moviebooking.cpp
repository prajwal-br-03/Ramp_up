#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;
mutex mut1;
mutex mut2;


class seat{

public:

    seat(){

        state = available;

    }

    int seatnumber;

    enum status{

        reserved,
        available
        };
    status state;    
};

class theater{

public:

    seat s[30];
    theater(){

        for(int i=0;i<30;i++){
            s[i].seatnumber = i+1;
        }
    }

    void showavaliableseats(){

        cout<<"seats available are:"<<endl;
        for(int i=0;i<30;i++){
            if(s[i].state == seat::available){
                cout<<s[i].seatnumber<<"  ";
            }
        }

        cout<<endl;
    }

    void reserveseat(int sn){

        mut1.lock();

         for(int i=0;i<30;i++){
             if(s[i].seatnumber == sn){
                 s[i].state = seat::reserved;
                 cout<<"Seat Number "<<sn<<" succesfully reserved"<<endl;
             }
         }

         mut1.unlock();
    }

    void cancelseat(int sn){
        mut2.lock();
        for(int i=0;i<30;i++){
             if(s[i].seatnumber == sn){
                 s[i].state = seat::available;
                 cout<<"your seat reservation has been cancled"<<endl;

             }}

        mut2.unlock();

    } 
};
 
void customeroperation(theater& th,int sn,string name,bool reserve){
    if(reserve){

        th.reserveseat(sn);
         th.showavaliableseats();

    }else{

        th.cancelseat(sn);
        th.showavaliableseats();
    }
    }
 
int main(){

    theater th;
    cout<<"select a seat number you want to book or cancle"<<endl;

     th.showavaliableseats();

    std::thread customer1(customeroperation,std::ref(th),12,string("supriya"),true);

    std::thread customer2(customeroperation,std::ref(th),13,string("himani"),true);

    std::thread customer3(customeroperation,std::ref(th),13,string("himani"),false);

    customer1.join();

    customer2.join();

    customer3.join();
}
 
