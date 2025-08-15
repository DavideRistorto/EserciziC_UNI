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
