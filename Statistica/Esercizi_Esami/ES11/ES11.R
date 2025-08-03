setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES11")

load("batterie.RData")
str(dati)
head(dati)

nrow(dati)
mean(dati$durata[dati$marca == "B"])
sd(dati$durata[dati$marca == "B"])

#Doppio filtro in AND
sum(dati$marca == "B" & dati$durata >= 10)
quantile(dati$durata[dati$marca == "B"], 0.95)

#boxplot
boxplot(durata ~ marca, data = dati)
hist(dati$durata)
barplot(table(dati$marca))

t.test(dati$durata[dati$marca == "B"], dati$durata[dati$marca == "A"], alternative = "two.sided", paired = FALSE)