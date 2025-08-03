setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES12")

load("atleti.RData")
str(dati)
head(dati)

nrow(dati)
sum(is.na(dati))

# pulisco i dati, perhcè senno media e sd non funzionano
dati <- na.omit(dati)
mean(dati$index_PRE)
sd(dati$index_PRE)

quantile(dati$index_PRE, 0.75)

boxplot(dati$index_PRE, dati$index_POST)

t.test(dati$index_PRE, dati$index_POST, alternative = "less", paired = TRUE)

# pre_Allenamento < post_Allenamento ? accetto H0 perchè p-value > 0.05