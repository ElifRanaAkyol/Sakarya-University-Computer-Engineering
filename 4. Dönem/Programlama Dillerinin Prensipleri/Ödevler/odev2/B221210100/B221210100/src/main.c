/** 
* @file / main.c
* @description / main dosyasý. Burada yapýlan þeyler dosya okuma ve buna baðlý olarak deðerlerden canlý türlerini oluþturma.
* @course / Programlama Dillerinin Prensipleri / 1-A
* @assignment / 2.Ödev
* @date / 12-05-2024
* @author / Muhammed Yusuf Öngel / muhammed.ongel@sakarya.edu.tr
*/

#include "Bitki.c"
#include "Canli.c"
#include "Bocek.c"
#include "Sinek.c"
#include "Pire.c"
#include "Habitat.c"

typedef void* Object;

int main()
{
    int column = 0;
    int row = 0;
    int maxKapasite = 100;
    int number = 0;
    FILE* file;

    char line[600];
    file = fopen("./src/Veri.txt", "r");
    
	if (file == NULL)
		return 0;
    
    
    int** numbers = (int**)malloc(100 * sizeof(int*));

    for(int i=0;i<100;i++)
        numbers[i] = (int*)malloc(100 * sizeof(int));

    //Dosya okuma
    while(fgets(line,sizeof(line),file) != NULL)
    {
        if(row >= maxKapasite)
        {
            maxKapasite = 2 * row;
            numbers = (int**)realloc(numbers, maxKapasite * sizeof(int*));
            
            for(int i=0;i<maxKapasite;i++)
            {
                numbers[i] = (int*)realloc(numbers[i], 2 * column * sizeof(int));
            }
        }
        
        column = 0;
        int index = 0;
        

        while(line[index] != NULL)
        {
            if(isdigit(line[index]))
            {
                if(isdigit(line[index+1]))
                {
                    char numberChar[1];

                    //char deðiþkenini sayýya çevirmek için 48 çýkardýk. (ASCII tablosunda 0 = 48)
                    sprintf(numberChar, "%d%d", line[index] - 48, line[index + 1] - 48);

                    number = strtol(numberChar, NULL, 10);
                    
                    printf("%d ", number);
                    index++;

                    numbers[row][column] = number;
                    column++;
                }
                else
                {
                    char numberChar[1];
                    numberChar[0] = line[index];
                    numberChar[1] = ' ';

                    if(sscanf(numberChar, "%d", &number))
                    {
                        printf("%d ", number);

                        numbers[row][column] = number;
                        column++;
                
                    }
                    
                }
            }

            index++;
        }


        printf("\n");
        row++;
    }
    printf("---------\n");
        
    //Canlýlar matrisi oluþturdum. Bu þekilde karþýlaþtýrmalarý yapacaðým.
    Canli** canlilar = (Canli**)malloc(row * sizeof(Canli*));

    for(int i=0;i<row;i++)
        canlilar[i] = (Canli*)malloc(column * sizeof(Canli));

    //Canlýlarýn türlerini bu dizide tutabileceðim void* sayesinde. Böylece onlarý sileceðim.
    Object** canlilarTur = (Object**)malloc(row * sizeof(Object*));

    for(int i=0;i<row;i++)
        canlilarTur[i] = (Object*)malloc(column * sizeof(Object));
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            //Canlýnýn ne olduðunu bulmaya çalýþýyoruz.
            if(numbers[i][j] >= 1 && numbers[i][j] <= 9)
            {
                Bitki bitki = newBitki(numbers[i][j]);
                //Bir canlýnýn ne olduðunu view soyut sýnýfýyla zaten belirleyebiliyoruz.
                canlilar[i][j] = bitki->super;
                canlilarTur[i][j] = bitki;
            }
            else if(numbers[i][j] <= 20)
            {
                Bocek bocek = newBocek(numbers[i][j]);
                //Bir canlýnýn ne olduðunu view soyut sýnýfýyla zaten belirleyebiliyoruz.
                canlilar[i][j] = bocek->super;
                canlilarTur[i][j] = bocek;
            }
            
            else if(numbers[i][j] <= 50)
            {
                Sinek sinek = newSinek(numbers[i][j]);
                //Bir canlýnýn ne olduðunu view soyut sýnýfýyla zaten belirleyebiliyoruz.
                canlilar[i][j] = sinek->super->super;
                canlilarTur[i][j] = sinek;
            }
            
            else if(numbers[i][j] <= 99)
            {
                Pire pire = newPire(numbers[i][j]);
                //Bir canlýnýn ne olduðunu view soyut sýnýfýyla zaten belirleyebiliyoruz.
                canlilar[i][j] = pire->super->super;
                canlilarTur[i][j] = pire;
            }

            canlilar[i][j]->view(canlilarTur[i][j]);
        }
        
        printf("\n");
    }

    system("PAUSE");

    Canli c1 = canlilar[0][0];
    Canli c2 = canlilar[0][1];

    int boolControl = 0;
    
    for(int i=0;i<row;i++)
    {
        boolControl = 0;

        for(int j=0;j<column-1;j++)
        {
            //Burada boolControl deðiþkeni ile sonraki satýra geçtiðimizde önceki satýrdan kalan canlýyla vs atabiliyoruz.
            if(j == 0 && i != 0 && boolControl == 0)
            {
                boolControl++;
                j -= 1;
            }

            Habitat habitat = newHabitat();
            habitat->vs(c1, c2);

            //Burada j+2 kontrolü yapýyorum çünkü canlýnýn indeksi j+2 olacak ve eðer j+2 indeksi yoksa hata verir.
            if(c1->symbol != "X" && j+2 <= column-1)
            {
                c2 = c1;
                c1 = canlilar[i][j+2];
            }

            if(c2->symbol != "X" && j+2 <= column-1)
                c1 = canlilar[i][j+2];

            if(c1->symbol != "X" && j+2 > column-1)
            {
                //Eðer bir sonraki satýra geçtiyse
                if(i+1 < row)
                {
                    c2 = c1;
                    c1 = canlilar[i+1][0];
                }
            }
            
            if(c2->symbol != "X" && j+2 > column-1)
            {
                if(i+1 < row)
                {
                    c1 = canlilar[i+1][0];
                }
            }
            system("CLS");
            printf("\n");

            //Yazdýrma iþlemi
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    if(canlilar[i][j]->symbol != "X")
                        canlilar[i][j]->view(canlilarTur[i][j]);
                    else
                        printf("%s ", canlilar[i][j]->viewDead());

                }
                
                printf("\n");
            }

            printf("\n");
            habitat->deleteHabitat(habitat);
        }
    }

    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            //Eðer sembol deðiþmemiþse kazanan canlýyý yazdýrýyoruz.
            if(canlilar[i][j]->symbol != "X")
                printf("Kazanan: %s(%d, %d)", canlilar[i][j]->symbol, i, j);

            else
            {
                //Deðerlere göre canlýnýn hangi tür olduðunu belirliyoruz. Ardýndan onlarý siliyoruz.
                if(canlilar[i][j]->value <= 9)
                {
                    Bitki bitki = (Bitki)canlilarTur[i][j];
                    bitki->deleteBitki(bitki);
                    canlilar[i][j] = NULL;
                }
                else if(canlilar[i][j]->value <= 20)
                {
                    Bocek bocek = (Bocek)canlilarTur[i][j];
                    bocek->deleteBocek(bocek);
                    canlilar[i][j] = NULL;
                }
                else if(canlilar[i][j]->value <= 50)
                {
                    Sinek sinek = (Sinek)canlilarTur[i][j];
                    sinek->deleteSinek(sinek);
                    canlilar[i][j] = NULL;
                }
                else if(canlilar[i][j]->value <= 99)
                {
                    Pire pire = (Pire)canlilarTur[i][j];
                    pire->deletePire(pire);
                    canlilar[i][j] = NULL;
                }
            }
        }
    }

}
