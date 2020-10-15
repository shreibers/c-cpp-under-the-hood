#include "polymorpism.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*// TextFormatter //*/

typeVpnPointer arrayOfVirtFunctionsStructTextFormatter[] = {(typeFuncPointer)_ZN13TextFormatterDEv, (typeFuncPointer)NULL};
typeVpnPointer arrayOfVirtFunctionsStructDefaultTextFormatter[] ={(typeFuncPointer)_ZN20DefaultTextFormatterDEv, (typeFuncPointer)_ZN13DefaultTextFormatter5printEc};
typeVpnPointer arrayOfVirtFunctionsStructPrePostFixer[] ={(typeFuncPointer)_ZN12PrePostFixerDEv,
                                                            (typeFuncPointer)_ZNK12PrePostFixer5printEPKc,
                                                            (typeFuncPointer)_ZNK12PrePostFixer5printElc,
                                                            (typeFuncPointer)_ZNK12PrePostFixer16getDefaultSymbolEv};
typeVpnPointer arrayOfVirtFunctionsStructPrePostHashFixer[] ={(typeFuncPointer)_ZN16PrePostHashFixerDEv,
                                                                (typeFuncPointer)_ZNK12PrePostFixer5printEPKc,
                                                                (typeFuncPointer)_ZN16PrePostHashFixer5printElc,
                                                                (typeFuncPointer)_ZNK16PrePostHashFixer16getDefaultSymbolEv};
typeVpnPointer arrayOfVirtFunctionsStructPrePostFloatDollarFixer[]={(typeFuncPointer)_ZN18PrePostFloatDollarFixerCEcc,
                                                                       (typeFuncPointer)_ZNK12PrePostFixer5printEPKc,
                                                                       (typeFuncPointer)_ZN16PrePostHashFixer5printElc,
                                                                       (typeFuncPointer)_ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv};
typeVpnPointer arrayOfVirtFunctionsStructPrePostDollarFixer[]={(typeFuncPointer)_ZN18PrePostDollarFixerDEv,
                                                                  (typeFuncPointer)_ZNK12PrePostFixer5printEPKc,
                                                                  (typeFuncPointer)_ZN18PrePostDollarFixer5printElc,
                                                                  (typeFuncPointer)_ZN18PrePostDollarFixer16getDefaultSymbol};
typeVpnPointer arrayOfVirtFunctionsStructPrePostChecker[] ={(typeFuncPointer)_ZN14PrePostCheckerDEv,
                                                                  (typeFuncPointer)_ZNK12PrePostFixer5printEPKc,
                                                                  (typeFuncPointer)_ZN18PrePostDollarFixer5printElc,
                                                                  (typeFuncPointer)_ZN18PrePostDollarFixer16getDefaultSymbol};
typeVpnPointer arrayOfVirtFunctionsStructMultiplier[] ={(typeFuncPointer)_ZN10MultiplierD0Ev, (typeFuncPointer)_ZNK10Multiplier5printEPKc};




void _ZN13TextFormatterCEv(TextFormatter* this){
    this->vPtr = arrayOfVirtFunctionsStructTextFormatter;
}

void _ZN13TextFormatterDEv(void* this){}


/*// DefaultTextFormatter //*/
int _ZN20DefaultTextFormatter4Ider7next_idE=0;

void _ZN20DefaultTextFormatterCEv(DefaultTextFormatter * this){
    _ZN13TextFormatterCEv((TextFormatter*)this);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructDefaultTextFormatter;
    this->_id = _ZN20DefaultTextFormatter4Ider7next_idE++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->_id);
}

void _ZN20DefaultTextFormatterDEv(void * this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", ((DefaultTextFormatter*)this)->_id);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructTextFormatter;
    _ZN13TextFormatterDEv((TextFormatter*)this);
}


void _ZN13DefaultTextFormatter5printEc(const void *const this, const char* text){
    printf("%-60s | ","[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

void _ZN23PrePostFloatDollarFixerCEPKcS_(DefaultTextFormatter * this, const DefaultTextFormatter*const other){
    _ZN13TextFormatterCEv((TextFormatter*)this);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructDefaultTextFormatter;
    this->_id = _ZN20DefaultTextFormatter4Ider7next_idE++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->_id, this->_id);
}

DefaultTextFormatter* _ZN20DefaultTextFormatter2AsEpkD(DefaultTextFormatter * this, const DefaultTextFormatter*const other){
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->_id, this->_id);
    return this;
}

