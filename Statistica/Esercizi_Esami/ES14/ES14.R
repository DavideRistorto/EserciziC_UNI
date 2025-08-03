setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES14")

load("voti.RData")
str(dati)
head(dati)

table(dati$scuola)
mean(dati$voto[dati$scuola == "A"])
sd(dati$voto[dati$scuola == "A"])
quantile(dati$voto[dati$scuola == "A"], 0.95)

boxplot(voto ~ scuola, data = dati)

# Media_A = Media_B ?
t.test(dati$voto[dati$scuola == "A"], conf.level = 0.99)
t.test(dati$voto[dati$scuola == "B"], conf.level = 0.99)