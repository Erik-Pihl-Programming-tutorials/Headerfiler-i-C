/********************************************************************************
* main.c: Demonstration av headerfiler i C.
* 
*         Headerfiler anv�nds i C f�r att implementera bibliotek, exempelvis
*         standardbibliotek s�som stdio.h och stdlib.h, samt f�r att deklarera
*         och definiera inneh�ll f�r anv�ndning i en eller flera k�llkodsfiler,
*         exempelvis funktionsdeklarationer, makrodefinitioner, enumerationer 
*         andra bibliotek med mera. 
*
*         Genom att placera inneh�ll i en headerfil s� beh�ver inte detta 
*         klistras in manuellt i olika k�llkodsfiler; i st�llet kr�vs enbart
*         att headerfilen inkluderas via inkluderingsdirektivet #include,
*         vilket medf�r att headerfilens inneh�ll klistras in i k�llkodsfilen.
* 
*         Ett standardbibliotek s�som stdio.h inkluderas med <> enligt nedan:
* 
*         #include <stdio.h>
* 
*         N�r <> anv�nds vid inkludering s�ks headerfilen enbart bland
*         C:s standardbibliotek.
* 
*         En egenskapad headerfil inkluderas med "" enligt nedan:
* 
*         #include "double_array.h"
* 
*         N�r citattecken anv�nds s�som ovan s�ks headerfilen f�rst bland
*         lokala headerfiler (p� aktuell fils�kv�g). Om denna inte hittas s� 
*         sker s�kning bland C:s standardbibliotek.
* 
*         F�r att se till att inneh�llet i en headerfil inte definieras mer
*         �n en g�ng, oavsett antalet k�llkodsfiler denna headerfil inkluderas
*         i s� anv�nds s� kallade header guards eller include guards, som
*         skrivs enligt nedan:
* 
*         #ifndef HEADERFILENS_NAMN_H_
*         #define HEADERFILENS_NAMN_H_
* 
*         // Mellan #define och #endif placeras headerfilens inneh�ll.
* 
*         #endif 
*  
*         F�r traditionella header guards anv�nds ett flerradigt makro f�r att 
*         kontrollera s� att headerfilens inneh�ll inte blir definierat med �n 
*         en g�ng, se HEADERFILENS_NAMN_H_ ovan. Detta makro brukar d�pas till 
*         samma som headerfilen, men enbart med stora bokst�ver, ett understreck 
*         i st�llet f�r punkt samt ett avslutande understreck. Detta g�rs f�r att 
*         undvika namnkrock med ett annat makro i ett givet program, s� m�ls�ttningen
*         �r att makrot d�ps till ett unikt namn. 
* 
*         Som exempel, f�r en headerfil d�pt double_array.h kan ett flerradigt
*         makro d�pt DOUBLE_ARRAY_H_ anv�ndas. N�r headerfilen double_array.h
*         inkluderas i en k�llkodsfil, vilket i praktiken medf�r att inneh�llet
*         klistras in, s� sker f�rst kontroll att makrot DOUBLE_ARRAY_H_ inte
*         har blivit definierat �n via direktivet #ifndef, vilket st�r f�r
*         "if not defined". Om detta �r sant, s� defineras makrots inneh�ll,
*         allts� allt mellan #define samt #endif. N�r makrot (och d�rmed 
*         inneh�llet mellan #define och #endif) har blivit definierat en g�ng,
*         s� sker inga fler definitioner, d� ifall denna headerfil inkluderas
*         �n en g�ng i en annan k�llkodsfil s� sker kontroll ifall makrot
*         DOUBLE_ARRAY_H_ har definierats. Eftersom detta makro nu �r
*         definierat s� sker ingen ytterligare definition. Inneh�llet i
*         headerfilen �r dock fortfarande synlig i den fil inneh�llet har
*         inkluderats, men det sker allts� inte en ny definition.
* 
*         En nyare typ av header guard �r direktivet #pragma once, som placeras
*         l�ngst upp i en fil s� att filens inneh�ll inte definieras mer �n en
*         g�ng. Detta direktiv har f�rdelen att det �r l�ttare att skriva samt 
*         att risken f�r namnkrockar med de makron som anv�nds f�r regulj�ra 
*         header guards elimineras (d� detta inte beh�vs alls). #pragma once 
*         ing�r dock inte i C-standarden och st�ds d�rmed inte f�r alla 
*         kompilatorer, till skillnad mot header guards, som st�ds universellt. 
*         D�rmed �r det inte s�kert att #pragma once fungerar f�r en given
*         plattform. De flesta kompilatorer st�djer dock #pragma once, s� f�r
*         det mesta kan detta anv�ndas, antingen enbart eller i kombination
*         med traditionella header guards. I detta exempel anv�nds enbart
*         traditionella header guards.
********************************************************************************/
#include "double_array.h"

/********************************************************************************
* main: Deklarerar en flyttalsarray som rymmer 20 flyttal. Denna array fylls
*       till bredden flyttal i steg om 0.5 (0, 0.5, 1, 1.5 med mera). Arrayens
*       inneh�ll sorteras sedan i fallande ordning och skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   double data[20];
   double_array_assign(data, 20, 0.5);

   double_array_sort_descending(data, 20);
   double_array_print(data, 20);

   double_array_sort_ascending(data, 20);
   double_array_print(data, 20);

   return 0;
}


