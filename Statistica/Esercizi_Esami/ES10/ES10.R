setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES10")

load("compressione.RData")
str(dati)
head(dati)

nrow(dati)
mean(dati$compressione_B)
sd(dati$compressione_B)
sum(dati$compressione_B > 50)
quantile(dati$compressione_B, 0.2)

hist(dati$compressione_B)
boxplot(dati$compressione_A, dati$compressione_B)

t.test(dati$compressione_A, dati$compressione_B, alternative = "two.sided", paired = TRUE)