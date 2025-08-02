setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES6")

load("diametri.RData")
str(dati)
head(dati)

nrow(dati) # numero righe totali
table(dati$stabilimento)  #numero righe per stabilimento

proportions(table(dati$stabilimento)) # proporzioni per stabilimento
mean(dati$diametro[dati$stabilimento == "B"])

quantile(dati$diametro, 0.1)

hist(dati$diametro[dati$stabilimento == "B"])

boxplot(diametro ~ stabilimento, data = dati)

t.test(dati$diametro[dati$stabilimento == "B"]) #p value