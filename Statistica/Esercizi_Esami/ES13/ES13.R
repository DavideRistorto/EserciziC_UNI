setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES13")

load("atleti.RData")
str(dati)
head(dati)

table(dati$gruppo)
mean(dati$index[dati$gruppo == "I"])
sd(dati$index[dati$gruppo == "I"])
quantile(dati$index[dati$gruppo == "I"], 0.85)

boxplot(index ~ gruppo, data = dati)

#media(I) > media(T) ?
t.test(dati$index[dati$gruppo == "I"], dati$index[dati$gruppo == "T"], alternative = "greater")