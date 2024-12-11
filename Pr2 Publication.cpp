// Imagine a publishing company which does marketing for book and audio cassette 
// versions.Create a class publication that stores the title (a string) and price (type float) of
// publications. From this class derive two classes: book which adds a page count (type int) 
// and tape which adds playing time in minutes (type float).
// Write a program that instantiates the book and tape class, allows user to enter data and
// displays the data members. If an exception is caught, replace all the data member values 
// with
// zero values.

// to learn - Exceptional handeling and inheritance

#include <iostream>
#include <stdexcept>
using namespace std;

class publication {
protected:
    string title;
    float price;
public:
    void getdata(){

        cout<<"Enter the title of the publication ::";
        cin>>title;
        cout<<"Enter the price of publication ::";
        cin>>price;
        if(price<=0){
            throw runtime_error("Price can't be smaller than or equal to 0 ");
         }
    }

    void getdisplay(){
        cout<<"Title of the publication is ::"<<title<<endl;
        cout <<"Price of the publication is ::"<<price<<endl;
    }

    void reset(){
        title="Unknown";
        price=0.0f;
    }
};

class book : public publication{
    int PageCount;
    public:
        void getCount(){
            cout<<"Enter the number of pages of the book ::";
            cin>>PageCount;
            if(PageCount<=0){
            throw runtime_error("Page Count can't be smaller than or equal to 0 ");
         }
        }
        
        void displayCount(){
            cout<<"Number of pages of book ::"<<PageCount<<endl<<"\n\t";
        }
        void reset(){
        publication::reset();
        PageCount=0.0f;
    }
};

class tape : public publication{
    float PlayTime;
    public:
        void getTime(){
            cout<<"Enter the Playing time of tape in minutes ::";
            cin>>PlayTime;
            if(PlayTime<=0){
            throw runtime_error("Play Time  can't be smaller than or equal to 0 ");
         }
        }
        void displayTime(){
            cout<<"Playing time of the tape is ::"<<PlayTime<<endl;
        }
        void reset(){
        publication::reset();
        PlayTime=0.0f;
    }
};

int main(){
    cout<<"**********BOOK*********"<<endl;
    book b1;
    try{
    b1.getdata();
    b1.getCount();
    b1.getdisplay();
    b1.displayCount();
    }
    catch(const runtime_error &e){
        cout<<"Exception::"<<e.what();
        b1.reset();
        cout<<"Data is reset ::"<<endl;
        b1.getdisplay();
        b1.displayCount();
    }

    cout<<"************TAPE***********"<<endl;
    tape t1;
    try{
    t1.getdata();
    t1.getTime();
    t1.getdisplay();
    t1.displayTime();
    }
    catch(const runtime_error &e){
        cout<<"Exception::"<<e.what();
        t1.reset();
        cout<<"Data is reset ::"<<endl;
        t1.getdisplay();
        t1.displayTime();
    }

    return 0;
}