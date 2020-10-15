
/*/ Created by a on 6/14/20.*/

#include "encapsulation.h"


void _ZN3BoxC1Ed(Box* box, const double dim){
    box->_height = dim;
    box->_length = dim;
    box->_width = dim;
    _ZNK3Box5printEv(box);
}

void _ZN3BoxC1Eddd(Box* box, const double l, const double w, const double h){
    box->_height = l;
    box->_length = w;
    box->_width = h;
    _ZNK3Box5printEv(box);
}



void _ZN3BoxC1Ev(Box* box){
    box->_height = 1;
    box->_length = 1;
    box->_width = 1;
    _ZNK3Box5printEv(box);
}

void  _ZN3BoxCPEpb(Box* this, const Box *const other){
    *this = *other;
}

Box* _ZN3BoxAsEpb(Box* this, const Box *const other){

    *this = *other;
    return this;
}

void _ZN3BoxDEv(Box *box){
    printf("Box destructor, %f x %f x %f\n", box->_width, box->_height, box->_length);
}

Box _ZeqRK3BoxS1_(Box* box, double mult)
{
    box->_width *= mult;
    box->_length*= mult;
    box->_height*= mult;
    return *box;
}

void _ZNK3Box5printEv(const Box *const  box){
    printf("Box: %f x %f x %f\n", box->_length, box->_width, box->_height);
}

void _ZN5ShelfCEv(Shelf* shelf){
    unsigned char i=0;
    for(;i<3;i++){
        _ZN3BoxC1Ed(&shelf->_boxes[i], 1);
    }
}


void _ZN3ShelfDEv(Shelf *shelf){
    unsigned char i=0;
    for(;i<3;i++){
        _ZN3BoxDEv(&shelf->_boxes[i]);
    }

}



const char* _Z5Shelf7message = "The total volume held on the shelf is";

void _ZN5Shelf6setBoxEiRK3Box(Shelf *shelf, int index, Box *const dims){
    shelf->_boxes[index] = *dims;
}

double _ZNK5Shelf9getVolumeEv(const Shelf *const shelf){
    double vol = 0;
    size_t i=0;
    for (; i < 3; ++i)
        vol += shelf->_boxes[i]._width * shelf->_boxes[i]._length * shelf->_boxes[i]._height;

    return vol;
}

void _ZNK3Shelf9printEv(const Shelf *const shelf){
    printf("%s %f\n", _Z5Shelf7message, _ZNK5Shelf9getVolumeEv(shelf));
}






