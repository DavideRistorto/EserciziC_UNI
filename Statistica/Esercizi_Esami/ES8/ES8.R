setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES8")

load("preferenza.RData")
str(dati)
head(dati)

nrow(dati)
mean(dati$Affidabilita)

table(dati$Preferenza)
proportions(table(dati$Preferenza))
proportions(table(dati$Preferenza[dati$Affidabilita > 0.5]))
mean(dati$Affidabilita[dati$Preferenza == "A"])

hist(dati$Affidabilita)
boxplot(Affidabilita ~ Preferenza, data = dati)
barplot(table(dati$Preferenza))

#il prodotto di marca A è preferito dalla metà dei consumatori?
binom.test(sum(dati$Preferenza == "A"), nrow(dati), p = 0.5, alternative = "two.sided")