setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/Esame_11_Luglio")
################################# ES1
load("fito.RData")
head(fito)

nrow(fito)          #Numero righe
sum(is.na(fito))    #Numero dati mancanti
which(is.na(fito))  #Quale riga manga il dato

fito <- na.omit(fito) #Pulisco togliendo i dati mancanti, che sennò non permettono il giusto calcolo 
mean(fito$fitoplancton[fito$temperatura<18.5])
sd(fito$fitoplancton[fito$temperatura<18.5])
quantile(fito$temperatura, 0.05)

plot(fito$temperatura, fito$fitoplancton)  #Scatterplot

#Il grafico fa pensare che le 2 variabili siano positivamente correlate:
#Al crescere di una, cresce anche l' altra
cor.test(fito$temperatura, fito$fitoplancton)   # Test sulla correlazione delle variabili
summary(lm(fitoplancton ~ temperatura,data = fito))  #Calcolo il valore R^2

################################# ES2
pnorm(1.5, 0, 2)
pnorm(3, 0, 2, lower.tail = FALSE)
(pnorm(6,0,2)-pnorm(3,0,2))/pnorm(6,0,2)

################################# ES3

load("escursioni.RData")
head(escursioni)

nrow(escursioni)
(table(escursioni$Preferenza))

mean(escursioni$`Numero escursioni`[escursioni$Preferenza == "Sentiero facile"])

barplot(table(escursioni$Preferenza))
hist(escursioni$`Numero escursioni`, breaks = 9)
binom.test(91, 91+71, p=0.5, alternative = "greater")









