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
        sign: .quad 0x80000000
        exp: .quad 0x7F800000
        mantisa: .quad 0x007FFFFF
        BIAS: .quad 0x3F800000
        .text
        .globl  cubef
        .type   cubef, @function

/*
 * W moim rozwiązaniu używam następującej techniki: Bierzemy x z wejścia. Dodajemy wykładniki x oraz x, czyli
 defacto podwajamy wykładnik iksa, mnożymy mantysy x i x, normalizujemy wynik. W ten sposób będziemy mieli x^2
 , a więc otrzymaną liczbę x^2 przemnożymy jeszcze raz przez x, aby mieć szcześcian. Zrobimy to taką samą techniką
 jak pierwsze mnożenie iksa z iksem. Ponadto w końcowej normalizacji sprawdzamy guard, round i sticky bit, aby zrobić
 odpowiednie zaokrągelnie. Problem w moim rozwiązaniu polega na tym, że ostatni bit jest źle zaokrąglany. Oprócz samego liczenia wykładników i mantys
 to jeszcze jumpa używamy w celu sprawdzenia overflowa jak i zbyt małego wyniku, by był reprezentowalny. W sekcji data są wszystkie 
 potrzebne zmienne i stałe
 */
/* seee eeee emmm mmmm mmmm mmmm mmmm mmmm */
/* uint32_t cubef(uint32_t x (%rdi))*/
cubef:
        mov %rdi, %rdx
        mov %rdi, %rsi
        mov %rdi, %rax
	/*Wykładniki x*x*/
	and 	exp,%rdi
	sub 	BIAS,%rdi
	add 	%rdi,%rdi
	add 	BIAS,%rdi
        cmp     $0, %rdi
        jle     LP
        cmp     exp, %rdi 
        jge     RP 

	/*Mantysa x*x*/
	and 	mantisa,%rsi
	or 	$0x800000,%rsi /*jedynka z przodu mantysy*/
	imul 	%rsi,%rsi
	shr 	$23,%rsi
	
	/*Normalizacja x*x*/
	mov 	$0xff000000,%rcx
	and 	%rsi,%rcx
	shr 	$1,%rcx
	add	%rcx,%rdi
	shr	$23,%rcx
	shr 	%cl,%rsi
	and 	mantisa,%rsi
 

	/*Łączenie znów w jedną liczbę*/
	or 	%rsi,%rdi
	and 	sign,%rax
	or 	%rdi,%rax

        mov 	%rdx,%rdi
        mov     %rax,%r8
        mov 	%rax,%r9
        /*Wykładniki x^2 *x*/
	and 	exp,%rdi
	and 	exp,%r8
	sub 	BIAS,%r8
	sub 	BIAS,%rdi
	add 	%rdi,%r8
	add 	BIAS,%r8
        cmp     $0, %r8 
        jle     LP
        cmp     exp, %r8 
        jge     RP 

	/*Mantysy x^2 * x*/
	and 	mantisa,%rdx
	and 	mantisa,%r9
	or 	$0x800000,%rdx
	or 	$0x800000,%r9
	imul 	%rdx,%r9
        mov     %r9, %r10
        mov     %r9, %r11
        shr     $21, %r10
        shr     $22, %r11
	shr 	$23,%r9


	/*Normalizacja wyniku*/
	mov 	$0xff000000,%rcx
	and 	%r9,%rcx
	shr 	$1,%rcx
	add	%rcx,%r8
	shr	$23,%rcx
	shr 	%cl,%r9
	and 	mantisa,%r9
        mov     %r9, %rcx
        and     $1, %rcx
        and     $1, %r10
        and     $1, %r11
        and     %r11,%r10
        and     %rcx,%r11
        or      %r11, %r10
        add     %r10, %r9

	/*Wszystko w jednym rejsetrze*/
	or 	%r9,%r8
	and 	sign,%rax
	or 	%r8,%rax
	ret
LP:     and sign, %rax /* + - zero*/
        ret
RP:     and sign, %rdx  /* + - inf */
        mov exp, %rax
        or  %rdx, %rax
        ret
        .size   cubef, .-cubef
        .size   cubef, .-cubef
	