/********************************************************************************
* double_array.h: Innehåller funktionalitet för implementering av arrayer
*                 innehållande flyttal, exempelvis tilldelning, utskrift och
*                 och sortering.
********************************************************************************/
#ifndef DOUBLE_ARRAY_H_
#define DOUBLE_ARRAY_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* double_array_assign: Tilldelar flyttal till en array med angiven steghastighet.
*
*                      - self: Pekare till arrayen som skall tilldelas.
*                      - size: Arrayens storlek, dvs. antalet element den rymmer.
*                      - step: Stegringshastighet, dvs. skillnaden mellan varje
*                              tillagt element, exempelvis 0,5 för att tilldela
*                              0, 0.5, 1, 1.5, 2 och så vidare.
********************************************************************************/
void double_array_assign(double* self,
                         const int size,
                         const double step);

/********************************************************************************
* double_array_print: Skriver ut flyttal lagrade i angiven array i terminalen.
*
*                      - self: Pekare till flyttalsarrayen.
*                      - size: Arrayens storlek, dvs. antalet element den rymmer.
********************************************************************************/
void double_array_print(const double* self,
                        const int size);

/********************************************************************************
* double_array_sort_ascending: Sorterar flyttal lagrade i angiven array i
*                              stigande ordning, dvs. från minst till störst.
* 
*                              - self: Pekare till arrayen vars innehåll skall
*                                      sorteras.
*                              - size: Arrayens storlek, dvs. antalet element
*                                      denna rymmer.
********************************************************************************/
void double_array_sort_ascending(double* self,
                                 const int size);

/********************************************************************************
* double_array_sort_descending: Sorterar flyttal lagrade i angiven array i
*                               fallande ordning, dvs. från störst till minst.
*
*                               - self: Pekare till arrayen vars innehåll skall
*                                       sorteras.
*                               - size: Arrayens storlek, dvs. antalet element
*                                       denna rymmer.
********************************************************************************/
void double_array_sort_descending(double* self,
                                  const int size);

#endif /* DOUBLE_ARRAY_H_ */