################################# ES1

setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_29_Gennaio")

load("alberi.RData")
head(dati)

nrow(dati)
sum(is.na(dati))

dati <- na.omit(dati)
mean(dati$diametro[dati$altezza>=25 & dati$altezza<=35])
sd(dati$diametro[dati$altezza>=25 & dati$altezza<=35])
quantile(dati$altezza, 0.9)

boxplot(dati$altezza[dati$diametro<40],dati$altezza[dati$diametro>=40])
cor.test(dati$altezza, dati$diametro)
#Stimo la retta di regressione lineare considerando
lm(altezza ~ diametro, data = dati)$coefficients #Il secondo numero è il coefficiente angolare

################################# ES2
pexp(1.5, 2) + pexp(3, 2, lower.tail = FALSE)
pexp(3, 2, lower.tail = FALSE)
pexp(6, 2) - pexp(3,2)

################################# ES3

load("fertilizzante.RData")
head(dati)

table(dati$fertilizzante)
mean(dati$altezza[dati$fertilizzante == "A"])
sd(dati$altezza[dati$fertilizzante == "A"])
quantile(dati$altezza[dati$fertilizzante == "A"], 0.9)

boxplot(dati$altezza[dati$fertilizzante == "A"], dati$altezza[dati$fertilizzante == "B"])

t.test(dati$altezza[dati$fertilizzante == "A"], dati$altezza[dati$fertilizzante == "B"], alternative = "two.sided")

################################# ES4

#Si tira quattro volte una moneta non equa, con probabilità di ottenere testa pari a 1/3

#i primi tre lanci sono uguali
(2/3)^3 + (1/3)^3

#gli ultimi due risultati sono uguali
(2/3)^2 + (1/3)^2

# Sia A che B
(2/3)^4 + (1/3)^4


pnorm(1.5, 0, 2)
pnorm(3, 0, 2, lower.tail = FALSE)
(pnorm(6, 0, 2) - pnorm(3, 0, 2)) / pnorm(6, 0, 2)





4*0.3
pbinom(3, 4, 0.3)
pbinom(3, 4, 0.3) - pbinom(1, 4, 0.3)
(pbinom(3, 4, 0.3) - dbinom(0, 4, 0.3)) / (1 - dbinom(0, 4, 0.3))











