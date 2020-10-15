

#ifndef UNDERTHEHOOD_POLYMORPISM_H
#define UNDERTHEHOOD_POLYMORPISM_H

typedef void*(*typeFuncPointer)(void*);
typedef void*(*typeVpnPointer)(void*);
typedef void(*typeFuncPrintLongChar)(const void* const, long, char);
typedef char(*typeFuncGetDefaultSymbol)(const void* const);
typedef void(*typeFuncPrintPointerToChar)(const void* const, const char*);
typedef void(*typeDtor)(void*);



extern int _ZN20DefaultTextFormatter4Ider7next_idE;
extern typeVpnPointer arrayOfVirtFunctionsStructTextFormatter[];
extern typeVpnPointer arrayOfVirtFunctionsStructDefaultTextFormatter[];
extern typeVpnPointer arrayOfVirtFunctionsStructPrePostFixer[];
extern typeVpnPointer arrayOfVirtFunctionsStructPrePostHashFixer[];
extern typeVpnPointer arrayOfVirtFunctionsStructPrePostFloatDollarFixer[];
extern typeVpnPointer arrayOfVirtFunctionsStructPrePostDollarFixer[];
extern typeVpnPointer arrayOfVirtFunctionsStructMultiplier[];
extern typeVpnPointer arrayOfVirtFunctionsStructPrePostChecker[];




typedef enum FunctionsName
{
    E_Dtor,
    E_PrintEConst_char,
    E_PrintELongAndChar,
    E_GetDefaultSymbol
}FunctionsName;




/*// TextFormatter //*/

typedef struct TextFormatter{
    void *(** vPtr)(void*);
}TextFormatter;

void _ZN13TextFormatterCEv(TextFormatter* this);

void _ZN13TextFormatterDEv(void* this);


/*// DefaultTextFormatter //*/


typedef struct DefaultTextFormatter{
    TextFormatter textFormatter;
    int _id;
}DefaultTextFormatter;



void _ZN20DefaultTextFormatterCEv(DefaultTextFormatter * this);

void _ZN20DefaultTextFormatterDEv(void* this);

void _ZN13DefaultTextFormatter5printEc(const void*const this, const char* text);

void _ZN23PrePostFloatDollarFixerCEPKcS_(DefaultTextFormatter * this, const DefaultTextFormatter*const other);

DefaultTextFormatter* _ZN20DefaultTextFormatter2AsEpkD(DefaultTextFormatter * this, const DefaultTextFormatter*const other);

DefaultTextFormatter* _Z22generateFormatterArrayEv();


/*// PrePostFixer//*/
typedef struct  PrePostFixer{
     DefaultTextFormatter defaultTextFormatter;
     const char* _pre;
     const char* _post;
}PrePostFixer;

void _ZN12PrePostFixerC1ERKS_(PrePostFixer* this, const char* prefix, const char* postfix);
void _ZN12PrePostFixerDEv(void* this);
void _ZN12PrePostFixerC1EPKcS1_(PrePostFixer* this, const PrePostFixer*const other);
void _ZNK12PrePostFixer5printEPKc(const void*const this, const char* text);
void _ZNK12PrePostFixer5printElc(const void* const this, long num, char symbol);
char _ZNK12PrePostFixer16getDefaultSymbolEv(const void*const this);


/*PrePostDollarFixer*/
typedef struct PrePostDollarFixer{
    PrePostFixer prePostFixer;
}PrePostDollarFixer;


void _ZN18PrePostDollarFixerCERKS_(PrePostDollarFixer* this, const char* prefix, const char* postfix);
void _ZN18PrePostDollarFixerDEv(void* this);
void _ZN18PrePostDollarFixerCEPKcS(PrePostDollarFixer* this, const PrePostDollarFixer*const other);
void _ZN18PrePostDollarFixer5printElc(const void *const this,long num, char symbol);
void _ZN18PrePostDollarFixer5printEic(const PrePostDollarFixer*const this,int num, char symbol);
void _ZN18PrePostDollarFixer5printEdc(const PrePostDollarFixer*const this, double num, char symbol);
char _ZN18PrePostDollarFixer16getDefaultSymbol(const void*const this);



/* PrePostHashFixer*/
typedef struct PrePostHashFixer {
    PrePostDollarFixer prePostDollarFixer;
    int _precision;
}PrePostHashFixer;

void _ZN18PrePostHashFixerCEcc(PrePostHashFixer* this, int prc);
void _ZN16PrePostHashFixerDEv(void* this);
void _ZN18PrePostHashFixerCpEpp(PrePostHashFixer* this, const PrePostHashFixer*const other);
void _ZN16PrePostHashFixer5printEic(const PrePostHashFixer* const this,int num, char symbol);
void _ZN16PrePostHashFixer5printElc(const void* const this,long num, char symbol);


char _ZNK16PrePostHashFixer16getDefaultSymbolEv(const void*const this);


/*PrePostFloatDollarFixer*/
typedef struct PrePostFloatDollarFixer{
    PrePostDollarFixer prePostDollarFixer;
}PrePostFloatDollarFixer;

void _ZN18PrePostFloatDollarFixerCEcc(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix);
void _ZN18PrePostFloatDollarFixerCpEpp(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer*const other);
void _ZN16PrePostFloatDollarFixerDEv(void* this);
void _ZN23PrePostFloatDollarFixer5printEf(const void* const this, float num);
void _ZNK23PrePostFloatDollarFixer5printEfc(const void* const this, float num, char symbol);
char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(const void*const this);

/*PrePostChecker*/
typedef struct PrePostChecker{
    PrePostFloatDollarFixer prePostFloatDollarFixer;
}PrePostChecker;

void _ZN14PrePostCheckerCEv(void* this);
void _ZN14PrePostCheckerDEv(void* this);
void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(const void*const this);
void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(const void*const this);
void _ZN14PrePostChecker24printDollarSymbolByCastUsingFuncEv(const void*const this);
void _ZN14PrePostChecker24printDollarSymbolByScopeUsingFuncEv(const void*const this);
void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(const void*const this);
void _ZN14PrePostChecker24printDollarSymbolByScopeDirectlyEv(const void*const this);


/* Multiplier*/

typedef struct Multiplier{
    DefaultTextFormatter defaultTextFormatter;
    int _times;
}Multiplier;

void _ZN10MultiplierD0Ev(void* this);
void _ZN10MultiplierC1ERKS_(Multiplier* this, const Multiplier*const other);
void _ZNK10Multiplier5printEPKc(const void*const this, const char*);

#endif /*/UNDERTHEHOOD_POLYMORPISM_H*/
