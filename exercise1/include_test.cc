#include "bar.h"
#include "foo.h"
int main()
{
    Bar b{"testing"};
    Foo f(b,17);

    f.print();
    return 0;
}
