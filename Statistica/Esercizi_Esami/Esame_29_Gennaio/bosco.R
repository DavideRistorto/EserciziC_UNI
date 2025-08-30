################################# ES1

setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_29_Gennaio")

load("bosco.RData")
head(dati)

nrow(dati)
mean(dati$DOPO)
sd(dati$DOPO)
sum(dati$DOPO>500)
quantile(dati$DOPO, 0.9)

boxplot(dati$PRIMA, dati$DOPO)
hist(dati$PRIMA, breaks = 15)
hist(dati$DOPO, breaks = 15)

t.test(dati$PRIMA, dati$DOPO, paired = TRUE, alternative = "greater")

################################# ES2
4/16
8/16
2/16

################################# ES3
pexp(1.5, 1)
pexp(3, 1, lower.tail = FALSE)
(pexp(6, 1) - pexp(3, 1)) / pexp(6, 1)