DefaultTextFormatter* _Z22generateFormatterArrayEv(){
    unsigned char i=0;
    DefaultTextFormatter* ret = malloc(3*sizeof(DefaultTextFormatter));
    for(;i<3;i++){
        _ZN20DefaultTextFormatterCEv(&ret[i]);
    }
    return ret;
}

/*// PrePostFixer Defs //*/

void _ZN12PrePostFixerC1ERKS_(PrePostFixer* this, const char* prefix, const char* postfix){
    _ZN20DefaultTextFormatterCEv((DefaultTextFormatter*)this);
    ((TextFormatter*)(DefaultTextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructDefaultTextFormatter;
    this->_pre = prefix;
    this->_post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->_pre, this->_post);
}

void _ZN12PrePostFixerDEv(void* this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);
    ((TextFormatter*)(DefaultTextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructTextFormatter;
    _ZN20DefaultTextFormatterDEv((DefaultTextFormatter*)this);
}

void _ZN12PrePostFixerC1EPKcS1_(PrePostFixer* this, const PrePostFixer*const other){

    _ZN23PrePostFloatDollarFixerCEPKcS_((DefaultTextFormatter *) this, (DefaultTextFormatter *) other);
    ((TextFormatter*)(DefaultTextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructTextFormatter;
    this->_pre = other->_pre;
    this->_post = other->_post;

}

void _ZNK12PrePostFixer5printEPKc(const void*const this, const char* text){
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", ((PrePostFixer*)this)->_pre, text, ((PrePostFixer*)this)->_post);
}

void _ZNK12PrePostFixer5printElc(const void*const this, long num, char symbol){
    printf("%-60s | ","[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol){
        printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", ((PrePostFixer*)this)->_pre, symbol, num, ((PrePostFixer*)this)->_post);
    }
    else{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", ((PrePostFixer*)this)->_pre, num, ((PrePostFixer*)this)->_post);

    }
}

char _ZNK12PrePostFixer16getDefaultSymbolEv(const void*const this){
    return '\0';
}


/*PrePostDollarFixer defs*/

void _ZN18PrePostDollarFixerCERKS_(PrePostDollarFixer* this, const char* prefix, const char* postfix){
    _ZN12PrePostFixerC1ERKS_((PrePostFixer *) this, prefix, postfix);
    ((TextFormatter*)(DefaultTextFormatter*)this)->vPtr= arrayOfVirtFunctionsStructPrePostDollarFixer;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,  ((PrePostFixer*)this)->_post);
}
void _ZN18PrePostDollarFixerDEv(void* this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,   ((PrePostFixer*)this)->_post);
    ((TextFormatter*)(DefaultTextFormatter*)this)->vPtr= arrayOfVirtFunctionsStructPrePostFixer;
    _ZN12PrePostFixerDEv((PrePostFixer*)this);
}

void _ZN18PrePostDollarFixerCEPKcS(PrePostDollarFixer* this, const PrePostDollarFixer*const other){
    _ZN12PrePostFixerC1EPKcS1_((PrePostFixer *) this, (PrePostFixer *) other);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostDollarFixer;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,  ((PrePostFixer*)this)->_post);
}

void _ZN18PrePostDollarFixer5printElc(const void*const this,long num, char symbol){

    printf("%-60s | ","[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    _ZNK12PrePostFixer5printElc((PrePostFixer *) this, num, symbol);

}

void _ZN18PrePostDollarFixer5printEic(const PrePostDollarFixer*const this,int num, char symbol){
    printf("%-60s | ","[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    ((typeFuncPrintLongChar)(((TextFormatter*)this)->vPtr)[E_PrintELongAndChar])(this, (long)num, symbol);


}

void _ZN18PrePostDollarFixer5printEdc(const PrePostDollarFixer*const this, double num, char symbol){
    printf("%-60s | ","[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)this)->_pre,   symbol, num, ((PrePostFixer*)this)->_post);
}

char _ZN18PrePostDollarFixer16getDefaultSymbol(const void *const this){
    return '@';
}


/* PrePostHashFixer*/

void _ZN18PrePostHashFixerCEcc(PrePostHashFixer* this, int prc){
    _ZN18PrePostDollarFixerCERKS_((PrePostDollarFixer *) this, "===> ", " <===");
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostHashFixer;
    ((PrePostHashFixer*)this)->_precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post, this->_precision);
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->_pre, '#', this->_precision, 9999.9999, ((PrePostFixer*)this)->_post);
}

void _ZN16PrePostHashFixerDEv(void* this){
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostDollarFixer;
    _ZN18PrePostDollarFixerDEv((PrePostDollarFixer*)this);

}

void _ZN18PrePostHashFixerCpEpp(PrePostHashFixer* this, const PrePostHashFixer*const other){
    _ZN18PrePostDollarFixerCEPKcS((PrePostDollarFixer *) this, (PrePostDollarFixer *) other);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostHashFixer;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,  ((PrePostFixer*)this)->_post);
    this->_precision = other->_precision;
}



void _ZN16PrePostHashFixer5printElc(const void* const this,long num, char symbol){
    printf("%-60s | ", ("[PrePostHashFixer::print(long, char)]"));
    printf("-->\n");
    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->_pre, symbol, ((PrePostHashFixer*)this)->_precision, (double)num, ((PrePostFixer*)this)->_post);
}

