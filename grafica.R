

resultados = read.table("resultados.txt", header = TRUE)

head(resultados)

#install.packages("dplyr")
library("dplyr")

x = c(2**8,3*2**8,2**11,3*2**10,2**13,2**14,2**15)
z = c(1, 2, 16, 64, 95)
nombres= list(z,  x) 

datos = matrix (nrow = 5, ncol = 7, dimnames = nombres)

for (i in c(seq(1, 5, by=1))) {
  for (j in c(seq(1, 7, by=1)))
    datos[i, j] = filter(resultados, D == z[i] & L == x[j])$Ciclos
}

barplot(datos, col=c("black", "brown3", "darkgoldenrod3", "dodgerblue3", "darkgrey") , border="black", 
        font.axis=2, beside=T, legend=rownames(data), xlab="L", ylab="Ciclos", font.lab=2)