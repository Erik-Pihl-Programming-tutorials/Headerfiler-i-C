/********************************************************************************
* main.c: Demonstration av headerfiler i C.
* 
*         Headerfiler används i C för att implementera bibliotek, exempelvis
*         standardbibliotek såsom stdio.h och stdlib.h, samt för att deklarera
*         och definiera innehåll för användning i en eller flera källkodsfiler,
*         exempelvis funktionsdeklarationer, makrodefinitioner, enumerationer 
*         andra bibliotek med mera. 
*
*         Genom att placera innehåll i en headerfil så behöver inte detta 
*         klistras in manuellt i olika källkodsfiler; i stället krävs enbart
*         att headerfilen inkluderas via inkluderingsdirektivet #include,
*         vilket medför att headerfilens innehåll klistras in i källkodsfilen.
* 
*         Ett standardbibliotek såsom stdio.h inkluderas med <> enligt nedan:
* 
*         #include <stdio.h>
* 
*         När <> används vid inkludering söks headerfilen enbart bland
*         C:s standardbibliotek.
* 
*         En egenskapad headerfil inkluderas med "" enligt nedan:
* 
*         #include "double_array.h"
* 
*         När citattecken används såsom ovan söks headerfilen först bland
*         lokala headerfiler (på aktuell filsökväg). Om denna inte hittas så 
*         sker sökning bland C:s standardbibliotek.
* 
*         För att se till att innehållet i en headerfil inte definieras mer
*         än en gång, oavsett antalet källkodsfiler denna headerfil inkluderas
*         i så används så kallade header guards eller include guards, som
*         skrivs enligt nedan:
* 
*         #ifndef HEADERFILENS_NAMN_H_
*         #define HEADERFILENS_NAMN_H_
* 
*         // Mellan #define och #endif placeras headerfilens innehåll.
* 
*         #endif 
*  
*         För traditionella header guards används ett flerradigt makro för att 
*         kontrollera så att headerfilens innehåll inte blir definierat med än 
*         en gång, se HEADERFILENS_NAMN_H_ ovan. Detta makro brukar döpas till 
*         samma som headerfilen, men enbart med stora bokstäver, ett understreck 
*         i stället för punkt samt ett avslutande understreck. Detta görs för att 
*         undvika namnkrock med ett annat makro i ett givet program, så målsättningen
*         är att makrot döps till ett unikt namn. 
* 
*         Som exempel, för en headerfil döpt double_array.h kan ett flerradigt
*         makro döpt DOUBLE_ARRAY_H_ användas. När headerfilen double_array.h
*         inkluderas i en källkodsfil, vilket i praktiken medför att innehållet
*         klistras in, så sker först kontroll att makrot DOUBLE_ARRAY_H_ inte
*         har blivit definierat än via direktivet #ifndef, vilket står för
*         "if not defined". Om detta är sant, så defineras makrots innehåll,
*         alltså allt mellan #define samt #endif. När makrot (och därmed 
*         innehållet mellan #define och #endif) har blivit definierat en gång,
*         så sker inga fler definitioner, då ifall denna headerfil inkluderas
*         än en gång i en annan källkodsfil så sker kontroll ifall makrot
*         DOUBLE_ARRAY_H_ har definierats. Eftersom detta makro nu är
*         definierat så sker ingen ytterligare definition. Innehållet i
*         headerfilen är dock fortfarande synlig i den fil innehållet har
*         inkluderats, men det sker alltså inte en ny definition.
* 
*         En nyare typ av header guard är direktivet #pragma once, som placeras
*         längst upp i en fil så att filens innehåll inte definieras mer än en
*         gång. Detta direktiv har fördelen att det är lättare att skriva samt 
*         att risken för namnkrockar med de makron som används för reguljära 
*         header guards elimineras (då detta inte behövs alls). #pragma once 
*         ingår dock inte i C-standarden och stöds därmed inte för alla 
*         kompilatorer, till skillnad mot header guards, som stöds universellt. 
*         Därmed är det inte säkert att #pragma once fungerar för en given
*         plattform. De flesta kompilatorer stödjer dock #pragma once, så för
*         det mesta kan detta användas, antingen enbart eller i kombination
*         med traditionella header guards. I detta exempel används enbart
*         traditionella header guards.
********************************************************************************/
#include "double_array.h"

/********************************************************************************
* main: Deklarerar en flyttalsarray som rymmer 20 flyttal. Denna array fylls
*       till bredden flyttal i steg om 0.5 (0, 0.5, 1, 1.5 med mera). Arrayens
*       innehåll sorteras sedan i fallande ordning och skrivs ut i terminalen.
*       Slutligen sorteras innehållet i stigande ordning och skrivs ut igen.
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


