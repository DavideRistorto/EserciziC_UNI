setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES15")

load("sicurezza.RData")
str(dati)
head(dati)

table(dati$sicurezza)
sum(is.na(dati))

mean(dati$vel[dati$sicurezza == "presente"])
sd(dati$vel[dati$sicurezza == "presente"])

quantile(dati$vel, 0.9, na.rm = TRUE)

hist(dati$vel)

# più del 60% dei veicoli in circolazione dispone di dispositivi per la sicurezza stradale?
binom.test(80, 115, p = 0.6, alternative = "greater")