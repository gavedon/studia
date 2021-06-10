/*
 * UWAGA! W poniższym kodzie należy zawrzeć krótki opis metody rozwiązania
 *        zadania. Będzie on czytany przez sprawdzającego. Przed przystąpieniem
 *        do rozwiązywania zapoznaj się dokładnie z jego treścią. Poniżej należy
 *        wypełnić oświadczenie o samodzielnym wykonaniu zadania.
 *
 * Oświadczam, że zapoznałem(-am) się z regulaminem prowadzenia zajęć
 * i jestem świadomy(-a) konsekwencji niestosowania się do podanych tam zasad.
 *
 * Imię i nazwisko, numer indeksu: Krzysztof Chmiel, 316749
 */

        .text
        .globl  addsb
        .type   addsb, @function

/*
 * W moim rozwiązaniu używam następującej techniki: Wycinam bity znaków. Sprawdzam kiedy są te same znaki, dające 
 potencjalnego overflowa, bo dla przeciwnych nie da się mieć nadmiaru. Następnie wykonuje dodawanie wektorów typu int_8 
 i sprawdzam gdzie faktycznie wystąpił overflow. Potem sumuje overflowy dodatnie z ujemnymi i na końcu tam gdzie wystąpiły
 albo zostawiam 1000 0000, jeśli był ujemny overflow, albo nakładam maskę 0111 1111 dla dodatnich, sumy bez nadmiaru
 pozostawiam bez zmian.
 */

/* uint64_t saturatingAddition(uint64_t x (%rdi), uint64_t y (%rsi))*/

addsb:
    mov     $0x7F7F7F7F7F7F7F7F,%r8 /* maska postaci ...01111 1111 0111 1111... ,której użyjemy do pozbycia się znaków */
    mov     $0x8080808080808080,%r9 /*maska postaci  ...1000 0000 1000 0000...  , której użyjemy do znalezienia overflow-ów */
    mov     %rdi,%rcx /*bedę potrzebował dwóch kopii iksa*/
    mov     %rdi,%rdx  
                        /* poniższe dwie linijki są do znalezienia potencjalnego dodatniego overflowa  
                         ponieważ zaprzeczenie or-a da 0 dla par (0,1); (1,0); (1,1), a tylko dla pary (0,0) da 1 */
    or      %rsi,%rdx
    not     %rdx 
    and     %rsi,%rcx /*z kolei potencjalny overflow ujemny da 1 tylko dla pary (1,1), więc wystarczy AND */     
    and     %r9,%rdx /*wyzbywamy się niepotrzebnych innych jedynek za pomocą maski, zostawiając jedynki tylko 
                       na sign bitach potencjalnego dodatniego overflowa*/
    and     %r9,%rcx /*tutaj postępujemy podobnie, z tym że dla overflowa ujemnego*/
    and     %r8,%rdi /*teraz kiedy już wyłuskaliśmy potencjalne overflowy możemy pozbyć się znaków wektorów z x...*/
    and     %r8,%rsi /*... oraz z y*/
    add     %rsi,%rdi /*teraz dodajemy x i y, które już nie mają zapalonych sign bitów i pakujemy wynik do x*/
    mov     %rdx,%rax /*tworzymy kopię rejestru z potencjalnymi dodatnimi overflow-ami */

                      /* poniższe trzy linijki to: do %rax-a dajemy sumę wystąpień wszystkich potencjalnych overflow-ów, 
                      bez względu na znak, następnie zaprzeczamy. Służy to do tego, że wektory postaci 1000 0000,czyli 
                      takie gdzie występuje któryś z overflow-ów (dowolnie + lub -) przechodzą na 0111 1111, a takie
                      gdzie overflowa żadnego nie ma przechodzą z 0000 0000 na 1111 1111. Zrobienie potem AND-a z sign maską
                      da tyle, że zapisze się nam znak wektorów bez overflowa tj. 0&1 => 0 ,a 1&1 => 1*/
    or      %rcx,%rax
    not     %rax    
    and     %rax,%r9
    and     %rdi,%rdx /*sprawdzamy potencjalny overflow dodatni z faktycznym przeniesieniem, które mogło wystąpić przy 
                        dodawaniu, gdy największe bity przed bitem znaku są jedynkami i zapisujemy jedynkę na bicie znaku, 
                        jeśli potecjalny overflow zgadza się z faktycznym*/

                   /*poniżej negujemy sumę x i y, która jest w x, aby znaleźć gdzie wystąpił faktyczny ujemny overflow. 
                   Robimy tak, bo dla dwóch ujemnych liczb overflow jest, jeśli któryś największy bit przed bitem znaku 
                   jest zerem,czyli jeśli oba są lub jeden jest jedynką, a drugi zerem, to dodawanie dwóch takich wektorów 
                   nie przeniesie jedynki na bit znaku, a co za tym idzie zanegowanie sprawi, że w miejscu sign bitu 
                   pojawi się jedynka, która z AND-em z potencjalnym wystąpieniem overflowa da informację o faktycznym
                   overflow. Z kolei jeśli oba bity poprzedzające bit znaku są jedynkami to overflowa na pewno nie ma 
                   i dwie jedynki dadzą przeniesienie na bit znaku, a zaprzeczenie liczby wykasuje tę jedynkę     
                   */
    not     %rdi 
    and     %rdi,%rcx 
    not     %rdi    
    mov     %rcx,%rax
    or      %rdx,%rax /*teraz wsadzamy do jednego rejestru faktyczne dodatnie jak i ujemne overflow-y*/
                             
                             /* poniższe 3 instrukcje odpowiadają za zmianę 1000 0000 na 1111 1111, czyli w każdym miejscu
                             gdzie pojawia się nadmiar. Najpierw 1000 0000 zmieniamy na 1 0000 0000 za pomocą lea, potem 
                             za pomocą shifta w prawo z 1000 0000 robimy 0000 0001, a potem odejmujemy, czyli
                             1 0000 0000 - 0000 0001 co daje 1111 1111 
                             */   
    lea     (%rax,%rax),%r10 
    shr     $7,%rax 
    sub     %rax,%r10 
    not     %r10  /*mając wektory z overflowem w postaci 1111 1111 łatwo możemy je wyciąć, negując*/
    and     %r10,%rdi /*otrzymujemy 0000 0000 w miejscu overflow-ów i wyniki sumowania bez overflowa w pozostałych miejscach*/
    xor     %r9,%rdi /*przywracamy znaki tam gdzie overflow-a nie było, ponieważ w 52 linijce zmieniliśmy maskę i teraz
                       za pomocą XOR-a zrobimy: 0^1=>1 i 0^0=>0, gdzie pierwsze zera to sign bity w %rdi, a 0 lub 1
                       to zapamętane w masce prawdziwe znaki wektorów bez overflow-a  */ 
    mov     %rdx,%rax /*kopia overflow-ów dodtanich */ 
    shr     $7,%rdx /*zmieniamy 1000 0000 na 0000 0001 w miejscach dodatnich faktycznych overflow-ów */ 
    sub     %rdx,%rax /*mamy 1111 1111 - 0000 0001, otrzymując 0111 1111, czyli maskę dla dodatnich faktycznych overflow-ów*/
    or      %rcx,%rax /* dodajemy do siebie dodatnie overflow-y w postaci 0111 1111 i ujemne, które pozostały postaci 1000 0000 */
    or      %rdi,%rax /*sumujemy wektory z nasyceniem, które były w rax-ie z pozostałymi wektorami bez nadmiaru*/
    ret
        .size   addsb, .-addsb
