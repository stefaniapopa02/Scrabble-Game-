POPA STEFANIA, 315CD

In functia main:
    Citesc prima linie a inputului, care va reprezenta numarul taskului, si in functie de caracterul citit('0', '1', '2', '3', '4','5' sau '6'), 
    apelez functia corespunzatoare taskului aferent.

Modul de citire a inputului: 
    La fiecare task, voi citi inputul linie cu linie intr-un vector de caractere. Voi separa datele de pe o linie citita cu ajutorul functiei 
    "strtok". Cele care reprezinta numere sau cifre vor fi transformate in date de tip intreg, folosind functia "atoi". Datele sunt salvate 
    in variabilele aferente, cu nume sugestiv, sau cu nume preluat din cerinta temei.           

Cerinta 0:
    Am populat tabla de joc cu valoarea '.'(caracterul punct), folosind 2 structuri repetitive cu ajutorul carora parcurg matricea.

Cerinta 1: 
    Inainte de a ma apuca de rezolvarea efectiva a acestei cerinte, am populat tabla de joc cu '.', folosind functia de la cerinta anterioara.
    Pentru fiecare din cele N cuvinte citite, asezam cuvantul pe tabla de joc, pornind de la linia si coloana citite, in functie de directia 
    data. Pentru aceasta, calculam lungimea cuvantului(length) curent folosind functia "strlen". In cazul in care cuvantul va fi pus pe 
    orizontala, vom aseza cele length litere ale cuvantului pastrand linia si avansand  cu cate o coloana. In cazul in care cuvantul va fi pus 
    pe verticala, vom aseza cele length litere ale cuvantului pastrand coloana si avansand  cu cate o linie. La sfarsit, afisam tabla de joc
    folosind functia "print_board".

Cerinta 2:
    Pentru retinerea punctajului fiecarei litere, folosim un vector de tip intreg(score[25]): valoarea primului element(score[0]) va reprezenta
    punctajul literei 'A', a celui de-al doilea element, valoarea literei 'B',..., valoarea ultimului element(score[25]) va reprezenta punctajul
    literei 'Z'. Consideram ca actualul cuvant este al i-lea cuvant citit. Daca i este numar impar, atunci scorul cuvantului se va adauga la 
    punctajul primului jucator, iar daca este numar par, se va adauga la punctajul celui de-al doilea jucator. Calculam scorul fiecarui cuvant
    insumand punctajele literelor acestuia, folosind vectorul score. Pentru a ne putea folosi de vectorul score, trebuie sa aflam de fiecare 
    data a cata litera din alfabet este cea curenta. Pentru acest fapt, scadem din litera curenta, litera 'A'('A' este litera de pe pozitia zero
    , 'A' - 'A' = 0; 'B' este litera de pe pozitia 1, 'B' - 'A' = 1, s.a.m.d ). La sfarsit afisam punctajele conform formatului cerut.

Cerinta 3:
    Mai intai, calculez scorul cuvantului curent asa cum am facut la taskul precedent. Verific apoi daca acesta respecta conditiile pentru
    bonus1(in interiorul cuvantului se regaseste grupul de litere citit in vectorul XX) respectiv pentru bonus2(ultimele 2 litere ale 
    cuvantului se identifica cu grupul citit in vectorul YY). Parcurgem cuvantul si verificam daca pe pozitia literei curente, regasim pe 
    tabla de bonusuri valoarea 1 sau valoarea 2. Daca la un moment dat gasim valoarea 1 si condiitile pentru bonus1 sunt respectate, atunci
    scorul se dubleaza, iar daca gasim valoarea 2 si conditiile pentru bonus2 sunt respectate, scorul cuvantului actual se tripleaza. In 
    functie de paritatea numarului cuvantului actual, adaugam scorul acestuia la scorul primului jucator(daca nr cuvantului citit este impar),  
    respectiv la scorul celui de-al doilea jucator(daca nr cuvantului citit este par). Afisam scorurile jucatorilor conform formatului cerut.
    
Cerinta 4:
    Inainte de a ma apuca de rezolvarea efectiva a acestei cerinte, am populat tabla de joc cu '.', folosind functia "task0" de la cerinta 0.
    In timp ce citim datele, vom folosi matricea used[100][30] pentru a retine cele N cuvinte folosite, cate unul pe linie. Voi lua in ordine 
    cate un cuvant din vectorul words, iar pentru fiecare: voi verifica daca acesta a mai fost folosit(cautand in vectorul de cuvinte used);
    daca nu a mai fost folosit voi verifica daca prima sa litera se gaseste deja pe tabla de joc; daca da, voi incerca sa il asez pe orizontala;
    pentru aceasta voi verifica daca nu se suprapune cu un alt cuvant(pentru a nu se suprapune cu un alt cuvant ar trebui ca toate casutele pe 
    care ar urma sa fie asezate literele cuvantului sa contina caracterul '.'); daca nu au fost indeplinite toate conditiile pentru a putea 
    aseza cuvantul pe orziontala, voi incerca in acelasi mod sa il asez pe verticala. In momentul in care gasesc un cuvant care respecta toate
    conditiile, opresc cautarea si il asez pe tabla de joc la coordonatele gasite si pe directia gasita. La sfarsit, afisam stadiul final al 
    tablei de joc, folosind functia "print_board".

Cerinta 5:
    Inainte de a ma apuca de rezolvarea efectiva a acestei cerinte, am populat tabla de joc cu '.', folosind functia "task0" de la cerinta 0.
    Mai intai calculam scorul fiecarui jucator dupa cele N cuvinte jucate, in acelasi mod in care am procedat la cerinta 3. Apoi aflu cuvantul,
    coordonatele si directia care aduc scorul maxim posibil dintre toate cuvintele din vectorul words si dintre toate posibilitatile de 
    pozitionare ale acestora. Pentru a face acest lucru, procedez ca la cerina 4, doar ca nu ma opresc la primul cuvant gasit in vectorul
    words care respecta toate conditiile, ci procedez la fel pentru toate cuvintele din vector si pentru toate pozitionarile posibile ale 
    acestora. In plus, voi calcula de fiecare data scorul adus de cuvantul si pozitionarea curente si voi retine toate datele(cuvantul, scorul,
    coordonatele si directia) despre cuvantul care genereaza scorul maxim pana la momentul actual. La sfarsit voi avea datele despre cuvantul
    optim pe care il poate juca al doilea jucator. La sfarsit, in cazul in care cuvantul gasit ii aduce castigul sau remiza celui de-al doilea
    jucator, vom adauga cuvantul pe tabla de joc si o vom afisa folosind functia "print_board", altfel vom afisa "Fail!".

Cerinta BONUS:
    Inainte de a ma apuca de rezolvarea efectiva a acestei cerinte, am populat tabla de joc cu '.', folosind functia "task0" de la cerinta 0.
    Dupa citirea si adaugarea pe tabla ale unui nou cuvant jucat de player1, voi actualiza scorul primului jucator, iar apoi voi proceda exact 
    ca la cerinta anterioara pentru a gasi cuvantul optim pe care player2 il poate juca. Adaug cuvantul optim pe tabla si actualizez scorul
    celui de-al doilea jucator. Procedez in acest fel pentru fiecare din cele N cuvinte date si jucate de player1. La sfarsit, afisez stadiul 
    final al tablei de joc si jucatorul castigator.

    
    