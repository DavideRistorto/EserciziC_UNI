setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_12_Febbraio")

################################# ES1

pnorm(1.9,2,1, lower.tail = FALSE)
pnorm(3,2,1,lower.tail = FALSE)
(pnorm(3.5, 2, 1) - pnorm(1.7, 2, 1)) / pnorm(3.5, 2, 1)

################################# ES2

dpois(5, 1) + dpois(3,1)
ppois(7, 1) - ppois(0, 1)
( ppois(4,1) - dpois(0,1) ) / (1 - dpois(0,1))

################################# ES3
load("ristorante.RData")
head(ristorante)

nrow(ristorante)
table(ristorante$fascia_oraria)
proportions(table(ristorante$fascia_oraria))
table(ristorante$categoria_piatto == "Piatti vegetariani" & ristorante$fascia_oraria == "Pranzo")

chisq.test(table(ristorante$categoria_piatto))
  
################################## ES4
load("pezzi.RData")
head(pezzi)
proportions(table(pezzi$StatoPezzo))
proportions(table(pezzi$TipoDifetto[pezzi$StatoPezzo == "Non Conforme"]))
  
barplot(table(pezzi$TipoDifetto))  

binom.test(22, 51, p = 0.5, alternative = "less")
  
