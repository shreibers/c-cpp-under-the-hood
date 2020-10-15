
#include "inheritance.h"
#include <string.h>

/*/// Materials ///////////*/
const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };


void _ZN9MaterialsCEv(Materials *this){}

void _ZN9MaterialsDEv(Materials *this){}

void _ZN10Material_tDEv(Material_t *this){
    _ZN9MaterialsDEv((Materials *) this);
}
/*/// PhysicalBox ///////////*/

void _ZN11PhysicalBoxCEddd(PhysicalBox* this, double l, double w, double h){
    _ZN3BoxC1Eddd((Box*)this, l, w, h);
    _ZN9MaterialsCEv((Materials *) (Material_t *) this);
    this->_material._material = OTHER;
    printf("Material created, set to %s\n",names[this->_material._material]);
    _ZN11PhysicalBox6printpEv(this);
}


void _ZN11PhysicalBoxCEdddMT(PhysicalBox* this, double l, double w, double h, Types t){
    _ZN3BoxC1Eddd((Box*)this, l, w, h);
    _ZN9MaterialsCEv((Materials *) (Material_t *) this);
    this->_material._material = t;
    printf("Material created, set to %s\n",names[this->_material._material]);
    _ZN11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxCEMT(PhysicalBox* this, Types t){
    _ZN3BoxC1Ed((Box*)this, 1);
    _ZN9MaterialsCEv((Materials *) (Material_t *) this);
    this->_material._material = t;
    printf("Material created, set to %s\n",names[this->_material._material]);
    _ZN11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxDEv(PhysicalBox* this){
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->_box._length, this->_box._width, this->_box._height, names[this->_material._material]);
    _ZN10Material_tDEv((Material_t *) this);
    _ZN3BoxDEv((Box*)this);
}

void _ZN11PhysicalBoxCpEv(PhysicalBox* this, const PhysicalBox *const other){
    _ZN3BoxCPEpb((Box*)this, (Box*)other);

    memcpy(this+ sizeof(Box), other+ sizeof(Box), sizeof(PhysicalBox)- sizeof(Box));
}

PhysicalBox* _ZN11PhysicalBoxAsEv(PhysicalBox* this, const PhysicalBox *const other){

    /*/_ZN3BoxAsEpb((Box*)this, (Box*)other);*/
    memcpy(this+ sizeof(Box), other+ sizeof(Box), sizeof(PhysicalBox)- sizeof(Box));
    return this;
}

void _ZN11PhysicalBox6printpEv(const PhysicalBox *const this){
    printf("PhysicalBox, made of %s; ", names[this->_material._material]);
    _ZNK3Box5printEv((Box*)this);
}

/*/// WeightBox ///////////*/

void _ZN9WeightBoxCEdddd(WeightBox* this, double l, double w, double h, double wgt){
    _ZN3BoxC1Eddd((Box*)this, l, w, h);
    this->_weight = wgt;
    _ZN9WeightBox6printwEv(this);
}

void _ZN9WeightBoxDEv(WeightBox* this){
    printf("Destructing WeightBox; ");
    _ZN9WeightBox6printwEv(this);
    _ZN3BoxDEv((Box*)this);

}

void _ZN9WeightBoxCpEPw(WeightBox* this, const WeightBox*const other){
    _ZN3BoxC1Ed((Box*)this, 1);
    this->_weight = other->_weight;
    _ZN9WeightBox6printwEv(this);
}

WeightBox* _ZN9WeightBoxAsEpw(WeightBox* this, const WeightBox*const other){
    this->_weight = other->_weight;
    return this;
}

void _ZN9WeightBox6printwEv(const WeightBox*const this){
    printf("WeightBox, weight: %f; ", this->_weight);
    _ZNK3Box5printEv((Box*)this);
}

