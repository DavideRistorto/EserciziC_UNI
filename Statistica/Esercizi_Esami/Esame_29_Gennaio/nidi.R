setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_29_Gennaio")

################################# ES1

load("nidi.RData")
head(dati)

nrow(dati)
which(is.na(dati$Nido))
dati <- na.omit(dati)

table(dati$Foresta)
proportions(table(dati$Foresta))
sum(dati$Foresta == "Primaria" & dati$Nido == "Occupato")

barplot(table(dati$Nido))
barplot(table(dati$Foresta))

min(chisq.test(dati$Foresta, dati$Nido)$expected)


################################# ES2

pnorm(3, 1, 1, lower.tail = FALSE)
(pnorm(6, 1, 1) - pnorm(0.5, 1, 1))/pnorm(6, 1, 1)

################################# ES3

dpois(2, 10) + dpois(7,10) + dpois(8, 10) + dpois(9, 10)
ppois(4, 10, lower.tail = FALSE)
(ppois(3, 10) - ppois(0, 10) ) / (1-dpois(0,10))


################################# ES4

load("pallavolo.RData")
head(dati)

nrow(dati)
mean(dati$DOPO)
sd(dati$DOPO)

sum(dati$DOPO > 0.7)
quantile(dati$DOPO, 0.95)

boxplot(dati$PRIMA, dati$DOPO)
t.test(dati$PRIMA, dati$DOPO, paired = TRUE, alternative = "less")