void _ZN16PrePostHashFixer5printEic(const PrePostHashFixer* const this,int num, char symbol){
   printf("%-60s | ", ("[PrePostHashFixer::print(int, char)]"));
   printf("-->\n");
    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->_pre, symbol, ((PrePostHashFixer*)this)->_precision, (double)num, ((PrePostFixer*)this)->_post);

}



char _ZNK16PrePostHashFixer16getDefaultSymbolEv(const void*const this){
    return '#';
}

/*PrePostFloatDollarFixer*/
void _ZN18PrePostFloatDollarFixerCEcc(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix){

    _ZN18PrePostDollarFixerCERKS_((PrePostDollarFixer *) this, prefix, postfix);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostFloatDollarFixer;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);

}

void _ZN18PrePostFloatDollarFixerCpEpp(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer*const other){
    _ZN18PrePostDollarFixerCEPKcS((PrePostDollarFixer *) this, (PrePostDollarFixer *) other);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostFloatDollarFixer;


}

void _ZN16PrePostFloatDollarFixerDEv(void* this){
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostHashFixer;
    _ZN18PrePostDollarFixerDEv((PrePostDollarFixer*)this);
}

void _ZN23PrePostFloatDollarFixer5printEf(const void* const this, float num){
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", ((PrePostFixer*)this)->_pre, '@', num, ((PrePostFixer*)this)->_post);


}
void _ZNK23PrePostFloatDollarFixer5printEfc(const void* const this, float num, char symbol){
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", ((PrePostFixer*)this)->_pre, symbol, num, ((PrePostFixer*)this)->_post);
}

char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(const void*const this){
    return '@';
}

/*PrePostChecker*/
void _ZN14PrePostCheckerCEv(void* this){
    _ZN18PrePostFloatDollarFixerCEcc((PrePostFloatDollarFixer*)this, "[[[[ ", " ]]]]");
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostChecker;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);

}

void _ZN14PrePostCheckerDEv(void* this){
    printf("--- PrePostChecker DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructPrePostFloatDollarFixer;
    _ZN16PrePostFloatDollarFixerDEv((PrePostDollarFixer*)this);
}
void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(const void*const this){
    printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");
    printf("Default symbol is %c\n", ((typeFuncGetDefaultSymbol)(((TextFormatter*)this)->vPtr)[E_GetDefaultSymbol])(this));
}

void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(const void*const this){
    printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", '@');

}

void _ZN14PrePostChecker24printDollarSymbolByCastUsingFuncEv(const void*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", '@');

}
void _ZN14PrePostChecker24printDollarSymbolByScopeUsingFuncEv(const void*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", '@');
}
void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(const void*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n",'$');

}
void _ZN14PrePostChecker24printDollarSymbolByScopeDirectlyEv(const void*const this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", '$');

}


/* Multiplier Defs */


void _ZN10MultiplierD0Ev(void* this){
    printf("--- Multiplier DTOR: times = %d\n", ((Multiplier*)this)->_times);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructDefaultTextFormatter;
    _ZN20DefaultTextFormatterDEv((DefaultTextFormatter*)this);
}

void _ZN10MultiplierC1ERKS_(Multiplier* this, const Multiplier*const other){
    _ZN23PrePostFloatDollarFixerCEPKcS_((DefaultTextFormatter *) this, (DefaultTextFormatter *) other);
    ((TextFormatter*)this)->vPtr = arrayOfVirtFunctionsStructMultiplier;
    this->_times = other->_times;
}

void _ZNK10Multiplier5printEPKc(const void*const this, const char* text){
    int i = 0;
    printf("%-60s | ","[Multiplier::print(const char*)]");

    for (; i <((Multiplier*)this)->_times; ++i)
        printf("%s", text);
    printf("\n");
}


