#include "inheritance.h"




void _ZN11doMaterialsEv(){
    Materials mat;
    Material_t mat1, mat2;
    typedef struct MatTest {
        Materials _mat;
        Material_t _mat_t;
    }MatTest;
    printf("\n--- Start doMaterials() ---\n\n");


    _ZN9MaterialsCEv(&mat);

    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t)- sizeof(Types));



    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest)- sizeof(Types));

    _ZN9MaterialsCEv((Materials *)&mat1);

    mat2._material = OTHER;

    printf("Material created, set to %s\n",names[mat2._material]);

    _ZN9MaterialsCEv((Materials *)& mat2);
    mat2._material = METAL;

    printf("Material created, set to %s\n",names[mat2._material]);
    printf("\n--- End doMaterials() ---\n\n");

    _ZN10Material_tDEv(&mat2);
    _ZN10Material_tDEv(&mat1);
    _ZN9MaterialsDEv(&mat);


}

void _ZN13doPhysicalBoxEv()
{
    PhysicalBox pb1, pb2, pb3, pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    _ZN11PhysicalBoxCEdddMT(&pb1,8, 6, 4, PLASTIC);
    _ZN11PhysicalBoxCEMT(&pb2,WOOD);
    _ZN11PhysicalBoxCEddd(&pb3,7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");
    _ZN11PhysicalBoxCpEv(&pb4, &pb1);
    _ZN11PhysicalBox6printpEv(&pb4);
    _ZN11PhysicalBox6printpEv(&pb1);

    printf("pb4 %s pb1\n",
           pb4._box._height == pb1._box._height&&pb4._box._length == pb1._box._length&&
           pb4._box._width == pb1._box._width
           &&pb1._material._material == pb2._material._material? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    _ZN11PhysicalBoxAsEv(&pb4, &pb3);
    _ZN11PhysicalBox6printpEv(&pb4);
    _ZN11PhysicalBox6printpEv(&pb3);
    printf("pb4 %s pb3\n",
           pb4._box._height == pb3._box._height&&pb4._box._length == pb3._box._length&&
           pb4._box._width == pb3._box._width
           &&pb4._material._material == pb3._material._material? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");

    _ZN11PhysicalBoxDEv(&pb4);
    _ZN11PhysicalBoxDEv(&pb3);
    _ZN11PhysicalBoxDEv(&pb2);
    _ZN11PhysicalBoxDEv(&pb1);
}

void _ZN11doWeightBoxEv()
{
    WeightBox pw1, pw2, pw3, pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    _ZN9WeightBoxCEdddd(&pw1, 8, 6, 4, 25);
    _ZN9WeightBoxCEdddd(&pw2,1, 2, 3, 0);
    _ZN9WeightBoxCEdddd(&pw3, 10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    _ZN9WeightBoxCpEPw(&pw4, &pw1);
    _ZN9WeightBox6printwEv(&pw4);
    _ZN9WeightBox6printwEv(&pw1);
    printf("pw4 %s pw1\n",
           pw4._box._height == pw1._box._height&&pw4._box._length == pw1._box._length&&
           pw4._box._width == pw1._box._width
           &&pw4._weight == pw1._weight? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    _ZN9WeightBoxAsEpw(&pw4, &pw3);
    _ZN9WeightBox6printwEv(&pw4);
    _ZN9WeightBox6printwEv(&pw3);
    printf("pw4 %s pw3\n",
           pw4._box._height == pw3._box._height&&pw4._box._length == pw3._box._length&&
           pw4._box._width == pw3._box._width
           &&pw4._weight == pw3._weight? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    _ZN9WeightBoxDEv(&pw4);
    _ZN9WeightBoxDEv(&pw3);
    _ZN9WeightBoxDEv(&pw2);
    _ZN9WeightBoxDEv(&pw1);

}

int main(){
    printf("\n--- Start main() ---\n\n");

    _ZN11doMaterialsEv();

    _ZN13doPhysicalBoxEv();

    _ZN11doWeightBoxEv();

    printf("\n--- End main() ---\n\n");
    return 0;
}



