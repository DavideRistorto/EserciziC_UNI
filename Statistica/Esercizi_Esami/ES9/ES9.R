setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES9")

load("applicazione.RData")
str(dati)
head(dati)

nrow(dati)
sum(is.na(dati))

mean(dati$time_new_version)
sd(dati$time_new_version)

sum(dati$time_new_version > 26.5)

quantile(dati$time_new_version, 0.9)

hist(dati$time_old_version)
# less perchè vogliamo che media_new < media_old e i dati sono appaiati
t.test(dati$time_new_version, dati$time_old_version, alternative = "less", paired = TRUE)