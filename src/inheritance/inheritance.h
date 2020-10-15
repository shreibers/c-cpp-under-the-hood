
#ifndef UNDERTHEHOOD_INHERITANCE_H
#define UNDERTHEHOOD_INHERITANCE_H

#include "../encapsulation/encapsulation.h"
extern const char* const names[];

/*/// Materials ///////////*/

typedef struct Materials
{
    char i;

}Materials;


typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;



void _ZN9MaterialsCEv(Materials *this);
void _ZN9MaterialsDEv(Materials *this);

typedef struct Material_t{

    Materials materials;
    Types _material;

}Material_t;

void _ZN10Material_tDEv(Material_t *this);


/*/// PhysicalBox ///////////*/


typedef struct PhysicalBox{
    Box _box;
    Material_t _material;
}PhysicalBox;

void _ZN11PhysicalBoxCEddd(PhysicalBox* this, double l, double w, double h);
void _ZN11PhysicalBoxCEdddMT(PhysicalBox* this, double l, double w, double h, Types t);
void _ZN11PhysicalBoxCEMT(PhysicalBox* this, Types t);
void _ZN11PhysicalBoxCpEv(PhysicalBox* this, const PhysicalBox *const other);
PhysicalBox* _ZN11PhysicalBoxAsEv(PhysicalBox* this, const PhysicalBox *const other);
void _ZN11PhysicalBoxDEv(PhysicalBox* this);
void _ZN11PhysicalBox6printpEv(const PhysicalBox *const this);


/*/// WeightBox ///////////*/
typedef struct WeightBox{
    Box _box;
    double _weight;
}WeightBox;

void _ZN9WeightBoxCEdddd(WeightBox* this, double l, double w, double h, double wgt);
void _ZN9WeightBoxDEv(WeightBox* this);
void _ZN9WeightBoxCpEPw(WeightBox* this, const WeightBox*const other);
WeightBox* _ZN9WeightBoxAsEpw(WeightBox* this, const WeightBox*const other);
void _ZN9WeightBox6printwEv(const WeightBox*const this);

#endif /*/UNDERTHEHOOD_INHERITANCE_H*/
