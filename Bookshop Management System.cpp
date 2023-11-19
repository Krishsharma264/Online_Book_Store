#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    string name;
    int Book_price;
    Node *next;
    Node *prev;

};

class Bookstore{
    public:
    Node *head;
    Node *mid;
    string Book_name;
    int price;

    Bookstore(){
        head = NULL;
    }
    void CreateNode(){
        if(head == NULL){
            Node *new_node = new Node;
            cout<<"Name of BOOK: ";
            cin.ignore();
            getline(cin,Book_name);
            new_node->name = Book_name;

            cout<<"BOOK Price: ";
            cin>>price;
            new_node->Book_price=price;

            new_node->next=NULL;
            new_node->prev == NULL;
            head = new_node;

            cout<<"BOOK ADDED"<<endl;

        }
        else{
            Node *new_node = new Node;
            cout<<"Name of BOOK: ";
            cin.ignore();
            getline(cin,Book_name);
            new_node->name = Book_name;

            cout<<"BOOk PRICE: ";
            cin>>price;
            new_node->Book_price=price;

            new_node->next=NULL;

            Node *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev=temp;
            cout<<"Book Added "<<endl;
        }
    }

    void Display(){
        Node *temp=head;
        int count =0;

        if(temp == NULL){
            cout<< " NO BOOKS .. PLEASE ADD sOME BOOKS"<<endl;
            cout<<"THANKS"<<endl;
        }else{
            BubbleSort();

            cout<<"\n Book Name "
                <<"    BOOK PRice\n"
                <<endl;

            while(temp != NULL){
                count++;
                cout<< " " << temp->name << ":";
                cout<<" "<<temp->Book_price<<endl;
                temp=temp->next;
            }
            cout<<"\n\n Total BOOKs: "<<count <<endl;
        }
    }

    bool Bsearch(){
        cout<<"Enter BOOK name "<<endl;
        cin.ignore();
        getline(cin,Book_name);

        Node *temp = head;
        Node *left =head;
        Node *right =head;

        while(right->next != NULL && right->next->next != NULL){
            left = left->next;
            right = right->next->next;
        }
        mid =left;

        while(mid!=NULL){
            if(mid->name == Book_name){
                cout<<"Book is found "<<endl;
                cout<<"Book name : "<<mid->name <<endl;
                cout<<"Book price: "<<mid->Book_price<<endl;

                return true;
            }
            else if(mid->name > Book_name){
                mid = temp;

                while(mid != left){
                    if(mid->name == Book_name){
                        cout<<"\nBook is Found\n"
                            <<endl;
                        cout<<"\nBook name: "<<mid->name <<endl;
                        cout<<"\nBook price : "<<mid->Book_price<<endl;
                        return true ;

                    }
                    mid = mid->next;
                }
                cout<<"\nBook Not Found"<<endl;
                return false;
            }
            else{
                mid = mid->next;

            }
            
        }
        cout<<"\nBook Not Found"<<endl;
        return false;
    }

    void DeleteAll_Books(){
        Node *temp = head;
        Node *temp2;
        if(head == NULL){
            cout<<" Book store is empty"<<endl;
            cout<<"************"<<endl;
        }
        else{
            while(temp!= NULL){
                temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
            head = NULL;
            cout<<" Successfully Deleted All BOOKs "<<endl;
            cout<<"*************"<<endl;
        }
    }

    bool DeleteBooks(){
        bool check = false;
        Node *temp;
        cout<<"************"<<endl;

    
            if(Bsearch()==true){
                temp=mid;
                check=true;

            if(check == true){
                int User_input;
                cout<<"Press 1 to Delete A BOOK : ";
                cin>>User_input;
                if(User_input==1 && temp ==head){
                    Node *temp1;
                    temp1 = temp;
                    temp = temp->next;
                    delete temp1;

                    head = temp;
                    cout<<"Book Delete Successfully"<<endl;
                    return true;

                }

                if(User_input == 1 && temp->next == NULL){
                    temp->prev->next = NULL;
                    delete temp;
                    cout<<"Book Delete Successfully"<<endl;
                    return true ;

                }

                if(User_input ==1){
                    Node *temp1;
                    temp1 = temp;
                    temp->prev->next = temp1->next;
                    temp->next->prev = temp1->prev;

                    delete temp1;

                    cout<< "Book Delete Successfully "<<endl;
                    return true;

                }
                else{
                    cout<<"Invalid Command "<<endl;

                }
            }
        }
    }


    

    void BubbleSort(){
        Node *temp =head;
        Node *i,*j;
        string n;
        int swap2;
        if(temp == NULL){
            cout<<"Books store is Empty"<<endl;

        }
        else{
            for(i = temp;i->next!=NULL && i!=NULL;i=i->next){
                for(j=i->next;j!=NULL;j=j->next){
                    if(i->name > j->name ){
                        n=i->name;
                        i->name = j->name;
                        j->name = n;

                        swap2 = i->Book_price;
                        i->Book_price=j->Book_price;
                        j->Book_price=swap2;
                    }
                }
            }
        }
    }

    int EditContacts(){
        Node *temp;
        cout<<"**************"<<endl;

        bool flag = false;
        if(Bsearch()==true){
            temp= mid;
            flag =true;

            if(flag == true){
                int User_input;
                cout<<"\n\n Press 1 to Edit the Book: ";
                cin>>User_input;

                if(User_input == 1){
                    cout<<"Enter New BOok Name: ";
                    cin.ignore();
                    getline(cin,Book_name);
                    cout<<"Enter New Book Price: ";
                    cin>>price;

                    temp->name = Book_name;
                    temp->Book_price=price;

                    cout<<"Book Edited Successfully "<<endl;

                }
                else{
                    cout<<"Invalid User_input"<<endl;
                }
            }
        }
    }

    void Filesave(){
        Node *temp = head;
        ofstream myfile("Book_store.txt");
        if(myfile.is_open()){
            while(temp != NULL){
                myfile << temp->name <<endl;
                myfile << temp->Book_price<<endl;
                temp=temp->next;
            }
            myfile.close();
        }
    }


};

int main(){
    Bookstore bs;
    int user;

    cout<<"***************************************"<<endl;
    cout<<" "
        <<"Welcome to book store management system"<<endl;
    cout<<"\n******************************************"<<endl;

    do{
        cout<<"1. Add Book"<<endl;
        cout<<"2. Edit the book"<<endl;
        cout<<"3. Delete Book"<<endl;
        cout<<"4.Search Book"<<endl;
        cout<<"5. Display ALL Books"<<endl;
        cout<<"6. Delete All bOoks"<<endl;
        cout<<"0. Close the program"<<endl;
        cout<<"****************"<<endl;
        cout<<"Enter the input"<<endl;
        
        cin>>user;

        switch (user)
        {

        case 1:
            bs.CreateNode();
            bs.Filesave();
            break;

        case 2:
            bs.EditContacts();
            bs.Filesave();
            break;
        case 3:
            bs.DeleteBooks();
            break;

        case 4:
            bs.Bsearch();
            break;
        
        case 5:
            bs.Display();
            bs.Filesave();
            break;

        case 6:
            bs.DeleteAll_Books();
            bs.Filesave();

            break;
            case 0:
                break;
        default:
        cout<<"Error: invalid option"<<endl;
            
        }


    }
    while(user != 0 );

    return 0;
}