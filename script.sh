#Script para compilar

gcc -o computos.out computos.c rutinas_clock.c -msse3

echo R Ciclos D > resultados.txt

LISTA1="$((2**16)) $((3*2**16)) $((2**19)) $((3*2**18)) $((2**21)) $((2**22)) $((2**23))"
LISTA2="1 6 10 20 24"

for R in $LISTA1
do
	for D in $LISTA2
	do
		echo $R
		./computos.out $R $D >> auxiliar.txt
	done
done	

awk '{print $11" "$12" "$13}' auxiliar.txt >> resultados.txt
rm auxiliar.txt
