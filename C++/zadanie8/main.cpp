#include "LinkedList.hpp"
#include "LinkedList.cpp"
using namespace std;

void printable_interface()
{
    cout<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"Press one of the given numbers to execute a command next to the number:"<<endl;
    cout<<"1 - insert new elem to list"<<endl;
    cout<<"2 - remove particular elem from the list"<<endl;
    cout<<"3 - check if the list is sorted or not"<<endl;
    cout<<"4 - print the whole list"<<endl;
    cout<<"5 - sort the list"<<endl;
    cout<<"6 - show length of the list"<<endl;
    cout<<"7 - delete the list"<<endl;
    cout<<"8 - exit the program"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<">";
}

int main()
{
    LinkedList<int>* lst= new LinkedList<int>();
    char x='0';
    while (x!='8') {
        printable_interface();
        cin>>x;
        cout<<endl;
        switch (x) {
            case '1': {
                int a, b;
                cout<<"Write a number: ";
                cin>>a;
                cout<<"Write the position, where to put the new elem";
                cin>>b;
                lst->insertNewNode(a, b);
                break;
            }
            case '2': {
                int c;
                cout<<"What elem you want to be removed?";
                cin>>c;
                lst->deleteNode(c);
                break;
            }
            case '3': {
                cout << (check(lst) ? "List is sorted" : "Sorry, the list is unsorted");
                break;
            }
            case '4': {
                cout<<*lst;
                break;
            }
            case '5': {
                sort(lst);
                break;
            }
            case '6': {
                cout<<"Number of the elems in the list is: "<<lst->getNumberOfElements();
                break;
            }
            case '7': {
                delete lst;
                LinkedList<int>* lst= new LinkedList<int>();
                break;
            }
        }
    }
    delete lst;
    return 0;
}