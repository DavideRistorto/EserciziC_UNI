################################# ES1

setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_29_Gennaio")

load("bosco.RData")
head(dati)
nrow(dati)
mean(dati$DOPO)
sd(dati$DOPO)
sum(dati$DOPO > 500)
quantile(dati$DOPO, 0.9)

hist(dati$PRIMA, breaks = 14)
boxplot(dati$DOPO, dati$PRIMA)

t.test(dati$PRIMA, dati$DOPO, paired = TRUE, alternative = "greater")