/********************************************************************************
* double_array.c: Inneh�ller funktionsdefinitioner f�r implementering av arrayer
*                 inneh�llande flyttal, exempelvis tilldelning, utskrift och
*                 och sortering.
********************************************************************************/
#include "double_array.h"

/********************************************************************************
* double_array_assign: Tilldelar flyttal till en array med angiven steghastighet.
*
*                      - self: Pekare till arrayen som skall tilldelas.
*                      - size: Arrayens storlek, dvs. antalet element den rymmer.
*                      - step: Stegringshastighet, dvs. skillnaden mellan varje
*                              tillagt element, exempelvis 0,5 f�r att tilldela
*                              0, 0.5, 1, 1.5, 2 och s� vidare.
********************************************************************************/
void double_array_assign(double* self,
                         const int size,
                         const double step)
{
   double num = 0;

   for (int i = 0; i < size; ++i)
   {
      self[i] = num;
      num += step;
   }

   return;
}

/********************************************************************************
* double_array_print: Skriver ut flyttal lagrade i angiven array i terminalen.
*                     Varje flyttal skrivs ut med en decimal.
*
*                      - self: Pekare till flyttalsarrayen.
*                      - size: Arrayens storlek, dvs. antalet element den rymmer.
********************************************************************************/
void double_array_print(const double* self,
                        const int size)
{
   if (size <= 0) return;
   printf("--------------------------------------------------------------------------------\n");

   for (int i = 0; i < size; ++i)
   {
      printf("%.1lf\n", self[i]);
   }

   printf("--------------------------------------------------------------------------------\n\n");
   return;
}

/********************************************************************************
* double_array_sort_ascending: Sorterar flyttal lagrade i angiven array i
*                              stigande ordning, dvs. fr�n minst till st�rst.
*
*                              - self: Pekare till arrayen vars inneh�ll skall
*                                      sorteras.
*                              - size: Arrayens storlek, dvs. antalet element
*                                      denna rymmer.
********************************************************************************/
void double_array_sort_ascending(double* self,
                                 const int size)
{
   for (int i = 0; i < size - 1; ++i)
   {
      for (int j = i + 1; j < size; ++j)
      {
         if (self[i] > self[j])
         {
            const double temp = self[i];
            self[i] = self[j];
            self[j] = temp;
         }
      }
   }

   return;
}

/********************************************************************************
* double_array_sort_descending: Sorterar flyttal lagrade i angiven array i
*                               fallande ordning, dvs. fr�n st�rst till minst.
*
*                               - self: Pekare till arrayen vars inneh�ll skall
*                                       sorteras.
*                               - size: Arrayens storlek, dvs. antalet element
*                                       denna rymmer.
********************************************************************************/
void double_array_sort_descending(double* self,
                                  const int size)
{
   for (int i = 0; i < size - 1; ++i)
   {
      for (int j = i + 1; j < size; ++j)
      {
         if (self[i] < self[j])
         {
            const double temp = self[i];
            self[i] = self[j];
            self[j] = temp;
         }
      }
   }

   return;
}