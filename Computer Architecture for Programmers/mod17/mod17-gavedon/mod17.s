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
       .data   
        odd: .quad 0xF0F0F0F0F0F0F0F0 /*maska, żeby wyciąć liczby na nieparzystych indeksach (licząc od prawej od zera)*/
        even: .quad 0x0F0F0F0F0F0F0F0F /*maska, żeby wyciąć liczby na parzystych indeksach (licząc od prawej od zera)*/
		four_bits: .quad 0x0F /*lowest four bits mask*/
		seventeen: .quad 0x11
        .text
        .globl  mod17
        .type   mod17, @function

/*
 * W moim rozwiązaniu używam następującej techniki: Bierzemy liczbę, sumujemy "cyfry" (cyfra to coś od 0 do 15) stojące na parzystych
 indeksach (licząc od prawej od 0), sumujemy cyfry stojące na parzystych indeksach, a następnie odejmujemy, czyli 
 suma_parzystych - suma_nieparzystych= wynik. Wynik % 17 da to samo, co wejściowa liczba %17.
 */
/*int mod17(uint64_t x (%rdi))*/

mod17:
	mov %rdi, %rax
	mov %rdi, %r9
	and even, %rax /*zotawiamy w wyjściowym iksie tylko liczby z parzystych indeksów*/
	and odd, %r9 /*to samo dla nieparzystych */
	shr $4, %r9

	/*Cała poniższa sekcja będzie odpowiadała za sumowanie liczb z parzystych indesków ze sobą oraz nieprzystych ze sobą, odejmując
	nieprzyte od parzystych. Możemy zauważyć, że liczba uint64_t ma 16 liczb hex w sobie, czyli po 8 parzystych i nieparzystych. 
	Ponadto wiemy, że największa możliwa suma, to jeśli każda z ośmiu liczb hex będzie "0xF", wtedy suma będzie równa 0x8*0xF, czyli 
	120 w systemie decymalnym. Możemy zatem operować tylko na dolnym bajcie w każdym z rejestrów. */ 
	add %ah, %al
	mov %al, %r11b
	ror $16, %rax 
	add %ah, %al
	add %al, %r11b
	ror $16, %rax
	add %ah, %al
	add %al, %r11b
	ror $16, %rax
	add %ah, %al
	add %al, %r11b

	mov %r9, %rax
	add %ah, %al
	mov %al, %r8b
	ror $16, %rax 
	add %ah, %al
	add %al, %r8b
	ror $16, %rax
	add %ah, %al
	add %al, %r8b
	ror $16, %rax
	add %ah, %al
	add %al, %r8b

	mov %r11b, %al
	sub %r8b, %al



	/*Otrzymaliśmy nasz wynik, ale nie jest jeszcze tak kolorowo jak byśmy tego chcieli, ponieważ dla skrajnych przypadków pokroju
	0xF0F0F0F0F0F0F0F0 lub 0x0F0F0F0F0F0F0F0F otrzymamy wynik równy odpowiednio -120 i 120. Nie mogąc używać mnożenia ani dzielenia
	taki wynik nie rozwiąże nam całkowicie problemu. Musimy zatem dalej wykonywać różnice sumy parzystych i sumy nieparzystych 
	indeksów, aby dostać liczbę co do modułu mniejszą od 17. Jeśli pomyślimy o zawartości %al w systemie hexadecymalnym, to łatwo
	zauważyć, że największa możliwa uzyskana suma w nim to 30, bo 0xFF miesci się w przedziale [-120,120], a ponadto bierzemy
	F z parzystego indeksu i odejmujemy od niego (-F) z nieparzystego, dostając 0xF+0xF, czyli 30. Musimy wziąć -F, ponieważ mamy
	zapalony największy bit, tak jak bit znaku, który wpływa nam na ogólny znak liczby. Można sprawdzić, że to działa biorąc liczbę
	0xFF, czyli -1 i licząc %17 dla niej. Daje nam to 16, a nie 0 (które byśmy otrzymali odejmując F i F od siebie, nie uwzględnijąc
	znaku). Jeśli chodzi zaś o najmniejszą możliwą liczbę, to będzie to 0x70, które da -7. Nie musimy się nim martwić, ponieważ co do
	modułu wartośc ta jest mniejsza od 17. Bedziemy zatem wykonywać odejmowanie na liczbach, których róznica daje coś z 
	przedziału [17,30].*/
	mov		%al,%dil
	and		four_bits, %rax
	sar		$4,%dil   /*dla znaku równego zero po porstu odejmujemy, dla znaku równego jeden zmieniamy liczbę X na -X, żeby zachować
					    zasadę opisaną wyżej polegjącą na dodawaniu liczby jeśli jest ujemna, zamiast odejmowania*/
	sub		%dil,%al
	/*Rozpatrzmy 3 przypadki. Kiedy liczba w %al jest w przedziale [17,30], wtedy odejumujemy od niej 17 i mamy wynik, 
							  , gdy liczba w %al jest w przedziale [0,17), wtedy mamy wynik od razu
							  , gdy liczba w %al jest w przedziale [-7,0), wtedy 17-liczba to wynik*/ 
	xor 	%r10, %r10
	mov 	%al, %dl
	mov		%al, %cl
	cmp		$0x10, %al       /* Cała ta sekcja odpowiada rozpatrzenie tych 3 przedziałów tak, by nie używać jumpów*/
	cmove   seventeen, %r10  /*Ucinamy wszędzie cztery górne bity, zauważamy, że 4 dolne bity +1 to wynik liczb -[7,-1] modulo 17*/
	and     four_bits, %al   /*Z kolei liczby [17,30] po ucięciu 4 górnych bitów dają wynik, ale o jeden za duży, więc robimy -1*/
	shr 	$7, %dl			/*Liczby z przdziału [0,16] z kolei pozostaja bez zmian, poza 16, który jest edge casem
							bo po ucięciu 4 górych bitów dawałaby 0 zamiast 16. Operacje w ostatnich linijkach sprawdzają właśnie
							znak liczby oraz piąty bity, czyli ten który się świeci tylko dla liczb 16+ i wykonuje njpierwa dodawanie
							jedynki dla AND sign, czyli +1 dla ujemnych, +0 dla reszty, potem zaś odejmuje 1 dla tych co mają
							zapalony piąty bit i znak zerowy (liczone xorem, bo zerowy znak i zerowy piąty bit daje na xorze 0
							tj. dla dodatnich z przedziału [0,15] oraz xor daje zero dla ujemnych, bo one mają 1 na znaku i 1 na
							piątym bicie.). Dla szesnastki przypisujemy cmove -em 17, żeby po odjęciu 1 dla liczb o zerowym znaku
							i niezerowym piątym bicie dostać pożądane 16 */
	add		%dl, %al
	shr     $4, %cl
	and     $1, %cl
	xor     %dl, %cl
	add		%r10b, %al
	sub     %cl, %al
	ret
        .size   mod17, .-mod17
