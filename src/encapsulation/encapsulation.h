/*/
// Created by a on 6/14/20.
/*/

#ifndef UNDERTHEHOOD_ENCAPSULATION_H
#define UNDERTHEHOOD_ENCAPSULATION_H

#include <stdio.h>

typedef struct Box{
    double _length;
    double _width;
    double _height;
}Box;

void _ZN3BoxC1Ed(Box* box, const double dim);
void _ZN3BoxC1Eddd(Box* box, const double l, const double w, const double h);
void _ZN3BoxDEv(Box *box);
Box _ZeqRK3BoxS1_(Box* box, double mult);
void _ZNK3Box5printEv(const Box *const  box);
void  _ZN3BoxCPEpb(Box* this, const Box *const other);
Box* _ZN3BoxAsEpb(Box* this, const Box *const other);


typedef struct Shelf{
    Box _boxes[3];
}Shelf;

void  _ZN5ShelfCEv(Shelf* shelf);
void _ZN3ShelfDEv(Shelf * shelf);
void _ZN5Shelf6setBoxEiRK3Box(Shelf *shelf, int index, Box *const dims);
double _ZNK5Shelf9getVolumeEv(const Shelf *const shelf);
void _ZNK3Shelf9printEv(const Shelf *const shelf);
extern const char* _Z5Shelf7message;



#endif /*/UNDERTHEHOOD_ENCAPSULATION_H*/
