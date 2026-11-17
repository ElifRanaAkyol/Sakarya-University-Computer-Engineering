#include "Daire.h"
#include "Kare.h"


//objectin benzetimi

typedef void Object; //objectin benzetimi
int main()
{
    Object* obj = new_Daire("Kırmızı", 5); 
    //Daire d1 = new_Daire("Kırmızı", 5);
    //char* str = d1->super->toString(d1->super, d1);
    char* str = ((Daire)obj)->super->toString(((Daire)obj)->super, obj);

    printf("%s", str);
    free(str);
    ((Daire)obj)->delete_Daire(obj);
    
    Kare k1 = new_Kare("Mavi", 4);
    str=k1->super->toString(k1->super, k1);
    printf("%s", str);
    free(str);

    
    k->delete_Kare(k1);

    return 0;
}