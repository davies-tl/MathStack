/*
Program name: MathStack.cpp
Programmer: Tyler Davies
Date: 11-7-21
Version: 1.0
Description: This program contains a MathStack class which creates a dynamic stack to hold integer
             values. The MathStack class has ten member functions: pop, push, isEmpty, print, add,
             sub, Mult, Div, addAll, and multAll. It also has constructor and destructor functions.
 */

#include<iostream>
using namespace std;

//The MathStack class uses the structure StackNode; each node will hold an integer value and a
//pointer to the next node. MathStack class also has a pointer which points to the top node. 
class MathStack
{
private:
    struct StackNode
    {
        int number;
        StackNode *next;
    };
    StackNode *top;
public:
    MathStack()
        { top = NULL; }
    void pop(int &);
    void push(int);
    bool isEmpty() const;
    void print() const;
    void add();
    void sub();
    void Mult();
    void Div();
    void addAll();
    void multAll();
    ~MathStack();
};

//The pop function takes the top node's number and stores it into its parameter which is passed-by-
//reference. If the stack is empty, a message will print indicating that the stack is empty.
void MathStack::pop(int &num)
{
    StackNode *temp;
    if (isEmpty())
        cout << "Stack is empty.\n";
    else
    {
        num = top->number;
        temp = top->next;
        delete top;
        top = temp;
    }
}

//The push function dynamically creates a newNode and stores num into that node. If the stack is
//empty, the newNode is made the top node; otherwise, the newNode is pushed onto the stack.
void MathStack::push(int num)
{
    StackNode *newNode;
    newNode = new StackNode;
    newNode->number = num;
    if (isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

//The isEmpty function checks if there is a top node. If there is, the stack is not empty.
bool MathStack::isEmpty() const
{
    if (!top)
        return true;
    else
        return false;
}

//The print function traverses the stack, printing all of the numbers in the stack on one line.
void MathStack::print() const
{
    StackNode *nodePtr;
    nodePtr = top;
    while (nodePtr != NULL)
    {
        cout << nodePtr->number << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

//The add function pops the top two values off the stack, adds them, and pushes their sum onto the stack.
void MathStack::add()
{
    int num, sum;
    pop(num);
    pop(sum);
    sum += num;
    push(sum);
}

//The sub function pops the top two values off the stack, subtracts the second value from the first,
//and pushes their difference onto the stack.
void MathStack::sub()
{
    int difference, num;
    pop(difference);
    pop(num);
    difference -= num;
    push(difference);
}

//The Mult function pops the top two values off the stack, multiplies them, and pushes their
//product onto the stack.
void MathStack::Mult()
{
    int num, product;
    pop(num);
    pop(product);
    product *= num;
    push(product);
}

//The Div function pops the top two values off the stack, divides the second value by the first,
//and pushes their quotient onto the stack.
void MathStack::Div()
{
    int num, quotient;
    pop(num);
    pop(quotient);
    quotient /= num;
    push(quotient);
}

//The addAll function pops all values off the stack, adds them, and pushes their sum onto the stack.
void MathStack::addAll()
{
    int num, sum = 0;
    while (!(isEmpty()))
    {
        pop(num);
        sum += num;
    }
    push(sum);
}

//The multAll function pops all values off the stack, multiplies them, and pushes their product
//onto the stack.
void MathStack::multAll()
{
    int num, product = 1;
    while (!(isEmpty()))
    {
        pop(num);
        product *= num;
    }
    push(product);
}

//The ~MathStack destructor traverses the stacked linked list, deleting each node.
MathStack::~MathStack()
{
    StackNode *nodePtr, *next;
    nodePtr = top;
    while (nodePtr != NULL)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}

//The main function acts as a driver program, initializing a MathStack object and demonstrating
//its member functions.
int main()
{
    cout << "Initializing MathStack object. \nPushing integer values 1-10 onto stack.\n";
    MathStack userStack;
    userStack.push(1);
    userStack.push(2);
    userStack.push(3);
    userStack.push(4);
    userStack.push(5);
    userStack.push(6);
    userStack.push(7);
    userStack.push(8);
    userStack.push(9);
    userStack.push(10);
    userStack.print();

    cout << "\nTesting the add member function.\n(Adds the top two values)\n";
    userStack.add();
    userStack.print();

    cout << "\nTesting the sub member function.\n(Subtracts the second value from the first)\n";
    userStack.sub();
    userStack.print();

    cout << "\nTesting the Mult member function.\n(Multiplies the top two values)\n";
    userStack.Mult();
    userStack.print();

    cout << "\nPushing integer value 11 onto stack. \n";
    cout << "Testing the Div member function.\n(Divides the second value by the first)\n";
    userStack.push(11);
    userStack.Div();
    userStack.print();

    cout << "\nTesting the addAll member function.\n(Adds all of the values in the stack)\n";
    userStack.addAll();
    userStack.print();

    cout << "\nPushing integer values 2 and 3 onto stack. \n";
    cout << "Testing the multAll member function.\n(Multiplies all of the values in the stack)\n";
    userStack.push(2);
    userStack.push(3);
    userStack.multAll();
    userStack.print();

    exit(0);
}