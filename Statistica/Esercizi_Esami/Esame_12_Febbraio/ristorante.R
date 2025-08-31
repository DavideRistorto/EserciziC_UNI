setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_12_Febbraio")

################################# ES1
pnorm(1.9, 2, 1, lower.tail = FALSE)
pnorm(3, 2, 1, lower.tail = FALSE)
(pnorm(3.5, 2, 1) - pnorm(1.7, 2, 1)) / pnorm(3.5, 2, 1)

################################# ES2
dpois(5, 1) + dpois(3, 1)
ppois(7, 1) - ppois(0.5, 1)
(ppois(4, 1) - ppois(0, 1)) / ppois(0,1, lower.tail = FALSE) #---------------------> DA CAPIRE
################################# ES3
load("ristorante.RData")
head(ristorante)

nrow(ristorante)
which(is.na(ristorante$categoria_piatto))
ristorante <- na.omit(ristorante)
table(ristorante$fascia_oraria)
proportions(table(ristorante$fascia_oraria))
sum(ristorante$fascia_oraria == "Pranzo" & ristorante$categoria_piatto == "Piatti vegetariani")

barplot(table(ristorante$categoria_piatto))
barplot(table(ristorante$fascia_oraria))
chisq.test(table(ristorante$categoria_piatto),p=rep(1/3,3))$expected

  
################################## ES4
load("pezzi.RData")
head(pezzi)

nrow(pezzi)
table(pezzi$StatoPezzo)
proportions(table(pezzi$StatoPezzo))
proportions(table(pezzi$TipoDifetto[pezzi$StatoPezzo == "Non Conforme"]))
barplot(table(pezzi$StatoPezzo))
barplot(table(pezzi$TipoDifetto))

sum(pezzi$StatoPezzo == "Non Conforme" & pezzi$TipoDifetto == "Estetico")

binom.test(22 , 51, p = 0.5, alternative = "less")






