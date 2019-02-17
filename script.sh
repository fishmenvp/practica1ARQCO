#Script para compilar

gcc -o computos.out computos.c rutinas_clock.c -msse3

echo R Ciclos D > resultados.txt

LISTA1="$((2**16)) $((3*2**16)) $((2**19)) $((3*2**18)) $((2**21)) $((2**22)) $((2**23))"
LISTA2="10 20 23 26 40"

for R in $LISTA1
do
	for D in $LISTA2
	do
		echo $R
		./computos.out $R $D >> resultados.txt 
	done
done	

awk '{print $11" "$12" "$13}' resultados.txt > resultados.txt

