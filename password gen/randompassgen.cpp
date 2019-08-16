//Rafaela Peralva
//A password generator between 8-16 characters
//June 21, 2019

#include <iostream>
#include <cstdlib>
#include <sstream>  //used to convert numbers into strings
#include <string>  
using namespace std;

class Password{
    private:
        string one;
        int two;
        string three;
        string pass;
        string numbers;
    public:
        Password(int size);
        int sizepass;
        string getLetters();
        string getNum();
        string getSym();

};

Password::Password(int size){//makes sure that it will reset everytime it is called
    pass=' ';
    //one=' ';
    sizepass=size-2;
}

string Password::getLetters(){//gets the letter component of password
    srand(time(NULL));//starts rand
    for (int i=0; i<(sizepass/2); i++){
       int cnum= rand() % 122+97;//ranges on lowercase letters
       while (cnum>122){
           cnum= rand() % 122+97;
       }
       cout<<cnum<<" number" <<endl;
       cout <<char(cnum)<<" char"<<endl;
       //char c= char(cnum);
       //cout << c <<endl;
       if (cnum<=122){
           one= one+char(cnum);

       }
    }
    return one;
}

string Password::getNum(){
    int numsize= sizepass-sizepass/2;
    ostringstream numstring;//string to convert numbers
    for (int i=0; i<numsize; i++){
        int randnum = rand() %10; //gets a random number from 0-9
        numstring <<randnum; //used to convert to numbers
        numbers = numstring.str();//adds the number to the final string of numbers

        cout<< numbers<< " random number"<<endl;
    }
    return numbers;
}

int main(){
    int size;
    cout<<"Enter password size smaller than 16: "<<endl;
    cin>>size;
    while (size>16){
        cout<<"Enter password size: "<<endl;
        cin>>size;

    }

    Password f(size);
    cout<< f.getLetters()<<" main"<<endl;
        cout<<f.getNum()<<" pass number"<<endl;

}

