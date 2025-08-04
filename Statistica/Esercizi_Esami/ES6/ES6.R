setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES6")

load("diametri.RData")
str(dati)
head(dati)

table(dati$stabilimento ) # separo le frequenze per stabilimento
proportions(table(dati$stabilimento)) # calcolo la % delle proporzioni suddivise per stabilimento
mean(dati$diametro[dati$stabilimento == "B"]) # media dei diamentri provenienti solo dallo stabilimento B

quantile(dati$diametro, 0.1)

hist(dati$diametro)
boxplot(diametro ~ stabilimento, data = dati)

#il diametro medio dei pezzi prodotti nello stabilimento B è pari a 26?
t.test(dati$diametro[dati$stabilimento == "B"], mu = 26)
  