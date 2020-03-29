#include<stdio.h>
#include<stdlib.h>

/*
  Snazim sa zistit, ci slovo na vstupe (o dlzke l) je entanglovane. Ak by nebolo (a podla
  emailu, ktory som vam pisal) by to znamenalo, te to slovo viem rozdelit na dve slova tak,
  ze nemaju navzajom spolocne pismenko. Algoritmus skusi presne toto urobit takto:
  
  - Povieme si, ze take rozdelenie existuje a nastavime dlzku prveho slova na 1
  - Pozrieme sa kde najdalej sa nachadza toto pismeno a ak je to nutne, tak navysime dlzku
    slova na tuto poziciu
  - Toto opakujeme postupne az po posledne pismeno dlzky
  - Ak je na konci dlzka rovnaka ako dlzka slova, tak take rozdelenie slov neexistuje
    a vtedy je slovo entanglovane (vystup 1), inak je neentanglovane (vystup 0)
*/

char test_prepletenosti(char *w, int l)
{
  int i, j, najdalej, dlzka = 1;
  
  for(i=0; i<dlzka; i++)
  {
    // v celom slove sa snazim najst najposlednejsiu polohu pismenka, na ktorom prave sme
    najdalej = 0;
    for(j=0; j<l; j++)
    {
      if(w[i] == w[j])
      {
        najdalej = j;
      }
    }
    // dlzka takeho slova potom je (najdalej+1) a ak je to viac ako mame doteraz, tak upravime dlzku
    if(dlzka < najdalej+1)
    {
      dlzka = najdalej+1;
    }
  }
  
  // ak je dlzka to iste ako l take rozdelenie neexistuje -- slovo je entanglovane
  if(dlzka == l)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// funkcia na vypis...
void vypis(char *w, int l)
{
  char vysledok;
  
  vysledok = test_prepletenosti(w, l);
  
  if(vysledok == 0)
  {
    printf("Slovo \"%s\" NIE je entanglovane.\n", w);
  }
  else
  {
    printf("Slovo \"%s\" JE entanglovane.\n", w);
  }
}

int main()
{
  char slovo1[5] = {'a', 'b', 'b', 'b', '\0'};
  char slovo2[5] = {'b', 'a', 'b', 'b', '\0'};
  char slovo3[8] = {'a', 'b', 'a', 'c', 'a', 'c', 'd', '\0'};
  
  vypis(slovo1, 4);
  vypis(slovo2, 4);
  vypis(slovo3, 7);
  
  return 0;
}
