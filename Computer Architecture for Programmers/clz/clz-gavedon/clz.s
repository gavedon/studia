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
        .globl  clz
        .type   clz, @function

/*
 * W moim rozwiązaniu używam następującej techniki: W tym zadaniu plan jest taki, że znajdujemy pierwsze wystąpienie
 jedynki, licząc od lewej, następnie zamieniamy wszystkie liczby występujące po niej na jedynki i żeby policzyć leading
 zeros odejmiemy od liczby wszystkich bitów tj. 64 bitów liczbę jedynek, którą policzymy tak jak w zadaniu 2 na liście
 pierwszej, za pomocą Hamming Weight'a.
 */

 /*
int clz(uint64_t x (%rdi))
 */

clz:
/*Sekcja pierwsza odpowiada właśnie za wyżej wspomniane ustawienie wszystkich bitów po pierwszej jedynce na jedynki
tzn. np. 0000 0000 01bb bbbb bbbb... => 0000 0000 01111 1111 1111... (gdzie b to dowolnie 0 lub 1).Technika tutaj jest 
bardzo prosta. Bierzemy wejściowego iksa i sumujemy z liczbą przesuniętą shiftem o jeden w prawo. 
To zagwarantuje nam, że pierwsza jedynka i bit po niej staną się jedynkami. Następnie sumujemy otrzymaną liczbę z 
zapewnionymi dwoma jedynkami z tą liczbą przesuniętą o 2, co dam nam pewność, że pierwsza jedynka i 3 bity po niej będą
jedynkami, potem 4 jedynki + przesunięte o 4 dadzą 8 itd. aż w końcu dojdziemy do momentu, że przesuniemy o 32 i wszystkie
liczby po pierwszej jedynce będą jedynkami.*/

/*1*/
        mov 	%rdi,%rdx
	shr     $1,%rdx
	or 	%rdx,%rdi

	mov 	%rdi,%rdx
	shr	$2,%rdx
	or 	%rdx,%rdi

	mov 	%rdi,%rdx
	shr	$4,%rdx
	or 	%rdx,%rdi

	mov 	%rdi,%rdx
	shr	$8,%rdx
	or 	%rdx,%rdi

	mov 	%rdi,%rdx
	shr	$16,%rdx
	or 	%rdx,%rdi

	mov 	%rdi,%rdx
	shr	$32,%rdi
	or 	%rdi,%rdx
        mov 	%rdx,%rdi

/* Druga sekcja, tak jak w skrótowym opisie odpowiada za nic innego jak zsumowanie wszystkich jedynek. Opiera się
na bardzo szybkiej metodzie zliczania zapalonych bitów:
int popcount64c(uint64_t x)
{
    x -= (x >> 1) & 0x5555555555555555;                                 //put count of each 2 bits into those 2 bits
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);     //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;                            //put count of each 8 bits into those 8 bits 
    return (x * 0x0101010101010101) >> 56;                     //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}*/

/*2*/ 
	mov 	$0x5555555555555555,%r8
	shr 	$1,%rdi
	and 	%r8,%rdi                        /*pierwsza instrukcja z powyższego kodu*/
        sub     %rdi, %rdx

	mov 	%rdx,%rdi
	mov 	$0x3333333333333333,%r9
	shr 	$2,%rdi
	and 	%r9,%rdx                         /*druga instrukcja z powyższego kodu*/
	and 	%r9,%rdi
	add 	%rdi,%rdx

	mov 	%rdx,%rdi
	mov 	$0x0f0f0f0f0f0f0f0f,%r10
	shr 	$4,%rdi                          /*trzecia instrukcja z powyższego kodu*/
        add 	%rdx,%rdi
	and 	%r10,%rdi

	mov	$0x0101010101010101,%rcx
	imul	%rcx,%rdi
        shr    	$56,%rdi                         /*czwarta instrukcja z powyższego kodu zmodyfikowana o 64 - liczba_jedynek*/
        mov     $0x40, %rax   /* liczba wszystkich 64 bitów*/
        sub     %rdi, %rax
        ret

        .size   clz, .-clz
