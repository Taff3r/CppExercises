#include <iostream>
using std::cout;
using std::endl;


class Foo {
private:
    static int created;
public:
    Foo() {++created;}
    ~Foo() {--created;}
    static void print_count();
};

int Foo::created{0};
void Foo::print_count() {
    cout << Foo::created << endl;
}
void example()
{
    {
        Foo a;
        a.print_count();

        Foo b;
        b.print_count();
    }

    {
        Foo c;
        Foo::print_count();
    }
    Foo::print_count();
}

void example2(){
    int created = 0;

    {
        Foo a;
        ++created;
        Foo b;
        ++created;
        cout << "created " << created << " alive ";
        Foo::print_count();
        cout << endl;
    }
    {
        Foo a;
        ++created;
        Foo b;
        ++created;
        Foo c;
        ++created;
        cout << "created " << created << " alive ";
        Foo::print_count();
        cout<<endl;
    }

    cout << "created " << created << " alive ";
    Foo::print_count();
    cout << endl;
}

int main()
{
    example();
    example2();
}
