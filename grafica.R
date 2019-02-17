

resultados = read.table("resultados.txt", header = TRUE)

head(resultados)

install.packages("dplyr")
library("dplyr")

nombres= list(x = c(seq(, 20000, by=2000)),  z = c(seq(2, 12, by=2))) 
datos = matrix (nrow = 10, ncol = 6, dimnames = nombres)

for (i in c(seq(2, 12, by=2))) {
  for (j in c(seq(2000, 20000, by=2000)))
    datos[j/2000, i/2] = filter(resultados, hilos == i & numero == j)$fallos
}

barplot(datos, col=c("black", "brown3", "darkgoldenrod3", "dodgerblue3", "darkgrey", 
                     "darkgoldenrod4", "darkorange3", "darkorchid3", "firebrick3", "deeppink3") , border="black", 
        font.axis=2, beside=T, legend=rownames(data), xlab="Hilos", ylab="Porcentaje", font.lab=2)
