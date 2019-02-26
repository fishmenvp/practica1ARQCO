#Script para compilar

gcc -o computos.out computos.c rutinas_clock.c -msse3

echo L Ciclos D > resultados.txt

#S1=$((2**9))
#S2=$((2**12))

LISTA1="$((2**8)) $((3*2**8)) $((2**11)) $((3*2**10)) $((2**13)) $((2**14)) $((2**15))"
LISTA2="1 2 16 64 95"

for L in $LISTA1
do
	for D in $LISTA2
	do
		echo $L
		./computos.out $L $D >> auxiliar.txt
	done
done	

awk '{print $11" "$12" "$13}' auxiliar.txt >> resultados.txt
rm auxiliar.txt
