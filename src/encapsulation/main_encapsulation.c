
#include "encapsulation.h"

static Box _ZL8largeBox;

static char flagBox99=0;
static char flagBox88=0;

void _Z8thisFuncv()
{
    static Box _ZZ8thisFuncvE5box99;
    printf("\n--- thisFunc() ---\n\n");

    if(flagBox99 == 2){
        _ZN3BoxDEv(&_ZZ8thisFuncvE5box99);
        return;
    }
    if(flagBox99 == 0){
        _ZN3BoxC1Ed(&_ZZ8thisFuncvE5box99, 99);
    }
    _ZeqRK3BoxS1_(&_ZZ8thisFuncvE5box99, 10);
    flagBox99 = 1;

}

void _Z8thatFuncv()
{
    static Box _ZZ8thatFuncvE5box88;
    printf("\n--- thatFunc() ---\n\n");

    if(flagBox88 == 2){
        _ZN3BoxDEv(&_ZZ8thatFuncvE5box88);
        return;
    }
    if(flagBox88 == 0){
        _ZN3BoxC1Ed(&_ZZ8thatFuncvE5box88, 88);
    }
    _ZeqRK3BoxS1_(&_ZZ8thatFuncvE5box88, 10);
    flagBox88 = 1;
}

void _Z7doBoxesv()
{
    printf("\n--- Start doBoxes() ---\n\n");
    Box b1, b2;
    _ZN3BoxC1Ed(&b1, 3);
    _ZN3BoxC1Eddd(&b2, 4, 5, 6);


    printf("b1 volume: %f\n", b1._width*b1._height*b1._length);
    printf("b2 volume: %f\n", b2._width*b2._height*b2._length);

    _ZeqRK3BoxS1_(&b1, 1.5);
    _ZeqRK3BoxS1_(&b2, 0.5);

    printf("b1 volume: %f\n", b1._width*b1._length*b1._height);
    printf("b2 volume: %f\n", b2._width*b2._height*b2._length);

    Box b3, b4, ret;
    _ZN3BoxCPEpb(&b3, &b2);

    _ZN3BoxCPEpb(&ret, &b2);
    _ZeqRK3BoxS1_(&ret, 3);
    _ZN3BoxAsEpb(&b4, &ret);
    printf("b3 %s b4\n", b3._length == b4._length&&b3._width == b4._width&&b3._height==b4._height ? "equals" : "does not equal");

    _ZeqRK3BoxS1_(&b3, 1.5);
    _ZeqRK3BoxS1_(&b4, 0.5);

    printf("Now, b3 %s b4\n", b3._length == b4._length&&b3._width == b4._width&&b3._height==b4._height ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    _ZN3BoxDEv(&ret);
    _ZN3BoxDEv(&b4);
    _ZN3BoxDEv(&b3);
    _ZN3BoxDEv(&b2);
    _ZN3BoxDEv(&b1);
}

void _Z9doShelvesv()
{
    printf("\n--- start doShelves() ---\n\n");

    Box temp, aBox;
    _ZN3BoxC1Ed(&temp, 5);
    _ZN3BoxAsEpb(&aBox, &temp);

    Shelf aShelf;
    _ZN5ShelfCEv(&aShelf);

    _ZNK3Shelf9printEv(&aShelf);

    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &_ZL8largeBox);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    _ZNK3Shelf9printEv(&aShelf);
    _Z5Shelf7message = "This is the total volume on the shelf:";
    _ZNK3Shelf9printEv(&aShelf);
    _Z5Shelf7message = "Shelf's volume:";
    _ZNK3Shelf9printEv(&aShelf);

    Box new_box;
    _ZN3BoxC1Eddd(&new_box, 2, 4, 6);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &new_box);

    _ZN3BoxC1Ed(&new_box, 2);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &new_box);
    _ZNK3Shelf9printEv(&aShelf);


    printf("\n--- end doShelves() ---\n\n");

    _ZN3BoxDEv(&new_box);
    _ZN3ShelfDEv(&aShelf);
    _ZN3BoxDEv(&aBox);
    _ZN3BoxDEv(&temp);

}

int main()
{
    _ZN3BoxC1Eddd(&_ZL8largeBox, 10, 20, 30);
    printf("\n--- Start main() ---\n\n");

    _Z7doBoxesv();

    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thatFuncv();
    _Z8thatFuncv();

    _Z9doShelvesv();
    if(flagBox99 == 1){
        flagBox99++;
        _Z8thisFuncv();
    }

    printf("\n--- End main() ---\n\n");
    _ZN3BoxDEv(&_ZL8largeBox);

    return 0;
}










