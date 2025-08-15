################################# ES1

setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_11_Luglio")

load("fito.RData")
str(fito)
head(fito)

nrow(fito)
sum(is.na(fito))

dati <- na.omit(fito)
mean(dati$fitoplancton[dati$temperatura < 18.5])
sd(dati$fitoplancton[dati$temperatura < 18.5])

quantile(dati$temperatura, 0.05)

plot(fito$temperatura,fito$fitoplancton)

cor.test(fito$temperatura, fito$fitoplancton)

summary(lm(fitoplancton ~ temperatura, data = dati))

################################# ES2
pnorm(1.5, 0, 2)
pnorm(3, 0, 2, lower.tail = FALSE)
(pnorm(6, 0, 2) - pnorm(3, 0, 2)) / pnorm(6, 0, 2)

################################# ES3

load("escursioni.RData")
head(escursioni)
str(escursioni)

nrow(escursioni)
table(escursioni$Preferenza)
proportions(table(escursioni$Preferenza))

mean(escursioni$`Numero escursioni`[escursioni$Preferenza == "Sentiero facile"])

barplot(table(escursioni$Preferenza))
hist(escursioni$`Numero escursioni`)

binom.test(91, 162, alternative = "greater", p = 0.5)
